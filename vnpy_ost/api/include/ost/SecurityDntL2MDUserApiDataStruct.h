#ifndef __H_SECURITY_Dnt_L2_MD_USER_API_STRUCT_H__
#define __H_SECURITY_Dnt_L2_MD_USER_API_STRUCT_H__

#include "SecurityDntL2MDUserApiDataType.h"

_DNT_NS_BEGIN_
/******************初始化参数****************/
struct CUDPAddrInfo {
	TAddress	Addr;			 // 地址
	TPort		Port;			 // 端口
public:
	CUDPAddrInfo() {
		memset(this, 0, sizeof(CUDPAddrInfo));
	}
};

struct CMulitcastInfo {
	TMDType		 MDType;		 // 订阅类型
	CUDPAddrInfo RemoteAddr;	 // 远程地址
	CUDPAddrInfo LocalAddr;		 // 本机地址
public:
	CMulitcastInfo() {
		memset(this, 0, sizeof(CMulitcastInfo));
	}
};

/******************请求参数****************/

// 行情订阅请求参数
struct CSecurityDntSubscribeReq {
	TSecuritySourceType     SecuritySource;    // 市场编号
	TSecurityIdType         SecurityId;        // 产品代码
public:
	CSecurityDntSubscribeReq() {
		memset(this, 0, sizeof(CSecurityDntSubscribeReq));
	}
};

/*****************响应参数*****************/
// 错误应答
struct CSecurityDntRspInfoField {
	TRetValueType	    ErrorID;            // 错误码
	TErrMessageType	    ErrorMsg;           // 错误信息
public:
	CSecurityDntRspInfoField() {
		memset(this, 0, sizeof(CSecurityDntRspInfoField));
	}
};

// 档位信息
struct EntryInfo {
	TLevelType          Level;              // 档位
	TPriceType          Price;              // 价格
	TOrderQty           OrderQty;           // 数量
public:
	EntryInfo() {
		memset(this, 0, sizeof(EntryInfo));
	}
};

typedef EntryInfo EntryInfoList[10];

// 快照行情信息
struct CSecurityDntMarketDataField {
	TLocalTimeStampType         OrigTime;           // 时间戳
	TChannelNoType              ChannelNo;          // 频道代码
	TSecuritySourceType         MarketId;           // 市场代码
	EMDStreamId                 MDStreamId;         // 行情类别
	EMDStreamType               MDStreamType;       // 行情类别
	TSecurityIdType             SecurityId;         // 产品代码
	TPriceType                  PreClosePx;         // 昨收价
	TPriceType                  OpenPx;             // 开盘价
	TPriceType                  ClosePx;            // 收盘价
	TPriceType                  LastPx;             // 最新价
	TPriceType                  HighPx;             // 最高价
	TPriceType                  LowPx;              // 最低价
	TPriceType                  UpperLimit;         // 涨停价
	TPriceType                  LowerLimit;         // 跌停价
	TTradingPhaseType           TradingPhase;       // 交易阶段
	TOrderQty                   TradeNums;          // 成交笔数
	TOrderQty                   TradeVolumn;        // 成交总量
	TPriceType                  TradeValue;         // 成交总金额
	TBuyLengthType              BuyLength;          // 买盘结果集个数
	EntryInfoList               BuyEntry;           // 买一至买十列表
	TsellLengthType             SellLength;         // 卖盘结果集个数
	EntryInfoList               SellEntry;          // 卖一至卖十列表
public:
	CSecurityDntMarketDataField() {
		memset(this, 0, sizeof(CSecurityDntMarketDataField));
	}
};

// 逐笔成交行情
struct CSecurityDntL2TradeField {
	TChannelNoType              ChannelNo;                  // 频道代码
	TSecuritySourceType         MarketId;                   // 市场代码
	TSeqNumType                 ApplSeqNum;          	    // 消息记录号
	EMDStreamId                 MDStreamID;                 // 行情类别
	TSeqNumType                 BidApplSeqNum;              // 买方委托索引 0表示无委托
	TSeqNumType                 OfferApplSeqNum;            // 卖方委托索引 0表示无委托
	TSecurityIdType             SecurityID;                 // 证券代码
	TSecurityIDSourceType       SecurityIDSource;           // 证券代码源
	TPriceType                  LastPrice;                  // 成交价格
	TOrderQty                   LastQty;                    // 成交数量
	TExecType                   ExecType;                   // 成交类别 4=撤销，F=成交
	TLocalTimeStampType         TransactTime;               // 成交时间
public:
	CSecurityDntL2TradeField() {
		memset(this, 0, sizeof(CSecurityDntL2TradeField));
	}
};

// 逐笔委托行情信息
struct CSecurityDntL2OrderField {
	TChannelNoType              ChannelNo;                  // 频道代码
	TSecuritySourceType         MarketId;                   // 市场代码
	TSeqNumType                 ApplSeqNum;                 // 消息记录号
	EMDStreamId                 MDStreamID;                 // 行情类别
	TSecurityIdType             SecurityID;                 // 证券代码
	TSecurityIDSourceType       SecurityIDSource;           // 证券代码源
	TPriceType                  Price;                      // 委托价格
	TOrderQty                   OrderQty;                   // 委托数量
	TSideType                   Side;                       // 买卖方向、成交类别
	TLocalTimeStampType         TransactTime;               // 委托时间
	TOrderType                  OrderType;                  //订单类别
	// UExtendFieldsType           ExtendFields;               // 扩展字段
public:
	CSecurityDntL2OrderField() {
		memset(this, 0, sizeof(CSecurityDntL2OrderField));
	}
};

//指数信息
struct CSecurityDntL2IndexField {
	TLocalTimeStampType			TimeStamp;					// 时间
	TSecuritySourceType			MarketId;					// 市场代码
	TSecurityIdType				SecurityID;					// 指数代码
	TPriceType					PreCloseIndex;				// 昨收价
	TPriceType					OpenIndex;					// 开盘价
	TPriceType					CloseIndex;					// 收盘价
	TPriceType					HighIndex;					// 最高价
	TPriceType					LowIndex;					// 最低价
	TPriceType					LastIndex;					// 最新价
	TPriceType					TurnOver;					// 参与计算相应指数的成交金额
	TOrderQty					TotalVolume;				// 参与计算相应指数的成交数量
public:
	CSecurityDntL2IndexField() {
		memset(this, 0, sizeof(CSecurityDntL2IndexField));
	}
};

_DNT_NS_END_

#endif // __H_SECURITY_Dnt_L2_MD_USER_API_STRUCT_H__
