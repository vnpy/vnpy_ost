#ifndef __H_SECURITY_Dnt_L2_MD_USER_API_H__
#define __H_SECURITY_Dnt_L2_MD_USER_API_H__

#include "SecurityDntL2MDUserApiDataStruct.h"

#if defined(_WIN32)
#ifdef DNT_EXPORTS
#define DNT_API __declspec(dllexport)
#else
#define DNT_API __declspec(dllimport)
#endif
#else
#define DNT_API
#endif

_DNT_NS_BEGIN_

class CSecurityDntL2MDUserSpi {
public:
	/// 订阅L2行情应答
	virtual void OnRspSubL2MarketData(const CSecurityDntRspInfoField& reply) {};

	/// 取消订阅Level2行情应答
	virtual void OnRspUnSubL2MarketData(const CSecurityDntRspInfoField& reply) {};

	/// 逐笔订阅应答
	virtual void OnRspSubL2OrderAndTrade(const CSecurityDntRspInfoField& reply) {};

	/// 取消逐笔订阅应答
	virtual void OnRspUnSubL2OrderAndTrade(const CSecurityDntRspInfoField& reply) {};

	/// 指数订阅应答
	virtual void OnRspSubL2IndexMarketData(const CSecurityDntRspInfoField& reply) {};

	/// 取消指数订阅应答
	virtual void OnRspUnSubL2IndexMarketData(const CSecurityDntRspInfoField& reply) {};

	/// Level2行情通知
	virtual void OnRtnL2MarketData(const CSecurityDntMarketDataField& reply) {};

	/// Level2指数通知
	virtual void OnRtnL2IndexMarketData(const CSecurityDntL2IndexField& reply) {};

	/// Level2逐笔委托行情通知
	virtual void OnRtnL2Order(const CSecurityDntL2OrderField& pL2Order) {};

	/// Level2逐笔成交行情通知
	virtual void OnRtnL2Trade(const CSecurityDntL2TradeField& pL2Trade) {};
};

class DNT_API CSecurityDntL2MDUserApi {
public:
	/// 创建API
	static CSecurityDntL2MDUserApi* CreateCSecurityDntL2MDUserApi();

	/// 注册回调
	virtual void RegisterSpi(const CSecurityDntL2MDUserSpi* pSpi) = 0;

	//// 销毁
	virtual void Release() = 0;

	/// 连接
	/// @param:len 为CMulitcastInfo*长度
	virtual void RegisterFront(const CMulitcastInfo* addr, uint32_t len) = 0;

	// L2行情订阅请求
	// @param:req为NULL 订阅全市场
	virtual int SubscribeL2MarketData(const CSecurityDntSubscribeReq* req) = 0;

	// 取消L2行情订阅请求
	// @param:req为NULL 退订全市场
	virtual int UnSubscribeL2MarketData(const CSecurityDntSubscribeReq* req) = 0;

	// 订阅逐笔委托及成交
	virtual int SubscribeL2OrderAndTrade() = 0;

	// 取消订阅逐笔委托及成交
	virtual int UnSubscribeL2OrderAndTrade() = 0;

	// 订阅指数
	virtual int SubscribeL2IndexMarketData() = 0;

	// 取消订阅指数
	virtual int UnSubscribeL2IndexMarketData() = 0;
protected:
	virtual ~CSecurityDntL2MDUserApi() {};
};

_DNT_NS_END_
#endif // __H_SECURITY_Dnt_L2_MD_USER_API_H__
