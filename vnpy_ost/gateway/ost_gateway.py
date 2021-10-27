import pytz
from datetime import datetime
from typing import Any, Dict, List, Set, Tuple
from pathlib import Path

from vnpy.event import EventEngine
from vnpy.trader.constant import (
    Direction,
    Exchange,
    OrderType,
    Product,
    Status
)
from vnpy.trader.gateway import BaseGateway

from vnpy.trader.object import (
    TickData,
    OrderData,
    TradeData,
    PositionData,
    AccountData,
    ContractData,
    OrderRequest,
    CancelRequest,
    SubscribeRequest,
)
from vnpy.trader.utility import get_folder_path
from vnpy.trader.event import EVENT_TIMER
from ..api import MdApi, TdApi

# 委托状态映射
STATUS_OST2VT: Dict[Any, Status] = {
    0: Status.ALLTRADED,
    1: Status.PARTTRADED,
    2: Status.PARTTRADED,
    3: Status.NOTTRADED,
    4: Status.NOTTRADED,
    5: Status.CANCELLED,
    "a": Status.REJECTED
}

# 买卖方向映射
DIRECTION_VT2OST: Dict[Direction, int] = {
    Direction.LONG: 0,
    Direction.SHORT: 1
}
DIRECTION_OST2VT: Dict[int, Direction] = {v: k for k, v in DIRECTION_VT2OST.items()}

# 交易所映射
EXCHANGE_OST2VT: Dict[int, Exchange] = {
    1: Exchange.SSE,
    2: Exchange.SZSE
}

# 产品类型映射
PRODUCT_OST2VT: Dict[int, Product] = {
    8: Product.EQUITY
}

# 中国时区
CHINA_TZ = pytz.timezone("Asia/Shanghai")

# 合约数据全局缓存字典
symbol_contract_map: Dict[str, ContractData] = {}

class OstGateway(BaseGateway):
    """
    vn.py用于对接东方证券OST的交易接口。
    """

    default_setting: Dict[str, str] = {
        "用户名": "",
        "密码": "",
        "经纪商代码": "",
        "交易服务器": "",
        "产品名称": "",
        "授权编码": ""
    }

    exchanges: List[str] = list(EXCHANGE_OST2VT.values())

    def __init__(self, event_engine: EventEngine, gateway_name: str = "OST") -> None:
        """构造函数"""
        super().__init__(event_engine, gateway_name)

        self.td_api: "OstTdApi" = OstTdApi(self)
        self.md_api: "OstMdApi" = OstMdApi(self)

    def connect(self, setting: dict) -> None:
        """连接交易接口"""
        userid: str = setting["用户名"]
        password: str = setting["密码"]
        brokerid: str = setting["经纪商代码"]
        td_address: str = setting["交易服务器"]
        appid: str = setting["产品名称"]
        auth_code: str = setting["授权编码"]

        if (
            (not td_address.startswith("tcp://"))
            and (not td_address.startswith("ssl://"))
        ):
            td_address = "tcp://" + td_address

        self.td_api.connect(td_address, userid, password, brokerid, auth_code, appid)
        self.td_api.connect()

        self.init_query()

    def subscribe(self, req: SubscribeRequest) -> None:
        """订阅行情"""
        self.md_api.subscribe(req)

    def send_order(self, req: OrderRequest) -> str:
        """委托下单"""
        vt_orderid: str = self.td_api.send_order(req)
        return vt_orderid

    def cancel_order(self, req: CancelRequest) -> None:
        """委托撤单"""
        self.td_api.cancel_order(req)

    def query_account(self) -> None:
        """查询资金"""
        self.td_api.query_account()

    def query_position(self) -> None:
        """查询持仓"""
        self.td_api.query_position()

    def close(self) -> None:
        """关闭接口"""
        self.td_api.close()
        self.md_api.close()

    def write_error(self, msg: str, error: dict) -> None:
        """输出错误信息日志"""
        error_id: int = error["ErrorID"]
        error_msg: str = error["ErrorMsg"]
        msg = f"{msg}，代码：{error_id}，信息：{error_msg}"
        self.write_log(msg)

    def process_timer_event(self, event) -> None:
        """定时事件处理"""
        self.count += 1
        if self.count < 2:
            return
        self.count = 0

        func = self.query_functions.pop(0)
        func()
        self.query_functions.append(func)

        self.md_api.update_date()

    def init_query(self) -> None:
        """初始化查询任务"""
        self.count: int = 0
        self.query_functions: list = [self.query_account, self.query_position]
        self.event_engine.register(EVENT_TIMER, self.process_timer_event)


class OstMdApi(MdApi):
    """"""

    def __init__(self, gateway: OstGateway) -> None:
        """构造函数"""
        super().__init__()

        self.gateway: OstGateway = gateway
        self.gateway_name: str = gateway.gateway_name

        self.reqid: int = 0

        self.connect_status: bool = False

        self.current_date: str = datetime.now().strftime("%Y%m%d")

    def onRspSubL1MarketData(self, data: dict,) -> None:
        """订阅行情回报"""
        if not data or not data["ErrorID"]:
            return

        self.gateway.write_log(f"行情订阅失败，错误码{data['ErrorID']}，原因{data['ErrorMsg']}")

    def onRtnL1MarketData(self, data: dict) -> None:
        """行情数据推送"""
        # 过滤没有时间戳的异常行情数据
        if not data["origTime"]:
            return

        symbol: str = data["securityId"]
        contract: ContractData = symbol_contract_map.get(symbol, None)
        if not contract:
            return

        tick: TickData = TickData(
            symbol=symbol,
            exchange=contract.exchange,
            datetime=generate_datetime(data["origTime"]),
            name=contract.name,
            volume=data["tradeVolumn"],
            turnover=data["tradeValue"],
            last_price=data["lastPx"],
            limit_up=data["upperLimit"],
            limit_down=data["lowerLimit"],
            open_price=data["openPx"],
            high_price=data["highPx"],
            low_price=data["lowPx"],
            pre_close=data["preClosePx"],
            gateway_name=self.gateway_name
        )

        tick.bid_price_1, tick.bid_price_2, tick.bid_price_3, tick.bid_price_4, tick.bid_price_5 = data["bid"][0:5]
        tick.ask_price_1, tick.ask_price_2, tick.ask_price_3, tick.ask_price_4, tick.ask_price_5 = data["ask"][0:5]
        tick.bid_volume_1, tick.bid_volume_2, tick.bid_volume_3, tick.bid_volume_4, tick.bid_volume_5 = data["bid_qty"][0:5]
        tick.ask_volume_1, tick.ask_volume_2, tick.ask_volume_3, tick.ask_volume_4, tick.ask_volume_5 = data["ask_qty"][0:5]
        self.gateway.on_tick(tick)

    def connect(self) -> None:
        """连接服务器"""
        # 禁止重复发起连接，会导致异常崩溃
        if not self.connect_status:
            self.createCSecurityDntL2MDUserApi()

            self.gateway.write_log("行情接口已连接")
            self.connect_status = True

    def subscribe(self, req: SubscribeRequest) -> None:
        """订阅行情"""
        if self.connect_status:
            ost_req: dict = {
               "securitySource": 101,
               "securityId": req.symbol,
               "subscribeType": 1
            }
            self.subscribeL1MarketData(ost_req)

    def close(self) -> None:
        """关闭连接"""
        if self.connect_status:
            self.exit()

    def update_date(self) -> None:
        """更新当前日期"""
        self.current_date = datetime.now().strftime("%Y%m%d")


class OstTdApi(TdApi):
    """"""

    def __init__(self, gateway: OstGateway) -> None:
        """构造函数"""
        super().__init__()

        self.gateway: OstGateway = gateway
        self.gateway_name: str = gateway.gateway_name

        self.reqid: int = 0
        self.order_ref: int = 0

        self.connect_status: bool = False
        self.login_status: bool = False
        self.auth_status: bool = False
        self.login_failed: bool = False
        self.contract_inited: bool = False

        self.userid: str = ""
        self.password: str = ""
        self.brokerid: str = ""
        self.auth_code: str = ""
        self.appid: str = ""

        self.frontid: int = 0
        self.sessionid: int = 0

        self.order_data: List[dict] = []
        self.trade_data: List[dict] = []
        self.positions: Dict[str, PositionData] = {}
        self.sysid_orderid_map: Dict[str, str] = {}

    def onFrontConnected(self) -> None:
        """服务器连接成功回报"""
        self.gateway.write_log("交易服务器连接成功")

        if self.auth_code:
            self.authenticate()
        else:
            self.login()

    def onFrontDisconnected(self, reason: int) -> None:
        """服务器连接断开回报"""
        self.login_status = False
        self.gateway.write_log(f"交易服务器连接断开，原因{reason}")

    def onRspAuthenticate(self, data: dict, error: dict, reqid: int, last: bool) -> None:
        """用户授权验证回报"""
        if not error['ErrorID']:
            self.auth_status = True
            self.gateway.write_log("交易服务器授权验证成功")
            self.login()
        else:
            self.gateway.write_error("交易服务器授权验证失败", error)

    def onRspUserLogin(self, data: dict, error: dict, reqid: int, last: bool) -> None:
        """用户登录请求回报"""
        if not error["ErrorID"]:
            self.frontid = data["FrontID"]
            self.sessionid = data["SessionID"]
            self.login_status = True
            self.gateway.write_log("交易服务器登录成功")

            # 自动确认结算单
            ost_req: dict = {
                "BrokerID": self.brokerid,
                "InvestorID": self.userid
            }
            self.reqid += 1
            self.reqSettlementInfoConfirm(ost_req, self.reqid)
        else:
            self.login_failed = True

            self.gateway.write_error("交易服务器登录失败", error)

    def onRspOrderInsert(self, data: dict, error: dict, reqid: int, last: bool) -> None:
        """委托下单失败回报"""
        order_ref: str = data["OrderRef"]
        orderid: str = f"{self.frontid}_{self.sessionid}_{order_ref}"

        symbol: str = data["InstrumentID"]
        contract: ContractData = symbol_contract_map[symbol]

        order: OrderData = OrderData(
            symbol=symbol,
            exchange=contract.exchange,
            orderid=orderid,
            direction=DIRECTION_OST2VT[data["Direction"]],
            price=data["LimitPrice"],
            volume=data["VolumeTotalOriginal"],
            status=Status.REJECTED,
            gateway_name=self.gateway_name
        )
        self.gateway.on_order(order)

        self.gateway.write_error("交易委托失败", error)

    def onRspOrderAction(self, data: dict, error: dict, reqid: int, last: bool) -> None:
        """委托撤单失败回报"""
        self.gateway.write_error("交易撤单失败", error)

    def onRspSettlementInfoConfirm(self, data: dict, error: dict, reqid: int, last: bool) -> None:
        """确认结算单回报"""
        self.gateway.write_log("结算信息确认成功")

        # 由于流控，单次查询可能失败，通过while循环持续尝试，直到成功发出请求
        while True:
            self.reqid += 1
            n: int = self.reqQryInstrument({}, self.reqid)

            if not n:
                break
            else:
                sleep(1)

    def onRspQryInvestorPosition(self, data: dict, error: dict, reqid: int, last: bool) -> None:
        """持仓查询回报"""
        if not data:
            return

        # 必须已经收到了合约信息后才能处理
        symbol: str = data["InstrumentID"]
        contract: ContractData = symbol_contract_map.get(symbol, None)

        if contract:
            # 获取之前缓存的持仓数据缓存
            key: str = f"{data['InstrumentID'], data['PosiDirection']}"
            position: PositionData = self.positions.get(key, None)
            if not position:
                position: PositionData = PositionData(
                    symbol=data["InstrumentID"],
                    exchange=contract.exchange,
                    direction=Direction.NET,
                    gateway_name=self.gateway_name
                )
                self.positions[key] = position

            # 对于上期所昨仓需要特殊处理
            if position.exchange in [Exchange.SHFE, Exchange.INE]:
                if data["YdPosition"] and not data["TodayPosition"]:
                    position.yd_volume = data["Position"]
            # 对于其他交易所昨仓的计算
            else:
                position.yd_volume = data["Position"] - data["TodayPosition"]

            # 获取合约的乘数信息
            size: int = contract.size

            # 计算之前已有仓位的持仓总成本
            cost: float = position.price * position.volume * size

            # 累加更新持仓数量和盈亏
            position.volume += data["Position"]
            position.pnl += data["PositionProfit"]

            # 计算更新后的持仓总成本和均价
            if position.volume and size:
                cost += data["PositionCost"]
                position.price = cost / (position.volume * size)

            # 更新仓位冻结数量
            if position.direction == Direction.LONG:
                position.frozen += data["ShortFrozen"]
            else:
                position.frozen += data["LongFrozen"]

        if last:
            for position in self.positions.values():
                self.gateway.on_position(position)

            self.positions.clear()

    def onRspQryTradingAccount(self, data: dict, error: dict, reqid: int, last: bool) -> None:
        """资金查询回报"""
        if "AccountID" not in data:
            return

        account: AccountData = AccountData(
            accountid=data["AccountID"],
            balance=data["Balance"],
            frozen=data["FrozenMargin"] + data["FrozenCash"] + data["FrozenCommission"],
            gateway_name=self.gateway_name
        )
        account.available = data["Available"]

        self.gateway.on_account(account)

    def onRspQryInstrument(self, data: dict, error: dict, reqid: int, last: bool) -> None:
        """合约查询回报"""
        product: Product = PRODUCT_OST2VT.get(data["ProductClass"], None)
        if product:
            contract: ContractData = ContractData(
                symbol=data["InstrumentID"],
                exchange=EXCHANGE_OST2VT[data["ExchangeID"]],
                name=data["InstrumentName"],
                product=product,
                size=data["VolumeMultiple"],
                pricetick=data["PriceTick"],
                gateway_name=self.gateway_name
            )

            self.gateway.on_contract(contract)

            symbol_contract_map[contract.symbol] = contract

        if last:
            self.contract_inited = True
            self.gateway.write_log("合约信息查询成功")

            for data in self.order_data:
                self.onRtnOrder(data)
            self.order_data.clear()

            for data in self.trade_data:
                self.onRtnTrade(data)
            self.trade_data.clear()

    def onRtnOrder(self, data: dict) -> None:
        """委托更新推送"""
        if not self.contract_inited:
            self.order_data.append(data)
            return

        symbol: str = data["InstrumentID"]
        contract: ContractData = symbol_contract_map[symbol]

        frontid: int = data["FrontID"]
        sessionid: int = data["SessionID"]
        order_ref: str = data["OrderRef"]
        orderid: str = f"{frontid}_{sessionid}_{order_ref}"

        timestamp: str = f"{data['InsertDate']} {data['InsertTime']}"
        dt: datetime = datetime.strptime(timestamp, "%Y%m%d %H:%M:%S")
        dt: datetime = CHINA_TZ.localize(dt)

        tp = (data["OrderPriceType"], data["TimeCondition"], data["VolumeCondition"])

        order: OrderData = OrderData(
            symbol=symbol,
            exchange=contract.exchange,
            orderid=orderid,
            type=ORDERTYPE_CTP2VT[tp],
            direction=DIRECTION_OST2VT[data["Direction"]],
            price=data["LimitPrice"],
            volume=data["VolumeTotalOriginal"],
            traded=data["VolumeTraded"],
            status=STATUS_OST2VT[data["OrderStatus"]],
            datetime=dt,
            gateway_name=self.gateway_name
        )
        self.gateway.on_order(order)

        self.sysid_orderid_map[data["OrderSysID"]] = orderid

    def onRtnTrade(self, data: dict) -> None:
        """成交数据推送"""
        if not self.contract_inited:
            self.trade_data.append(data)
            return

        symbol: str = data["InstrumentID"]
        contract: ContractData = symbol_contract_map[symbol]

        orderid: str = self.sysid_orderid_map[data["OrderSysID"]]

        timestamp: str = f"{data['TradeDate']} {data['TradeTime']}"
        dt: datetime = datetime.strptime(timestamp, "%Y%m%d %H:%M:%S")
        dt: datetime = CHINA_TZ.localize(dt)

        trade: TradeData = TradeData(
            symbol=symbol,
            exchange=contract.exchange,
            orderid=orderid,
            tradeid=data["TradeID"],
            direction=DIRECTION_OST2VT[data["Direction"]],
            price=data["Price"],
            volume=data["Volume"],
            datetime=dt,
            gateway_name=self.gateway_name
        )
        self.gateway.on_trade(trade)

    def onRspForQuoteInsert(self, data: dict, error: dict, reqid: int, last: bool) -> None:
        """询价请求回报"""
        if not error["ErrorID"]:
            symbol: str = data["InstrumentID"]
            msg: str = f"{symbol}询价请求发送成功"
            self.gateway.write_log(msg)
        else:
            self.gateway.write_error("询价请求发送失败", error)

    def connect(
        self,
        address: str,
        userid: str,
        password: str,
        brokerid: int,
        auth_code: str,
        appid: str
    ) -> None:
        """连接服务器"""
        self.userid = userid
        self.password = password
        self.brokerid = brokerid
        self.auth_code = auth_code
        self.appid = appid

        if not self.connect_status:
            path: Path = get_folder_path(self.gateway_name.lower())
            self.createFtdcTraderApi((str(path) + "\\Td").encode("GBK"))

            self.subscribePrivateTopic(0)
            self.subscribePublicTopic(0)

            self.registerFront(address)
            self.init()

            self.connect_status = True
        else:
            self.authenticate()

    def authenticate(self) -> None:
        """发起授权验证"""
        ost_req: dict = {
            "UserID": self.userid,
            "BrokerID": self.brokerid,
            "AuthCode": self.auth_code,
            "AppID": self.appid
        }

        self.reqid += 1
        self.reqAuthenticate(ost_req, self.reqid)

    def login(self) -> None:
        """用户登录"""
        if self.login_failed:
            return

        ost_req: dict = {
            "UserID": self.userid,
            "Password": self.password,
            "BrokerID": self.brokerid,
            "AppID": self.appid
        }

        self.reqid += 1
        self.reqUserLogin(ost_req, self.reqid)

    def send_order(self, req: OrderRequest) -> str:
        """委托下单"""
        if req.type not in ORDERTYPE_VT2CTP:
            self.gateway.write_log(f"当前接口不支持该类型的委托{req.type.value}")
            return ""

        self.order_ref += 1

        tp = ORDERTYPE_VT2CTP[req.type]
        price_type, time_condition, volume_condition = tp

        ost_req: dict = {
            "InstrumentID": req.symbol,
            "ExchangeID": req.exchange.value,
            "LimitPrice": req.price,
            "VolumeTotalOriginal": int(req.volume),
            "OrderPriceType": price_type,
            "Direction": DIRECTION_VT2CTP.get(req.direction, ""),
            "OrderRef": str(self.order_ref),
            "InvestorID": self.userid,
            "UserID": self.userid,
            "BrokerID": self.brokerid,
            "CombHedgeFlag": THOST_FTDC_HF_Speculation,
            "ContingentCondition": THOST_FTDC_CC_Immediately,
            "ForceCloseReason": THOST_FTDC_FCC_NotForceClose,
            "IsAutoSuspend": 0,
            "TimeCondition": time_condition,
            "VolumeCondition": volume_condition,
            "MinVolume": 1
        }

        self.reqid += 1
        self.reqOrderInsert(ost_req, self.reqid)

        orderid: str = f"{self.frontid}_{self.sessionid}_{self.order_ref}"
        order: OrderData = req.create_order_data(orderid, self.gateway_name)
        self.gateway.on_order(order)

        return order.vt_orderid

    def cancel_order(self, req: CancelRequest) -> None:
        """委托撤单"""
        frontid, sessionid, order_ref = req.orderid.split("_")

        ost_req: dict = {
            "InstrumentID": req.symbol,
            "ExchangeID": req.exchange.value,
            "OrderRef": order_ref,
            "FrontID": int(frontid),
            "SessionID": int(sessionid),
            "ActionFlag": THOST_FTDC_AF_Delete,
            "BrokerID": self.brokerid,
            "InvestorID": self.userid
        }

        self.reqid += 1
        self.reqOrderAction(ost_req, self.reqid)

    def query_account(self) -> None:
        """查询资金"""
        self.reqid += 1
        self.reqQryTradingAccount({}, self.reqid)

    def query_position(self) -> None:
        """查询持仓"""
        if not symbol_contract_map:
            return

        ost_req: dict = {
            "BrokerID": self.brokerid,
            "InvestorID": self.userid
        }

        self.reqid += 1
        self.reqQryInvestorPosition(ost_req, self.reqid)

    def close(self) -> None:
        """关闭连接"""
        if self.connect_status:
            self.exit()


def generate_datetime(timestamp: float) -> datetime:
    """生成时间"""
    dt: datetime = datetime.fromtimestamp(timestamp / 1000)
    dt: datetime = CHINA_TZ.localize(dt)
    return dt