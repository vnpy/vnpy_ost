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

