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

int TdApi::reqOrderInsert(const dict &req, int reqid)
{
	CUTInputOrderField myreq = CUTInputOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getInt(req, "OrderRef", &myreq.OrderRef);
	getChar(req, "Direction", &myreq.Direction);
	getChar(req, "OffsetFlag", &myreq.OffsetFlag);
	getChar(req, "HedgeFlag", &myreq.HedgeFlag);
	getChar(req, "OrderPriceType", &myreq.OrderPriceType);
	getInt(req, "VolumeTotalOriginal", &myreq.VolumeTotalOriginal);
	getDouble(req, "LimitPrice", &myreq.LimitPrice);
	getChar(req, "TimeCondition", &myreq.TimeCondition);
	getChar(req, "VolumeCondition", &myreq.VolumeCondition);
	getChar(req, "ContingentCondition", &myreq.ContingentCondition);
	getInt(req, "GTDDate", &myreq.GTDDate);
	getInt(req, "MinVolume", &myreq.MinVolume);
	getShort(req, "IsAutoSuspend", &myreq.IsAutoSuspend);
	getShort(req, "UserForceClose", &myreq.UserForceClose);
	getDouble(req, "StopPrice", &myreq.StopPrice);
	getShort(req, "IsSwapOrder", &myreq.IsSwapOrder);
	getInt(req, "IPAddressAsInt", &myreq.IPAddressAsInt);
	getLonglong(req, "MacAddressAsLong", &myreq.MacAddressAsLong);
	int i = this->api->ReqOrderInsert(&myreq, reqid);
	return i;
};

int TdApi::reqOrderAction(const dict &req, int reqid)
{
	CUTInputOrderActionField myreq = CUTInputOrderActionField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "OrderActionRef", &myreq.OrderActionRef);
	getInt(req, "FrontID", &myreq.FrontID);
	getLonglong(req, "SessionID", &myreq.SessionID);
	getInt(req, "OrderRef", &myreq.OrderRef);
	getChar(req, "ActionFlag", &myreq.ActionFlag);
	getDouble(req, "LimitPrice", &myreq.LimitPrice);
	getInt(req, "VolumeChange", &myreq.VolumeChange);
	getInt(req, "IPAddressAsInt", &myreq.IPAddressAsInt);
	getLonglong(req, "MacAddressAsLong", &myreq.MacAddressAsLong);
	int i = this->api->ReqOrderAction(&myreq, reqid);
	return i;
};

int TdApi::reqLogin(const dict &req, int reqid)
{
	CUTReqLoginField myreq = CUTReqLoginField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "UserID", myreq.UserID);
	getString(req, "Password", myreq.Password);
	getString(req, "UserProductInfo", myreq.UserProductInfo);
	getString(req, "UserProductPassword", myreq.UserProductPassword);
	getString(req, "OneTimePassword", myreq.OneTimePassword);
	getString(req, "LoginRemark", myreq.LoginRemark);
	int i = this->api->ReqLogin(&myreq, reqid);
	return i;
};

int TdApi::reqLogout(const dict &req, int reqid)
{
	CUTReqLogoutField myreq = CUTReqLogoutField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "UserID", myreq.UserID);
	int i = this->api->ReqLogout(&myreq, reqid);
	return i;
};

int TdApi::reqUserPasswordUpdate(const dict &req, int reqid)
{
	CUTUserPasswordUpdateField myreq = CUTUserPasswordUpdateField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "UserID", myreq.UserID);
	getString(req, "OldPassword", myreq.OldPassword);
	getString(req, "NewPassword", myreq.NewPassword);
	int i = this->api->ReqUserPasswordUpdate(&myreq, reqid);
	return i;
};

int TdApi::reqTransferInsert(const dict &req, int reqid)
{
	CUTInputTransferField myreq = CUTInputTransferField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getInt(req, "TransferRef", &myreq.TransferRef);
	getChar(req, "TransferType", &myreq.TransferType);
	getDouble(req, "Deposit", &myreq.Deposit);
	getString(req, "CurrencyID", myreq.CurrencyID);
	getChar(req, "AccType", &myreq.AccType);
	getString(req, "BankID", myreq.BankID);
	getString(req, "FundPassword", myreq.FundPassword);
	getString(req, "BankPassword", myreq.BankPassword);
	int i = this->api->ReqTransferInsert(&myreq, reqid);
	return i;
};

int TdApi::reqFundPaybackInsert(const dict &req, int reqid)
{
	CUTInputFundPaybackField myreq = CUTInputFundPaybackField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "CurrencyID", myreq.CurrencyID);
	getInt(req, "FundPaybackRef", &myreq.FundPaybackRef);
	getDouble(req, "Amount", &myreq.Amount);
	getInt(req, "IPAddressAsInt", &myreq.IPAddressAsInt);
	getLonglong(req, "MacAddressAsLong", &myreq.MacAddressAsLong);
	int i = this->api->ReqFundPaybackInsert(&myreq, reqid);
	return i;
};

int TdApi::reqStockPaybackInsert(const dict &req, int reqid)
{
	CUTInputStockPaybackField myreq = CUTInputStockPaybackField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getInt(req, "StockPaybackRef", &myreq.StockPaybackRef);
	getLonglong(req, "Volume", &myreq.Volume);
	getInt(req, "IPAddressAsInt", &myreq.IPAddressAsInt);
	getLonglong(req, "MacAddressAsLong", &myreq.MacAddressAsLong);
	int i = this->api->ReqStockPaybackInsert(&myreq, reqid);
	return i;
};

int TdApi::reqLockInsert(const dict &req, int reqid)
{
	CUTInputLockField myreq = CUTInputLockField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getInt(req, "LockRef", &myreq.LockRef);
	getInt(req, "Volume", &myreq.Volume);
	getChar(req, "LockType", &myreq.LockType);
	getInt(req, "IPAddressAsInt", &myreq.IPAddressAsInt);
	getLonglong(req, "MacAddressAsLong", &myreq.MacAddressAsLong);
	int i = this->api->ReqLockInsert(&myreq, reqid);
	return i;
};

int TdApi::reqExecOrderInsert(const dict &req, int reqid)
{
	CUTInputExecOrderField myreq = CUTInputExecOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getInt(req, "ExecOrderRef", &myreq.ExecOrderRef);
	getInt(req, "Volume", &myreq.Volume);
	getInt(req, "IPAddressAsInt", &myreq.IPAddressAsInt);
	getLonglong(req, "MacAddressAsLong", &myreq.MacAddressAsLong);
	int i = this->api->ReqExecOrderInsert(&myreq, reqid);
	return i;
};

int TdApi::reqExecOrderAction(const dict &req, int reqid)
{
	CUTInputExecOrderActionField myreq = CUTInputExecOrderActionField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "ExecOrderActionRef", &myreq.ExecOrderActionRef);
	getInt(req, "FrontID", &myreq.FrontID);
	getLonglong(req, "SessionID", &myreq.SessionID);
	getInt(req, "ExecOrderRef", &myreq.ExecOrderRef);
	getInt(req, "IPAddressAsInt", &myreq.IPAddressAsInt);
	getLonglong(req, "MacAddressAsLong", &myreq.MacAddressAsLong);
	int i = this->api->ReqExecOrderAction(&myreq, reqid);
	return i;
};

int TdApi::reqQryInstrument(const dict &req, int reqid)
{
	CUTQryInstrumentField myreq = CUTQryInstrumentField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryInstrument(&myreq, reqid);
	return i;
};

int TdApi::reqQryDepthMarketData(const dict &req, int reqid)
{
	CUTQryDepthMarketDataField myreq = CUTQryDepthMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryDepthMarketData(&myreq, reqid);
	return i;
};

int TdApi::reqQryInvestorPosition(const dict &req, int reqid)
{
	CUTQryInvestorPositionField myreq = CUTQryInvestorPositionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryInvestorPosition(&myreq, reqid);
	return i;
};

int TdApi::reqQryTradingAccount(const dict &req, int reqid)
{
	CUTQryTradingAccountField myreq = CUTQryTradingAccountField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "CurrencyID", myreq.CurrencyID);
	getChar(req, "AccType", &myreq.AccType);
	int i = this->api->ReqQryTradingAccount(&myreq, reqid);
	return i;
};

int TdApi::reqQryOrder(const dict &req, int reqid)
{
	CUTQryOrderField myreq = CUTQryOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getLonglong(req, "SequenceNo", &myreq.SequenceNo);
	getInt(req, "Limit", &myreq.Limit);
	getChar(req, "OrderStatus", &myreq.OrderStatus);
	int i = this->api->ReqQryOrder(&myreq, reqid);
	return i;
};

int TdApi::reqQryTrade(const dict &req, int reqid)
{
	CUTQryTradeField myreq = CUTQryTradeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getLonglong(req, "SequenceNo", &myreq.SequenceNo);
	getInt(req, "Limit", &myreq.Limit);
	int i = this->api->ReqQryTrade(&myreq, reqid);
	return i;
};

int TdApi::reqQryOptionInstrMarginByVolume(const dict &req, int reqid)
{
	CUTQryOptionInstrMarginByVolumeField myreq = CUTQryOptionInstrMarginByVolumeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryOptionInstrMarginByVolume(&myreq, reqid);
	return i;
};

int TdApi::reqQryOptionInstrCommRate(const dict &req, int reqid)
{
	CUTQryOptionInstrCommRateField myreq = CUTQryOptionInstrCommRateField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryOptionInstrCommRate(&myreq, reqid);
	return i;
};

int TdApi::reqQryInstrumentCommissionRate(const dict &req, int reqid)
{
	CUTQryInstrumentCommissionRateField myreq = CUTQryInstrumentCommissionRateField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryInstrumentCommissionRate(&myreq, reqid);
	return i;
};

int TdApi::reqQryInvestor(const dict &req, int reqid)
{
	CUTQryInvestorField myreq = CUTQryInvestorField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	int i = this->api->ReqQryInvestor(&myreq, reqid);
	return i;
};

int TdApi::reqQryTransfer(const dict &req, int reqid)
{
	CUTQryTransferField myreq = CUTQryTransferField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	int i = this->api->ReqQryTransfer(&myreq, reqid);
	return i;
};

int TdApi::reqQryTradingCode(const dict &req, int reqid)
{
	CUTQryTradingCodeField myreq = CUTQryTradingCodeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	int i = this->api->ReqQryTradingCode(&myreq, reqid);
	return i;
};

int TdApi::reqQryMaxOrderVolume(const dict &req, int reqid)
{
	CUTQryMaxOrderVolumeField myreq = CUTQryMaxOrderVolumeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getChar(req, "HedgeFlag", &myreq.HedgeFlag);
	getChar(req, "Direction", &myreq.Direction);
	getChar(req, "OffsetFlag", &myreq.OffsetFlag);
	getDouble(req, "Price", &myreq.Price);
	int i = this->api->ReqQryMaxOrderVolume(&myreq, reqid);
	return i;
};

int TdApi::reqQryCreditInstrument(const dict &req, int reqid)
{
	CUTQryCreditInstrumentField myreq = CUTQryCreditInstrumentField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryCreditInstrument(&myreq, reqid);
	return i;
};

int TdApi::reqQryCreditInvestor(const dict &req, int reqid)
{
	CUTQryCreditInvestorField myreq = CUTQryCreditInvestorField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	int i = this->api->ReqQryCreditInvestor(&myreq, reqid);
	return i;
};

int TdApi::reqQryPrivateCreditStock(const dict &req, int reqid)
{
	CUTQryPrivateCreditStockField myreq = CUTQryPrivateCreditStockField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	int i = this->api->ReqQryPrivateCreditStock(&myreq, reqid);
	return i;
};

int TdApi::reqQryCreditConcentration(const dict &req, int reqid)
{
	CUTQryCreditConcentrationField myreq = CUTQryCreditConcentrationField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	int i = this->api->ReqQryCreditConcentration(&myreq, reqid);
	return i;
};

int TdApi::reqQryCreditFundDetail(const dict &req, int reqid)
{
	CUTQryCreditFundDetailField myreq = CUTQryCreditFundDetailField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	int i = this->api->ReqQryCreditFundDetail(&myreq, reqid);
	return i;
};

int TdApi::reqQryCreditStockDetail(const dict &req, int reqid)
{
	CUTQryCreditStockDetailField myreq = CUTQryCreditStockDetailField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	int i = this->api->ReqQryCreditStockDetail(&myreq, reqid);
	return i;
};

int TdApi::reqQryFundPayback(const dict &req, int reqid)
{
	CUTQryFundPaybackField myreq = CUTQryFundPaybackField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	int i = this->api->ReqQryFundPayback(&myreq, reqid);
	return i;
};

int TdApi::reqQryStockPayback(const dict &req, int reqid)
{
	CUTQryStockPaybackField myreq = CUTQryStockPaybackField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	int i = this->api->ReqQryStockPayback(&myreq, reqid);
	return i;
};

int TdApi::reqQryPublicCreditFund(const dict &req, int reqid)
{
	CUTQryPublicCreditFundField myreq = CUTQryPublicCreditFundField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "Time", &myreq.Time);
	int i = this->api->ReqQryPublicCreditFund(&myreq, reqid);
	return i;
};

int TdApi::reqQryETFInfo(const dict &req, int reqid)
{
	CUTQryETFInfoField myreq = CUTQryETFInfoField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryETFInfo(&myreq, reqid);
	return i;
};

int TdApi::reqQryETFComponent(const dict &req, int reqid)
{
	CUTQryETFComponentField myreq = CUTQryETFComponentField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "ETFID", myreq.ETFID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryETFComponent(&myreq, reqid);
	return i;
};

int TdApi::reqQryCreditAvailableDetail(const dict &req, int reqid)
{
	CUTQryCreditAvailableDetailField myreq = CUTQryCreditAvailableDetailField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountID", myreq.AccountID);
	int i = this->api->ReqQryCreditAvailableDetail(&myreq, reqid);
	return i;
};

int TdApi::reqQryLock(const dict &req, int reqid)
{
	CUTQryLockField myreq = CUTQryLockField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	int i = this->api->ReqQryLock(&myreq, reqid);
	return i;
};

int TdApi::reqQryExecOrder(const dict &req, int reqid)
{
	CUTQryExecOrderField myreq = CUTQryExecOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryExecOrder(&myreq, reqid);
	return i;
};

int TdApi::reqQryLockPosition(const dict &req, int reqid)
{
	CUTQryLockPositionField myreq = CUTQryLockPositionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	int i = this->api->ReqQryLockPosition(&myreq, reqid);
	return i;
};

int TdApi::reqQryOptPosiLimit(const dict &req, int reqid)
{
	CUTQryOptPosiLimitField myreq = CUTQryOptPosiLimitField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	int i = this->api->ReqQryOptPosiLimit(&myreq, reqid);
	return i;
};

int TdApi::reqQryOptAmountLimit(const dict &req, int reqid)
{
	CUTQryOptAmountLimitField myreq = CUTQryOptAmountLimitField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	int i = this->api->ReqQryOptAmountLimit(&myreq, reqid);
	return i;
};


///-------------------------------------------------------------------------------------
///Boost.Python封装
///-------------------------------------------------------------------------------------


class PyTdApi : public TdApi
{
public:
	using TdApi::TdApi;
	void onFrontConnected() override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onFrontConnected);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onFrontDisconnected(int reqid) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onFrontDisconnected, reqid);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspError(const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspError, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnOrder(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnOrder, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnTrade(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnTrade, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onErrRtnOrderAction(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onErrRtnOrderAction, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspOrderInsert(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspOrderInsert, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspOrderAction(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspOrderAction, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspLogin(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspLogin, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspUserPasswordUpdate(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspUserPasswordUpdate, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspTransferInsert(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspTransferInsert, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnTransfer(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnTransfer, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFundPaybackInsert(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFundPaybackInsert, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnFundPayback(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnFundPayback, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockPaybackInsert(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockPaybackInsert, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnStockPayback(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnStockPayback, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnPrivateCreditStock(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnPrivateCreditStock, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnLock(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnLock, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspLockInsert(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspLockInsert, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnExecOrder(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnExecOrder, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspExecOrderInsert(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspExecOrderInsert, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspExecOrderAction(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspExecOrderAction, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onErrRtnExecOrderAction(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onErrRtnExecOrderAction, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryInstrument(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryInstrument, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryDepthMarketData(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryDepthMarketData, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryInvestorPosition(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryInvestorPosition, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryTradingAccount(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryTradingAccount, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryOptionInstrMarginByVolume(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryOptionInstrMarginByVolume, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryOptionInstrCommRate(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryOptionInstrCommRate, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryOrder(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryOrder, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryTrade(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryTrade, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryInstrumentCommissionRate(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryInstrumentCommissionRate, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryInvestor(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryInvestor, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryTransfer(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryTransfer, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryTradingCode(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryTradingCode, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryMaxOrderVolume(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryMaxOrderVolume, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryCreditInstrument(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryCreditInstrument, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryCreditInvestor(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryCreditInvestor, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryPrivateCreditStock(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryPrivateCreditStock, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryCreditConcentration(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryCreditConcentration, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryCreditFundDetail(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryCreditFundDetail, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryCreditStockDetail(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryCreditStockDetail, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryFundPayback(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryFundPayback, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryStockPayback(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryStockPayback, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryPublicCreditFund(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryPublicCreditFund, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryETFInfo(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryETFInfo, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryETFComponent(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryETFComponent, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryCreditAvailableDetail(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryCreditAvailableDetail, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryLock(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryLock, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryExecOrder(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryExecOrder, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryLockPosition(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryLockPosition, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryOptPosiLimit(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryOptPosiLimit, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryOptAmountLimit(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryOptAmountLimit, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};
};

PYBIND11_MODULE(vnosttd, m)
{
	class_<TdApi, PyTdApi> TdApi(m, "TdApi", module_local());
	TdApi
		.def(init<>())
		.def("createApi", &TdApi::createApi)
		.def("release", &TdApi::release)
		.def("init", &TdApi::init)
		.def("join", &TdApi::join)
		.def("exit", &TdApi::exit)
		.def("getApiVersion", &TdApi::getApiVersion)
		.def("registerFront", &TdApi::registerFront)
		.def("subscribePrivateTopic", &TdApi::subscribePrivateTopic)
		.def("subscribePublicTopic", &TdApi::subscribePublicTopic)
		.def("submitTerminalInfo", &TdApi::submitTerminalInfo)
		
		.def("reqOrderInsert", &TdApi::reqOrderInsert)
		.def("reqOrderAction", &TdApi::reqOrderAction)
		.def("reqLogin", &TdApi::reqLogin)
		.def("reqLogout", &TdApi::reqLogout)
		.def("reqUserPasswordUpdate", &TdApi::reqUserPasswordUpdate)
		.def("reqTransferInsert", &TdApi::reqTransferInsert)
		.def("reqFundPaybackInsert", &TdApi::reqFundPaybackInsert)
		.def("reqStockPaybackInsert", &TdApi::reqStockPaybackInsert)
		.def("reqLockInsert", &TdApi::reqLockInsert)
		.def("reqExecOrderInsert", &TdApi::reqExecOrderInsert)
		.def("reqExecOrderAction", &TdApi::reqExecOrderAction)
		.def("reqQryInstrument", &TdApi::reqQryInstrument)
		.def("reqQryDepthMarketData", &TdApi::reqQryDepthMarketData)
		.def("reqQryInvestorPosition", &TdApi::reqQryInvestorPosition)
		.def("reqQryTradingAccount", &TdApi::reqQryTradingAccount)
		.def("reqQryOrder", &TdApi::reqQryOrder)
		.def("reqQryTrade", &TdApi::reqQryTrade)
		.def("reqQryOptionInstrMarginByVolume", &TdApi::reqQryOptionInstrMarginByVolume)
		.def("reqQryOptionInstrCommRate", &TdApi::reqQryOptionInstrCommRate)
		.def("reqQryInstrumentCommissionRate", &TdApi::reqQryInstrumentCommissionRate)
		.def("reqQryInvestor", &TdApi::reqQryInvestor)
		.def("reqQryTransfer", &TdApi::reqQryTransfer)
		.def("reqQryTradingCode", &TdApi::reqQryTradingCode)
		.def("reqQryMaxOrderVolume", &TdApi::reqQryMaxOrderVolume)
		.def("reqQryCreditInstrument", &TdApi::reqQryCreditInstrument)
		.def("reqQryCreditInvestor", &TdApi::reqQryCreditInvestor)
		.def("reqQryPrivateCreditStock", &TdApi::reqQryPrivateCreditStock)
		.def("reqQryCreditConcentration", &TdApi::reqQryCreditConcentration)
		.def("reqQryCreditFundDetail", &TdApi::reqQryCreditFundDetail)
		.def("reqQryCreditStockDetail", &TdApi::reqQryCreditStockDetail)
		.def("reqQryFundPayback", &TdApi::reqQryFundPayback)
		.def("reqQryStockPayback", &TdApi::reqQryStockPayback)
		.def("reqQryPublicCreditFund", &TdApi::reqQryPublicCreditFund)
		.def("reqQryETFInfo", &TdApi::reqQryETFInfo)
		.def("reqQryETFComponent", &TdApi::reqQryETFComponent)
		.def("reqQryCreditAvailableDetail", &TdApi::reqQryCreditAvailableDetail)
		.def("reqQryLock", &TdApi::reqQryLock)
		.def("reqQryExecOrder", &TdApi::reqQryExecOrder)
		.def("reqQryLockPosition", &TdApi::reqQryLockPosition)
		.def("reqQryOptPosiLimit", &TdApi::reqQryOptPosiLimit)
		.def("reqQryOptAmountLimit", &TdApi::reqQryOptAmountLimit)

		.def("onFrontConnected", &TdApi::onFrontConnected)
		.def("onFrontDisconnected", &TdApi::onFrontDisconnected)
		.def("onRspError", &TdApi::onRspError)
		.def("onRtnOrder", &TdApi::onRtnOrder)
		.def("onRtnTrade", &TdApi::onRtnTrade)
		.def("onErrRtnOrderAction", &TdApi::onErrRtnOrderAction)
		.def("onRspOrderInsert", &TdApi::onRspOrderInsert)
		.def("onRspOrderAction", &TdApi::onRspOrderAction)
		.def("onRspLogin", &TdApi::onRspLogin)
		.def("onRspUserPasswordUpdate", &TdApi::onRspUserPasswordUpdate)
		.def("onRspTransferInsert", &TdApi::onRspTransferInsert)
		.def("onRtnTransfer", &TdApi::onRtnTransfer)
		.def("onRspFundPaybackInsert", &TdApi::onRspFundPaybackInsert)
		.def("onRtnFundPayback", &TdApi::onRtnFundPayback)
		.def("onRspStockPaybackInsert", &TdApi::onRspStockPaybackInsert)
		.def("onRtnStockPayback", &TdApi::onRtnStockPayback)
		.def("onRtnPrivateCreditStock", &TdApi::onRtnPrivateCreditStock)
		.def("onRtnLock", &TdApi::onRtnLock)
		.def("onRspLockInsert", &TdApi::onRspLockInsert)
		.def("onRtnExecOrder", &TdApi::onRtnExecOrder)
		.def("onRspExecOrderInsert", &TdApi::onRspExecOrderInsert)
		.def("onRspExecOrderAction", &TdApi::onRspExecOrderAction)
		.def("onErrRtnExecOrderAction", &TdApi::onErrRtnExecOrderAction)
		.def("onRspQryInstrument", &TdApi::onRspQryInstrument)
		.def("onRspQryDepthMarketData", &TdApi::onRspQryDepthMarketData)
		.def("onRspQryInvestorPosition", &TdApi::onRspQryInvestorPosition)
		.def("onRspQryTradingAccount", &TdApi::onRspQryTradingAccount)
		.def("onRspQryOptionInstrMarginByVolume", &TdApi::onRspQryOptionInstrMarginByVolume)
		.def("onRspQryOptionInstrCommRate", &TdApi::onRspQryOptionInstrCommRate)
		.def("onRspQryOrder", &TdApi::onRspQryOrder)
		.def("onRspQryTrade", &TdApi::onRspQryTrade)
		.def("onRspQryInstrumentCommissionRate", &TdApi::onRspQryInstrumentCommissionRate)
		.def("onRspQryInvestor", &TdApi::onRspQryInvestor)
		.def("onRspQryTransfer", &TdApi::onRspQryTransfer)
		.def("onRspQryTradingCode", &TdApi::onRspQryTradingCode)
		.def("onRspQryMaxOrderVolume", &TdApi::onRspQryMaxOrderVolume)
		.def("onRspQryCreditInstrument", &TdApi::onRspQryCreditInstrument)
		.def("onRspQryCreditInvestor", &TdApi::onRspQryCreditInvestor)
		.def("onRspQryPrivateCreditStock", &TdApi::onRspQryPrivateCreditStock)
		.def("onRspQryCreditConcentration", &TdApi::onRspQryCreditConcentration)
		.def("onRspQryCreditFundDetail", &TdApi::onRspQryCreditFundDetail)
		.def("onRspQryCreditStockDetail", &TdApi::onRspQryCreditStockDetail)
		.def("onRspQryFundPayback", &TdApi::onRspQryFundPayback)
		.def("onRspQryStockPayback", &TdApi::onRspQryStockPayback)
		.def("onRspQryPublicCreditFund", &TdApi::onRspQryPublicCreditFund)
		.def("onRspQryETFInfo", &TdApi::onRspQryETFInfo)
		.def("onRspQryETFComponent", &TdApi::onRspQryETFComponent)
		.def("onRspQryCreditAvailableDetail", &TdApi::onRspQryCreditAvailableDetail)
		.def("onRspQryLock", &TdApi::onRspQryLock)
		.def("onRspQryExecOrder", &TdApi::onRspQryExecOrder)
		.def("onRspQryLockPosition", &TdApi::onRspQryLockPosition)
		.def("onRspQryOptPosiLimit", &TdApi::onRspQryOptPosiLimit)
		.def("onRspQryOptAmountLimit", &TdApi::onRspQryOptAmountLimit)
		;
}