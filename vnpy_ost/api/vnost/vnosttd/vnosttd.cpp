// vnosttd.cpp : 定义 DLL 应用程序的导出函数。
//

#include "vnosttd.h"


///-------------------------------------------------------------------------------------
///C++的回调函数将数据保存到队列中
///-------------------------------------------------------------------------------------

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

///-------------------------------------------------------------------------------------
///工作线程从队列中取出数据，转化为python对象后，进行推送
///-------------------------------------------------------------------------------------

void TdApi::processTask()
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

			case ONFRONTDISCONNECTED:
			{
				this->processFrontDisconnected(&task);
				break;
			}

			case ONRSPERROR:
			{
				this->processRspError(&task);
				break;
			}

			case ONRTNORDER:
			{
				this->processRtnOrder(&task);
				break;
			}

			case ONRTNTRADE:
			{
				this->processRtnTrade(&task);
				break;
			}

			case ONERRRTNORDERACTION:
			{
				this->processErrRtnOrderAction(&task);
				break;
			}

			case ONRSPORDERINSERT:
			{
				this->processRspOrderInsert(&task);
				break;
			}

			case ONRSPORDERACTION:
			{
				this->processRspOrderAction(&task);
				break;
			}

			case ONRSPLOGIN:
			{
				this->processRspLogin(&task);
				break;
			}

			case ONRSPUSERPASSWORDUPDATE:
			{
				this->processRspUserPasswordUpdate(&task);
				break;
			}

			case ONRSPTRANSFERINSERT:
			{
				this->processRspTransferInsert(&task);
				break;
			}

			case ONRTNTRANSFER:
			{
				this->processRtnTransfer(&task);
				break;
			}

			case ONRSPFUNDPAYBACKINSERT:
			{
				this->processRspFundPaybackInsert(&task);
				break;
			}

			case ONRTNFUNDPAYBACK:
			{
				this->processRtnFundPayback(&task);
				break;
			}

			case ONRSPSTOCKPAYBACKINSERT:
			{
				this->processRspStockPaybackInsert(&task);
				break;
			}

			case ONRTNSTOCKPAYBACK:
			{
				this->processRtnStockPayback(&task);
				break;
			}

			case ONRTNPRIVATECREDITSTOCK:
			{
				this->processRtnPrivateCreditStock(&task);
				break;
			}

			case ONRTNLOCK:
			{
				this->processRtnLock(&task);
				break;
			}

			case ONRSPLOCKINSERT:
			{
				this->processRspLockInsert(&task);
				break;
			}

			case ONRTNEXECORDER:
			{
				this->processRtnExecOrder(&task);
				break;
			}

			case ONRSPEXECORDERINSERT:
			{
				this->processRspExecOrderInsert(&task);
				break;
			}

			case ONRSPEXECORDERACTION:
			{
				this->processRspExecOrderAction(&task);
				break;
			}

			case ONERRRTNEXECORDERACTION:
			{
				this->processErrRtnExecOrderAction(&task);
				break;
			}

			case ONRSPQRYINSTRUMENT:
			{
				this->processRspQryInstrument(&task);
				break;
			}

			case ONRSPQRYDEPTHMARKETDATA:
			{
				this->processRspQryDepthMarketData(&task);
				break;
			}

			case ONRSPQRYINVESTORPOSITION:
			{
				this->processRspQryInvestorPosition(&task);
				break;
			}

			case ONRSPQRYTRADINGACCOUNT:
			{
				this->processRspQryTradingAccount(&task);
				break;
			}

			case ONRSPQRYOPTIONINSTRMARGINBYVOLUME:
			{
				this->processRspQryOptionInstrMarginByVolume(&task);
				break;
			}

			case ONRSPQRYOPTIONINSTRCOMMRATE:
			{
				this->processRspQryOptionInstrCommRate(&task);
				break;
			}

			case ONRSPQRYORDER:
			{
				this->processRspQryOrder(&task);
				break;
			}

			case ONRSPQRYTRADE:
			{
				this->processRspQryTrade(&task);
				break;
			}

			case ONRSPQRYINSTRUMENTCOMMISSIONRATE:
			{
				this->processRspQryInstrumentCommissionRate(&task);
				break;
			}

			case ONRSPQRYINVESTOR:
			{
				this->processRspQryInvestor(&task);
				break;
			}

			case ONRSPQRYTRANSFER:
			{
				this->processRspQryTransfer(&task);
				break;
			}

			case ONRSPQRYTRADINGCODE:
			{
				this->processRspQryTradingCode(&task);
				break;
			}

			case ONRSPQRYMAXORDERVOLUME:
			{
				this->processRspQryMaxOrderVolume(&task);
				break;
			}

			case ONRSPQRYCREDITINSTRUMENT:
			{
				this->processRspQryCreditInstrument(&task);
				break;
			}

			case ONRSPQRYCREDITINVESTOR:
			{
				this->processRspQryCreditInvestor(&task);
				break;
			}

			case ONRSPQRYPRIVATECREDITSTOCK:
			{
				this->processRspQryPrivateCreditStock(&task);
				break;
			}

			case ONRSPQRYCREDITCONCENTRATION:
			{
				this->processRspQryCreditConcentration(&task);
				break;
			}

			case ONRSPQRYCREDITFUNDDETAIL:
			{
				this->processRspQryCreditFundDetail(&task);
				break;
			}

			case ONRSPQRYCREDITSTOCKDETAIL:
			{
				this->processRspQryCreditStockDetail(&task);
				break;
			}

			case ONRSPQRYFUNDPAYBACK:
			{
				this->processRspQryFundPayback(&task);
				break;
			}

			case ONRSPQRYSTOCKPAYBACK:
			{
				this->processRspQryStockPayback(&task);
				break;
			}

			case ONRSPQRYPUBLICCREDITFUND:
			{
				this->processRspQryPublicCreditFund(&task);
				break;
			}

			case ONRSPQRYETFINFO:
			{
				this->processRspQryETFInfo(&task);
				break;
			}

			case ONRSPQRYETFCOMPONENT:
			{
				this->processRspQryETFComponent(&task);
				break;
			}

			case ONRSPQRYCREDITAVAILABLEDETAIL:
			{
				this->processRspQryCreditAvailableDetail(&task);
				break;
			}

			case ONRSPQRYLOCK:
			{
				this->processRspQryLock(&task);
				break;
			}

			case ONRSPQRYEXECORDER:
			{
				this->processRspQryExecOrder(&task);
				break;
			}

			case ONRSPQRYLOCKPOSITION:
			{
				this->processRspQryLockPosition(&task);
				break;
			}

			case ONRSPQRYOPTPOSILIMIT:
			{
				this->processRspQryOptPosiLimit(&task);
				break;
			}

			case ONRSPQRYOPTAMOUNTLIMIT:
			{
				this->processRspQryOptAmountLimit(&task);
				break;
			}
			};
		}
	}
	catch (const TerminatedError&)
	{
	}
};

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

///-------------------------------------------------------------------------------------
///主动函数
///-------------------------------------------------------------------------------------\

void TdApi::createApi(string pszFlowPath, int nCPUID)
{
	this->api = CUTApi::CreateApi(pszFlowPath.c_str(), nCPUID);
	this->api->RegisterSpi(this);
};

void TdApi::release()
{
	this->api->Release();
};

void TdApi::init()
{
	this->active = true;
	this->task_thread = thread(&TdApi::processTask, this);

	this->api->Init();
};

int TdApi::join()
{
	int i = this->api->Join();
	return i;
};

int TdApi::exit()
{
	this->active = false;
	this->task_queue.terminate();
	this->task_thread.join();

	this->api->RegisterSpi(NULL);
	this->api->Release();
	this->api = NULL;
	return 1;
};

string TdApi::getApiVersion()
{
	string version = this->api->GetApiVersion();
	return version;
};

void TdApi::registerFront(string pszFrontAddress)
{
	this->api->RegisterFront((char*)pszFrontAddress.c_str());
};

void TdApi::subscribePrivateTopic(int nResumeType)
{
	this->api->SubscribePrivateTopic((UT_TE_RESUME_TYPE)nResumeType);
};

void TdApi::subscribePublicTopic(int nResumeType)
{
	this->api->SubscribePublicTopic((UT_TE_RESUME_TYPE)nResumeType);
};

void TdApi::submitTerminalInfo(const dict &req)
{
	CUTSubmitTerminalInfoField myreq = CUTSubmitTerminalInfoField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "UserID", myreq.UserID);
	getLonglong(req, "LoginSeq", &myreq.LoginSeq);
	getString(req, "TerminalInfo", myreq.TerminalInfo);
	this->api->SubmitTerminalInfo(&myreq);
};