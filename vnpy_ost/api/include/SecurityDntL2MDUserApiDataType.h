#ifndef __H_SECURITY_MD_USER_API_DATATYPE_H__
#define __H_SECURITY_MD_USER_API_DATATYPE_H__

#include <string>
#include <stdint.h>
#include <cstring>

#include "DNT_ns.h"

//using namespace std;

_DNT_NS_BEGIN_

typedef char        TUserIdType[20];            // 用户ID
typedef char        TReqAddress[100];           // 请求地址
typedef char        TPasswordType[20];          // 密码
typedef uint32_t    THeartBeatType;             // 心跳间隔

typedef int32_t     TRetValueType;              // 返回值
typedef char        TErrMessageType[100];       // 错误信息

typedef uint32_t    TLoginStatusType;           // 登录状态
typedef char        TSysDateType[10];           // 系统日期

// 市场代码 uint16  101：上交所市场 102：深交所市场
typedef uint16_t    TSecuritySourceType;        // 市场代码
typedef char        TSecurityIdType[9];         // 证券代码
typedef char        TSecurityIDSourceType[5];   // 证券代码源

// 档位信息
typedef uint16_t    TLevelType;                 // 档位
typedef int64_t     TPriceType;                 // 价格
typedef int64_t     TOrderQty;                  // 数量
typedef int64_t     TNumOrder;                  // 总委托笔数

// 快照行情信息
typedef uint16_t    TChannelNoType;             // 频道代码
typedef uint16_t    TBuyLengthType;             // 买盘结果集个数
typedef uint16_t    TsellLengthType;            // 卖盘结果集个数

///非交易时段
#define SECURITY_DNT_TP_NonTrade '0'
///集合竞价时段
#define SECURITY_DNT_TP_Bidding '1'
///连续交易时段
#define SECURITY_DNT_TP_Continuous '2'
///停牌时段
#define SECURITY_DNT_TP_Suspension '3'
///波动性熔断时段
#define SECURITY_DNT_TP_Fuse '4'
///可恢复熔断时段
#define SECURITY_DNT_TP_RecovFuse '5'
///不可恢复熔断时段
#define SECURITY_DNT_TP_UnrecovFuse '6'
///集合竞价结束时段
#define SECURITY_DNT_TP_BiddingOver '7'
///临时停牌时段
#define SECURITY_DNT_TP_TempSuspension '8'

typedef char TTradingPhaseType;

// 逐笔交易信息
typedef uint32_t    TMsgType;                   // 消息类型
typedef int64_t     TSeqNumType;                // 消息序号
typedef char        TExecType;                  // 成交类别 4=撤销， F=成交
typedef int64_t     TLocalTimeStampType;        // 时间戳字段类型
typedef int64_t     TMsgIndexType;              // 消息索引
typedef char        TSideType;                  // 买卖方向 1=买，2=卖，G=借入，F=出借
typedef char        TOrderType;                 // 委托订单类别 1=市价， 2=限价， U=本方最优

// 行情类别: 股票，债券，基金
enum EMDStreamId {
	CASH_COMMODITY = 1,    // 现货
	COLLATERALISED_REPO = 2,    // 质押式回购
	BOND_DISTRIBUTION = 3,    // 债券分销
	OPTION = 4     // 期权
};

// 行情类别
enum EMDStreamType {
	INCREMENT = 1,              // 增量
	TOTAL = 2               // 全量
};

// 订阅类型
enum ESubscribeType {
	SUBSCRIBE = 1,            // 订阅
	UNSUBSCRIBE = 2             // 取消订阅
};

// 错误码
enum ESecurityDntMDApiError {
	ACTION_SUCCESS = 0,		// 操作成功
	Security_SPI_IS_EMPTY,						// SPI为空
	REQ_ADDRESS_IS_EMPTY,						// 请求地址为空
	INVALID_REQ_ADDRESS,						// 请求地址不合法
	USER_IS_NOT_LOG_IN,							// 用户未登录
	SECURITY_HAS_SUBSCRIBE,						// 股票已订阅
	SECURITY_HAS_NOT_SUBSCRIBE,					// 股票未订阅
	UNKNOW_ERROR								// 未知错误
};

_DNT_NS_END_

#endif // __H_SECURITY_MD_USER_API_DATATYPE_H__
