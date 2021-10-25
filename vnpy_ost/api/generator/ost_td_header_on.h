virtual void onFrontConnected() {};

virtual void onFrontDisconnected(int reqid) {};

virtual void onRspError(const dict &error, int reqid, bool last) {};

virtual void onRtnOrder(const dict &data) {};

virtual void onRtnTrade(const dict &data) {};

virtual void onErrRtnOrderAction(const dict &data) {};

virtual void onRspOrderInsert(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspOrderAction(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspLogin(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspUserPasswordUpdate(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspTransferInsert(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRtnTransfer(const dict &data) {};

virtual void onRspFundPaybackInsert(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRtnFundPayback(const dict &data) {};

virtual void onRspStockPaybackInsert(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRtnStockPayback(const dict &data) {};

virtual void onRtnPrivateCreditStock(const dict &data) {};

virtual void onRtnLock(const dict &data) {};

virtual void onRspLockInsert(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRtnExecOrder(const dict &data) {};

virtual void onRspExecOrderInsert(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspExecOrderAction(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onErrRtnExecOrderAction(const dict &data) {};

virtual void onRspQryInstrument(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspQryDepthMarketData(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspQryInvestorPosition(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspQryTradingAccount(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspQryOptionInstrMarginByVolume(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspQryOptionInstrCommRate(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspQryOrder(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspQryTrade(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspQryInstrumentCommissionRate(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspQryInvestor(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspQryTransfer(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspQryTradingCode(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspQryMaxOrderVolume(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspQryCreditInstrument(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspQryCreditInvestor(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspQryPrivateCreditStock(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspQryCreditConcentration(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspQryCreditFundDetail(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspQryCreditStockDetail(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspQryFundPayback(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspQryStockPayback(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspQryPublicCreditFund(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspQryETFInfo(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspQryETFComponent(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspQryCreditAvailableDetail(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspQryLock(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspQryExecOrder(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspQryLockPosition(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspQryOptPosiLimit(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspQryOptAmountLimit(const dict &data, const dict &error, int reqid, bool last) {};

