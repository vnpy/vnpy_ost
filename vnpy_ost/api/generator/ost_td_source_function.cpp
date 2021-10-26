int TdApi::reqOrderInsert(const dict &req, int reqid)
{
	CUTInputOrderField myreq = CUTInputOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TUTInvestorIDType", myreq.TUTInvestorIDType);
	getChar(req, "TUTExchangeIDType", &myreq.TUTExchangeIDType);
	getString(req, "TUTInstrumentIDType", myreq.TUTInstrumentIDType);
	getInt(req, "TUTOrderRefType", &myreq.TUTOrderRefType);
	getChar(req, "TUTDirectionType", &myreq.TUTDirectionType);
	getChar(req, "TUTOffsetFlagType", &myreq.TUTOffsetFlagType);
	getChar(req, "TUTHedgeFlagType", &myreq.TUTHedgeFlagType);
	getChar(req, "TUTOrderPriceTypeType", &myreq.TUTOrderPriceTypeType);
	getInt(req, "TUTVolumeType", &myreq.TUTVolumeType);
	getDouble(req, "TUTPriceType", &myreq.TUTPriceType);
	getChar(req, "TUTTimeConditionType", &myreq.TUTTimeConditionType);
	getChar(req, "TUTVolumeConditionType", &myreq.TUTVolumeConditionType);
	getChar(req, "TUTContingentConditionType", &myreq.TUTContingentConditionType);
	getInt(req, "TUTDateType", &myreq.TUTDateType);
	getInt(req, "TUTBoolType", &myreq.TUTBoolType);
	getInt(req, "TUTIPAddressAsIntType", &myreq.TUTIPAddressAsIntType);
	getInt(req, "TUTMacAddressAsLongType", &myreq.TUTMacAddressAsLongType);
	int i = this->api->ReqOrderInsert(&myreq, reqid);
	return i;
};

int TdApi::reqOrderAction(const dict &req, int reqid)
{
	CUTInputOrderActionField myreq = CUTInputOrderActionField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "TUTOrderRefType", &myreq.TUTOrderRefType);
	getInt(req, "TUTFrontIDType", &myreq.TUTFrontIDType);
	getInt(req, "TUTSessionIDType", &myreq.TUTSessionIDType);
	getChar(req, "TUTActionFlagType", &myreq.TUTActionFlagType);
	getDouble(req, "TUTPriceType", &myreq.TUTPriceType);
	getInt(req, "TUTVolumeType", &myreq.TUTVolumeType);
	getInt(req, "TUTIPAddressAsIntType", &myreq.TUTIPAddressAsIntType);
	getInt(req, "TUTMacAddressAsLongType", &myreq.TUTMacAddressAsLongType);
	int i = this->api->ReqOrderAction(&myreq, reqid);
	return i;
};

int TdApi::reqLogin(const dict &req, int reqid)
{
	CUTReqLoginField myreq = CUTReqLoginField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TUTUserIDType", myreq.TUTUserIDType);
	getString(req, "TUTPasswordType", myreq.TUTPasswordType);
	getString(req, "TUTProductInfoType", myreq.TUTProductInfoType);
	getString(req, "TUTLoginRemarkType", myreq.TUTLoginRemarkType);
	int i = this->api->ReqLogin(&myreq, reqid);
	return i;
};

int TdApi::reqLogout(const dict &req, int reqid)
{
	CUTReqLogoutField myreq = CUTReqLogoutField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TUTUserIDType", myreq.TUTUserIDType);
	int i = this->api->ReqLogout(&myreq, reqid);
	return i;
};

int TdApi::reqUserPasswordUpdate(const dict &req, int reqid)
{
	CUTUserPasswordUpdateField myreq = CUTUserPasswordUpdateField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TUTUserIDType", myreq.TUTUserIDType);
	getString(req, "TUTPasswordType", myreq.TUTPasswordType);
	int i = this->api->ReqUserPasswordUpdate(&myreq, reqid);
	return i;
};

int TdApi::reqTransferInsert(const dict &req, int reqid)
{
	CUTInputTransferField myreq = CUTInputTransferField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TUTInvestorIDType", myreq.TUTInvestorIDType);
	getInt(req, "TUTOrderRefType", &myreq.TUTOrderRefType);
	getChar(req, "TUTTransferTypeType", &myreq.TUTTransferTypeType);
	getDouble(req, "TUTMoneyType", &myreq.TUTMoneyType);
	getString(req, "TUTCurrencyIDType", myreq.TUTCurrencyIDType);
	getChar(req, "TUTAccTypeType", &myreq.TUTAccTypeType);
	getString(req, "TUTBankIDType", myreq.TUTBankIDType);
	getString(req, "TUTPasswordType", myreq.TUTPasswordType);
	int i = this->api->ReqTransferInsert(&myreq, reqid);
	return i;
};

int TdApi::reqFundPaybackInsert(const dict &req, int reqid)
{
	CUTInputFundPaybackField myreq = CUTInputFundPaybackField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TUTInvestorIDType", myreq.TUTInvestorIDType);
	getString(req, "TUTCurrencyIDType", myreq.TUTCurrencyIDType);
	getInt(req, "TUTOrderRefType", &myreq.TUTOrderRefType);
	getDouble(req, "TUTMoneyType", &myreq.TUTMoneyType);
	getInt(req, "TUTIPAddressAsIntType", &myreq.TUTIPAddressAsIntType);
	getInt(req, "TUTMacAddressAsLongType", &myreq.TUTMacAddressAsLongType);
	int i = this->api->ReqFundPaybackInsert(&myreq, reqid);
	return i;
};

int TdApi::reqStockPaybackInsert(const dict &req, int reqid)
{
	CUTInputStockPaybackField myreq = CUTInputStockPaybackField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TUTInvestorIDType", myreq.TUTInvestorIDType);
	getChar(req, "TUTExchangeIDType", &myreq.TUTExchangeIDType);
	getString(req, "TUTInstrumentIDType", myreq.TUTInstrumentIDType);
	getInt(req, "TUTOrderRefType", &myreq.TUTOrderRefType);
	getInt(req, "TUTLargeVolumeType", &myreq.TUTLargeVolumeType);
	getInt(req, "TUTIPAddressAsIntType", &myreq.TUTIPAddressAsIntType);
	getInt(req, "TUTMacAddressAsLongType", &myreq.TUTMacAddressAsLongType);
	int i = this->api->ReqStockPaybackInsert(&myreq, reqid);
	return i;
};

int TdApi::reqLockInsert(const dict &req, int reqid)
{
	CUTInputLockField myreq = CUTInputLockField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TUTInvestorIDType", myreq.TUTInvestorIDType);
	getChar(req, "TUTExchangeIDType", &myreq.TUTExchangeIDType);
	getString(req, "TUTInstrumentIDType", myreq.TUTInstrumentIDType);
	getInt(req, "TUTOrderRefType", &myreq.TUTOrderRefType);
	getInt(req, "TUTVolumeType", &myreq.TUTVolumeType);
	getChar(req, "TUTLockTypeType", &myreq.TUTLockTypeType);
	getInt(req, "TUTIPAddressAsIntType", &myreq.TUTIPAddressAsIntType);
	getInt(req, "TUTMacAddressAsLongType", &myreq.TUTMacAddressAsLongType);
	int i = this->api->ReqLockInsert(&myreq, reqid);
	return i;
};

int TdApi::reqExecOrderInsert(const dict &req, int reqid)
{
	CUTInputExecOrderField myreq = CUTInputExecOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TUTInvestorIDType", myreq.TUTInvestorIDType);
	getChar(req, "TUTExchangeIDType", &myreq.TUTExchangeIDType);
	getString(req, "TUTInstrumentIDType", myreq.TUTInstrumentIDType);
	getInt(req, "TUTOrderRefType", &myreq.TUTOrderRefType);
	getInt(req, "TUTVolumeType", &myreq.TUTVolumeType);
	getInt(req, "TUTIPAddressAsIntType", &myreq.TUTIPAddressAsIntType);
	getInt(req, "TUTMacAddressAsLongType", &myreq.TUTMacAddressAsLongType);
	int i = this->api->ReqExecOrderInsert(&myreq, reqid);
	return i;
};

int TdApi::reqExecOrderAction(const dict &req, int reqid)
{
	CUTInputExecOrderActionField myreq = CUTInputExecOrderActionField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "TUTOrderRefType", &myreq.TUTOrderRefType);
	getInt(req, "TUTFrontIDType", &myreq.TUTFrontIDType);
	getInt(req, "TUTSessionIDType", &myreq.TUTSessionIDType);
	getInt(req, "TUTIPAddressAsIntType", &myreq.TUTIPAddressAsIntType);
	getInt(req, "TUTMacAddressAsLongType", &myreq.TUTMacAddressAsLongType);
	int i = this->api->ReqExecOrderAction(&myreq, reqid);
	return i;
};

int TdApi::reqQryInstrument(const dict &req, int reqid)
{
	CUTQryInstrumentField myreq = CUTQryInstrumentField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "TUTExchangeIDType", &myreq.TUTExchangeIDType);
	getString(req, "TUTInstrumentIDType", myreq.TUTInstrumentIDType);
	int i = this->api->ReqQryInstrument(&myreq, reqid);
	return i;
};

int TdApi::reqQryDepthMarketData(const dict &req, int reqid)
{
	CUTQryDepthMarketDataField myreq = CUTQryDepthMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "TUTExchangeIDType", &myreq.TUTExchangeIDType);
	getString(req, "TUTInstrumentIDType", myreq.TUTInstrumentIDType);
	int i = this->api->ReqQryDepthMarketData(&myreq, reqid);
	return i;
};

int TdApi::reqQryInvestorPosition(const dict &req, int reqid)
{
	CUTQryInvestorPositionField myreq = CUTQryInvestorPositionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TUTInvestorIDType", myreq.TUTInvestorIDType);
	getChar(req, "TUTExchangeIDType", &myreq.TUTExchangeIDType);
	getString(req, "TUTInstrumentIDType", myreq.TUTInstrumentIDType);
	int i = this->api->ReqQryInvestorPosition(&myreq, reqid);
	return i;
};

int TdApi::reqQryTradingAccount(const dict &req, int reqid)
{
	CUTQryTradingAccountField myreq = CUTQryTradingAccountField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TUTInvestorIDType", myreq.TUTInvestorIDType);
	getString(req, "TUTCurrencyIDType", myreq.TUTCurrencyIDType);
	getChar(req, "TUTAccTypeType", &myreq.TUTAccTypeType);
	int i = this->api->ReqQryTradingAccount(&myreq, reqid);
	return i;
};

int TdApi::reqQryOrder(const dict &req, int reqid)
{
	CUTQryOrderField myreq = CUTQryOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TUTInvestorIDType", myreq.TUTInvestorIDType);
	getChar(req, "TUTExchangeIDType", &myreq.TUTExchangeIDType);
	getString(req, "TUTInstrumentIDType", myreq.TUTInstrumentIDType);
	getInt(req, "TUTSequenceNoType", &myreq.TUTSequenceNoType);
	getInt(req, "TUTVolumeType", &myreq.TUTVolumeType);
	getChar(req, "TUTOrderStatusType", &myreq.TUTOrderStatusType);
	int i = this->api->ReqQryOrder(&myreq, reqid);
	return i;
};

int TdApi::reqQryTrade(const dict &req, int reqid)
{
	CUTQryTradeField myreq = CUTQryTradeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TUTInvestorIDType", myreq.TUTInvestorIDType);
	getChar(req, "TUTExchangeIDType", &myreq.TUTExchangeIDType);
	getString(req, "TUTInstrumentIDType", myreq.TUTInstrumentIDType);
	getInt(req, "TUTSequenceNoType", &myreq.TUTSequenceNoType);
	getInt(req, "TUTVolumeType", &myreq.TUTVolumeType);
	int i = this->api->ReqQryTrade(&myreq, reqid);
	return i;
};

int TdApi::reqQryOptionInstrMarginByVolume(const dict &req, int reqid)
{
	CUTQryOptionInstrMarginByVolumeField myreq = CUTQryOptionInstrMarginByVolumeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TUTInvestorIDType", myreq.TUTInvestorIDType);
	getChar(req, "TUTExchangeIDType", &myreq.TUTExchangeIDType);
	getString(req, "TUTInstrumentIDType", myreq.TUTInstrumentIDType);
	int i = this->api->ReqQryOptionInstrMarginByVolume(&myreq, reqid);
	return i;
};

int TdApi::reqQryOptionInstrCommRate(const dict &req, int reqid)
{
	CUTQryOptionInstrCommRateField myreq = CUTQryOptionInstrCommRateField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TUTInvestorIDType", myreq.TUTInvestorIDType);
	getChar(req, "TUTExchangeIDType", &myreq.TUTExchangeIDType);
	getString(req, "TUTInstrumentIDType", myreq.TUTInstrumentIDType);
	int i = this->api->ReqQryOptionInstrCommRate(&myreq, reqid);
	return i;
};

int TdApi::reqQryInstrumentCommissionRate(const dict &req, int reqid)
{
	CUTQryInstrumentCommissionRateField myreq = CUTQryInstrumentCommissionRateField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TUTInvestorIDType", myreq.TUTInvestorIDType);
	getChar(req, "TUTExchangeIDType", &myreq.TUTExchangeIDType);
	getString(req, "TUTInstrumentIDType", myreq.TUTInstrumentIDType);
	int i = this->api->ReqQryInstrumentCommissionRate(&myreq, reqid);
	return i;
};

int TdApi::reqQryInvestor(const dict &req, int reqid)
{
	CUTQryInvestorField myreq = CUTQryInvestorField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TUTInvestorIDType", myreq.TUTInvestorIDType);
	int i = this->api->ReqQryInvestor(&myreq, reqid);
	return i;
};

int TdApi::reqQryTransfer(const dict &req, int reqid)
{
	CUTQryTransferField myreq = CUTQryTransferField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TUTInvestorIDType", myreq.TUTInvestorIDType);
	int i = this->api->ReqQryTransfer(&myreq, reqid);
	return i;
};

int TdApi::reqQryTradingCode(const dict &req, int reqid)
{
	CUTQryTradingCodeField myreq = CUTQryTradingCodeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TUTInvestorIDType", myreq.TUTInvestorIDType);
	int i = this->api->ReqQryTradingCode(&myreq, reqid);
	return i;
};

int TdApi::reqQryMaxOrderVolume(const dict &req, int reqid)
{
	CUTQryMaxOrderVolumeField myreq = CUTQryMaxOrderVolumeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TUTInvestorIDType", myreq.TUTInvestorIDType);
	getChar(req, "TUTExchangeIDType", &myreq.TUTExchangeIDType);
	getString(req, "TUTInstrumentIDType", myreq.TUTInstrumentIDType);
	getChar(req, "TUTHedgeFlagType", &myreq.TUTHedgeFlagType);
	getChar(req, "TUTDirectionType", &myreq.TUTDirectionType);
	getChar(req, "TUTOffsetFlagType", &myreq.TUTOffsetFlagType);
	getDouble(req, "TUTPriceType", &myreq.TUTPriceType);
	int i = this->api->ReqQryMaxOrderVolume(&myreq, reqid);
	return i;
};

int TdApi::reqQryCreditInstrument(const dict &req, int reqid)
{
	CUTQryCreditInstrumentField myreq = CUTQryCreditInstrumentField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "TUTExchangeIDType", &myreq.TUTExchangeIDType);
	getString(req, "TUTInstrumentIDType", myreq.TUTInstrumentIDType);
	int i = this->api->ReqQryCreditInstrument(&myreq, reqid);
	return i;
};

int TdApi::reqQryCreditInvestor(const dict &req, int reqid)
{
	CUTQryCreditInvestorField myreq = CUTQryCreditInvestorField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TUTInvestorIDType", myreq.TUTInvestorIDType);
	int i = this->api->ReqQryCreditInvestor(&myreq, reqid);
	return i;
};

int TdApi::reqQryPrivateCreditStock(const dict &req, int reqid)
{
	CUTQryPrivateCreditStockField myreq = CUTQryPrivateCreditStockField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TUTInvestorIDType", myreq.TUTInvestorIDType);
	int i = this->api->ReqQryPrivateCreditStock(&myreq, reqid);
	return i;
};

int TdApi::reqQryCreditConcentration(const dict &req, int reqid)
{
	CUTQryCreditConcentrationField myreq = CUTQryCreditConcentrationField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TUTInvestorIDType", myreq.TUTInvestorIDType);
	int i = this->api->ReqQryCreditConcentration(&myreq, reqid);
	return i;
};

int TdApi::reqQryCreditFundDetail(const dict &req, int reqid)
{
	CUTQryCreditFundDetailField myreq = CUTQryCreditFundDetailField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TUTInvestorIDType", myreq.TUTInvestorIDType);
	int i = this->api->ReqQryCreditFundDetail(&myreq, reqid);
	return i;
};

int TdApi::reqQryCreditStockDetail(const dict &req, int reqid)
{
	CUTQryCreditStockDetailField myreq = CUTQryCreditStockDetailField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TUTInvestorIDType", myreq.TUTInvestorIDType);
	int i = this->api->ReqQryCreditStockDetail(&myreq, reqid);
	return i;
};

int TdApi::reqQryFundPayback(const dict &req, int reqid)
{
	CUTQryFundPaybackField myreq = CUTQryFundPaybackField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TUTInvestorIDType", myreq.TUTInvestorIDType);
	int i = this->api->ReqQryFundPayback(&myreq, reqid);
	return i;
};

int TdApi::reqQryStockPayback(const dict &req, int reqid)
{
	CUTQryStockPaybackField myreq = CUTQryStockPaybackField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TUTInvestorIDType", myreq.TUTInvestorIDType);
	int i = this->api->ReqQryStockPayback(&myreq, reqid);
	return i;
};

int TdApi::reqQryPublicCreditFund(const dict &req, int reqid)
{
	CUTQryPublicCreditFundField myreq = CUTQryPublicCreditFundField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "TUTTimeType", &myreq.TUTTimeType);
	int i = this->api->ReqQryPublicCreditFund(&myreq, reqid);
	return i;
};

int TdApi::reqQryETFInfo(const dict &req, int reqid)
{
	CUTQryETFInfoField myreq = CUTQryETFInfoField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "TUTExchangeIDType", &myreq.TUTExchangeIDType);
	getString(req, "TUTInstrumentIDType", myreq.TUTInstrumentIDType);
	int i = this->api->ReqQryETFInfo(&myreq, reqid);
	return i;
};

int TdApi::reqQryETFComponent(const dict &req, int reqid)
{
	CUTQryETFComponentField myreq = CUTQryETFComponentField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "TUTExchangeIDType", &myreq.TUTExchangeIDType);
	getString(req, "TUTFundIDType", myreq.TUTFundIDType);
	getString(req, "TUTInstrumentIDType", myreq.TUTInstrumentIDType);
	int i = this->api->ReqQryETFComponent(&myreq, reqid);
	return i;
};

int TdApi::reqQryCreditAvailableDetail(const dict &req, int reqid)
{
	CUTQryCreditAvailableDetailField myreq = CUTQryCreditAvailableDetailField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TUTAccountIDType", myreq.TUTAccountIDType);
	int i = this->api->ReqQryCreditAvailableDetail(&myreq, reqid);
	return i;
};

int TdApi::reqQryLock(const dict &req, int reqid)
{
	CUTQryLockField myreq = CUTQryLockField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TUTInvestorIDType", myreq.TUTInvestorIDType);
	int i = this->api->ReqQryLock(&myreq, reqid);
	return i;
};

int TdApi::reqQryExecOrder(const dict &req, int reqid)
{
	CUTQryExecOrderField myreq = CUTQryExecOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TUTInvestorIDType", myreq.TUTInvestorIDType);
	getChar(req, "TUTExchangeIDType", &myreq.TUTExchangeIDType);
	getString(req, "TUTInstrumentIDType", myreq.TUTInstrumentIDType);
	int i = this->api->ReqQryExecOrder(&myreq, reqid);
	return i;
};

int TdApi::reqQryLockPosition(const dict &req, int reqid)
{
	CUTQryLockPositionField myreq = CUTQryLockPositionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TUTInvestorIDType", myreq.TUTInvestorIDType);
	int i = this->api->ReqQryLockPosition(&myreq, reqid);
	return i;
};

int TdApi::reqQryOptPosiLimit(const dict &req, int reqid)
{
	CUTQryOptPosiLimitField myreq = CUTQryOptPosiLimitField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TUTInvestorIDType", myreq.TUTInvestorIDType);
	int i = this->api->ReqQryOptPosiLimit(&myreq, reqid);
	return i;
};

int TdApi::reqQryOptAmountLimit(const dict &req, int reqid)
{
	CUTQryOptAmountLimitField myreq = CUTQryOptAmountLimitField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TUTInvestorIDType", myreq.TUTInvestorIDType);
	int i = this->api->ReqQryOptAmountLimit(&myreq, reqid);
	return i;
};

