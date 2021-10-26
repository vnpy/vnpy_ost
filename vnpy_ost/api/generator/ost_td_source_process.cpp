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
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTInstrumentIDType"] = toUtf(task_data->TUTInstrumentIDType);
		data["TUTOrderRefType"] = task_data->TUTOrderRefType;
		data["TUTDirectionType"] = task_data->TUTDirectionType;
		data["TUTOffsetFlagType"] = task_data->TUTOffsetFlagType;
		data["TUTHedgeFlagType"] = task_data->TUTHedgeFlagType;
		data["TUTOrderPriceTypeType"] = task_data->TUTOrderPriceTypeType;
		data["TUTVolumeType"] = task_data->TUTVolumeType;
		data["TUTPriceType"] = task_data->TUTPriceType;
		data["TUTTimeConditionType"] = task_data->TUTTimeConditionType;
		data["TUTVolumeConditionType"] = task_data->TUTVolumeConditionType;
		data["TUTContingentConditionType"] = task_data->TUTContingentConditionType;
		data["TUTDateType"] = task_data->TUTDateType;
		data["TUTBoolType"] = task_data->TUTBoolType;
		data["TUTTraderIDType"] = toUtf(task_data->TUTTraderIDType);
		data["TUTOrderLocalIDType"] = toUtf(task_data->TUTOrderLocalIDType);
		data["TUTParticipantIDType"] = toUtf(task_data->TUTParticipantIDType);
		data["TUTClientIDType"] = toUtf(task_data->TUTClientIDType);
		data["TUTProductInfoType"] = toUtf(task_data->TUTProductInfoType);
		data["TUTBranchIDType"] = toUtf(task_data->TUTBranchIDType);
		data["TUTInstallIDType"] = task_data->TUTInstallIDType;
		data["TUTIPAddressAsIntType"] = task_data->TUTIPAddressAsIntType;
		data["TUTMacAddressAsLongType"] = task_data->TUTMacAddressAsLongType;
		data["TUTOrderSysIDType"] = toUtf(task_data->TUTOrderSysIDType);
		data["TUTOrderStatusType"] = task_data->TUTOrderStatusType;
		data["TUTOrderTypeType"] = task_data->TUTOrderTypeType;
		data["TUTTimeType"] = task_data->TUTTimeType;
		data["TUTSequenceNoType"] = task_data->TUTSequenceNoType;
		data["TUTFrontIDType"] = task_data->TUTFrontIDType;
		data["TUTSessionIDType"] = task_data->TUTSessionIDType;
		data["TUTExchangeErrorIDType"] = task_data->TUTExchangeErrorIDType;
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
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTInstrumentIDType"] = toUtf(task_data->TUTInstrumentIDType);
		data["TUTOrderRefType"] = task_data->TUTOrderRefType;
		data["TUTTradeIDType"] = toUtf(task_data->TUTTradeIDType);
		data["TUTDirectionType"] = task_data->TUTDirectionType;
		data["TUTOrderSysIDType"] = toUtf(task_data->TUTOrderSysIDType);
		data["TUTClientIDType"] = toUtf(task_data->TUTClientIDType);
		data["TUTOffsetFlagType"] = task_data->TUTOffsetFlagType;
		data["TUTHedgeFlagType"] = task_data->TUTHedgeFlagType;
		data["TUTPriceType"] = task_data->TUTPriceType;
		data["TUTVolumeType"] = task_data->TUTVolumeType;
		data["TUTDateType"] = task_data->TUTDateType;
		data["TUTTimeType"] = task_data->TUTTimeType;
		data["TUTTradeTypeType"] = task_data->TUTTradeTypeType;
		data["TUTTraderIDType"] = toUtf(task_data->TUTTraderIDType);
		data["TUTOrderLocalIDType"] = toUtf(task_data->TUTOrderLocalIDType);
		data["TUTSequenceNoType"] = task_data->TUTSequenceNoType;
		data["TUTInstallIDType"] = task_data->TUTInstallIDType;
		data["TUTFrontIDType"] = task_data->TUTFrontIDType;
		data["TUTSessionIDType"] = task_data->TUTSessionIDType;
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
		data["TUTOrderRefType"] = task_data->TUTOrderRefType;
		data["TUTFrontIDType"] = task_data->TUTFrontIDType;
		data["TUTSessionIDType"] = task_data->TUTSessionIDType;
		data["TUTActionFlagType"] = task_data->TUTActionFlagType;
		data["TUTPriceType"] = task_data->TUTPriceType;
		data["TUTVolumeType"] = task_data->TUTVolumeType;
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTOrderSysIDType"] = toUtf(task_data->TUTOrderSysIDType);
		data["TUTInstrumentIDType"] = toUtf(task_data->TUTInstrumentIDType);
		data["TUTDateType"] = task_data->TUTDateType;
		data["TUTTimeType"] = task_data->TUTTimeType;
		data["TUTTraderIDType"] = toUtf(task_data->TUTTraderIDType);
		data["TUTOrderLocalIDType"] = toUtf(task_data->TUTOrderLocalIDType);
		data["TUTParticipantIDType"] = toUtf(task_data->TUTParticipantIDType);
		data["TUTClientIDType"] = toUtf(task_data->TUTClientIDType);
		data["TUTOrderActionStatusType"] = task_data->TUTOrderActionStatusType;
		data["TUTDirectionType"] = task_data->TUTDirectionType;
		data["TUTBranchIDType"] = toUtf(task_data->TUTBranchIDType);
		data["TUTOrderTypeType"] = task_data->TUTOrderTypeType;
		data["TUTInstallIDType"] = task_data->TUTInstallIDType;
		data["TUTExchangeErrorIDType"] = task_data->TUTExchangeErrorIDType;
		data["TUTIPAddressAsIntType"] = task_data->TUTIPAddressAsIntType;
		data["TUTMacAddressAsLongType"] = task_data->TUTMacAddressAsLongType;
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
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTInstrumentIDType"] = toUtf(task_data->TUTInstrumentIDType);
		data["TUTOrderRefType"] = task_data->TUTOrderRefType;
		data["TUTDirectionType"] = task_data->TUTDirectionType;
		data["TUTOffsetFlagType"] = task_data->TUTOffsetFlagType;
		data["TUTHedgeFlagType"] = task_data->TUTHedgeFlagType;
		data["TUTOrderPriceTypeType"] = task_data->TUTOrderPriceTypeType;
		data["TUTVolumeType"] = task_data->TUTVolumeType;
		data["TUTPriceType"] = task_data->TUTPriceType;
		data["TUTTimeConditionType"] = task_data->TUTTimeConditionType;
		data["TUTVolumeConditionType"] = task_data->TUTVolumeConditionType;
		data["TUTContingentConditionType"] = task_data->TUTContingentConditionType;
		data["TUTDateType"] = task_data->TUTDateType;
		data["TUTBoolType"] = task_data->TUTBoolType;
		data["TUTIPAddressAsIntType"] = task_data->TUTIPAddressAsIntType;
		data["TUTMacAddressAsLongType"] = task_data->TUTMacAddressAsLongType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTOrderRefType"] = task_data->TUTOrderRefType;
		data["TUTFrontIDType"] = task_data->TUTFrontIDType;
		data["TUTSessionIDType"] = task_data->TUTSessionIDType;
		data["TUTActionFlagType"] = task_data->TUTActionFlagType;
		data["TUTPriceType"] = task_data->TUTPriceType;
		data["TUTVolumeType"] = task_data->TUTVolumeType;
		data["TUTIPAddressAsIntType"] = task_data->TUTIPAddressAsIntType;
		data["TUTMacAddressAsLongType"] = task_data->TUTMacAddressAsLongType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTDateType"] = task_data->TUTDateType;
		data["TUTTimeType"] = task_data->TUTTimeType;
		data["TUTUserIDType"] = toUtf(task_data->TUTUserIDType);
		data["TUTSystemNameType"] = toUtf(task_data->TUTSystemNameType);
		data["TUTFrontIDType"] = task_data->TUTFrontIDType;
		data["TUTSessionIDType"] = task_data->TUTSessionIDType;
		data["TUTSequenceNoType"] = task_data->TUTSequenceNoType;
		data["TUTMultiAddressType"] = toUtf(task_data->TUTMultiAddressType);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTUserIDType"] = toUtf(task_data->TUTUserIDType);
		data["TUTPasswordType"] = toUtf(task_data->TUTPasswordType);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTOrderRefType"] = task_data->TUTOrderRefType;
		data["TUTTransferTypeType"] = task_data->TUTTransferTypeType;
		data["TUTMoneyType"] = task_data->TUTMoneyType;
		data["TUTCurrencyIDType"] = toUtf(task_data->TUTCurrencyIDType);
		data["TUTAccTypeType"] = task_data->TUTAccTypeType;
		data["TUTBankIDType"] = toUtf(task_data->TUTBankIDType);
		data["TUTPasswordType"] = toUtf(task_data->TUTPasswordType);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTOrderRefType"] = task_data->TUTOrderRefType;
		data["TUTTransferTypeType"] = task_data->TUTTransferTypeType;
		data["TUTMoneyType"] = task_data->TUTMoneyType;
		data["TUTCurrencyIDType"] = toUtf(task_data->TUTCurrencyIDType);
		data["TUTAccTypeType"] = task_data->TUTAccTypeType;
		data["TUTBankIDType"] = toUtf(task_data->TUTBankIDType);
		data["TUTPasswordType"] = toUtf(task_data->TUTPasswordType);
		data["TUTFrontIDType"] = task_data->TUTFrontIDType;
		data["TUTSessionIDType"] = task_data->TUTSessionIDType;
		data["TUTOrderLocalIDType"] = toUtf(task_data->TUTOrderLocalIDType);
		data["TUTOrderSysIDType"] = toUtf(task_data->TUTOrderSysIDType);
		data["TUTTransferStatusType"] = task_data->TUTTransferStatusType;
		data["TUTExchangeErrorIDType"] = task_data->TUTExchangeErrorIDType;
		data["TUTDateType"] = task_data->TUTDateType;
		data["TUTTimeType"] = task_data->TUTTimeType;
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
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTCurrencyIDType"] = toUtf(task_data->TUTCurrencyIDType);
		data["TUTOrderRefType"] = task_data->TUTOrderRefType;
		data["TUTMoneyType"] = task_data->TUTMoneyType;
		data["TUTIPAddressAsIntType"] = task_data->TUTIPAddressAsIntType;
		data["TUTMacAddressAsLongType"] = task_data->TUTMacAddressAsLongType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTCurrencyIDType"] = toUtf(task_data->TUTCurrencyIDType);
		data["TUTOrderRefType"] = task_data->TUTOrderRefType;
		data["TUTMoneyType"] = task_data->TUTMoneyType;
		data["TUTFrontIDType"] = task_data->TUTFrontIDType;
		data["TUTSessionIDType"] = task_data->TUTSessionIDType;
		data["TUTOrderLocalIDType"] = toUtf(task_data->TUTOrderLocalIDType);
		data["TUTDateType"] = task_data->TUTDateType;
		data["TUTTimeType"] = task_data->TUTTimeType;
		data["TUTIPAddressAsIntType"] = task_data->TUTIPAddressAsIntType;
		data["TUTMacAddressAsLongType"] = task_data->TUTMacAddressAsLongType;
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
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTInstrumentIDType"] = toUtf(task_data->TUTInstrumentIDType);
		data["TUTOrderRefType"] = task_data->TUTOrderRefType;
		data["TUTLargeVolumeType"] = task_data->TUTLargeVolumeType;
		data["TUTIPAddressAsIntType"] = task_data->TUTIPAddressAsIntType;
		data["TUTMacAddressAsLongType"] = task_data->TUTMacAddressAsLongType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTInstrumentIDType"] = toUtf(task_data->TUTInstrumentIDType);
		data["TUTOrderRefType"] = task_data->TUTOrderRefType;
		data["TUTLargeVolumeType"] = task_data->TUTLargeVolumeType;
		data["TUTFrontIDType"] = task_data->TUTFrontIDType;
		data["TUTSessionIDType"] = task_data->TUTSessionIDType;
		data["TUTTraderIDType"] = toUtf(task_data->TUTTraderIDType);
		data["TUTOrderLocalIDType"] = toUtf(task_data->TUTOrderLocalIDType);
		data["TUTClientIDType"] = toUtf(task_data->TUTClientIDType);
		data["TUTInstallIDType"] = task_data->TUTInstallIDType;
		data["TUTDateType"] = task_data->TUTDateType;
		data["TUTTimeType"] = task_data->TUTTimeType;
		data["TUTOrderSysIDType"] = toUtf(task_data->TUTOrderSysIDType);
		data["TUTOrderActionStatusType"] = task_data->TUTOrderActionStatusType;
		data["TUTExchangeErrorIDType"] = task_data->TUTExchangeErrorIDType;
		data["TUTBranchIDType"] = toUtf(task_data->TUTBranchIDType);
		data["TUTIPAddressAsIntType"] = task_data->TUTIPAddressAsIntType;
		data["TUTMacAddressAsLongType"] = task_data->TUTMacAddressAsLongType;
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
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTInstrumentIDType"] = toUtf(task_data->TUTInstrumentIDType);
		data["TUTLargeVolumeType"] = task_data->TUTLargeVolumeType;
		data["TUTDateType"] = task_data->TUTDateType;
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
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTInstrumentIDType"] = toUtf(task_data->TUTInstrumentIDType);
		data["TUTOrderRefType"] = task_data->TUTOrderRefType;
		data["TUTVolumeType"] = task_data->TUTVolumeType;
		data["TUTLockTypeType"] = task_data->TUTLockTypeType;
		data["TUTTraderIDType"] = toUtf(task_data->TUTTraderIDType);
		data["TUTOrderLocalIDType"] = toUtf(task_data->TUTOrderLocalIDType);
		data["TUTClientIDType"] = toUtf(task_data->TUTClientIDType);
		data["TUTDateType"] = task_data->TUTDateType;
		data["TUTBranchIDType"] = toUtf(task_data->TUTBranchIDType);
		data["TUTInstallIDType"] = task_data->TUTInstallIDType;
		data["TUTIPAddressAsIntType"] = task_data->TUTIPAddressAsIntType;
		data["TUTMacAddressAsLongType"] = task_data->TUTMacAddressAsLongType;
		data["TUTOrderSysIDType"] = toUtf(task_data->TUTOrderSysIDType);
		data["TUTOrderActionStatusType"] = task_data->TUTOrderActionStatusType;
		data["TUTTimeType"] = task_data->TUTTimeType;
		data["TUTSequenceNoType"] = task_data->TUTSequenceNoType;
		data["TUTFrontIDType"] = task_data->TUTFrontIDType;
		data["TUTSessionIDType"] = task_data->TUTSessionIDType;
		data["TUTExchangeErrorIDType"] = task_data->TUTExchangeErrorIDType;
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
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTInstrumentIDType"] = toUtf(task_data->TUTInstrumentIDType);
		data["TUTOrderRefType"] = task_data->TUTOrderRefType;
		data["TUTVolumeType"] = task_data->TUTVolumeType;
		data["TUTLockTypeType"] = task_data->TUTLockTypeType;
		data["TUTIPAddressAsIntType"] = task_data->TUTIPAddressAsIntType;
		data["TUTMacAddressAsLongType"] = task_data->TUTMacAddressAsLongType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTInstrumentIDType"] = toUtf(task_data->TUTInstrumentIDType);
		data["TUTOrderRefType"] = task_data->TUTOrderRefType;
		data["TUTVolumeType"] = task_data->TUTVolumeType;
		data["TUTTraderIDType"] = toUtf(task_data->TUTTraderIDType);
		data["TUTOrderLocalIDType"] = toUtf(task_data->TUTOrderLocalIDType);
		data["TUTClientIDType"] = toUtf(task_data->TUTClientIDType);
		data["TUTDateType"] = task_data->TUTDateType;
		data["TUTBranchIDType"] = toUtf(task_data->TUTBranchIDType);
		data["TUTInstallIDType"] = task_data->TUTInstallIDType;
		data["TUTIPAddressAsIntType"] = task_data->TUTIPAddressAsIntType;
		data["TUTMacAddressAsLongType"] = task_data->TUTMacAddressAsLongType;
		data["TUTOrderSysIDType"] = toUtf(task_data->TUTOrderSysIDType);
		data["TUTExecResultType"] = task_data->TUTExecResultType;
		data["TUTTimeType"] = task_data->TUTTimeType;
		data["TUTSequenceNoType"] = task_data->TUTSequenceNoType;
		data["TUTFrontIDType"] = task_data->TUTFrontIDType;
		data["TUTSessionIDType"] = task_data->TUTSessionIDType;
		data["TUTExchangeErrorIDType"] = task_data->TUTExchangeErrorIDType;
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
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTInstrumentIDType"] = toUtf(task_data->TUTInstrumentIDType);
		data["TUTOrderRefType"] = task_data->TUTOrderRefType;
		data["TUTVolumeType"] = task_data->TUTVolumeType;
		data["TUTIPAddressAsIntType"] = task_data->TUTIPAddressAsIntType;
		data["TUTMacAddressAsLongType"] = task_data->TUTMacAddressAsLongType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTOrderRefType"] = task_data->TUTOrderRefType;
		data["TUTFrontIDType"] = task_data->TUTFrontIDType;
		data["TUTSessionIDType"] = task_data->TUTSessionIDType;
		data["TUTIPAddressAsIntType"] = task_data->TUTIPAddressAsIntType;
		data["TUTMacAddressAsLongType"] = task_data->TUTMacAddressAsLongType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTOrderRefType"] = task_data->TUTOrderRefType;
		data["TUTFrontIDType"] = task_data->TUTFrontIDType;
		data["TUTSessionIDType"] = task_data->TUTSessionIDType;
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTOrderSysIDType"] = toUtf(task_data->TUTOrderSysIDType);
		data["TUTInstrumentIDType"] = toUtf(task_data->TUTInstrumentIDType);
		data["TUTDateType"] = task_data->TUTDateType;
		data["TUTTimeType"] = task_data->TUTTimeType;
		data["TUTTraderIDType"] = toUtf(task_data->TUTTraderIDType);
		data["TUTOrderLocalIDType"] = toUtf(task_data->TUTOrderLocalIDType);
		data["TUTClientIDType"] = toUtf(task_data->TUTClientIDType);
		data["TUTOrderActionStatusType"] = task_data->TUTOrderActionStatusType;
		data["TUTBranchIDType"] = toUtf(task_data->TUTBranchIDType);
		data["TUTInstallIDType"] = task_data->TUTInstallIDType;
		data["TUTExchangeErrorIDType"] = task_data->TUTExchangeErrorIDType;
		data["TUTIPAddressAsIntType"] = task_data->TUTIPAddressAsIntType;
		data["TUTMacAddressAsLongType"] = task_data->TUTMacAddressAsLongType;
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
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTInstrumentIDType"] = toUtf(task_data->TUTInstrumentIDType);
		data["TUTInstrumentNameType"] = toUtf(task_data->TUTInstrumentNameType);
		data["TUTProductIDType"] = toUtf(task_data->TUTProductIDType);
		data["TUTProductClassType"] = task_data->TUTProductClassType;
		data["TUTYearType"] = task_data->TUTYearType;
		data["TUTMonthType"] = task_data->TUTMonthType;
		data["TUTVolumeType"] = task_data->TUTVolumeType;
		data["TUTVolumeMultipleType"] = task_data->TUTVolumeMultipleType;
		data["TUTPriceType"] = task_data->TUTPriceType;
		data["TUTDateType"] = task_data->TUTDateType;
		data["TUTBoolType"] = task_data->TUTBoolType;
		data["TUTInstLifePhaseType"] = task_data->TUTInstLifePhaseType;
		data["TUTPositionTypeType"] = task_data->TUTPositionTypeType;
		data["TUTPositionDateTypeType"] = task_data->TUTPositionDateTypeType;
		data["TUTMaxMarginSideAlgorithmType"] = task_data->TUTMaxMarginSideAlgorithmType;
		data["TUTOptionsTypeType"] = task_data->TUTOptionsTypeType;
		data["TUTCombinationTypeType"] = task_data->TUTCombinationTypeType;
		data["TUTUnderlyingMultipleType"] = task_data->TUTUnderlyingMultipleType;
		data["TUTInstrumentCodeType"] = toUtf(task_data->TUTInstrumentCodeType);
		data["TUTCurrencyIDType"] = toUtf(task_data->TUTCurrencyIDType);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTInstrumentIDType"] = toUtf(task_data->TUTInstrumentIDType);
		data["TUTDateType"] = task_data->TUTDateType;
		data["TUTPriceType"] = task_data->TUTPriceType;
		data["TUTLargeVolumeType"] = task_data->TUTLargeVolumeType;
		data["TUTTimeType"] = task_data->TUTTimeType;
		data["TUTInstrumentStatusType"] = task_data->TUTInstrumentStatusType;
		data["TUTMoneyType"] = task_data->TUTMoneyType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTInstrumentIDType"] = toUtf(task_data->TUTInstrumentIDType);
		data["TUTHedgeFlagType"] = task_data->TUTHedgeFlagType;
		data["TUTPosiDirectionType"] = task_data->TUTPosiDirectionType;
		data["TUTLargeVolumeType"] = task_data->TUTLargeVolumeType;
		data["TUTMoneyType"] = task_data->TUTMoneyType;
		data["TUTPriceType"] = task_data->TUTPriceType;
		data["TUTDateType"] = task_data->TUTDateType;
		data["TUTRatioType"] = task_data->TUTRatioType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTAccountIDType"] = toUtf(task_data->TUTAccountIDType);
		data["TUTCurrencyIDType"] = toUtf(task_data->TUTCurrencyIDType);
		data["TUTAccTypeType"] = task_data->TUTAccTypeType;
		data["TUTDateType"] = task_data->TUTDateType;
		data["TUTMoneyType"] = task_data->TUTMoneyType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTInstrumentIDType"] = toUtf(task_data->TUTInstrumentIDType);
		data["TUTHedgeFlagType"] = task_data->TUTHedgeFlagType;
		data["TUTMoneyType"] = task_data->TUTMoneyType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTInstrumentIDType"] = toUtf(task_data->TUTInstrumentIDType);
		data["TUTInvestorRangeType"] = task_data->TUTInvestorRangeType;
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTHedgeFlagType"] = task_data->TUTHedgeFlagType;
		data["TUTPosiDirectionType"] = task_data->TUTPosiDirectionType;
		data["TUTRatioType"] = task_data->TUTRatioType;
		data["TUTMoneyType"] = task_data->TUTMoneyType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTInstrumentIDType"] = toUtf(task_data->TUTInstrumentIDType);
		data["TUTOrderRefType"] = task_data->TUTOrderRefType;
		data["TUTDirectionType"] = task_data->TUTDirectionType;
		data["TUTOffsetFlagType"] = task_data->TUTOffsetFlagType;
		data["TUTHedgeFlagType"] = task_data->TUTHedgeFlagType;
		data["TUTOrderPriceTypeType"] = task_data->TUTOrderPriceTypeType;
		data["TUTVolumeType"] = task_data->TUTVolumeType;
		data["TUTPriceType"] = task_data->TUTPriceType;
		data["TUTTimeConditionType"] = task_data->TUTTimeConditionType;
		data["TUTVolumeConditionType"] = task_data->TUTVolumeConditionType;
		data["TUTContingentConditionType"] = task_data->TUTContingentConditionType;
		data["TUTDateType"] = task_data->TUTDateType;
		data["TUTBoolType"] = task_data->TUTBoolType;
		data["TUTTraderIDType"] = toUtf(task_data->TUTTraderIDType);
		data["TUTOrderLocalIDType"] = toUtf(task_data->TUTOrderLocalIDType);
		data["TUTParticipantIDType"] = toUtf(task_data->TUTParticipantIDType);
		data["TUTClientIDType"] = toUtf(task_data->TUTClientIDType);
		data["TUTProductInfoType"] = toUtf(task_data->TUTProductInfoType);
		data["TUTBranchIDType"] = toUtf(task_data->TUTBranchIDType);
		data["TUTInstallIDType"] = task_data->TUTInstallIDType;
		data["TUTIPAddressAsIntType"] = task_data->TUTIPAddressAsIntType;
		data["TUTMacAddressAsLongType"] = task_data->TUTMacAddressAsLongType;
		data["TUTOrderSysIDType"] = toUtf(task_data->TUTOrderSysIDType);
		data["TUTOrderStatusType"] = task_data->TUTOrderStatusType;
		data["TUTOrderTypeType"] = task_data->TUTOrderTypeType;
		data["TUTTimeType"] = task_data->TUTTimeType;
		data["TUTSequenceNoType"] = task_data->TUTSequenceNoType;
		data["TUTFrontIDType"] = task_data->TUTFrontIDType;
		data["TUTSessionIDType"] = task_data->TUTSessionIDType;
		data["TUTExchangeErrorIDType"] = task_data->TUTExchangeErrorIDType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTInstrumentIDType"] = toUtf(task_data->TUTInstrumentIDType);
		data["TUTOrderRefType"] = task_data->TUTOrderRefType;
		data["TUTTradeIDType"] = toUtf(task_data->TUTTradeIDType);
		data["TUTDirectionType"] = task_data->TUTDirectionType;
		data["TUTOrderSysIDType"] = toUtf(task_data->TUTOrderSysIDType);
		data["TUTClientIDType"] = toUtf(task_data->TUTClientIDType);
		data["TUTOffsetFlagType"] = task_data->TUTOffsetFlagType;
		data["TUTHedgeFlagType"] = task_data->TUTHedgeFlagType;
		data["TUTPriceType"] = task_data->TUTPriceType;
		data["TUTVolumeType"] = task_data->TUTVolumeType;
		data["TUTDateType"] = task_data->TUTDateType;
		data["TUTTimeType"] = task_data->TUTTimeType;
		data["TUTTradeTypeType"] = task_data->TUTTradeTypeType;
		data["TUTTraderIDType"] = toUtf(task_data->TUTTraderIDType);
		data["TUTOrderLocalIDType"] = toUtf(task_data->TUTOrderLocalIDType);
		data["TUTSequenceNoType"] = task_data->TUTSequenceNoType;
		data["TUTInstallIDType"] = task_data->TUTInstallIDType;
		data["TUTFrontIDType"] = task_data->TUTFrontIDType;
		data["TUTSessionIDType"] = task_data->TUTSessionIDType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTInstrumentIDType"] = toUtf(task_data->TUTInstrumentIDType);
		data["TUTInvestorRangeType"] = task_data->TUTInvestorRangeType;
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTHedgeFlagType"] = task_data->TUTHedgeFlagType;
		data["TUTPosiDirectionType"] = task_data->TUTPosiDirectionType;
		data["TUTRatioType"] = task_data->TUTRatioType;
		data["TUTMoneyType"] = task_data->TUTMoneyType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTPartyNameType"] = toUtf(task_data->TUTPartyNameType);
		data["TUTIdCardTypeType"] = task_data->TUTIdCardTypeType;
		data["TUTIdentifiedCardNoType"] = toUtf(task_data->TUTIdentifiedCardNoType);
		data["TUTBoolType"] = task_data->TUTBoolType;
		data["TUTTelephoneType"] = toUtf(task_data->TUTTelephoneType);
		data["TUTAddressType"] = toUtf(task_data->TUTAddressType);
		data["TUTDateType"] = task_data->TUTDateType;
		data["TUTMobileType"] = toUtf(task_data->TUTMobileType);
		data["TUTInstallIDType"] = task_data->TUTInstallIDType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTOrderRefType"] = task_data->TUTOrderRefType;
		data["TUTTransferTypeType"] = task_data->TUTTransferTypeType;
		data["TUTMoneyType"] = task_data->TUTMoneyType;
		data["TUTCurrencyIDType"] = toUtf(task_data->TUTCurrencyIDType);
		data["TUTAccTypeType"] = task_data->TUTAccTypeType;
		data["TUTBankIDType"] = toUtf(task_data->TUTBankIDType);
		data["TUTPasswordType"] = toUtf(task_data->TUTPasswordType);
		data["TUTFrontIDType"] = task_data->TUTFrontIDType;
		data["TUTSessionIDType"] = task_data->TUTSessionIDType;
		data["TUTOrderLocalIDType"] = toUtf(task_data->TUTOrderLocalIDType);
		data["TUTOrderSysIDType"] = toUtf(task_data->TUTOrderSysIDType);
		data["TUTTransferStatusType"] = task_data->TUTTransferStatusType;
		data["TUTExchangeErrorIDType"] = task_data->TUTExchangeErrorIDType;
		data["TUTDateType"] = task_data->TUTDateType;
		data["TUTTimeType"] = task_data->TUTTimeType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTClientIDType"] = toUtf(task_data->TUTClientIDType);
		data["TUTBoolType"] = task_data->TUTBoolType;
		data["TUTClientIDTypeType"] = task_data->TUTClientIDTypeType;
		data["TUTBranchIDType"] = toUtf(task_data->TUTBranchIDType);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTInstrumentIDType"] = toUtf(task_data->TUTInstrumentIDType);
		data["TUTHedgeFlagType"] = task_data->TUTHedgeFlagType;
		data["TUTDirectionType"] = task_data->TUTDirectionType;
		data["TUTOffsetFlagType"] = task_data->TUTOffsetFlagType;
		data["TUTPriceType"] = task_data->TUTPriceType;
		data["TUTVolumeType"] = task_data->TUTVolumeType;
		data["TUTLargeVolumeType"] = task_data->TUTLargeVolumeType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTInstrumentIDType"] = toUtf(task_data->TUTInstrumentIDType);
		data["TUTRatioType"] = task_data->TUTRatioType;
		data["TUTBoolType"] = task_data->TUTBoolType;
		data["TUTMoneyType"] = task_data->TUTMoneyType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTRatioType"] = task_data->TUTRatioType;
		data["TUTMoneyType"] = task_data->TUTMoneyType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTInstrumentIDType"] = toUtf(task_data->TUTInstrumentIDType);
		data["TUTLargeVolumeType"] = task_data->TUTLargeVolumeType;
		data["TUTDateType"] = task_data->TUTDateType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTConcentrationBizTypeType"] = task_data->TUTConcentrationBizTypeType;
		data["TUTConcentrationInstrTypeType"] = task_data->TUTConcentrationInstrTypeType;
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTInstrumentIDType"] = toUtf(task_data->TUTInstrumentIDType);
		data["TUTRatioType"] = task_data->TUTRatioType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTInstrumentIDType"] = toUtf(task_data->TUTInstrumentIDType);
		data["TUTDateType"] = task_data->TUTDateType;
		data["TUTTradeIDType"] = toUtf(task_data->TUTTradeIDType);
		data["TUTMoneyType"] = task_data->TUTMoneyType;
		data["TUTVolumeType"] = task_data->TUTVolumeType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTInstrumentIDType"] = toUtf(task_data->TUTInstrumentIDType);
		data["TUTDateType"] = task_data->TUTDateType;
		data["TUTTradeIDType"] = toUtf(task_data->TUTTradeIDType);
		data["TUTVolumeType"] = task_data->TUTVolumeType;
		data["TUTMoneyType"] = task_data->TUTMoneyType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTCurrencyIDType"] = toUtf(task_data->TUTCurrencyIDType);
		data["TUTOrderRefType"] = task_data->TUTOrderRefType;
		data["TUTMoneyType"] = task_data->TUTMoneyType;
		data["TUTFrontIDType"] = task_data->TUTFrontIDType;
		data["TUTSessionIDType"] = task_data->TUTSessionIDType;
		data["TUTOrderLocalIDType"] = toUtf(task_data->TUTOrderLocalIDType);
		data["TUTDateType"] = task_data->TUTDateType;
		data["TUTTimeType"] = task_data->TUTTimeType;
		data["TUTIPAddressAsIntType"] = task_data->TUTIPAddressAsIntType;
		data["TUTMacAddressAsLongType"] = task_data->TUTMacAddressAsLongType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTInstrumentIDType"] = toUtf(task_data->TUTInstrumentIDType);
		data["TUTOrderRefType"] = task_data->TUTOrderRefType;
		data["TUTLargeVolumeType"] = task_data->TUTLargeVolumeType;
		data["TUTFrontIDType"] = task_data->TUTFrontIDType;
		data["TUTSessionIDType"] = task_data->TUTSessionIDType;
		data["TUTTraderIDType"] = toUtf(task_data->TUTTraderIDType);
		data["TUTOrderLocalIDType"] = toUtf(task_data->TUTOrderLocalIDType);
		data["TUTClientIDType"] = toUtf(task_data->TUTClientIDType);
		data["TUTInstallIDType"] = task_data->TUTInstallIDType;
		data["TUTDateType"] = task_data->TUTDateType;
		data["TUTTimeType"] = task_data->TUTTimeType;
		data["TUTOrderSysIDType"] = toUtf(task_data->TUTOrderSysIDType);
		data["TUTOrderActionStatusType"] = task_data->TUTOrderActionStatusType;
		data["TUTExchangeErrorIDType"] = task_data->TUTExchangeErrorIDType;
		data["TUTBranchIDType"] = toUtf(task_data->TUTBranchIDType);
		data["TUTIPAddressAsIntType"] = task_data->TUTIPAddressAsIntType;
		data["TUTMacAddressAsLongType"] = task_data->TUTMacAddressAsLongType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTMoneyType"] = task_data->TUTMoneyType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTInstrumentIDType"] = toUtf(task_data->TUTInstrumentIDType);
		data["TUTFundIDType"] = toUtf(task_data->TUTFundIDType);
		data["TUTVolumeType"] = task_data->TUTVolumeType;
		data["TUTRatioType"] = task_data->TUTRatioType;
		data["TUTBoolType"] = task_data->TUTBoolType;
		data["TUTMoneyType"] = task_data->TUTMoneyType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTFundIDType"] = toUtf(task_data->TUTFundIDType);
		data["TUTInstrumentIDType"] = toUtf(task_data->TUTInstrumentIDType);
		data["TUTVolumeType"] = task_data->TUTVolumeType;
		data["TUTSubstituteFlagType"] = task_data->TUTSubstituteFlagType;
		data["TUTRatioType"] = task_data->TUTRatioType;
		data["TUTMoneyType"] = task_data->TUTMoneyType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTAccountIDType"] = toUtf(task_data->TUTAccountIDType);
		data["TUTMoneyType"] = task_data->TUTMoneyType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTInstrumentIDType"] = toUtf(task_data->TUTInstrumentIDType);
		data["TUTOrderRefType"] = task_data->TUTOrderRefType;
		data["TUTVolumeType"] = task_data->TUTVolumeType;
		data["TUTLockTypeType"] = task_data->TUTLockTypeType;
		data["TUTTraderIDType"] = toUtf(task_data->TUTTraderIDType);
		data["TUTOrderLocalIDType"] = toUtf(task_data->TUTOrderLocalIDType);
		data["TUTClientIDType"] = toUtf(task_data->TUTClientIDType);
		data["TUTDateType"] = task_data->TUTDateType;
		data["TUTBranchIDType"] = toUtf(task_data->TUTBranchIDType);
		data["TUTInstallIDType"] = task_data->TUTInstallIDType;
		data["TUTIPAddressAsIntType"] = task_data->TUTIPAddressAsIntType;
		data["TUTMacAddressAsLongType"] = task_data->TUTMacAddressAsLongType;
		data["TUTOrderSysIDType"] = toUtf(task_data->TUTOrderSysIDType);
		data["TUTOrderActionStatusType"] = task_data->TUTOrderActionStatusType;
		data["TUTTimeType"] = task_data->TUTTimeType;
		data["TUTSequenceNoType"] = task_data->TUTSequenceNoType;
		data["TUTFrontIDType"] = task_data->TUTFrontIDType;
		data["TUTSessionIDType"] = task_data->TUTSessionIDType;
		data["TUTExchangeErrorIDType"] = task_data->TUTExchangeErrorIDType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTInstrumentIDType"] = toUtf(task_data->TUTInstrumentIDType);
		data["TUTOrderRefType"] = task_data->TUTOrderRefType;
		data["TUTVolumeType"] = task_data->TUTVolumeType;
		data["TUTTraderIDType"] = toUtf(task_data->TUTTraderIDType);
		data["TUTOrderLocalIDType"] = toUtf(task_data->TUTOrderLocalIDType);
		data["TUTClientIDType"] = toUtf(task_data->TUTClientIDType);
		data["TUTDateType"] = task_data->TUTDateType;
		data["TUTBranchIDType"] = toUtf(task_data->TUTBranchIDType);
		data["TUTInstallIDType"] = task_data->TUTInstallIDType;
		data["TUTIPAddressAsIntType"] = task_data->TUTIPAddressAsIntType;
		data["TUTMacAddressAsLongType"] = task_data->TUTMacAddressAsLongType;
		data["TUTOrderSysIDType"] = toUtf(task_data->TUTOrderSysIDType);
		data["TUTExecResultType"] = task_data->TUTExecResultType;
		data["TUTTimeType"] = task_data->TUTTimeType;
		data["TUTSequenceNoType"] = task_data->TUTSequenceNoType;
		data["TUTFrontIDType"] = task_data->TUTFrontIDType;
		data["TUTSessionIDType"] = task_data->TUTSessionIDType;
		data["TUTExchangeErrorIDType"] = task_data->TUTExchangeErrorIDType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTInstrumentIDType"] = toUtf(task_data->TUTInstrumentIDType);
		data["TUTLargeVolumeType"] = task_data->TUTLargeVolumeType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTInstrumentIDType"] = toUtf(task_data->TUTInstrumentIDType);
		data["TUTLargeVolumeType"] = task_data->TUTLargeVolumeType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
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
		data["TUTInvestorIDType"] = toUtf(task_data->TUTInvestorIDType);
		data["TUTExchangeIDType"] = task_data->TUTExchangeIDType;
		data["TUTMoneyType"] = task_data->TUTMoneyType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CUTRspInfoField *task_error = (CUTRspInfoField*)task->task_error;
		error["TUTErrorIDType"] = task_error->TUTErrorIDType;
		error["TUTErrorMsgType"] = toUtf(task_error->TUTErrorMsgType);
		delete task_error;
	}
	this->onRspQryOptAmountLimit(data, error, task->task_id, task->task_last);
};

