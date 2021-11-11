// vnostmd.cpp : 定义 DLL 应用程序的导出函数。
//

#include "vnostmd.h"


///-------------------------------------------------------------------------------------
///C++的回调函数将数据保存到队列中
///-------------------------------------------------------------------------------------

void MdApi::OnRspSubL2MarketData(const CSecurityDntRspInfoField& reply) 
{
	Task task = Task();
	task.task_name = ONRSPSUBL2MARKETDATA;
	CSecurityDntRspInfoField *task_data = new CSecurityDntRspInfoField();
	*task_data = reply;
	task.task_data = task_data;
	this->task_queue.push(task);
};

void MdApi::OnRspUnSubL2MarketData(const CSecurityDntRspInfoField& reply)
{
	Task task = Task();
	task.task_name = ONRSPUNSUBL2MARKETDATA;
	CSecurityDntRspInfoField *task_data = new CSecurityDntRspInfoField();
	*task_data = reply;
	task.task_data = task_data;
	this->task_queue.push(task);
};

void MdApi::OnRspSubL2OrderAndTrade(const CSecurityDntRspInfoField& reply)
{
	Task task = Task();
	task.task_name = ONRSPSUBL2ORDERANDTRADE;
	CSecurityDntRspInfoField *task_data = new CSecurityDntRspInfoField();
	*task_data = reply;
	task.task_data = task_data;
	this->task_queue.push(task);
};

void MdApi::OnRspUnSubL2OrderAndTrade(const CSecurityDntRspInfoField& reply)
{
	Task task = Task();
	task.task_name = ONRSPUNSUBL2ORDERANDTRADE;
	CSecurityDntRspInfoField *task_data = new CSecurityDntRspInfoField();
	*task_data = reply;
	task.task_data = task_data;
	this->task_queue.push(task);
};

void MdApi::OnRspSubL2IndexMarketData(const CSecurityDntRspInfoField& reply)
{
	Task task = Task();
	task.task_name = ONRSPSUBL2INDEXMARKETDATA;
	CSecurityDntRspInfoField *task_data = new CSecurityDntRspInfoField();
	*task_data = reply;
	task.task_data = task_data;
	this->task_queue.push(task);
};

void MdApi::OnRspUnSubL2IndexMarketData(const CSecurityDntRspInfoField& reply)
{
	Task task = Task();
	task.task_name = ONRSPUNSUBL2INDEXMARKETDATA;
	CSecurityDntRspInfoField *task_data = new CSecurityDntRspInfoField();
	*task_data = reply;
	task.task_data = task_data;
	this->task_queue.push(task);
};

void MdApi::OnRtnL2MarketData(const CSecurityDntMarketDataField& reply)
{
	Task task = Task();
	task.task_name = ONRTNL2MARKETDATA;
	CSecurityDntMarketDataField *task_data = new CSecurityDntMarketDataField();
	*task_data = reply;
	task.task_data = task_data;
	this->task_queue.push(task);
};

void MdApi::OnRtnL2IndexMarketData(const CSecurityDntL2IndexField& reply)
{
	Task task = Task();
	task.task_name = ONRTNL2INDEXMARKETDATA;
	CSecurityDntL2IndexField *task_data = new CSecurityDntL2IndexField();
	*task_data = reply;
	task.task_data = task_data;
	this->task_queue.push(task);
};

void MdApi::OnRtnL2Order(const CSecurityDntL2OrderField& pL2Order)
{
	Task task = Task();
	task.task_name = ONRTNL2ORDER;
	CSecurityDntL2OrderField *task_data = new CSecurityDntL2OrderField();
	*task_data = pL2Order;
	task.task_data = task_data;
	this->task_queue.push(task);
};

void MdApi::OnRtnL2Trade(const CSecurityDntL2TradeField& pL2Trade)
{
	Task task = Task();
	task.task_name = ONRTNL2TRADE;
	CSecurityDntL2TradeField *task_data = new CSecurityDntL2TradeField();
	*task_data = pL2Trade;
	task.task_data = task_data;
	this->task_queue.push(task);
};

///-------------------------------------------------------------------------------------
///工作线程从队列中取出数据，转化为python对象后，进行推送
///-------------------------------------------------------------------------------------

void MdApi::processTask()
{
	try
	{
		while (this->active)
		{
			Task task = this->task_queue.pop();

			switch (task.task_name)
			{
			case ONRSPSUBL2MARKETDATA:
			{
				this->processRspSubL2MarketData(&task);
				break;
			}

			case ONRSPUNSUBL2MARKETDATA:
			{
				this->processRspUnSubL2MarketData(&task);
				break;
			}

			case ONRSPSUBL2ORDERANDTRADE:
			{
				this->processRspSubL2OrderAndTrade(&task);
				break;
			}

			case ONRSPUNSUBL2ORDERANDTRADE:
			{
				this->processRspUnSubL2OrderAndTrade(&task);
				break;
			}

			case ONRSPSUBL2INDEXMARKETDATA:
			{
				this->processRspSubL2IndexMarketData(&task);
				break;
			}

			case ONRSPUNSUBL2INDEXMARKETDATA:
			{
				this->processRspUnSubL2IndexMarketData(&task);
				break;
			}

			case ONRTNL2MARKETDATA:
			{
				this->processRtnL2MarketData(&task);
				break;
			}

			case ONRTNL2INDEXMARKETDATA:
			{
				this->processRtnL2IndexMarketData(&task);
				break;
			}

			case ONRTNL2ORDER:
			{
				this->processRtnL2Order(&task);
				break;
			}

			case ONRTNL2TRADE:
			{
				this->processRtnL2Trade(&task);
				break;
			}
			};
		}
	}
	catch (const TerminatedError&)
	{
	}
};

void MdApi::processRspSubL2MarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	CSecurityDntRspInfoField *task_data = (CSecurityDntRspInfoField*)task->task_data;
	data["ErrorID"] = task_data->ErrorID;
	data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
	delete task_data;
	this->onRspSubL2MarketData(data);
};

void MdApi::processRspUnSubL2MarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	CSecurityDntRspInfoField *task_data = (CSecurityDntRspInfoField*)task->task_data;
	data["ErrorID"] = task_data->ErrorID;
	data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
	delete task_data;
	this->onRspUnSubL2MarketData(data);
};

void MdApi::processRspSubL2OrderAndTrade(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	CSecurityDntRspInfoField *task_data = (CSecurityDntRspInfoField*)task->task_data;
	data["ErrorID"] = task_data->ErrorID;
	data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
	delete task_data;
	this->onRspSubL2OrderAndTrade(data);
};

void MdApi::processRspUnSubL2OrderAndTrade(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	CSecurityDntRspInfoField *task_data = (CSecurityDntRspInfoField*)task->task_data;
	data["ErrorID"] = task_data->ErrorID;
	data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
	delete task_data;
	this->onRspUnSubL2OrderAndTrade(data);
};

void MdApi::processRspSubL2IndexMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	CSecurityDntRspInfoField *task_data = (CSecurityDntRspInfoField*)task->task_data;
	data["ErrorID"] = task_data->ErrorID;
	data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
	delete task_data;
	this->onRspSubL2IndexMarketData(data);
};

void MdApi::processRspUnSubL2IndexMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	CSecurityDntRspInfoField *task_data = (CSecurityDntRspInfoField*)task->task_data;
	data["ErrorID"] = task_data->ErrorID;
	data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
	delete task_data;
	this->onRspUnSubL2IndexMarketData(data);
};

void MdApi::processRtnL2MarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	CSecurityDntMarketDataField *task_data = (CSecurityDntMarketDataField*)task->task_data;
	data["OrigTime"] = task_data->OrigTime;
	data["ChannelNo"] = task_data->ChannelNo;
	data["MarketId"] = task_data->MarketId;
	//data["MDStreamId"] = task_data->MDStreamId;
	//data["MDStreamType"] = task_data->MDStreamType;
	data["SecurityId"] = toUtf(task_data->SecurityId);
	data["PreClosePx"] = task_data->PreClosePx/10000.0;
	data["OpenPx"] = task_data->OpenPx/10000.0;
	data["ClosePx"] = task_data->ClosePx/10000.0;
	data["LastPx"] = task_data->LastPx/10000.0;
	data["HighPx"] = task_data->HighPx/10000.0;
	data["LowPx"] = task_data->LowPx/10000.0;
	data["UpperLimit"] = task_data->UpperLimit/10000.0;
	data["LowerLimit"] = task_data->LowerLimit/10000.0;
	//data["TradingPhase"] = task_data->TradingPhase;
	data["TradeNums"] = task_data->TradeNums/100.0;
	data["TradeVolumn"] = task_data->TradeVolumn/100.0;
	data["TradeValue"] = task_data->TradeValue/100.0;
	data["BuyLength"] = task_data->BuyLength;
	data["SellLength"] = task_data->SellLength;

	pybind11::list ask;
	pybind11::list ask_qty;
	pybind11::list bid;
	pybind11::list bid_qty;

	for (int i = 0; i < 10; i++)
	{
		ask.append(task_data->SellEntry[i].Price/10000.0);
		ask_qty.append(task_data->SellEntry[i].OrderQty/100.0);
		bid.append(task_data->BuyEntry[i].Price/10000.0);
		bid_qty.append(task_data->BuyEntry[i].OrderQty/100.0);
	}

	data["ask"] = ask;
	data["bid"] = bid;
	data["bid_qty"] = bid_qty;
	data["ask_qty"] = ask_qty;
	delete task_data;
	this->onRtnL2MarketData(data);
};

void MdApi::processRtnL2IndexMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	CSecurityDntL2IndexField *task_data = (CSecurityDntL2IndexField*)task->task_data;
	data["TimeStamp"] = task_data->TimeStamp;
	data["MarketId"] = task_data->MarketId;
	data["SecurityID"] = toUtf(task_data->SecurityID);
	data["PreCloseIndex"] = task_data->PreCloseIndex;
	data["OpenIndex"] = task_data->OpenIndex;
	data["CloseIndex"] = task_data->CloseIndex;
	data["HighIndex"] = task_data->HighIndex;
	data["LowIndex"] = task_data->LowIndex;
	data["LastIndex"] = task_data->LastIndex;
	data["TurnOver"] = task_data->TurnOver;
	data["TotalVolume"] = task_data->TotalVolume;
	delete task_data;
	this->onRtnL2IndexMarketData(data);
};

void MdApi::processRtnL2Order(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	CSecurityDntL2OrderField *task_data = (CSecurityDntL2OrderField*)task->task_data;
	data["ChannelNo"] = task_data->ChannelNo;
	data["MarketId"] = task_data->MarketId;
	data["ApplSeqNum"] = task_data->ApplSeqNum;
	data["MDStreamID"] = task_data->MDStreamID;
	data["SecurityID"] = toUtf(task_data->SecurityID);
	data["SecurityIDSource"] = toUtf(task_data->SecurityIDSource);
	data["Price"] = task_data->Price;
	data["OrderQty"] = task_data->OrderQty;
	data["Side"] = task_data->Side;
	data["TransactTime"] = task_data->TransactTime;
	data["OrderType"] = task_data->OrderType;
	delete task_data;
	this->onRtnL2Order(data);
};

void MdApi::processRtnL2Trade(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	CSecurityDntL2TradeField *task_data = (CSecurityDntL2TradeField*)task->task_data;
	data["ChannelNo"] = task_data->ChannelNo;
	data["MarketId"] = task_data->MarketId;
	data["ApplSeqNum"] = task_data->ApplSeqNum;
	data["MDStreamID"] = task_data->MDStreamID;
	data["BidApplSeqNum"] = task_data->BidApplSeqNum;
	data["OfferApplSeqNum"] = task_data->OfferApplSeqNum;
	data["SecurityID"] = toUtf(task_data->SecurityID);
	data["SecurityIDSource"] = toUtf(task_data->SecurityIDSource);
	data["LastPrice"] = task_data->LastPrice;
	data["LastQty"] = task_data->LastQty;
	data["ExecType"] = task_data->ExecType;
	data["TransactTime"] = task_data->TransactTime;
	delete task_data;
	this->onRtnL2Trade(data);
};

///-------------------------------------------------------------------------------------
///主动函数
///-------------------------------------------------------------------------------------

void MdApi::createCSecurityDntL2MDUserApi()
{
	this->api = CSecurityDntL2MDUserApi::CreateCSecurityDntL2MDUserApi();
	this->api->RegisterSpi(this);
	this->active = true;
	this->task_thread = thread(&MdApi::processTask, this);
};

void MdApi::release()
{
	this->api->Release();
};

int MdApi::exit()
{
	this->active = false;
	this->task_queue.terminate();

	this->api->RegisterSpi(NULL);
	this->api->Release();
	this->api = NULL;
	return 1;
};

void MdApi::registerFront(const dict& sh_req, const dict& sz_req, uint32_t len)
{
	CMulitcastInfo myreq[2];
	getUint16(sh_req, "MDType", &myreq[0].MDType);
    getString(sh_req, "RemoteAddr", myreq[0].RemoteAddr.Addr);
    getInt32(sh_req, "RemotePort", &myreq[0].RemoteAddr.Port);
    getString(sh_req, "LocalAddr", myreq[0].LocalAddr.Addr);
    getInt32(sh_req, "LocalPort", &myreq[0].LocalAddr.Port);

	getUint16(sz_req, "MDType", &myreq[1].MDType);
    getString(sz_req, "RemoteAddr", myreq[1].RemoteAddr.Addr);
    getInt32(sz_req, "RemotePort", &myreq[1].RemoteAddr.Port);
    getString(sz_req, "LocalAddr", myreq[1].LocalAddr.Addr);
    getInt32(sz_req, "LocalPort", &myreq[1].LocalAddr.Port);
	this->api->RegisterFront(myreq, len);
};

int MdApi::subscribeL2MarketData(const dict& req)
{
	CSecurityDntSubscribeReq myreq = CSecurityDntSubscribeReq();
	memset(&myreq, 0, sizeof(myreq));
	getUint16(req, "SecuritySource", &myreq.SecuritySource);
	getString(req, "SecurityId", myreq.SecurityId);
	int i = this->api->SubscribeL2MarketData(&myreq);
	return i;
};

int MdApi::unSubscribeL2MarketData(const dict& req)
{
	CSecurityDntSubscribeReq myreq = CSecurityDntSubscribeReq();
	memset(&myreq, 0, sizeof(myreq));
	getUint16(req, "SecuritySource", &myreq.SecuritySource);
	getString(req, "SecurityId", myreq.SecurityId);
	int i = this->api->UnSubscribeL2MarketData(&myreq);
	return i;
};

int MdApi::subscribeL2OrderAndTrade()
{
	int i = this->api->SubscribeL2OrderAndTrade();
	return i;
};

int MdApi::unSubscribeL2OrderAndTrade()
{
	int i = this->api->UnSubscribeL2OrderAndTrade();
	return i;
};

int MdApi::subscribeL2IndexMarketData()
{
	int i = this->api->SubscribeL2IndexMarketData();
	return i;
};

int MdApi::unSubscribeL2IndexMarketData()
{
	int i = this->api->UnSubscribeL2IndexMarketData();
	return i;
};


///-------------------------------------------------------------------------------------
///Boost.Python封装
///-------------------------------------------------------------------------------------

class PyMdApi : public MdApi
{
public:
	using MdApi::MdApi;
	void onRspSubL2MarketData(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspSubL2MarketData, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspUnSubL2MarketData(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspUnSubL2MarketData, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSubL2OrderAndTrade(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspSubL2OrderAndTrade, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspUnSubL2OrderAndTrade(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspUnSubL2OrderAndTrade, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSubL2IndexMarketData(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspSubL2IndexMarketData, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspUnSubL2IndexMarketData(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspUnSubL2IndexMarketData, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnL2MarketData(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRtnL2MarketData, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnL2IndexMarketData(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRtnL2IndexMarketData, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnL2Order(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRtnL2Order, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnL2Trade(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRtnL2Trade, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};
};

PYBIND11_MODULE(vnostmd, m)
{
	class_<MdApi, PyMdApi> mdapi(m, "MdApi", module_local());
	mdapi
		.def(init<>())
		.def("createCSecurityDntL2MDUserApi", &MdApi::createCSecurityDntL2MDUserApi)
		.def("release", &MdApi::release)
		.def("exit", &MdApi::exit)
		.def("registerFront", &MdApi::registerFront)
		.def("subscribeL2MarketData", &MdApi::subscribeL2MarketData)
		.def("unSubscribeL2MarketData", &MdApi::unSubscribeL2MarketData)
		.def("subscribeL2OrderAndTrade", &MdApi::subscribeL2OrderAndTrade)
		.def("unSubscribeL2OrderAndTrade", &MdApi::unSubscribeL2OrderAndTrade)
		.def("subscribeL2IndexMarketData", &MdApi::subscribeL2IndexMarketData)
		.def("unSubscribeL2IndexMarketData", &MdApi::unSubscribeL2IndexMarketData)

		.def("onRspSubL2MarketData", &MdApi::onRspSubL2MarketData)
		.def("onRspUnSubL2MarketData", &MdApi::onRspUnSubL2MarketData)
		.def("onRspSubL2OrderAndTrade", &MdApi::onRspSubL2OrderAndTrade)
		.def("onRspUnSubL2OrderAndTrade", &MdApi::onRspUnSubL2OrderAndTrade)
		.def("onRspSubL2IndexMarketData", &MdApi::onRspSubL2IndexMarketData)
		.def("onRspUnSubL2IndexMarketData", &MdApi::onRspUnSubL2IndexMarketData)
		.def("onRtnL2MarketData", &MdApi::onRtnL2MarketData)
		.def("onRtnL2IndexMarketData", &MdApi::onRtnL2IndexMarketData)
		.def("onRtnL2Order", &MdApi::onRtnL2Order)
		.def("onRtnL2Trade", &MdApi::onRtnL2Trade)
		;
}