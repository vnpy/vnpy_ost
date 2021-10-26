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
	data["buyEntry"] = task_data->buyEntry;
	data["sellLength"] = task_data->sellLength;
	data["sellEntry"] = task_data->sellEntry;
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
	data["buyEntry"] = task_data->buyEntry;
	data["sellLength"] = task_data->sellLength;
	data["sellEntry"] = task_data->sellEntry;
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
	data["buyEntry"] = task_data->buyEntry;
	data["sellLength"] = task_data->sellLength;
	data["sellEntry"] = task_data->sellEntry;
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
	int i = this->api->SubscribeFutureMarketData(myreq, bAll);
	return i;
};
