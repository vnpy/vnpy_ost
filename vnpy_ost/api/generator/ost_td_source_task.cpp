void TdApi::OnFrontConnected()
{
	Task task = Task();
	task.task_name = ONFRONTCONNECTED;
	this->task_queue.push(task);
};

void TdApi::OnFrontDisconnected(int nReason)
{
	Task task = Task();
	task.task_name = ONFRONTDISCONNECTED;
	task.task_id = nReason;
	this->task_queue.push(task);
};

void TdApi::OnRspError(CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPERROR;
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRtnOrder(CUTOrderField *pOrder) 
{
	Task task = Task();
	task.task_name = ONRTNORDER;
	if (pOrder)
	{
		CUTOrderField *task_data = new CUTOrderField();
		*task_data = *pOrder;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnTrade(CUTTradeField *pTrade) 
{
	Task task = Task();
	task.task_name = ONRTNTRADE;
	if (pTrade)
	{
		CUTTradeField *task_data = new CUTTradeField();
		*task_data = *pTrade;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnErrRtnOrderAction(CUTOrderActionField *pOrderAction) 
{
	Task task = Task();
	task.task_name = ONERRRTNORDERACTION;
	if (pOrderAction)
	{
		CUTOrderActionField *task_data = new CUTOrderActionField();
		*task_data = *pOrderAction;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspOrderInsert(CUTInputOrderField *pInputOrder, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPORDERINSERT;
	if (pInputOrder)
	{
		CUTInputOrderField *task_data = new CUTInputOrderField();
		*task_data = *pInputOrder;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspOrderAction(CUTInputOrderActionField *pInputOrderAction, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPORDERACTION;
	if (pInputOrderAction)
	{
		CUTInputOrderActionField *task_data = new CUTInputOrderActionField();
		*task_data = *pInputOrderAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspLogin(CUTRspLoginField *pRspLogin, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPLOGIN;
	if (pRspLogin)
	{
		CUTRspLoginField *task_data = new CUTRspLoginField();
		*task_data = *pRspLogin;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspUserPasswordUpdate(CUTUserPasswordUpdateField *pUserPasswordUpdate, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPUSERPASSWORDUPDATE;
	if (pUserPasswordUpdate)
	{
		CUTUserPasswordUpdateField *task_data = new CUTUserPasswordUpdateField();
		*task_data = *pUserPasswordUpdate;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspTransferInsert(CUTInputTransferField *pInputTransfer, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPTRANSFERINSERT;
	if (pInputTransfer)
	{
		CUTInputTransferField *task_data = new CUTInputTransferField();
		*task_data = *pInputTransfer;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRtnTransfer(CUTTransferField *pTransfer) 
{
	Task task = Task();
	task.task_name = ONRTNTRANSFER;
	if (pTransfer)
	{
		CUTTransferField *task_data = new CUTTransferField();
		*task_data = *pTransfer;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspFundPaybackInsert(CUTInputFundPaybackField *pInputFundPayback, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPFUNDPAYBACKINSERT;
	if (pInputFundPayback)
	{
		CUTInputFundPaybackField *task_data = new CUTInputFundPaybackField();
		*task_data = *pInputFundPayback;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRtnFundPayback(CUTFundPaybackField *pFundPayback) 
{
	Task task = Task();
	task.task_name = ONRTNFUNDPAYBACK;
	if (pFundPayback)
	{
		CUTFundPaybackField *task_data = new CUTFundPaybackField();
		*task_data = *pFundPayback;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspStockPaybackInsert(CUTInputStockPaybackField *pInputStockPayback, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPSTOCKPAYBACKINSERT;
	if (pInputStockPayback)
	{
		CUTInputStockPaybackField *task_data = new CUTInputStockPaybackField();
		*task_data = *pInputStockPayback;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRtnStockPayback(CUTStockPaybackField *pStockPayback) 
{
	Task task = Task();
	task.task_name = ONRTNSTOCKPAYBACK;
	if (pStockPayback)
	{
		CUTStockPaybackField *task_data = new CUTStockPaybackField();
		*task_data = *pStockPayback;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnPrivateCreditStock(CUTPrivateCreditStockField *pPrivateCreditStock) 
{
	Task task = Task();
	task.task_name = ONRTNPRIVATECREDITSTOCK;
	if (pPrivateCreditStock)
	{
		CUTPrivateCreditStockField *task_data = new CUTPrivateCreditStockField();
		*task_data = *pPrivateCreditStock;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnLock(CUTLockField *pLock) 
{
	Task task = Task();
	task.task_name = ONRTNLOCK;
	if (pLock)
	{
		CUTLockField *task_data = new CUTLockField();
		*task_data = *pLock;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspLockInsert(CUTInputLockField *pInputLock, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPLOCKINSERT;
	if (pInputLock)
	{
		CUTInputLockField *task_data = new CUTInputLockField();
		*task_data = *pInputLock;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRtnExecOrder(CUTExecOrderField *pExecOrder) 
{
	Task task = Task();
	task.task_name = ONRTNEXECORDER;
	if (pExecOrder)
	{
		CUTExecOrderField *task_data = new CUTExecOrderField();
		*task_data = *pExecOrder;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspExecOrderInsert(CUTInputExecOrderField *pInputExecOrder, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPEXECORDERINSERT;
	if (pInputExecOrder)
	{
		CUTInputExecOrderField *task_data = new CUTInputExecOrderField();
		*task_data = *pInputExecOrder;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspExecOrderAction(CUTInputExecOrderActionField *pInputExecOrderAction, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPEXECORDERACTION;
	if (pInputExecOrderAction)
	{
		CUTInputExecOrderActionField *task_data = new CUTInputExecOrderActionField();
		*task_data = *pInputExecOrderAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnErrRtnExecOrderAction(CUTExecOrderActionField *pExecOrderAction) 
{
	Task task = Task();
	task.task_name = ONERRRTNEXECORDERACTION;
	if (pExecOrderAction)
	{
		CUTExecOrderActionField *task_data = new CUTExecOrderActionField();
		*task_data = *pExecOrderAction;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryInstrument(CUTInstrumentField *pInstrument, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYINSTRUMENT;
	if (pInstrument)
	{
		CUTInstrumentField *task_data = new CUTInstrumentField();
		*task_data = *pInstrument;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryDepthMarketData(CUTDepthMarketDataField *pDepthMarketData, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYDEPTHMARKETDATA;
	if (pDepthMarketData)
	{
		CUTDepthMarketDataField *task_data = new CUTDepthMarketDataField();
		*task_data = *pDepthMarketData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryInvestorPosition(CUTInvestorPositionField *pInvestorPosition, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYINVESTORPOSITION;
	if (pInvestorPosition)
	{
		CUTInvestorPositionField *task_data = new CUTInvestorPositionField();
		*task_data = *pInvestorPosition;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryTradingAccount(CUTTradingAccountField *pTradingAccount, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYTRADINGACCOUNT;
	if (pTradingAccount)
	{
		CUTTradingAccountField *task_data = new CUTTradingAccountField();
		*task_data = *pTradingAccount;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryOptionInstrMarginByVolume(CUTOptionInstrMarginByVolumeField *pOptionInstrMarginByVolume, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYOPTIONINSTRMARGINBYVOLUME;
	if (pOptionInstrMarginByVolume)
	{
		CUTOptionInstrMarginByVolumeField *task_data = new CUTOptionInstrMarginByVolumeField();
		*task_data = *pOptionInstrMarginByVolume;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryOptionInstrCommRate(CUTOptionInstrCommRateField *pOptionInstrCommRate, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYOPTIONINSTRCOMMRATE;
	if (pOptionInstrCommRate)
	{
		CUTOptionInstrCommRateField *task_data = new CUTOptionInstrCommRateField();
		*task_data = *pOptionInstrCommRate;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryOrder(CUTOrderField *pOrder, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYORDER;
	if (pOrder)
	{
		CUTOrderField *task_data = new CUTOrderField();
		*task_data = *pOrder;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryTrade(CUTTradeField *pTrade, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYTRADE;
	if (pTrade)
	{
		CUTTradeField *task_data = new CUTTradeField();
		*task_data = *pTrade;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryInstrumentCommissionRate(CUTInstrumentCommissionRateField *pInstrumentCommissionRate, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYINSTRUMENTCOMMISSIONRATE;
	if (pInstrumentCommissionRate)
	{
		CUTInstrumentCommissionRateField *task_data = new CUTInstrumentCommissionRateField();
		*task_data = *pInstrumentCommissionRate;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryInvestor(CUTInvestorField *pInvestor, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYINVESTOR;
	if (pInvestor)
	{
		CUTInvestorField *task_data = new CUTInvestorField();
		*task_data = *pInvestor;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryTransfer(CUTTransferField *pTransfer, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYTRANSFER;
	if (pTransfer)
	{
		CUTTransferField *task_data = new CUTTransferField();
		*task_data = *pTransfer;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryTradingCode(CUTTradingCodeField *pTradingCode, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYTRADINGCODE;
	if (pTradingCode)
	{
		CUTTradingCodeField *task_data = new CUTTradingCodeField();
		*task_data = *pTradingCode;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryMaxOrderVolume(CUTMaxOrderVolumeField *pMaxOrderVolume, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYMAXORDERVOLUME;
	if (pMaxOrderVolume)
	{
		CUTMaxOrderVolumeField *task_data = new CUTMaxOrderVolumeField();
		*task_data = *pMaxOrderVolume;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryCreditInstrument(CUTCreditInstrumentField *pCreditInstrument, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYCREDITINSTRUMENT;
	if (pCreditInstrument)
	{
		CUTCreditInstrumentField *task_data = new CUTCreditInstrumentField();
		*task_data = *pCreditInstrument;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryCreditInvestor(CUTCreditInvestorField *pCreditInvestor, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYCREDITINVESTOR;
	if (pCreditInvestor)
	{
		CUTCreditInvestorField *task_data = new CUTCreditInvestorField();
		*task_data = *pCreditInvestor;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryPrivateCreditStock(CUTPrivateCreditStockField *pPrivateCreditStock, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYPRIVATECREDITSTOCK;
	if (pPrivateCreditStock)
	{
		CUTPrivateCreditStockField *task_data = new CUTPrivateCreditStockField();
		*task_data = *pPrivateCreditStock;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryCreditConcentration(CUTCreditConcentrationField *pCreditConcentration, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYCREDITCONCENTRATION;
	if (pCreditConcentration)
	{
		CUTCreditConcentrationField *task_data = new CUTCreditConcentrationField();
		*task_data = *pCreditConcentration;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryCreditFundDetail(CUTCreditFundDetailField *pCreditFundDetail, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYCREDITFUNDDETAIL;
	if (pCreditFundDetail)
	{
		CUTCreditFundDetailField *task_data = new CUTCreditFundDetailField();
		*task_data = *pCreditFundDetail;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryCreditStockDetail(CUTCreditStockDetailField *pCreditStockDetail, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYCREDITSTOCKDETAIL;
	if (pCreditStockDetail)
	{
		CUTCreditStockDetailField *task_data = new CUTCreditStockDetailField();
		*task_data = *pCreditStockDetail;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryFundPayback(CUTFundPaybackField *pFundPayback, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYFUNDPAYBACK;
	if (pFundPayback)
	{
		CUTFundPaybackField *task_data = new CUTFundPaybackField();
		*task_data = *pFundPayback;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryStockPayback(CUTStockPaybackField *pStockPayback, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYSTOCKPAYBACK;
	if (pStockPayback)
	{
		CUTStockPaybackField *task_data = new CUTStockPaybackField();
		*task_data = *pStockPayback;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryPublicCreditFund(CUTPublicCreditFundField *pPublicCreditFund, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYPUBLICCREDITFUND;
	if (pPublicCreditFund)
	{
		CUTPublicCreditFundField *task_data = new CUTPublicCreditFundField();
		*task_data = *pPublicCreditFund;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryETFInfo(CUTETFInfoField *pETFInfo, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYETFINFO;
	if (pETFInfo)
	{
		CUTETFInfoField *task_data = new CUTETFInfoField();
		*task_data = *pETFInfo;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryETFComponent(CUTETFComponentField *pETFComponent, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYETFCOMPONENT;
	if (pETFComponent)
	{
		CUTETFComponentField *task_data = new CUTETFComponentField();
		*task_data = *pETFComponent;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryCreditAvailableDetail(CUTCreditAvailableDetailField *pCreditAvailableDetail, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYCREDITAVAILABLEDETAIL;
	if (pCreditAvailableDetail)
	{
		CUTCreditAvailableDetailField *task_data = new CUTCreditAvailableDetailField();
		*task_data = *pCreditAvailableDetail;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryLock(CUTLockField *pLock, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYLOCK;
	if (pLock)
	{
		CUTLockField *task_data = new CUTLockField();
		*task_data = *pLock;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryExecOrder(CUTExecOrderField *pExecOrder, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYEXECORDER;
	if (pExecOrder)
	{
		CUTExecOrderField *task_data = new CUTExecOrderField();
		*task_data = *pExecOrder;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryLockPosition(CUTLockPositionField *pLockPosition, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYLOCKPOSITION;
	if (pLockPosition)
	{
		CUTLockPositionField *task_data = new CUTLockPositionField();
		*task_data = *pLockPosition;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryOptPosiLimit(CUTOptPosiLimitField *pOptPosiLimit, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYOPTPOSILIMIT;
	if (pOptPosiLimit)
	{
		CUTOptPosiLimitField *task_data = new CUTOptPosiLimitField();
		*task_data = *pOptPosiLimit;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryOptAmountLimit(CUTOptAmountLimitField *pOptAmountLimit, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	Task task = Task();
	task.task_name = ONRSPQRYOPTAMOUNTLIMIT;
	if (pOptAmountLimit)
	{
		CUTOptAmountLimitField *task_data = new CUTOptAmountLimitField();
		*task_data = *pOptAmountLimit;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CUTRspInfoField *task_error = new CUTRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

