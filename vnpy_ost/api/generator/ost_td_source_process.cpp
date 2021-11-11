void TdApi::processFrontConnected(Task *task)
{
	gil_scoped_acquire acquire;
	this->onFrontConnected();
};

void TdApi::processFrontDisconnected(Task *task)
{
	gil_scoped_acquire acquire;
	this->onFrontDisconnected(task->task_id);
};

void TdApi::processRspError(Task *task)
{
	gil_scoped_acquire acquire;
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspError(error, task->task_id, task->task_last);
};

void TdApi::processRtnOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTOrderField *task_data = (CUTOrderField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["OrderRef"] = task_data->OrderRef;
		data["Direction"] = task_data->Direction;
		data["OffsetFlag"] = task_data->OffsetFlag;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["OrderPriceType"] = task_data->OrderPriceType;
		data["VolumeTotalOriginal"] = task_data->VolumeTotalOriginal;
		data["LimitPrice"] = task_data->LimitPrice;
		data["TimeCondition"] = task_data->TimeCondition;
		data["VolumeCondition"] = task_data->VolumeCondition;
		data["ContingentCondition"] = task_data->ContingentCondition;
		data["GTDDate"] = task_data->GTDDate;
		data["MinVolume"] = task_data->MinVolume;
		data["IsAutoSuspend"] = task_data->IsAutoSuspend;
		data["UserForceClose"] = task_data->UserForceClose;
		data["StopPrice"] = task_data->StopPrice;
		data["IsSwapOrder"] = task_data->IsSwapOrder;
		data["TraderID"] = toUtf(task_data->TraderID);
		data["OrderLocalID"] = toUtf(task_data->OrderLocalID);
		data["ParticipantID"] = toUtf(task_data->ParticipantID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["TradingDay"] = task_data->TradingDay;
		data["UserProductInfo"] = toUtf(task_data->UserProductInfo);
		data["BranchID"] = toUtf(task_data->BranchID);
		data["InstallID"] = task_data->InstallID;
		data["IPAddressAsInt"] = task_data->IPAddressAsInt;
		data["MacAddressAsLong"] = task_data->MacAddressAsLong;
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["OrderStatus"] = task_data->OrderStatus;
		data["OrderType"] = task_data->OrderType;
		data["VolumeTraded"] = task_data->VolumeTraded;
		data["VolumeTotal"] = task_data->VolumeTotal;
		data["InsertDate"] = task_data->InsertDate;
		data["InsertTime"] = task_data->InsertTime;
		data["CancelTime"] = task_data->CancelTime;
		data["SequenceNo"] = task_data->SequenceNo;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["ExchangeErrorID"] = task_data->ExchangeErrorID;
		delete task_data;
	}
	this->onRtnOrder(data);
};

void TdApi::processRtnTrade(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTTradeField *task_data = (CUTTradeField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["OrderRef"] = task_data->OrderRef;
		data["TradeID"] = toUtf(task_data->TradeID);
		data["Direction"] = task_data->Direction;
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["OffsetFlag"] = task_data->OffsetFlag;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["Price"] = task_data->Price;
		data["Volume"] = task_data->Volume;
		data["TradeDate"] = task_data->TradeDate;
		data["TradeTime"] = task_data->TradeTime;
		data["TradeType"] = task_data->TradeType;
		data["TraderID"] = toUtf(task_data->TraderID);
		data["OrderLocalID"] = toUtf(task_data->OrderLocalID);
		data["SequenceNo"] = task_data->SequenceNo;
		data["TradingDay"] = task_data->TradingDay;
		data["InstallID"] = task_data->InstallID;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		delete task_data;
	}
	this->onRtnTrade(data);
};

void TdApi::processErrRtnOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTOrderActionField *task_data = (CUTOrderActionField*)task->task_data;
		data["OrderActionRef"] = task_data->OrderActionRef;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["OrderRef"] = task_data->OrderRef;
		data["ActionFlag"] = task_data->ActionFlag;
		data["LimitPrice"] = task_data->LimitPrice;
		data["VolumeChange"] = task_data->VolumeChange;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ActionDate"] = task_data->ActionDate;
		data["ActionTime"] = task_data->ActionTime;
		data["TraderID"] = toUtf(task_data->TraderID);
		data["OrderLocalID"] = toUtf(task_data->OrderLocalID);
		data["ActionLocalID"] = toUtf(task_data->ActionLocalID);
		data["ParticipantID"] = toUtf(task_data->ParticipantID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["OrderActionStatus"] = task_data->OrderActionStatus;
		data["Direction"] = task_data->Direction;
		data["BranchID"] = toUtf(task_data->BranchID);
		data["OrderType"] = task_data->OrderType;
		data["InstallID"] = task_data->InstallID;
		data["ExchangeErrorID"] = task_data->ExchangeErrorID;
		data["ActionFrontID"] = task_data->ActionFrontID;
		data["ActionSessionID"] = task_data->ActionSessionID;
		data["IPAddressAsInt"] = task_data->IPAddressAsInt;
		data["MacAddressAsLong"] = task_data->MacAddressAsLong;
		delete task_data;
	}
	this->onErrRtnOrderAction(data);
};

void TdApi::processRspOrderInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTInputOrderField *task_data = (CUTInputOrderField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["OrderRef"] = task_data->OrderRef;
		data["Direction"] = task_data->Direction;
		data["OffsetFlag"] = task_data->OffsetFlag;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["OrderPriceType"] = task_data->OrderPriceType;
		data["VolumeTotalOriginal"] = task_data->VolumeTotalOriginal;
		data["LimitPrice"] = task_data->LimitPrice;
		data["TimeCondition"] = task_data->TimeCondition;
		data["VolumeCondition"] = task_data->VolumeCondition;
		data["ContingentCondition"] = task_data->ContingentCondition;
		data["GTDDate"] = task_data->GTDDate;
		data["MinVolume"] = task_data->MinVolume;
		data["IsAutoSuspend"] = task_data->IsAutoSuspend;
		data["UserForceClose"] = task_data->UserForceClose;
		data["StopPrice"] = task_data->StopPrice;
		data["IsSwapOrder"] = task_data->IsSwapOrder;
		data["IPAddressAsInt"] = task_data->IPAddressAsInt;
		data["MacAddressAsLong"] = task_data->MacAddressAsLong;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspOrderInsert(data, error, task->task_id, task->task_last);
};

void TdApi::processRspOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTInputOrderActionField *task_data = (CUTInputOrderActionField*)task->task_data;
		data["OrderActionRef"] = task_data->OrderActionRef;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["OrderRef"] = task_data->OrderRef;
		data["ActionFlag"] = task_data->ActionFlag;
		data["LimitPrice"] = task_data->LimitPrice;
		data["VolumeChange"] = task_data->VolumeChange;
		data["IPAddressAsInt"] = task_data->IPAddressAsInt;
		data["MacAddressAsLong"] = task_data->MacAddressAsLong;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspOrderAction(data, error, task->task_id, task->task_last);
};

void TdApi::processRspLogin(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTRspLoginField *task_data = (CUTRspLoginField*)task->task_data;
		data["TradingDay"] = task_data->TradingDay;
		data["LoginTime"] = task_data->LoginTime;
		data["UserID"] = toUtf(task_data->UserID);
		data["SystemName"] = toUtf(task_data->SystemName);
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["PrivateSeq"] = task_data->PrivateSeq;
		data["PublicSeq"] = task_data->PublicSeq;
		data["MultiAddress"] = toUtf(task_data->MultiAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspLogin(data, error, task->task_id, task->task_last);
};

void TdApi::processRspUserPasswordUpdate(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTUserPasswordUpdateField *task_data = (CUTUserPasswordUpdateField*)task->task_data;
		data["UserID"] = toUtf(task_data->UserID);
		data["OldPassword"] = toUtf(task_data->OldPassword);
		data["NewPassword"] = toUtf(task_data->NewPassword);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspUserPasswordUpdate(data, error, task->task_id, task->task_last);
};

void TdApi::processRspTransferInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTInputTransferField *task_data = (CUTInputTransferField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["TransferRef"] = task_data->TransferRef;
		data["TransferType"] = task_data->TransferType;
		data["Deposit"] = task_data->Deposit;
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["AccType"] = task_data->AccType;
		data["BankID"] = toUtf(task_data->BankID);
		data["FundPassword"] = toUtf(task_data->FundPassword);
		data["BankPassword"] = toUtf(task_data->BankPassword);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspTransferInsert(data, error, task->task_id, task->task_last);
};

void TdApi::processRtnTransfer(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTTransferField *task_data = (CUTTransferField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["TransferRef"] = task_data->TransferRef;
		data["TransferType"] = task_data->TransferType;
		data["Deposit"] = task_data->Deposit;
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["AccType"] = task_data->AccType;
		data["BankID"] = toUtf(task_data->BankID);
		data["FundPassword"] = toUtf(task_data->FundPassword);
		data["BankPassword"] = toUtf(task_data->BankPassword);
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["TransferLocalID"] = toUtf(task_data->TransferLocalID);
		data["TransferSysID"] = toUtf(task_data->TransferSysID);
		data["TransferStatus"] = task_data->TransferStatus;
		data["ExchangeErrorID"] = task_data->ExchangeErrorID;
		data["InsertDate"] = task_data->InsertDate;
		data["InsertTime"] = task_data->InsertTime;
		delete task_data;
	}
	this->onRtnTransfer(data);
};

void TdApi::processRspFundPaybackInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTInputFundPaybackField *task_data = (CUTInputFundPaybackField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["FundPaybackRef"] = task_data->FundPaybackRef;
		data["Amount"] = task_data->Amount;
		data["IPAddressAsInt"] = task_data->IPAddressAsInt;
		data["MacAddressAsLong"] = task_data->MacAddressAsLong;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspFundPaybackInsert(data, error, task->task_id, task->task_last);
};

void TdApi::processRtnFundPayback(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTFundPaybackField *task_data = (CUTFundPaybackField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["FundPaybackRef"] = task_data->FundPaybackRef;
		data["Amount"] = task_data->Amount;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["FundPaybackLocalID"] = toUtf(task_data->FundPaybackLocalID);
		data["InsertDate"] = task_data->InsertDate;
		data["InsertTime"] = task_data->InsertTime;
		data["IPAddressAsInt"] = task_data->IPAddressAsInt;
		data["MacAddressAsLong"] = task_data->MacAddressAsLong;
		delete task_data;
	}
	this->onRtnFundPayback(data);
};

void TdApi::processRspStockPaybackInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTInputStockPaybackField *task_data = (CUTInputStockPaybackField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["StockPaybackRef"] = task_data->StockPaybackRef;
		data["Volume"] = task_data->Volume;
		data["IPAddressAsInt"] = task_data->IPAddressAsInt;
		data["MacAddressAsLong"] = task_data->MacAddressAsLong;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspStockPaybackInsert(data, error, task->task_id, task->task_last);
};

void TdApi::processRtnStockPayback(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTStockPaybackField *task_data = (CUTStockPaybackField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["StockPaybackRef"] = task_data->StockPaybackRef;
		data["Volume"] = task_data->Volume;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["TraderID"] = toUtf(task_data->TraderID);
		data["StockPaybackLocalID"] = toUtf(task_data->StockPaybackLocalID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["InstallID"] = task_data->InstallID;
		data["InsertDate"] = task_data->InsertDate;
		data["InsertTime"] = task_data->InsertTime;
		data["StockPaybackSysID"] = toUtf(task_data->StockPaybackSysID);
		data["StockPaybackStatus"] = task_data->StockPaybackStatus;
		data["ExchangeErrorID"] = task_data->ExchangeErrorID;
		data["BranchID"] = toUtf(task_data->BranchID);
		data["IPAddressAsInt"] = task_data->IPAddressAsInt;
		data["MacAddressAsLong"] = task_data->MacAddressAsLong;
		delete task_data;
	}
	this->onRtnStockPayback(data);
};

void TdApi::processRtnPrivateCreditStock(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTPrivateCreditStockField *task_data = (CUTPrivateCreditStockField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["Volume"] = task_data->Volume;
		data["BeginDate"] = task_data->BeginDate;
		data["EndDate"] = task_data->EndDate;
		data["ReserveVolume"] = task_data->ReserveVolume;
		delete task_data;
	}
	this->onRtnPrivateCreditStock(data);
};

void TdApi::processRtnLock(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTLockField *task_data = (CUTLockField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["LockRef"] = task_data->LockRef;
		data["Volume"] = task_data->Volume;
		data["LockType"] = task_data->LockType;
		data["TraderID"] = toUtf(task_data->TraderID);
		data["LockLocalID"] = toUtf(task_data->LockLocalID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["TradingDay"] = task_data->TradingDay;
		data["BranchID"] = toUtf(task_data->BranchID);
		data["InstallID"] = task_data->InstallID;
		data["IPAddressAsInt"] = task_data->IPAddressAsInt;
		data["MacAddressAsLong"] = task_data->MacAddressAsLong;
		data["LockSysID"] = toUtf(task_data->LockSysID);
		data["LockStatus"] = task_data->LockStatus;
		data["InsertDate"] = task_data->InsertDate;
		data["InsertTime"] = task_data->InsertTime;
		data["CancelTime"] = task_data->CancelTime;
		data["SequenceNo"] = task_data->SequenceNo;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["ExchangeErrorID"] = task_data->ExchangeErrorID;
		delete task_data;
	}
	this->onRtnLock(data);
};

void TdApi::processRspLockInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTInputLockField *task_data = (CUTInputLockField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["LockRef"] = task_data->LockRef;
		data["Volume"] = task_data->Volume;
		data["LockType"] = task_data->LockType;
		data["IPAddressAsInt"] = task_data->IPAddressAsInt;
		data["MacAddressAsLong"] = task_data->MacAddressAsLong;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspLockInsert(data, error, task->task_id, task->task_last);
};

void TdApi::processRtnExecOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTExecOrderField *task_data = (CUTExecOrderField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ExecOrderRef"] = task_data->ExecOrderRef;
		data["Volume"] = task_data->Volume;
		data["TraderID"] = toUtf(task_data->TraderID);
		data["ExecOrderLocalID"] = toUtf(task_data->ExecOrderLocalID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["TradingDay"] = task_data->TradingDay;
		data["BranchID"] = toUtf(task_data->BranchID);
		data["InstallID"] = task_data->InstallID;
		data["IPAddressAsInt"] = task_data->IPAddressAsInt;
		data["MacAddressAsLong"] = task_data->MacAddressAsLong;
		data["ExecOrderSysID"] = toUtf(task_data->ExecOrderSysID);
		data["ExecResult"] = task_data->ExecResult;
		data["InsertDate"] = task_data->InsertDate;
		data["InsertTime"] = task_data->InsertTime;
		data["CancelTime"] = task_data->CancelTime;
		data["SequenceNo"] = task_data->SequenceNo;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["ExchangeErrorID"] = task_data->ExchangeErrorID;
		delete task_data;
	}
	this->onRtnExecOrder(data);
};

void TdApi::processRspExecOrderInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTInputExecOrderField *task_data = (CUTInputExecOrderField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ExecOrderRef"] = task_data->ExecOrderRef;
		data["Volume"] = task_data->Volume;
		data["IPAddressAsInt"] = task_data->IPAddressAsInt;
		data["MacAddressAsLong"] = task_data->MacAddressAsLong;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspExecOrderInsert(data, error, task->task_id, task->task_last);
};

void TdApi::processRspExecOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTInputExecOrderActionField *task_data = (CUTInputExecOrderActionField*)task->task_data;
		data["ExecOrderActionRef"] = task_data->ExecOrderActionRef;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["ExecOrderRef"] = task_data->ExecOrderRef;
		data["IPAddressAsInt"] = task_data->IPAddressAsInt;
		data["MacAddressAsLong"] = task_data->MacAddressAsLong;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspExecOrderAction(data, error, task->task_id, task->task_last);
};

void TdApi::processErrRtnExecOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTExecOrderActionField *task_data = (CUTExecOrderActionField*)task->task_data;
		data["ExecOrderActionRef"] = task_data->ExecOrderActionRef;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["ExecOrderRef"] = task_data->ExecOrderRef;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["ExecOrderSysID"] = toUtf(task_data->ExecOrderSysID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ActionDate"] = task_data->ActionDate;
		data["ActionTime"] = task_data->ActionTime;
		data["TraderID"] = toUtf(task_data->TraderID);
		data["ExecOrderLocalID"] = toUtf(task_data->ExecOrderLocalID);
		data["ActionLocalID"] = toUtf(task_data->ActionLocalID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["OrderActionStatus"] = task_data->OrderActionStatus;
		data["BranchID"] = toUtf(task_data->BranchID);
		data["InstallID"] = task_data->InstallID;
		data["ExchangeErrorID"] = task_data->ExchangeErrorID;
		data["ActionFrontID"] = task_data->ActionFrontID;
		data["ActionSessionID"] = task_data->ActionSessionID;
		data["IPAddressAsInt"] = task_data->IPAddressAsInt;
		data["MacAddressAsLong"] = task_data->MacAddressAsLong;
		delete task_data;
	}
	this->onErrRtnExecOrderAction(data);
};

void TdApi::processRspQryInstrument(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTInstrumentField *task_data = (CUTInstrumentField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["InstrumentName"] = toUtf(task_data->InstrumentName);
		data["ProductID"] = toUtf(task_data->ProductID);
		data["ProductClass"] = task_data->ProductClass;
		data["DeliveryYear"] = task_data->DeliveryYear;
		data["DeliveryMonth"] = task_data->DeliveryMonth;
		data["MaxMarketOrderVolume"] = task_data->MaxMarketOrderVolume;
		data["MinMarketOrderVolume"] = task_data->MinMarketOrderVolume;
		data["MaxLimitOrderVolume"] = task_data->MaxLimitOrderVolume;
		data["MinLimitOrderVolume"] = task_data->MinLimitOrderVolume;
		data["VolumeMultiple"] = task_data->VolumeMultiple;
		data["PriceTick"] = task_data->PriceTick;
		data["CreateDate"] = task_data->CreateDate;
		data["OpenDate"] = task_data->OpenDate;
		data["ExpireDate"] = task_data->ExpireDate;
		data["StartDelivDate"] = task_data->StartDelivDate;
		data["EndDelivDate"] = task_data->EndDelivDate;
		data["IsTrading"] = task_data->IsTrading;
		data["InstLifePhase"] = task_data->InstLifePhase;
		data["PositionType"] = task_data->PositionType;
		data["PositionDateType"] = task_data->PositionDateType;
		data["MaxMarginSideAlgorithm"] = task_data->MaxMarginSideAlgorithm;
		data["OptionsType"] = task_data->OptionsType;
		data["CombinationType"] = task_data->CombinationType;
		data["UnderlyingInstrID"] = toUtf(task_data->UnderlyingInstrID);
		data["StrikePrice"] = task_data->StrikePrice;
		data["UnderlyingMultiple"] = task_data->UnderlyingMultiple;
		data["MinBuyVolume"] = task_data->MinBuyVolume;
		data["MinSellVolume"] = task_data->MinSellVolume;
		data["InstrumentCode"] = toUtf(task_data->InstrumentCode);
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["MinMarketBuyVolume"] = task_data->MinMarketBuyVolume;
		data["MinMarketSellVolume"] = task_data->MinMarketSellVolume;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInstrument(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryDepthMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTDepthMarketDataField *task_data = (CUTDepthMarketDataField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["TradingDay"] = task_data->TradingDay;
		data["PreSettlementPrice"] = task_data->PreSettlementPrice;
		data["PreClosePrice"] = task_data->PreClosePrice;
		data["PreOpenInterest"] = task_data->PreOpenInterest;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["ActionDay"] = task_data->ActionDay;
		data["UpdateTime"] = task_data->UpdateTime;
		data["OpenPrice"] = task_data->OpenPrice;
		data["ClosePrice"] = task_data->ClosePrice;
		data["SettlementPrice"] = task_data->SettlementPrice;
		data["HighestPrice"] = task_data->HighestPrice;
		data["LowestPrice"] = task_data->LowestPrice;
		data["InstrumentStatus"] = task_data->InstrumentStatus;
		data["LastPrice"] = task_data->LastPrice;
		data["Volume"] = task_data->Volume;
		data["Turnover"] = task_data->Turnover;
		data["OpenInterest"] = task_data->OpenInterest;
		data["BidPrice1"] = task_data->BidPrice1;
		data["AskPrice1"] = task_data->AskPrice1;
		data["BidVolume1"] = task_data->BidVolume1;
		data["AskVolume1"] = task_data->AskVolume1;
		data["BidPrice2"] = task_data->BidPrice2;
		data["AskPrice2"] = task_data->AskPrice2;
		data["BidVolume2"] = task_data->BidVolume2;
		data["AskVolume2"] = task_data->AskVolume2;
		data["BidPrice3"] = task_data->BidPrice3;
		data["AskPrice3"] = task_data->AskPrice3;
		data["BidVolume3"] = task_data->BidVolume3;
		data["AskVolume3"] = task_data->AskVolume3;
		data["BidPrice4"] = task_data->BidPrice4;
		data["AskPrice4"] = task_data->AskPrice4;
		data["BidVolume4"] = task_data->BidVolume4;
		data["AskVolume4"] = task_data->AskVolume4;
		data["BidPrice5"] = task_data->BidPrice5;
		data["AskPrice5"] = task_data->AskPrice5;
		data["BidVolume5"] = task_data->BidVolume5;
		data["AskVolume5"] = task_data->AskVolume5;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryDepthMarketData(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryInvestorPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTInvestorPositionField *task_data = (CUTInvestorPositionField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["PosiDirection"] = task_data->PosiDirection;
		data["YdPosition"] = task_data->YdPosition;
		data["Position"] = task_data->Position;
		data["LongFrozen"] = task_data->LongFrozen;
		data["ShortFrozen"] = task_data->ShortFrozen;
		data["LongFrozenAmount"] = task_data->LongFrozenAmount;
		data["ShortFrozenAmount"] = task_data->ShortFrozenAmount;
		data["OpenVolume"] = task_data->OpenVolume;
		data["CloseVolume"] = task_data->CloseVolume;
		data["OpenAmount"] = task_data->OpenAmount;
		data["CloseAmount"] = task_data->CloseAmount;
		data["PositionCost"] = task_data->PositionCost;
		data["UseMargin"] = task_data->UseMargin;
		data["FrozenMargin"] = task_data->FrozenMargin;
		data["FrozenCash"] = task_data->FrozenCash;
		data["FrozenCommission"] = task_data->FrozenCommission;
		data["CashIn"] = task_data->CashIn;
		data["Commission"] = task_data->Commission;
		data["CloseProfit"] = task_data->CloseProfit;
		data["PositionProfit"] = task_data->PositionProfit;
		data["PreSettlementPrice"] = task_data->PreSettlementPrice;
		data["SettlementPrice"] = task_data->SettlementPrice;
		data["TradingDay"] = task_data->TradingDay;
		data["OpenCost"] = task_data->OpenCost;
		data["CombPosition"] = task_data->CombPosition;
		data["CloseProfitByDate"] = task_data->CloseProfitByDate;
		data["CloseProfitByTrade"] = task_data->CloseProfitByTrade;
		data["TodayPosition"] = task_data->TodayPosition;
		data["MarginByVolume"] = task_data->MarginByVolume;
		data["StrikeFrozen"] = task_data->StrikeFrozen;
		data["StrikeFrozenAmount"] = task_data->StrikeFrozenAmount;
		data["AbandonFrozen"] = task_data->AbandonFrozen;
		data["CreditFund"] = task_data->CreditFund;
		data["RedemptionPosition"] = task_data->RedemptionPosition;
		data["RedemptionFrozen"] = task_data->RedemptionFrozen;
		data["RedemptionPositionFrozen"] = task_data->RedemptionPositionFrozen;
		data["CreditFundVolume"] = task_data->CreditFundVolume;
		data["CreditFundCommission"] = task_data->CreditFundCommission;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInvestorPosition(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryTradingAccount(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTTradingAccountField *task_data = (CUTTradingAccountField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["AccType"] = task_data->AccType;
		data["TradingDay"] = task_data->TradingDay;
		data["PreMortgage"] = task_data->PreMortgage;
		data["PreCredit"] = task_data->PreCredit;
		data["PreDeposit"] = task_data->PreDeposit;
		data["PreBalance"] = task_data->PreBalance;
		data["PreMargin"] = task_data->PreMargin;
		data["InterestBase"] = task_data->InterestBase;
		data["Interest"] = task_data->Interest;
		data["Deposit"] = task_data->Deposit;
		data["Withdraw"] = task_data->Withdraw;
		data["FrozenMargin"] = task_data->FrozenMargin;
		data["FrozenCash"] = task_data->FrozenCash;
		data["FrozenCommission"] = task_data->FrozenCommission;
		data["CurrMargin"] = task_data->CurrMargin;
		data["CashIn"] = task_data->CashIn;
		data["Commission"] = task_data->Commission;
		data["CloseProfit"] = task_data->CloseProfit;
		data["PositionProfit"] = task_data->PositionProfit;
		data["Balance"] = task_data->Balance;
		data["Available"] = task_data->Available;
		data["WithdrawQuota"] = task_data->WithdrawQuota;
		data["Reserve"] = task_data->Reserve;
		data["Credit"] = task_data->Credit;
		data["Mortgage"] = task_data->Mortgage;
		data["DeliveryMargin"] = task_data->DeliveryMargin;
		data["Tax"] = task_data->Tax;
		data["CreditFund"] = task_data->CreditFund;
		data["CreditFundFrozen"] = task_data->CreditFundFrozen;
		data["CreditStock"] = task_data->CreditStock;
		data["CreditStockFrozen"] = task_data->CreditStockFrozen;
		data["CreditAvailable"] = task_data->CreditAvailable;
		data["CreditAvailableParam"] = task_data->CreditAvailableParam;
		data["CreditStockCloseFrozen"] = task_data->CreditStockCloseFrozen;
		data["CreditCollBuyFrozenOffset"] = task_data->CreditCollBuyFrozenOffset;
		data["CreditLiquidCost"] = task_data->CreditLiquidCost;
		data["CreditInterest"] = task_data->CreditInterest;
		data["CreditTotalValue"] = task_data->CreditTotalValue;
		data["CreditStockValue"] = task_data->CreditStockValue;
		data["CreditFundPayback"] = task_data->CreditFundPayback;
		data["CreditInterestProcess"] = task_data->CreditInterestProcess;
		data["CreditFundCommission"] = task_data->CreditFundCommission;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryTradingAccount(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryOptionInstrMarginByVolume(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTOptionInstrMarginByVolumeField *task_data = (CUTOptionInstrMarginByVolumeField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["MarginByVolume"] = task_data->MarginByVolume;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryOptionInstrMarginByVolume(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryOptionInstrCommRate(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTOptionInstrCommRateField *task_data = (CUTOptionInstrCommRateField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["InvestorRange"] = task_data->InvestorRange;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["PosiDirection"] = task_data->PosiDirection;
		data["OpenRatioByMoney"] = task_data->OpenRatioByMoney;
		data["OpenRatioByVolume"] = task_data->OpenRatioByVolume;
		data["CloseRatioByMoney"] = task_data->CloseRatioByMoney;
		data["CloseRatioByVolume"] = task_data->CloseRatioByVolume;
		data["CloseTodayRatioByMoney"] = task_data->CloseTodayRatioByMoney;
		data["CloseTodayRatioByVolume"] = task_data->CloseTodayRatioByVolume;
		data["StrikeRatioByMoney"] = task_data->StrikeRatioByMoney;
		data["StrikeRatioByVolume"] = task_data->StrikeRatioByVolume;
		data["CommByOrder"] = task_data->CommByOrder;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryOptionInstrCommRate(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTOrderField *task_data = (CUTOrderField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["OrderRef"] = task_data->OrderRef;
		data["Direction"] = task_data->Direction;
		data["OffsetFlag"] = task_data->OffsetFlag;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["OrderPriceType"] = task_data->OrderPriceType;
		data["VolumeTotalOriginal"] = task_data->VolumeTotalOriginal;
		data["LimitPrice"] = task_data->LimitPrice;
		data["TimeCondition"] = task_data->TimeCondition;
		data["VolumeCondition"] = task_data->VolumeCondition;
		data["ContingentCondition"] = task_data->ContingentCondition;
		data["GTDDate"] = task_data->GTDDate;
		data["MinVolume"] = task_data->MinVolume;
		data["IsAutoSuspend"] = task_data->IsAutoSuspend;
		data["UserForceClose"] = task_data->UserForceClose;
		data["StopPrice"] = task_data->StopPrice;
		data["IsSwapOrder"] = task_data->IsSwapOrder;
		data["TraderID"] = toUtf(task_data->TraderID);
		data["OrderLocalID"] = toUtf(task_data->OrderLocalID);
		data["ParticipantID"] = toUtf(task_data->ParticipantID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["TradingDay"] = task_data->TradingDay;
		data["UserProductInfo"] = toUtf(task_data->UserProductInfo);
		data["BranchID"] = toUtf(task_data->BranchID);
		data["InstallID"] = task_data->InstallID;
		data["IPAddressAsInt"] = task_data->IPAddressAsInt;
		data["MacAddressAsLong"] = task_data->MacAddressAsLong;
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["OrderStatus"] = task_data->OrderStatus;
		data["OrderType"] = task_data->OrderType;
		data["VolumeTraded"] = task_data->VolumeTraded;
		data["VolumeTotal"] = task_data->VolumeTotal;
		data["InsertDate"] = task_data->InsertDate;
		data["InsertTime"] = task_data->InsertTime;
		data["CancelTime"] = task_data->CancelTime;
		data["SequenceNo"] = task_data->SequenceNo;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["ExchangeErrorID"] = task_data->ExchangeErrorID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryOrder(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryTrade(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTTradeField *task_data = (CUTTradeField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["OrderRef"] = task_data->OrderRef;
		data["TradeID"] = toUtf(task_data->TradeID);
		data["Direction"] = task_data->Direction;
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["OffsetFlag"] = task_data->OffsetFlag;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["Price"] = task_data->Price;
		data["Volume"] = task_data->Volume;
		data["TradeDate"] = task_data->TradeDate;
		data["TradeTime"] = task_data->TradeTime;
		data["TradeType"] = task_data->TradeType;
		data["TraderID"] = toUtf(task_data->TraderID);
		data["OrderLocalID"] = toUtf(task_data->OrderLocalID);
		data["SequenceNo"] = task_data->SequenceNo;
		data["TradingDay"] = task_data->TradingDay;
		data["InstallID"] = task_data->InstallID;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryTrade(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryInstrumentCommissionRate(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTInstrumentCommissionRateField *task_data = (CUTInstrumentCommissionRateField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["InvestorRange"] = task_data->InvestorRange;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["PosiDirection"] = task_data->PosiDirection;
		data["OpenRatioByMoney"] = task_data->OpenRatioByMoney;
		data["OpenRatioByVolume"] = task_data->OpenRatioByVolume;
		data["CloseRatioByMoney"] = task_data->CloseRatioByMoney;
		data["CloseRatioByVolume"] = task_data->CloseRatioByVolume;
		data["CloseTodayRatioByMoney"] = task_data->CloseTodayRatioByMoney;
		data["CloseTodayRatioByVolume"] = task_data->CloseTodayRatioByVolume;
		data["OpenTaxRatioByMoney"] = task_data->OpenTaxRatioByMoney;
		data["OpenTaxRatioByVolume"] = task_data->OpenTaxRatioByVolume;
		data["CloseTaxRatioByMoney"] = task_data->CloseTaxRatioByMoney;
		data["CloseTaxRatioByVolume"] = task_data->CloseTaxRatioByVolume;
		data["CommByOrder"] = task_data->CommByOrder;
		data["MinCommByOrder"] = task_data->MinCommByOrder;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInstrumentCommissionRate(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryInvestor(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTInvestorField *task_data = (CUTInvestorField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["InvestorGroupID"] = toUtf(task_data->InvestorGroupID);
		data["InvestorName"] = toUtf(task_data->InvestorName);
		data["IdentifiedCardType"] = task_data->IdentifiedCardType;
		data["IdentifiedCardNo"] = toUtf(task_data->IdentifiedCardNo);
		data["IsActive"] = task_data->IsActive;
		data["Telephone"] = toUtf(task_data->Telephone);
		data["Address"] = toUtf(task_data->Address);
		data["OpenDate"] = task_data->OpenDate;
		data["Mobile"] = toUtf(task_data->Mobile);
		data["CommModelID"] = toUtf(task_data->CommModelID);
		data["MarginModelID"] = toUtf(task_data->MarginModelID);
		data["DepartmentID"] = toUtf(task_data->DepartmentID);
		data["AuthGroupID"] = toUtf(task_data->AuthGroupID);
		data["TradingRightGroupID"] = toUtf(task_data->TradingRightGroupID);
		data["InvestorInstallID"] = task_data->InvestorInstallID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInvestor(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryTransfer(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTTransferField *task_data = (CUTTransferField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["TransferRef"] = task_data->TransferRef;
		data["TransferType"] = task_data->TransferType;
		data["Deposit"] = task_data->Deposit;
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["AccType"] = task_data->AccType;
		data["BankID"] = toUtf(task_data->BankID);
		data["FundPassword"] = toUtf(task_data->FundPassword);
		data["BankPassword"] = toUtf(task_data->BankPassword);
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["TransferLocalID"] = toUtf(task_data->TransferLocalID);
		data["TransferSysID"] = toUtf(task_data->TransferSysID);
		data["TransferStatus"] = task_data->TransferStatus;
		data["ExchangeErrorID"] = task_data->ExchangeErrorID;
		data["InsertDate"] = task_data->InsertDate;
		data["InsertTime"] = task_data->InsertTime;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryTransfer(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryTradingCode(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTTradingCodeField *task_data = (CUTTradingCodeField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["ClientID"] = toUtf(task_data->ClientID);
		data["IsActive"] = task_data->IsActive;
		data["ClientIDType"] = task_data->ClientIDType;
		data["BranchID"] = toUtf(task_data->BranchID);
		data["PreBranchID"] = toUtf(task_data->PreBranchID);
		data["DepartmentBranchID"] = toUtf(task_data->DepartmentBranchID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryTradingCode(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryMaxOrderVolume(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTMaxOrderVolumeField *task_data = (CUTMaxOrderVolumeField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["Direction"] = task_data->Direction;
		data["OffsetFlag"] = task_data->OffsetFlag;
		data["Price"] = task_data->Price;
		data["MaxVolume"] = task_data->MaxVolume;
		data["MaxVolumeOri"] = task_data->MaxVolumeOri;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryMaxOrderVolume(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryCreditInstrument(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTCreditInstrumentField *task_data = (CUTCreditInstrumentField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ConvertRate"] = task_data->ConvertRate;
		data["IsCreditFund"] = task_data->IsCreditFund;
		data["IsCreditStock"] = task_data->IsCreditStock;
		data["IsGuarantee"] = task_data->IsGuarantee;
		data["IsLiquid"] = task_data->IsLiquid;
		data["ConcentrationGroupID"] = toUtf(task_data->ConcentrationGroupID);
		data["AssetPrice"] = task_data->AssetPrice;
		data["AssetPriceCreditStock"] = task_data->AssetPriceCreditStock;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCreditInstrument(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryCreditInvestor(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTCreditInvestorField *task_data = (CUTCreditInvestorField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["FundRate"] = task_data->FundRate;
		data["StockRate"] = task_data->StockRate;
		data["GuaranteeRate"] = task_data->GuaranteeRate;
		data["TotalLimit"] = task_data->TotalLimit;
		data["StockLimit"] = task_data->StockLimit;
		data["FundLimit"] = task_data->FundLimit;
		data["PrivateCreditFund"] = task_data->PrivateCreditFund;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCreditInvestor(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryPrivateCreditStock(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTPrivateCreditStockField *task_data = (CUTPrivateCreditStockField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["Volume"] = task_data->Volume;
		data["BeginDate"] = task_data->BeginDate;
		data["EndDate"] = task_data->EndDate;
		data["ReserveVolume"] = task_data->ReserveVolume;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryPrivateCreditStock(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryCreditConcentration(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTCreditConcentrationField *task_data = (CUTCreditConcentrationField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ConcentrationBizType"] = task_data->ConcentrationBizType;
		data["ConcentrationInstrType"] = task_data->ConcentrationInstrType;
		data["ExchangeID"] = task_data->ExchangeID;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["GuaranteeRateLower"] = task_data->GuaranteeRateLower;
		data["GuaranteeRateUpper"] = task_data->GuaranteeRateUpper;
		data["ConcentrationRate"] = task_data->ConcentrationRate;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCreditConcentration(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryCreditFundDetail(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTCreditFundDetailField *task_data = (CUTCreditFundDetailField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["OpenDate"] = task_data->OpenDate;
		data["TradeID"] = toUtf(task_data->TradeID);
		data["ExpireDate"] = task_data->ExpireDate;
		data["Amount"] = task_data->Amount;
		data["AmountPayback"] = task_data->AmountPayback;
		data["Volume"] = task_data->Volume;
		data["VolumePayback"] = task_data->VolumePayback;
		data["YdAmountPayback"] = task_data->YdAmountPayback;
		data["Commission"] = task_data->Commission;
		data["CreditAmountPayback"] = task_data->CreditAmountPayback;
		data["FundAmountPayback"] = task_data->FundAmountPayback;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCreditFundDetail(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryCreditStockDetail(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTCreditStockDetailField *task_data = (CUTCreditStockDetailField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["OpenDate"] = task_data->OpenDate;
		data["TradeID"] = toUtf(task_data->TradeID);
		data["ExpireDate"] = task_data->ExpireDate;
		data["Volume"] = task_data->Volume;
		data["VolumePayback"] = task_data->VolumePayback;
		data["Amount"] = task_data->Amount;
		data["AmountPayback"] = task_data->AmountPayback;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCreditStockDetail(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryFundPayback(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTFundPaybackField *task_data = (CUTFundPaybackField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["FundPaybackRef"] = task_data->FundPaybackRef;
		data["Amount"] = task_data->Amount;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["FundPaybackLocalID"] = toUtf(task_data->FundPaybackLocalID);
		data["InsertDate"] = task_data->InsertDate;
		data["InsertTime"] = task_data->InsertTime;
		data["IPAddressAsInt"] = task_data->IPAddressAsInt;
		data["MacAddressAsLong"] = task_data->MacAddressAsLong;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryFundPayback(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryStockPayback(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTStockPaybackField *task_data = (CUTStockPaybackField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["StockPaybackRef"] = task_data->StockPaybackRef;
		data["Volume"] = task_data->Volume;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["TraderID"] = toUtf(task_data->TraderID);
		data["StockPaybackLocalID"] = toUtf(task_data->StockPaybackLocalID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["InstallID"] = task_data->InstallID;
		data["InsertDate"] = task_data->InsertDate;
		data["InsertTime"] = task_data->InsertTime;
		data["StockPaybackSysID"] = toUtf(task_data->StockPaybackSysID);
		data["StockPaybackStatus"] = task_data->StockPaybackStatus;
		data["ExchangeErrorID"] = task_data->ExchangeErrorID;
		data["BranchID"] = toUtf(task_data->BranchID);
		data["IPAddressAsInt"] = task_data->IPAddressAsInt;
		data["MacAddressAsLong"] = task_data->MacAddressAsLong;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryStockPayback(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryPublicCreditFund(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTPublicCreditFundField *task_data = (CUTPublicCreditFundField*)task->task_data;
		data["TotalAmount"] = task_data->TotalAmount;
		data["FrozenAmount"] = task_data->FrozenAmount;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryPublicCreditFund(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryETFInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTETFInfoField *task_data = (CUTETFInfoField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["RedemptionID"] = toUtf(task_data->RedemptionID);
		data["CreationRedemptionUnit"] = task_data->CreationRedemptionUnit;
		data["MaxCashRatio"] = task_data->MaxCashRatio;
		data["PublishIOPV"] = task_data->PublishIOPV;
		data["Creation"] = task_data->Creation;
		data["Redemption"] = task_data->Redemption;
		data["RecordNum"] = task_data->RecordNum;
		data["EstimateCashComponent"] = task_data->EstimateCashComponent;
		data["NAVperCU"] = task_data->NAVperCU;
		data["NAV"] = task_data->NAV;
		data["SubstituteAmount"] = task_data->SubstituteAmount;
		data["RedemptionStockVolume"] = task_data->RedemptionStockVolume;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryETFInfo(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryETFComponent(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTETFComponentField *task_data = (CUTETFComponentField*)task->task_data;
		data["ExchangeID"] = task_data->ExchangeID;
		data["ETFID"] = toUtf(task_data->ETFID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ComponentExchangeID"] = task_data->ComponentExchangeID;
		data["Volume"] = task_data->Volume;
		data["SubstituteFlag"] = task_data->SubstituteFlag;
		data["CreationPremiumRate"] = task_data->CreationPremiumRate;
		data["RedemptionDiscountRate"] = task_data->RedemptionDiscountRate;
		data["CreationCashSubstitute"] = task_data->CreationCashSubstitute;
		data["RedemptionCashSubstitute"] = task_data->RedemptionCashSubstitute;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryETFComponent(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryCreditAvailableDetail(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTCreditAvailableDetailField *task_data = (CUTCreditAvailableDetailField*)task->task_data;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CreditCollateralValue"] = task_data->CreditCollateralValue;
		data["CreditFundProfit"] = task_data->CreditFundProfit;
		data["CreditStockProfit"] = task_data->CreditStockProfit;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCreditAvailableDetail(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryLock(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTLockField *task_data = (CUTLockField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["LockRef"] = task_data->LockRef;
		data["Volume"] = task_data->Volume;
		data["LockType"] = task_data->LockType;
		data["TraderID"] = toUtf(task_data->TraderID);
		data["LockLocalID"] = toUtf(task_data->LockLocalID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["TradingDay"] = task_data->TradingDay;
		data["BranchID"] = toUtf(task_data->BranchID);
		data["InstallID"] = task_data->InstallID;
		data["IPAddressAsInt"] = task_data->IPAddressAsInt;
		data["MacAddressAsLong"] = task_data->MacAddressAsLong;
		data["LockSysID"] = toUtf(task_data->LockSysID);
		data["LockStatus"] = task_data->LockStatus;
		data["InsertDate"] = task_data->InsertDate;
		data["InsertTime"] = task_data->InsertTime;
		data["CancelTime"] = task_data->CancelTime;
		data["SequenceNo"] = task_data->SequenceNo;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["ExchangeErrorID"] = task_data->ExchangeErrorID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryLock(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryExecOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTExecOrderField *task_data = (CUTExecOrderField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ExecOrderRef"] = task_data->ExecOrderRef;
		data["Volume"] = task_data->Volume;
		data["TraderID"] = toUtf(task_data->TraderID);
		data["ExecOrderLocalID"] = toUtf(task_data->ExecOrderLocalID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["TradingDay"] = task_data->TradingDay;
		data["BranchID"] = toUtf(task_data->BranchID);
		data["InstallID"] = task_data->InstallID;
		data["IPAddressAsInt"] = task_data->IPAddressAsInt;
		data["MacAddressAsLong"] = task_data->MacAddressAsLong;
		data["ExecOrderSysID"] = toUtf(task_data->ExecOrderSysID);
		data["ExecResult"] = task_data->ExecResult;
		data["InsertDate"] = task_data->InsertDate;
		data["InsertTime"] = task_data->InsertTime;
		data["CancelTime"] = task_data->CancelTime;
		data["SequenceNo"] = task_data->SequenceNo;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["ExchangeErrorID"] = task_data->ExchangeErrorID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryExecOrder(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryLockPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTLockPositionField *task_data = (CUTLockPositionField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["Volume"] = task_data->Volume;
		data["FrozenVolume"] = task_data->FrozenVolume;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryLockPosition(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryOptPosiLimit(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTOptPosiLimitField *task_data = (CUTOptPosiLimitField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["TotalVolume"] = task_data->TotalVolume;
		data["LongVolume"] = task_data->LongVolume;
		data["OpenVolume"] = task_data->OpenVolume;
		data["LongOpenVolume"] = task_data->LongOpenVolume;
		data["TotalVolumeFrozen"] = task_data->TotalVolumeFrozen;
		data["LongVolumeFrozen"] = task_data->LongVolumeFrozen;
		data["OpenVolumeFrozen"] = task_data->OpenVolumeFrozen;
		data["LongOpenVolumeFrozen"] = task_data->LongOpenVolumeFrozen;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryOptPosiLimit(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryOptAmountLimit(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CUTOptAmountLimitField *task_data = (CUTOptAmountLimitField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["LongAmount"] = task_data->LongAmount;
		data["LongAmountFrozen"] = task_data->LongAmountFrozen;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryOptAmountLimit(data, error, task->task_id, task->task_last);
};

