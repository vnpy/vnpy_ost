// vnostmd.cpp : 定义 DLL 应用程序的导出函数。
//

#include "vnostmd.h"


///-------------------------------------------------------------------------------------
///C++的回调函数将数据保存到队列中
///-------------------------------------------------------------------------------------

void MdApi::OnFrontConnected(const CSecurityDntRspInfoField& reply)
{
	Task task = Task();
	task.task_name = ONFRONTCONNECTED;
	CSecurityDntRspInfoField *task_data = new CSecurityDntRspInfoField();
	*task_data = reply;
	task.task_data = task_data;
	this->task_queue.push(task);
};

void MdApi::OnRspSubFutureMarketData(const CSecurityDntRspInfoField& reply)
{
	Task task = Task();
	task.task_name = ONRSPSUBFUTUREMARKETDATA;
	CSecurityDntRspInfoField *task_data = new CSecurityDntRspInfoField();
	*task_data = reply;
	task.task_data = task_data;
	this->task_queue.push(task);
};

void MdApi::OnRspUnSubFutureMarketData(const CSecurityDntRspInfoField& reply)
{
	Task task = Task();
	task.task_name = ONRSPUNSUBFUTUREMARKETDATA;
	CSecurityDntRspInfoField *task_data = new CSecurityDntRspInfoField();
	*task_data = reply;
	task.task_data = task_data;
	this->task_queue.push(task);
};

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

void MdApi::OnRspSubL1MarketData(const CSecurityDntRspInfoField& reply)
{
	Task task = Task();
	task.task_name = ONRSPSUBL1MARKETDATA;
	CSecurityDntRspInfoField *task_data = new CSecurityDntRspInfoField();
	*task_data = reply;
	task.task_data = task_data;
	this->task_queue.push(task);
};

void MdApi::OnRspUnSubL1MarketData(const CSecurityDntRspInfoField& reply)
{
	Task task = Task();
	task.task_name = ONRSPUNSUBL1MARKETDATA;
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

void MdApi::OnRtnL1MarketData(const CSecurityDntMarketDataField& reply)
{
	Task task = Task();
	task.task_name = ONRTNL1MARKETDATA;
	CSecurityDntMarketDataField *task_data = new CSecurityDntMarketDataField();
	*task_data = reply;
	task.task_data = task_data;
	this->task_queue.push(task);
};

void MdApi::OnRtnFutureMarketData(const CSecurityDntMarketDataField& reply)
{
	Task task = Task();
	task.task_name = ONRTNFUTUREMARKETDATA;
	CSecurityDntMarketDataField *task_data = new CSecurityDntMarketDataField();
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
			case ONFRONTCONNECTED:
			{
				this->processFrontConnected(&task);
				break;
			}

			case ONRSPSUBFUTUREMARKETDATA:
			{
				this->processRspSubFutureMarketData(&task);
				break;
			}

			case ONRSPUNSUBFUTUREMARKETDATA:
			{
				this->processRspUnSubFutureMarketData(&task);
				break;
			}

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

			case ONRSPSUBL1MARKETDATA:
			{
				this->processRspSubL1MarketData(&task);
				break;
			}

			case ONRSPUNSUBL1MARKETDATA:
			{
				this->processRspUnSubL1MarketData(&task);
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

			case ONRTNL1MARKETDATA:
			{
				this->processRtnL1MarketData(&task);
				break;
			}

			case ONRTNFUTUREMARKETDATA:
			{
				this->processRtnFutureMarketData(&task);
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

void MdApi::processFrontConnected(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	CSecurityDntRspInfoField *task_data = (CSecurityDntRspInfoField*)task->task_data;
	data["ErrorID"] = task_data->ErrorID;
	data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
	delete task_data;
	this->onFrontConnected(data);
};

void MdApi::processRspSubFutureMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	CSecurityDntRspInfoField *task_data = (CSecurityDntRspInfoField*)task->task_data;
	data["ErrorID"] = task_data->ErrorID;
	data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
	delete task_data;
	this->onRspSubFutureMarketData(data);
};

void MdApi::processRspUnSubFutureMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	CSecurityDntRspInfoField *task_data = (CSecurityDntRspInfoField*)task->task_data;
	data["ErrorID"] = task_data->ErrorID;
	data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
	delete task_data;
	this->onRspUnSubFutureMarketData(data);
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

void MdApi::processRspSubL1MarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	CSecurityDntRspInfoField *task_data = (CSecurityDntRspInfoField*)task->task_data;
	data["ErrorID"] = task_data->ErrorID;
	data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
	delete task_data;
	this->onRspSubL1MarketData(data);
};

void MdApi::processRspUnSubL1MarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	CSecurityDntRspInfoField *task_data = (CSecurityDntRspInfoField*)task->task_data;
	data["ErrorID"] = task_data->ErrorID;
	data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
	delete task_data;
	this->onRspUnSubL1MarketData(data);
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

void MdApi::processRtnL1MarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	CSecurityDntMarketDataField *task_data = (CSecurityDntMarketDataField*)task->task_data;
	data["origTime"] = task_data->origTime;
	data["channelNo"] = task_data->channelNo;
	data["marketId"] = task_data->marketId;
	data["MDStreamId"] = task_data->MDStreamId;
	data["MDStreamType"] = task_data->MDStreamType;
	data["securityId"] = toUtf(task_data->securityId);
	data["preClosePx"] = task_data->preClosePx;
	data["openPx"] = task_data->openPx;
	data["closePx"] = task_data->closePx;
	data["lastPx"] = task_data->lastPx;
	data["highPx"] = task_data->highPx;
	data["lowPx"] = task_data->lowPx;
	data["upperLimit"] = task_data->upperLimit;
	data["lowerLimit"] = task_data->lowerLimit;
	data["tradingPhase"] = task_data->tradingPhase;
	data["tradeNums"] = task_data->tradeNums;
	data["tradeVolumn"] = task_data->tradeVolumn;
	data["tradeValue"] = task_data->tradeValue;
	data["buyLength"] = task_data->buyLength;
	data["sellLength"] = task_data->sellLength;

	pybind11::list ask;
	pybind11::list ask_qty;
	pybind11::list bid;
	pybind11::list bid_qty;

	for (int i = 0; i < 10; i++)
	{
		ask.append(task_data->sellEntry[i].price);
		ask_qty.append(task_data->sellEntry[i].OrderQty);
		bid.append(task_data->buyEntry[i].price);
		bid_qty.append(task_data->buyEntry[i].OrderQty);
	}

	data["ask"] = ask;
	data["bid"] = bid;
	data["bid_qty"] = bid_qty;
	data["ask_qty"] = ask_qty;

	delete task_data;
	this->onRtnL1MarketData(data);
};

void MdApi::processRtnFutureMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	CSecurityDntMarketDataField *task_data = (CSecurityDntMarketDataField*)task->task_data;
	data["origTime"] = task_data->origTime;
	data["channelNo"] = task_data->channelNo;
	data["marketId"] = task_data->marketId;
	data["MDStreamId"] = task_data->MDStreamId;
	data["MDStreamType"] = task_data->MDStreamType;
	data["securityId"] = toUtf(task_data->securityId);
	data["preClosePx"] = task_data->preClosePx;
	data["openPx"] = task_data->openPx;
	data["closePx"] = task_data->closePx;
	data["lastPx"] = task_data->lastPx;
	data["highPx"] = task_data->highPx;
	data["lowPx"] = task_data->lowPx;
	data["upperLimit"] = task_data->upperLimit;
	data["lowerLimit"] = task_data->lowerLimit;
	data["tradingPhase"] = task_data->tradingPhase;
	data["tradeNums"] = task_data->tradeNums;
	data["tradeVolumn"] = task_data->tradeVolumn;
	data["tradeValue"] = task_data->tradeValue;
	data["buyLength"] = task_data->buyLength;
	data["sellLength"] = task_data->sellLength;

	pybind11::list ask;
	pybind11::list ask_qty;
	pybind11::list bid;
	pybind11::list bid_qty;

	for (int i = 0; i < 10; i++)
	{
		ask.append(task_data->sellEntry[i].price);
		ask_qty.append(task_data->sellEntry[i].OrderQty);
		bid.append(task_data->buyEntry[i].price);
		bid_qty.append(task_data->buyEntry[i].OrderQty);
	}

	data["ask"] = ask;
	data["bid"] = bid;
	data["bid_qty"] = bid_qty;
	data["ask_qty"] = ask_qty;

	delete task_data;
	this->onRtnFutureMarketData(data);
};

void MdApi::processRtnL2MarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	CSecurityDntMarketDataField *task_data = (CSecurityDntMarketDataField*)task->task_data;
	data["origTime"] = task_data->origTime;
	data["channelNo"] = task_data->channelNo;
	data["marketId"] = task_data->marketId;
	//data["MDStreamId"] = task_data->MDStreamId;
	//data["MDStreamType"] = task_data->MDStreamType;
	data["securityId"] = toUtf(task_data->securityId);
	data["preClosePx"] = task_data->preClosePx/10000.0;
	data["openPx"] = task_data->openPx/10000.0;
	data["closePx"] = task_data->closePx/10000.0;
	data["lastPx"] = task_data->lastPx/10000.0;
	data["highPx"] = task_data->highPx/10000.0;
	data["lowPx"] = task_data->lowPx/10000.0;
	data["upperLimit"] = task_data->upperLimit/10000.0;
	data["lowerLimit"] = task_data->lowerLimit/10000.0;
	//data["tradingPhase"] = task_data->tradingPhase;
	data["tradeNums"] = task_data->tradeNums/100.0;
	data["tradeVolumn"] = task_data->tradeVolumn/100.0;
	data["tradeValue"] = task_data->tradeValue/100.0;
	data["buyLength"] = task_data->buyLength;
	data["sellLength"] = task_data->sellLength;

	pybind11::list ask;
	pybind11::list ask_qty;
	pybind11::list bid;
	pybind11::list bid_qty;

	for (int i = 0; i < 10; i++)
	{
		ask.append(task_data->sellEntry[i].price/10000.0);
		ask_qty.append(task_data->sellEntry[i].OrderQty/100.0);
		bid.append(task_data->buyEntry[i].price/10000.0);
		bid_qty.append(task_data->buyEntry[i].OrderQty/100.0);
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
	data["timeStamp"] = task_data->timeStamp;
	data["marketId"] = task_data->marketId;
	data["SecurityID"] = toUtf(task_data->SecurityID);
	data["preCloseIndex"] = task_data->preCloseIndex;
	data["openIndex"] = task_data->openIndex;
	data["closeIndex"] = task_data->closeIndex;
	data["highIndex"] = task_data->highIndex;
	data["lowIndex"] = task_data->lowIndex;
	data["lastIndex"] = task_data->lastIndex;
	data["turnOver"] = task_data->turnOver;
	data["totalVolume"] = task_data->totalVolume;
	delete task_data;
	this->onRtnL2IndexMarketData(data);
};

void MdApi::processRtnL2Order(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	CSecurityDntL2OrderField *task_data = (CSecurityDntL2OrderField*)task->task_data;
	data["ChannelNo"] = task_data->ChannelNo;
	data["marketId"] = task_data->marketId;
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
	data["marketId"] = task_data->marketId;
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
	this->api = CSecurityDntL2MDUserApi::createCSecurityDntL2MDUserApi();
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
	this->task_thread.join();

	this->api->RegisterSpi(NULL);
	this->api->Release();
	this->api = NULL;
	return 1;
};

string MdApi::getTradingDay()
{
	string day = this->api->GetTradingDay();
	return day;
};

void MdApi::registerFront(string kConnectorAddress, string kDomainServer, string kContextName)
{
	this->api->RegisterFront((char*)kConnectorAddress.c_str(), (char*)kDomainServer.c_str(), (char*)kContextName.c_str());
};

int MdApi::subscribeFutureMarketData(const dict& req, const bool bAll = false)
{
	CSecurityDntSubscribeReq myreq = CSecurityDntSubscribeReq();
	memset(&myreq, 0, sizeof(myreq));
	getUint16(req, "securitySource", &myreq.securitySource);
	getString(req, "securityId", myreq.securityId);
	int eSubscribeType;
	getInt(req, "subscribeType", &eSubscribeType);
	myreq.subscribeType = (ESubscribeType)eSubscribeType;
	int i = this->api->SubscribeFutureMarketData(myreq, bAll);
	return i;
};

int MdApi::unSubscribeFutureMarketData(const dict& req, const bool bAll = false)
{
	CSecurityDntSubscribeReq myreq = CSecurityDntSubscribeReq();
	memset(&myreq, 0, sizeof(myreq));
	getUint16(req, "securitySource", &myreq.securitySource);
	getString(req, "securityId", myreq.securityId);
	int eSubscribeType;
	getInt(req, "subscribeType", &eSubscribeType);
	myreq.subscribeType = (ESubscribeType)eSubscribeType;
	int i = this->api->UnSubscribeFutureMarketData(myreq, bAll);
	return i;
};

int MdApi::subscribeL1MarketData(const dict& req, const bool bAll = false)
{
	CSecurityDntSubscribeReq myreq = CSecurityDntSubscribeReq();
	memset(&myreq, 0, sizeof(myreq));
	getUint16(req, "securitySource", &myreq.securitySource);
	getString(req, "securityId", myreq.securityId);
	int eSubscribeType;
	getInt(req, "subscribeType", &eSubscribeType);
	myreq.subscribeType = (ESubscribeType)eSubscribeType;
	int i = this->api->SubscribeL1MarketData(myreq, bAll);
	return i;
};

int MdApi::unSubscribeL1MarketData(const dict& req, const bool bAll = false)
{
	CSecurityDntSubscribeReq myreq = CSecurityDntSubscribeReq();
	memset(&myreq, 0, sizeof(myreq));
	getUint16(req, "securitySource", &myreq.securitySource);
	getString(req, "securityId", myreq.securityId);
	int eSubscribeType;
	getInt(req, "subscribeType", &eSubscribeType);
	myreq.subscribeType = (ESubscribeType)eSubscribeType;
	int i = this->api->UnSubscribeL1MarketData(myreq, bAll);
	return i;
};

int MdApi::subscribeL2MarketData(const dict& req, const bool bAll = false)
{
	CSecurityDntSubscribeReq myreq = CSecurityDntSubscribeReq();
	memset(&myreq, 0, sizeof(myreq));
	getUint16(req, "securitySource", &myreq.securitySource);
	getString(req, "securityId", myreq.securityId);
	int eSubscribeType;
	getInt(req, "subscribeType", &eSubscribeType);
	myreq.subscribeType = (ESubscribeType)eSubscribeType;
	int i = this->api->SubscribeL2MarketData(myreq, bAll);
	return i;
};

int MdApi::unSubscribeL2MarketData(const dict& req, const bool bAll = false)
{
	CSecurityDntSubscribeReq myreq = CSecurityDntSubscribeReq();
	memset(&myreq, 0, sizeof(myreq));
	getUint16(req, "securitySource", &myreq.securitySource);
	getString(req, "securityId", myreq.securityId);
	int eSubscribeType;
	getInt(req, "subscribeType", &eSubscribeType);
	myreq.subscribeType = (ESubscribeType)eSubscribeType;
	int i = this->api->UnSubscribeL2MarketData(myreq, bAll);
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
	void onFrontConnected(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onFrontConnected, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSubFutureMarketData(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspSubFutureMarketData, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspUnSubFutureMarketData(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspUnSubFutureMarketData, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

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

	void onRspSubL1MarketData(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspSubL1MarketData, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspUnSubL1MarketData(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspUnSubL1MarketData, data);
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

	void onRtnL1MarketData(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRtnL1MarketData, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnFutureMarketData(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRtnFutureMarketData, data);
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
		.def("getTradingDay", &MdApi::getTradingDay)
		.def("subscribeFutureMarketData", &MdApi::subscribeFutureMarketData)
		.def("unSubscribeFutureMarketData", &MdApi::unSubscribeFutureMarketData)
		.def("subscribeL1MarketData", &MdApi::subscribeL1MarketData)
		.def("unSubscribeL1MarketData", &MdApi::unSubscribeL1MarketData)
		.def("subscribeL2MarketData", &MdApi::subscribeL2MarketData)
		.def("unSubscribeL2MarketData", &MdApi::unSubscribeL2MarketData)
		.def("subscribeL2OrderAndTrade", &MdApi::subscribeL2OrderAndTrade)
		.def("unSubscribeL2OrderAndTrade", &MdApi::unSubscribeL2OrderAndTrade)
		.def("subscribeL2IndexMarketData", &MdApi::subscribeL2IndexMarketData)
		.def("unSubscribeL2IndexMarketData", &MdApi::unSubscribeL2IndexMarketData)

		.def("onFrontConnected", &MdApi::onFrontConnected)
		.def("onRspSubFutureMarketData", &MdApi::onRspSubFutureMarketData)
		.def("onRspUnSubFutureMarketData", &MdApi::onRspUnSubFutureMarketData)
		.def("onRspSubL2MarketData", &MdApi::onRspSubL2MarketData)
		.def("onRspUnSubL2MarketData", &MdApi::onRspUnSubL2MarketData)
		.def("onRspSubL1MarketData", &MdApi::onRspSubL1MarketData)
		.def("onRspUnSubL1MarketData", &MdApi::onRspUnSubL1MarketData)
		.def("onRspSubL2OrderAndTrade", &MdApi::onRspSubL2OrderAndTrade)
		.def("onRspUnSubL2OrderAndTrade", &MdApi::onRspUnSubL2OrderAndTrade)
		.def("onRspSubL2IndexMarketData", &MdApi::onRspSubL2IndexMarketData)
		.def("onRspUnSubL2IndexMarketData", &MdApi::onRspUnSubL2IndexMarketData)
		.def("onRtnL1MarketData", &MdApi::onRtnL1MarketData)
		.def("onRtnFutureMarketData", &MdApi::onRtnFutureMarketData)
		.def("onRtnL2MarketData", &MdApi::onRtnL2MarketData)
		.def("onRtnL2IndexMarketData", &MdApi::onRtnL2IndexMarketData)
		.def("onRtnL2Order", &MdApi::onRtnL2Order)
		.def("onRtnL2Trade", &MdApi::onRtnL2Trade)
		;
}