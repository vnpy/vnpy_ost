//系统
#ifdef WIN32
#include "stdafx.h"
#endif

#include "vnost.h"
#include "pybind11/pybind11.h"
#include "ost/SecurityDntL2MDUserApi.h"


using namespace pybind11;

//常量
#define ONRSPSUBL2MARKETDATA 0
#define ONRSPUNSUBL2MARKETDATA 1
#define ONRSPSUBL2ORDERANDTRADE 2
#define ONRSPUNSUBL2ORDERANDTRADE 3
#define ONRSPSUBL2INDEXMARKETDATA 4
#define ONRSPUNSUBL2INDEXMARKETDATA 5
#define ONRTNL2MARKETDATA 6
#define ONRTNL2INDEXMARKETDATA 7
#define ONRTNL2ORDER 8
#define ONRTNL2TRADE 9


///-------------------------------------------------------------------------------------
///C++ SPI的回调函数方法实现
///-------------------------------------------------------------------------------------

//API的继承实现
using namespace _DNT_;
class MdApi : public CSecurityDntL2MDUserSpi
{
private:
	CSecurityDntL2MDUserApi* api;				//API对象
	thread task_thread;					//工作线程指针（向python中推送数据）
	TaskQueue task_queue;			    //任务队列
	bool active = false;				//工作状态

public:
	MdApi()
	{
	};

	~MdApi()
	{
		if (this->active)
		{
			this->exit();
		}
	};

	//-------------------------------------------------------------------------------------
	//API回调函数
	//-------------------------------------------------------------------------------------

	/// 订阅L2行情应答
	virtual void OnRspSubL2MarketData(const CSecurityDntRspInfoField& reply);

	/// 取消订阅Level2行情应答
	virtual void OnRspUnSubL2MarketData(const CSecurityDntRspInfoField& reply);

	/// 逐笔订阅应答
	virtual void OnRspSubL2OrderAndTrade(const CSecurityDntRspInfoField& reply);

	/// 取消逐笔订阅应答
	virtual void OnRspUnSubL2OrderAndTrade(const CSecurityDntRspInfoField& reply);

	/// 指数订阅应答
	virtual void OnRspSubL2IndexMarketData(const CSecurityDntRspInfoField& reply);

	/// 取消指数订阅应答
	virtual void OnRspUnSubL2IndexMarketData(const CSecurityDntRspInfoField& reply);

	/// Level2行情通知
	virtual void OnRtnL2MarketData(const CSecurityDntMarketDataField& reply);

	/// Level2指数通知
	virtual void OnRtnL2IndexMarketData(const CSecurityDntL2IndexField& reply);

	/// Level2逐笔委托行情通知
	virtual void OnRtnL2Order(const CSecurityDntL2OrderField& pL2Order);

	/// Level2逐笔成交行情通知
	virtual void OnRtnL2Trade(const CSecurityDntL2TradeField& pL2Trade);

    //-------------------------------------------------------------------------------------
    //task：任务
    //-------------------------------------------------------------------------------------

	void processTask();

    void processRspSubL2MarketData(Task *task);
    
    void processRspUnSubL2MarketData(Task *task);
    
    void processRspSubL2OrderAndTrade(Task *task);
    
    void processRspUnSubL2OrderAndTrade(Task *task);
    
    void processRspSubL2IndexMarketData(Task *task);
    
    void processRspUnSubL2IndexMarketData(Task *task);
    
    void processRtnL2MarketData(Task *task);
    
    void processRtnL2IndexMarketData(Task *task);
    
    void processRtnL2Order(Task *task);
    
    void processRtnL2Trade(Task *task);

	//-------------------------------------------------------------------------------------
    //data：回调函数的数据字典
    //error：回调函数的错误字典
    //id：请求id
    //last：是否为最后返回
    //i：整数
    //-------------------------------------------------------------------------------------

    virtual void onRspSubL2MarketData(const dict &data) {};
    
    virtual void onRspUnSubL2MarketData(const dict &data) {};
    
    virtual void onRspSubL2OrderAndTrade(const dict &data) {};
    
    virtual void onRspUnSubL2OrderAndTrade(const dict &data) {};
    
    virtual void onRspSubL2IndexMarketData(const dict &data) {};
    
    virtual void onRspUnSubL2IndexMarketData(const dict &data) {};
    
    virtual void onRtnL2MarketData(const dict &data) {};
    
    virtual void onRtnL2IndexMarketData(const dict &data) {};
    
    virtual void onRtnL2Order(const dict &data) {};
    
    virtual void onRtnL2Trade(const dict &data) {};

	//-------------------------------------------------------------------------------------
    //req:主动函数的请求字典
    //-------------------------------------------------------------------------------------

	void createCSecurityDntL2MDUserApi();

	void release();

	int exit();

	void registerFront(const dict &sh_req, const dict &sz_req, uint32_t len);

	int subscribeL2MarketData(const dict &req);

	int unSubscribeL2MarketData(const dict &req);

	int subscribeL2OrderAndTrade();

	int unSubscribeL2OrderAndTrade();

	int subscribeL2IndexMarketData();

	int unSubscribeL2IndexMarketData();

};