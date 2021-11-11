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

