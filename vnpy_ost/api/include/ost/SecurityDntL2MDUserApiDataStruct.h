#ifndef __H_SECURITY_Dnt_L2_MD_USER_API_STRUCT_H__
#define __H_SECURITY_Dnt_L2_MD_USER_API_STRUCT_H__

#include "SecurityDntL2MDUserApiDataType.h"

_DNT_NS_BEGIN_
#pragma pack(push)
#pragma pack(1)

/******************请求参数****************/

// 行情订阅请求参数
struct CSecurityDntSubscribeReq {
	TSecuritySourceType     securitySource;    // 市场编号
	TSecurityIdType         securityId;        // 产品代码
	ESubscribeType          subscribeType;     // 订阅类型
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
	TLevelType          level;              // 档位
	TPriceType          price;              // 价格
	TOrderQty           OrderQty;           // 数量
//	TNumOrder           NumOrder;           // 总委托笔数

public:
	EntryInfo() {
		memset(this, 0, sizeof(EntryInfo));
	}
};

typedef EntryInfo EntryInfoList[10];

// 快照行情信息
struct CSecurityDntMarketDataField {
	TLocalTimeStampType         origTime;           // 时间戳
	TChannelNoType              channelNo;          // 频道代码
	TSecuritySourceType         marketId;           // 市场代码
	EMDStreamId                 MDStreamId;         // 行情类别
	EMDStreamType               MDStreamType;       // 行情类别
	TSecurityIdType             securityId;         // 产品代码
	TPriceType                  preClosePx;         // 昨收价
	TPriceType                  openPx;             // 开盘价
	TPriceType                  closePx;            // 收盘价
	TPriceType                  lastPx;             // 最新价
	TPriceType                  highPx;             // 最高价
	TPriceType                  lowPx;              // 最低价
	TPriceType                  upperLimit;         // 涨停价
	TPriceType                  lowerLimit;         // 跌停价
	TTradingPhaseType           tradingPhase;       // 交易阶段
	TOrderQty                   tradeNums;          // 成交笔数
	TOrderQty                   tradeVolumn;        // 成交总量
	TPriceType                   tradeValue;         // 成交总金额
	TBuyLengthType              buyLength;          // 买盘结果集个数
	EntryInfoList               buyEntry;           // 买一至买十列表
	TsellLengthType             sellLength;         // 卖盘结果集个数
	EntryInfoList               sellEntry;          // 卖一至卖十列表
public:
	CSecurityDntMarketDataField() {
		memset(this, 0, sizeof(CSecurityDntMarketDataField));
	}
};

// 逐笔成交行情
struct CSecurityDntL2TradeField {
	TChannelNoType              ChannelNo;                  // 频道代码
	TSecuritySourceType         marketId;                   // 市场代码
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
	TSecuritySourceType         marketId;                   // 市场代码
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
	TLocalTimeStampType			timeStamp;					// 时间
	TSecuritySourceType			marketId;					// 市场代码
	TSecurityIdType				SecurityID;					// 指数代码
	TPriceType					preCloseIndex;				// 昨收价
	TPriceType					openIndex;					// 开盘价
	TPriceType					closeIndex;					// 收盘价
	TPriceType					highIndex;					// 最高价
	TPriceType					lowIndex;					// 最低价
	TPriceType					lastIndex;					// 最新价
	TPriceType					turnOver;					//参与计算相应指数的成交金额
	TOrderQty					totalVolume;				//参与计算相应指数的成交数量
public:
	CSecurityDntL2IndexField() {
		memset(this, 0, sizeof(CSecurityDntL2IndexField));
	}
};

#pragma pack(pop)
_DNT_NS_END_

#endif // __H_SECURITY_Dnt_L2_MD_USER_API_STRUCT_H__
