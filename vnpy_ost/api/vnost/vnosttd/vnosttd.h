//系统
#ifdef WIN32
#include "stdafx.h"
#endif

#include "vnost.h"
#include "pybind11/pybind11.h"
#include "ost/UTApi.h"


using namespace pybind11;

//常量
#define ONFRONTCONNECTED 0
#define ONFRONTDISCONNECTED 1
#define ONRSPERROR 2
#define ONRTNORDER 3
#define ONRTNTRADE 4
#define ONERRRTNORDERACTION 5
#define ONRSPORDERINSERT 6
#define ONRSPORDERACTION 7
#define ONRSPLOGIN 8
#define ONRSPUSERPASSWORDUPDATE 9
#define ONRSPTRANSFERINSERT 10
#define ONRTNTRANSFER 11
#define ONRSPFUNDPAYBACKINSERT 12
#define ONRTNFUNDPAYBACK 13
#define ONRSPSTOCKPAYBACKINSERT 14
#define ONRTNSTOCKPAYBACK 15
#define ONRTNPRIVATECREDITSTOCK 16
#define ONRTNLOCK 17
#define ONRSPLOCKINSERT 18
#define ONRTNEXECORDER 19
#define ONRSPEXECORDERINSERT 20
#define ONRSPEXECORDERACTION 21
#define ONERRRTNEXECORDERACTION 22
#define ONRSPQRYINSTRUMENT 23
#define ONRSPQRYDEPTHMARKETDATA 24
#define ONRSPQRYINVESTORPOSITION 25
#define ONRSPQRYTRADINGACCOUNT 26
#define ONRSPQRYOPTIONINSTRMARGINBYVOLUME 27
#define ONRSPQRYOPTIONINSTRCOMMRATE 28
#define ONRSPQRYORDER 29
#define ONRSPQRYTRADE 30
#define ONRSPQRYINSTRUMENTCOMMISSIONRATE 31
#define ONRSPQRYINVESTOR 32
#define ONRSPQRYTRANSFER 33
#define ONRSPQRYTRADINGCODE 34
#define ONRSPQRYMAXORDERVOLUME 35
#define ONRSPQRYCREDITINSTRUMENT 36
#define ONRSPQRYCREDITINVESTOR 37
#define ONRSPQRYPRIVATECREDITSTOCK 38
#define ONRSPQRYCREDITCONCENTRATION 39
#define ONRSPQRYCREDITFUNDDETAIL 40
#define ONRSPQRYCREDITSTOCKDETAIL 41
#define ONRSPQRYFUNDPAYBACK 42
#define ONRSPQRYSTOCKPAYBACK 43
#define ONRSPQRYPUBLICCREDITFUND 44
#define ONRSPQRYETFINFO 45
#define ONRSPQRYETFCOMPONENT 46
#define ONRSPQRYCREDITAVAILABLEDETAIL 47
#define ONRSPQRYLOCK 48
#define ONRSPQRYEXECORDER 49
#define ONRSPQRYLOCKPOSITION 50
#define ONRSPQRYOPTPOSILIMIT 51
#define ONRSPQRYOPTAMOUNTLIMIT 52

///-------------------------------------------------------------------------------------
///C++ SPI的回调函数方法实现
///-------------------------------------------------------------------------------------

//API的继承实现
class TdApi : public CUTSpi
{
private:
	CUTApi* api;            //API对象
	thread task_thread;                    //工作线程指针（向python中推送数据）
	TaskQueue task_queue;                //任务队列
	bool active = false;                //工作状态

public:
	TdApi()
	{
	};

	~TdApi()
	{
		if (this->active)
		{
			this->exit();
		}
	};

	//-------------------------------------------------------------------------------------
	//API回调函数
	//-------------------------------------------------------------------------------------

	///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
	virtual void OnFrontConnected();

	///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
	///@param nReason 错误原因
	///        0x1001 网络读失败
	///        0x1002 网络写失败
	///        0x2001 接收心跳超时
	///        0x2002 发送心跳失败
	///        0x2003 收到错误报文
	virtual void OnFrontDisconnected(int nReason);

	//请求后台不支持的功能时调用
	virtual void OnRspError(CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///报单
	virtual void OnRtnOrder(CUTOrderField *pOrder);

	///成交
	virtual void OnRtnTrade(CUTTradeField *pTrade);

	///报单操作回报
	virtual void OnErrRtnOrderAction(CUTOrderActionField *pOrderAction);


	///报单错误回报
	virtual void OnRspOrderInsert(CUTInputOrderField *pInputOrder, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///报单操作回报
	virtual void OnRspOrderAction(CUTInputOrderActionField *pInputOrderAction, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///用户登入应答
	virtual void OnRspLogin(CUTRspLoginField *pRspLogin, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///密码修改应答
	virtual void OnRspUserPasswordUpdate(CUTUserPasswordUpdateField *pUserPasswordUpdate, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///转账错误回报
	virtual void OnRspTransferInsert(CUTInputTransferField *pInputTransfer, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///转账
	virtual void OnRtnTransfer(CUTTransferField *pTransfer);

	///直接还款错误回报
	virtual void OnRspFundPaybackInsert(CUTInputFundPaybackField *pInputFundPayback, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///直接还款
	virtual void OnRtnFundPayback(CUTFundPaybackField *pFundPayback);

	///直接还券错误回报
	virtual void OnRspStockPaybackInsert(CUTInputStockPaybackField *pInputStockPayback, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///直接还券
	virtual void OnRtnStockPayback(CUTStockPaybackField *pStockPayback);

	///同步组件返回的券源保底额度信息
	virtual void OnRtnPrivateCreditStock(CUTPrivateCreditStockField *pPrivateCreditStock);

	///锁定
	virtual void OnRtnLock(CUTLockField *pLock);

	///锁定错误回报
	virtual void OnRspLockInsert(CUTInputLockField *pInputLock, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///行权
	virtual void OnRtnExecOrder(CUTExecOrderField *pExecOrder);

	///行权错误回报
	virtual void OnRspExecOrderInsert(CUTInputExecOrderField *pInputExecOrder, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///行权操作回报
	virtual void OnRspExecOrderAction(CUTInputExecOrderActionField *pInputExecOrderAction, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///行权操作回报
	virtual void OnErrRtnExecOrderAction(CUTExecOrderActionField *pExecOrderAction);


	///请求查询合约响应
	virtual void OnRspQryInstrument(CUTInstrumentField *pInstrument, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///请求查询行情响应
	virtual void OnRspQryDepthMarketData(CUTDepthMarketDataField *pDepthMarketData, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///请求查询持仓响应
	virtual void OnRspQryInvestorPosition(CUTInvestorPositionField *pInvestorPosition, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///请求查询资金响应
	virtual void OnRspQryTradingAccount(CUTTradingAccountField *pTradingAccount, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///请求查询期权合约每手保证金响应
	virtual void OnRspQryOptionInstrMarginByVolume(CUTOptionInstrMarginByVolumeField *pOptionInstrMarginByVolume, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///请求查询期权手续费率响应
	virtual void OnRspQryOptionInstrCommRate(CUTOptionInstrCommRateField *pOptionInstrCommRate, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///请求查询报单响应
	virtual void OnRspQryOrder(CUTOrderField *pOrder, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///请求查询成交响应
	virtual void OnRspQryTrade(CUTTradeField *pTrade, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///请求查询手续费率响应
	virtual void OnRspQryInstrumentCommissionRate(CUTInstrumentCommissionRateField *pInstrumentCommissionRate, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///请求查询投资者响应
	virtual void OnRspQryInvestor(CUTInvestorField *pInvestor, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///请求查询转账响应
	virtual void OnRspQryTransfer(CUTTransferField *pTransfer, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///请求查询交易编码
	virtual void OnRspQryTradingCode(CUTTradingCodeField *pTradingCode, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///查询最大下单量响应
	virtual void OnRspQryMaxOrderVolume(CUTMaxOrderVolumeField *pMaxOrderVolume, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///请求查询信用合约属性响应
	virtual void OnRspQryCreditInstrument(CUTCreditInstrumentField *pCreditInstrument, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///请求查询投资者信用信息响应
	virtual void OnRspQryCreditInvestor(CUTCreditInvestorField *pCreditInvestor, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///请求查询投资者可融券响应
	virtual void OnRspQryPrivateCreditStock(CUTPrivateCreditStockField *pPrivateCreditStock, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///请求查询集中度参数响应
	virtual void OnRspQryCreditConcentration(CUTCreditConcentrationField *pCreditConcentration, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///请求查询投资者融资明细响应
	virtual void OnRspQryCreditFundDetail(CUTCreditFundDetailField *pCreditFundDetail, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///请求查询投资者融券明细响应
	virtual void OnRspQryCreditStockDetail(CUTCreditStockDetailField *pCreditStockDetail, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///请求查询投资者直接还款响应
	virtual void OnRspQryFundPayback(CUTFundPaybackField *pFundPayback, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///请求查询投资者直接还券响应
	virtual void OnRspQryStockPayback(CUTStockPaybackField *pStockPayback, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///请求查询公有融资额度响应
	virtual void OnRspQryPublicCreditFund(CUTPublicCreditFundField *pPublicCreditFund, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///请求查询ETF信息响应
	virtual void OnRspQryETFInfo(CUTETFInfoField *pETFInfo, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///请求查询ETF成分股响应
	virtual void OnRspQryETFComponent(CUTETFComponentField *pETFComponent, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///请求查询保证金可用余额明细响应
	virtual void OnRspQryCreditAvailableDetail(CUTCreditAvailableDetailField *pCreditAvailableDetail, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///请求查询锁定响应
	virtual void OnRspQryLock(CUTLockField *pLock, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///请求查询行权响应
	virtual void OnRspQryExecOrder(CUTExecOrderField *pExecOrder, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///请求查询锁定仓位响应
	virtual void OnRspQryLockPosition(CUTLockPositionField *pLockPosition, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///请求查询期权限仓响应
	virtual void OnRspQryOptPosiLimit(CUTOptPosiLimitField *pOptPosiLimit, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	///请求查询期权限额响应
	virtual void OnRspQryOptAmountLimit(CUTOptAmountLimitField *pOptAmountLimit, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	//-------------------------------------------------------------------------------------
	//task：任务
	//-------------------------------------------------------------------------------------
	void processTask();

	void processFrontConnected(Task *task);

	void processFrontDisconnected(Task *task);

	void processRspError(Task *task);

	void processRtnOrder(Task *task);

	void processRtnTrade(Task *task);

	void processErrRtnOrderAction(Task *task);

	void processRspOrderInsert(Task *task);

	void processRspOrderAction(Task *task);

	void processRspLogin(Task *task);

	void processRspUserPasswordUpdate(Task *task);

	void processRspTransferInsert(Task *task);

	void processRtnTransfer(Task *task);

	void processRspFundPaybackInsert(Task *task);

	void processRtnFundPayback(Task *task);

	void processRspStockPaybackInsert(Task *task);

	void processRtnStockPayback(Task *task);

	void processRtnPrivateCreditStock(Task *task);

	void processRtnLock(Task *task);

	void processRspLockInsert(Task *task);

	void processRtnExecOrder(Task *task);

	void processRspExecOrderInsert(Task *task);

	void processRspExecOrderAction(Task *task);

	void processErrRtnExecOrderAction(Task *task);

	void processRspQryInstrument(Task *task);

	void processRspQryDepthMarketData(Task *task);

	void processRspQryInvestorPosition(Task *task);

	void processRspQryTradingAccount(Task *task);

	void processRspQryOptionInstrMarginByVolume(Task *task);

	void processRspQryOptionInstrCommRate(Task *task);

	void processRspQryOrder(Task *task);

	void processRspQryTrade(Task *task);

	void processRspQryInstrumentCommissionRate(Task *task);

	void processRspQryInvestor(Task *task);

	void processRspQryTransfer(Task *task);

	void processRspQryTradingCode(Task *task);

	void processRspQryMaxOrderVolume(Task *task);

	void processRspQryCreditInstrument(Task *task);

	void processRspQryCreditInvestor(Task *task);

	void processRspQryPrivateCreditStock(Task *task);

	void processRspQryCreditConcentration(Task *task);

	void processRspQryCreditFundDetail(Task *task);

	void processRspQryCreditStockDetail(Task *task);

	void processRspQryFundPayback(Task *task);

	void processRspQryStockPayback(Task *task);

	void processRspQryPublicCreditFund(Task *task);

	void processRspQryETFInfo(Task *task);

	void processRspQryETFComponent(Task *task);

	void processRspQryCreditAvailableDetail(Task *task);

	void processRspQryLock(Task *task);

	void processRspQryExecOrder(Task *task);

	void processRspQryLockPosition(Task *task);

	void processRspQryOptPosiLimit(Task *task);

	void processRspQryOptAmountLimit(Task *task);

	//-------------------------------------------------------------------------------------
	//data：回调函数的数据字典
	//error：回调函数的错误字典
	//id：请求id
	//last：是否为最后返回
	//i：整数
	//-------------------------------------------------------------------------------------

	virtual void onFrontConnected() {};

	virtual void onFrontDisconnected(int reqid) {};

	virtual void onRspError(const dict &error, int reqid, bool last) {};

	virtual void onRtnOrder(const dict &data) {};

	virtual void onRtnTrade(const dict &data) {};

	virtual void onErrRtnOrderAction(const dict &data) {};

	virtual void onRspOrderInsert(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspOrderAction(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspLogin(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspUserPasswordUpdate(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspTransferInsert(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRtnTransfer(const dict &data) {};

	virtual void onRspFundPaybackInsert(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRtnFundPayback(const dict &data) {};

	virtual void onRspStockPaybackInsert(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRtnStockPayback(const dict &data) {};

	virtual void onRtnPrivateCreditStock(const dict &data) {};

	virtual void onRtnLock(const dict &data) {};

	virtual void onRspLockInsert(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRtnExecOrder(const dict &data) {};

	virtual void onRspExecOrderInsert(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspExecOrderAction(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onErrRtnExecOrderAction(const dict &data) {};

	virtual void onRspQryInstrument(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryDepthMarketData(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryInvestorPosition(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryTradingAccount(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryOptionInstrMarginByVolume(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryOptionInstrCommRate(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryOrder(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryTrade(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryInstrumentCommissionRate(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryInvestor(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryTransfer(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryTradingCode(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryMaxOrderVolume(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryCreditInstrument(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryCreditInvestor(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryPrivateCreditStock(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryCreditConcentration(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryCreditFundDetail(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryCreditStockDetail(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryFundPayback(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryStockPayback(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryPublicCreditFund(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryETFInfo(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryETFComponent(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryCreditAvailableDetail(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryLock(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryExecOrder(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryLockPosition(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryOptPosiLimit(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryOptAmountLimit(const dict &data, const dict &error, int reqid, bool last) {};

	//-------------------------------------------------------------------------------------
	//req:主动函数的请求字典
	//-------------------------------------------------------------------------------------

	void CreateApi(string pszFlowPath = "", int nCPUID = 0);

	void release();

	void init();

	int join();

	int exit();

	string getApiVersion();

	void registerFront(string pszFrontAddress);

	void subscribePrivateTopic(int nResumeType);

	void subscribePublicTopic(int nResumeType);

	void subscribePrivateTopic(const dict &req);

	int reqOrderInsert(const dict &req, int reqid);

	int reqOrderAction(const dict &req, int reqid);

	int reqLogin(const dict &req, int reqid);

	int reqLogout(const dict &req, int reqid);

	int reqUserPasswordUpdate(const dict &req, int reqid);

	int reqTransferInsert(const dict &req, int reqid);

	int reqFundPaybackInsert(const dict &req, int reqid);

	int reqStockPaybackInsert(const dict &req, int reqid);

	int reqLockInsert(const dict &req, int reqid);

	int reqExecOrderInsert(const dict &req, int reqid);

	int reqExecOrderAction(const dict &req, int reqid);

	int reqQryInstrument(const dict &req, int reqid);

	int reqQryDepthMarketData(const dict &req, int reqid);

	int reqQryInvestorPosition(const dict &req, int reqid);

	int reqQryTradingAccount(const dict &req, int reqid);

	int reqQryOrder(const dict &req, int reqid);

	int reqQryTrade(const dict &req, int reqid);

	int reqQryOptionInstrMarginByVolume(const dict &req, int reqid);

	int reqQryOptionInstrCommRate(const dict &req, int reqid);

	int reqQryInstrumentCommissionRate(const dict &req, int reqid);

	int reqQryInvestor(const dict &req, int reqid);

	int reqQryTransfer(const dict &req, int reqid);

	int reqQryTradingCode(const dict &req, int reqid);

	int reqQryMaxOrderVolume(const dict &req, int reqid);

	int reqQryCreditInstrument(const dict &req, int reqid);

	int reqQryCreditInvestor(const dict &req, int reqid);

	int reqQryPrivateCreditStock(const dict &req, int reqid);

	int reqQryCreditConcentration(const dict &req, int reqid);

	int reqQryCreditFundDetail(const dict &req, int reqid);

	int reqQryCreditStockDetail(const dict &req, int reqid);

	int reqQryFundPayback(const dict &req, int reqid);

	int reqQryStockPayback(const dict &req, int reqid);

	int reqQryPublicCreditFund(const dict &req, int reqid);

	int reqQryETFInfo(const dict &req, int reqid);

	int reqQryETFComponent(const dict &req, int reqid);

	int reqQryCreditAvailableDetail(const dict &req, int reqid);

	int reqQryLock(const dict &req, int reqid);

	int reqQryExecOrder(const dict &req, int reqid);

	int reqQryLockPosition(const dict &req, int reqid);

	int reqQryOptPosiLimit(const dict &req, int reqid);

	int reqQryOptAmountLimit(const dict &req, int reqid);
};