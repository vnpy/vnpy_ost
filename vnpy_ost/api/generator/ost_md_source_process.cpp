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
	data["MDStreamId"] = task_data->MDStreamId;
	data["MDStreamType"] = task_data->MDStreamType;
	data["SecurityId"] = toUtf(task_data->SecurityId);
	data["PreClosePx"] = task_data->PreClosePx;
	data["OpenPx"] = task_data->OpenPx;
	data["ClosePx"] = task_data->ClosePx;
	data["LastPx"] = task_data->LastPx;
	data["HighPx"] = task_data->HighPx;
	data["LowPx"] = task_data->LowPx;
	data["UpperLimit"] = task_data->UpperLimit;
	data["LowerLimit"] = task_data->LowerLimit;
	data["TradingPhase"] = task_data->TradingPhase;
	data["TradeNums"] = task_data->TradeNums;
	data["TradeVolumn"] = task_data->TradeVolumn;
	data["TradeValue"] = task_data->TradeValue;
	data["BuyLength"] = task_data->BuyLength;
	data["BuyEntry"] = task_data->BuyEntry;
	data["SellLength"] = task_data->SellLength;
	data["SellEntry"] = task_data->SellEntry;
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

