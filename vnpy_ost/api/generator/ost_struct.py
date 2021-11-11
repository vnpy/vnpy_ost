CSecurityDntSubscribeReq = {
    "securitySource": "uint16_t",
    "securityId": "string",
    "subscribeType": "enum",
}

CSecurityDntRspInfoField = {
    "ErrorID": "int32_t",
    "ErrorMsg": "string",
}

EntryInfo = {
    "level": "uint16_t",
    "price": "int64_t",
    "OrderQty": "int64_t",
}

CSecurityDntMarketDataField = {
    "origTime": "int64_t",
    "channelNo": "uint16_t",
    "marketId": "uint16_t",
    "MDStreamId": "enum",
    "MDStreamType": "enum",
    "securityId": "string",
    "preClosePx": "int64_t",
    "openPx": "int64_t",
    "closePx": "int64_t",
    "lastPx": "int64_t",
    "highPx": "int64_t",
    "lowPx": "int64_t",
    "upperLimit": "int64_t",
    "lowerLimit": "int64_t",
    "tradingPhase": "char",
    "tradeNums": "int64_t",
    "tradeVolumn": "int64_t",
    "tradeValue": "int64_t",
    "buyLength": "uint16_t",
    "buyEntry": "dict",
    "sellLength": "uint16_t",
    "sellEntry": "dict",
}

CSecurityDntL2TradeField = {
    "ChannelNo": "uint16_t",
    "marketId": "uint16_t",
    "ApplSeqNum": "int64_t",
    "MDStreamID": "enum",
    "BidApplSeqNum": "int64_t",
    "OfferApplSeqNum": "int64_t",
    "SecurityID": "string",
    "SecurityIDSource": "string",
    "LastPrice": "int64_t",
    "LastQty": "int64_t",
    "ExecType": "char",
    "TransactTime": "int64_t",
}

CSecurityDntL2OrderField = {
    "ChannelNo": "uint16_t",
    "marketId": "uint16_t",
    "ApplSeqNum": "int64_t",
    "MDStreamID": "enum",
    "SecurityID": "string",
    "SecurityIDSource": "string",
    "Price": "int64_t",
    "OrderQty": "int64_t",
    "Side": "char",
    "TransactTime": "int64_t",
    "OrderType": "char",
}

CSecurityDntL2IndexField = {
    "timeStamp": "int64_t",
    "marketId": "uint16_t",
    "SecurityID": "string",
    "preCloseIndex": "int64_t",
    "openIndex": "int64_t",
    "closeIndex": "int64_t",
    "highIndex": "int64_t",
    "lowIndex": "int64_t",
    "lastIndex": "int64_t",
    "turnOver": "int64_t",
    "totalVolume": "int64_t",
}


CUTOptionInstrMarginRateField = {
    "ExchangeID": "char",
    "InstrumentID": "string",
    "InvestorRange": "char",
    "InvestorID": "string",
    "HedgeFlag": "char",
    "MarginRatioByMoney": "double",
    "MarginRatioByVolume": "double",
}

CUTInstrumentCommissionRateField = {
    "ExchangeID": "char",
    "InstrumentID": "string",
    "InvestorRange": "char",
    "InvestorID": "string",
    "HedgeFlag": "char",
    "PosiDirection": "char",
    "OpenRatioByMoney": "double",
    "OpenRatioByVolume": "double",
    "CloseRatioByMoney": "double",
    "CloseRatioByVolume": "double",
    "CloseTodayRatioByMoney": "double",
    "CloseTodayRatioByVolume": "double",
    "OpenTaxRatioByMoney": "double",
    "OpenTaxRatioByVolume": "double",
    "CloseTaxRatioByMoney": "double",
    "CloseTaxRatioByVolume": "double",
    "CommByOrder": "double",
    "MinCommByOrder": "double",
}

CUTTradingAccountField = {
    "AccountID": "string",
    "CurrencyID": "string",
    "AccType": "char",
    "TradingDay": "int",
    "PreMortgage": "double",
    "PreCredit": "double",
    "PreDeposit": "double",
    "PreBalance": "double",
    "PreMargin": "double",
    "InterestBase": "double",
    "Interest": "double",
    "Deposit": "double",
    "Withdraw": "double",
    "FrozenMargin": "double",
    "FrozenCash": "double",
    "FrozenCommission": "double",
    "CurrMargin": "double",
    "CashIn": "double",
    "Commission": "double",
    "CloseProfit": "double",
    "PositionProfit": "double",
    "Balance": "double",
    "Available": "double",
    "WithdrawQuota": "double",
    "Reserve": "double",
    "Credit": "double",
    "Mortgage": "double",
    "DeliveryMargin": "double",
    "Tax": "double",
    "CreditFund": "double",
    "CreditFundFrozen": "double",
    "CreditStock": "double",
    "CreditStockFrozen": "double",
    "CreditAvailable": "double",
    "CreditAvailableParam": "double",
    "CreditStockCloseFrozen": "double",
    "CreditCollBuyFrozenOffset": "double",
    "CreditLiquidCost": "double",
    "CreditInterest": "double",
    "CreditTotalValue": "double",
    "CreditStockValue": "double",
    "CreditFundPayback": "double",
    "CreditInterestProcess": "double",
    "CreditFundCommission": "double",
}

CUTInvestorPositionField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "InstrumentID": "string",
    "HedgeFlag": "char",
    "PosiDirection": "char",
    "YdPosition": "long long",
    "Position": "long long",
    "LongFrozen": "long long",
    "ShortFrozen": "long long",
    "LongFrozenAmount": "double",
    "ShortFrozenAmount": "double",
    "OpenVolume": "long long",
    "CloseVolume": "long long",
    "OpenAmount": "double",
    "CloseAmount": "double",
    "PositionCost": "double",
    "UseMargin": "double",
    "FrozenMargin": "double",
    "FrozenCash": "double",
    "FrozenCommission": "double",
    "CashIn": "double",
    "Commission": "double",
    "CloseProfit": "double",
    "PositionProfit": "double",
    "PreSettlementPrice": "double",
    "SettlementPrice": "double",
    "TradingDay": "int",
    "OpenCost": "double",
    "CombPosition": "long long",
    "CloseProfitByDate": "double",
    "CloseProfitByTrade": "double",
    "TodayPosition": "long long",
    "MarginByVolume": "double",
    "StrikeFrozen": "long long",
    "StrikeFrozenAmount": "double",
    "AbandonFrozen": "long long",
    "CreditFund": "double",
    "RedemptionPosition": "long long",
    "RedemptionFrozen": "long long",
    "RedemptionPositionFrozen": "long long",
    "CreditFundVolume": "double",
    "CreditFundCommission": "double",
}

CUTDepthMarketDataField = {
    "ExchangeID": "char",
    "InstrumentID": "string",
    "TradingDay": "int",
    "PreSettlementPrice": "double",
    "PreClosePrice": "double",
    "PreOpenInterest": "long long",
    "UpperLimitPrice": "double",
    "LowerLimitPrice": "double",
    "ActionDay": "int",
    "UpdateTime": "int",
    "OpenPrice": "double",
    "ClosePrice": "double",
    "SettlementPrice": "double",
    "HighestPrice": "double",
    "LowestPrice": "double",
    "InstrumentStatus": "char",
    "LastPrice": "double",
    "Volume": "long long",
    "Turnover": "double",
    "OpenInterest": "long long",
    "BidPrice1": "double",
    "AskPrice1": "double",
    "BidVolume1": "long long",
    "AskVolume1": "long long",
    "BidPrice2": "double",
    "AskPrice2": "double",
    "BidVolume2": "long long",
    "AskVolume2": "long long",
    "BidPrice3": "double",
    "AskPrice3": "double",
    "BidVolume3": "long long",
    "AskVolume3": "long long",
    "BidPrice4": "double",
    "AskPrice4": "double",
    "BidVolume4": "long long",
    "AskVolume4": "long long",
    "BidPrice5": "double",
    "AskPrice5": "double",
    "BidVolume5": "long long",
    "AskVolume5": "long long",
}

CUTInstrumentField = {
    "ExchangeID": "char",
    "InstrumentID": "string",
    "InstrumentName": "string",
    "ProductID": "string",
    "ProductClass": "char",
    "DeliveryYear": "int",
    "DeliveryMonth": "int",
    "MaxMarketOrderVolume": "int",
    "MinMarketOrderVolume": "int",
    "MaxLimitOrderVolume": "int",
    "MinLimitOrderVolume": "int",
    "VolumeMultiple": "int",
    "PriceTick": "double",
    "CreateDate": "int",
    "OpenDate": "int",
    "ExpireDate": "int",
    "StartDelivDate": "int",
    "EndDelivDate": "int",
    "IsTrading": "short",
    "InstLifePhase": "char",
    "PositionType": "char",
    "PositionDateType": "char",
    "MaxMarginSideAlgorithm": "char",
    "OptionsType": "char",
    "CombinationType": "char",
    "UnderlyingInstrID": "string",
    "StrikePrice": "double",
    "UnderlyingMultiple": "double",
    "MinBuyVolume": "int",
    "MinSellVolume": "int",
    "InstrumentCode": "string",
    "CurrencyID": "string",
    "MinMarketBuyVolume": "int",
    "MinMarketSellVolume": "int",
}

CUTInvestorField = {
    "InvestorID": "string",
    "InvestorGroupID": "string",
    "InvestorName": "string",
    "IdentifiedCardType": "char",
    "IdentifiedCardNo": "string",
    "IsActive": "short",
    "Telephone": "string",
    "Address": "string",
    "OpenDate": "int",
    "Mobile": "string",
    "CommModelID": "string",
    "MarginModelID": "string",
    "DepartmentID": "string",
    "AuthGroupID": "string",
    "TradingRightGroupID": "string",
    "InvestorInstallID": "int",
}

CUTOptionInstrCommRateField = {
    "ExchangeID": "char",
    "InstrumentID": "string",
    "InvestorRange": "char",
    "InvestorID": "string",
    "HedgeFlag": "char",
    "PosiDirection": "char",
    "OpenRatioByMoney": "double",
    "OpenRatioByVolume": "double",
    "CloseRatioByMoney": "double",
    "CloseRatioByVolume": "double",
    "CloseTodayRatioByMoney": "double",
    "CloseTodayRatioByVolume": "double",
    "StrikeRatioByMoney": "double",
    "StrikeRatioByVolume": "double",
    "CommByOrder": "double",
}

CUTExchangeField = {
    "ExchangeID": "char",
    "ExchangeName": "string",
}

CUTBrokerUserPasswordField = {
    "UserID": "string",
    "Password": "string",
    "UserName": "string",
    "UserType": "char",
    "IsActive": "short",
}

CUTTraderField = {
    "ExchangeID": "char",
    "ParticipantID": "string",
    "TraderID": "string",
    "TraderClass": "char",
    "BizType": "char",
    "Password": "string",
    "InstallID": "int",
    "OrderLocalID": "string",
    "TradingDay": "int",
    "DataCenterID": "int",
    "TraderConnectStatus": "char",
}

CUTDepartmentUserField = {
    "UserID": "string",
    "InvestorRange": "char",
    "InvestorID": "string",
}

CUTTradingCodeField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "ClientID": "string",
    "IsActive": "short",
    "ClientIDType": "char",
    "BranchID": "string",
    "PreBranchID": "string",
    "DepartmentBranchID": "string",
}

CUTPartBrokerField = {
    "ExchangeID": "char",
    "ParticipantID": "string",
    "IsActive": "short",
}

CUTExecFreezeField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "InstrumentID": "string",
    "PosiDirection": "char",
    "OptionsType": "char",
    "Volume": "int",
    "FrozenAmount": "double",
}

CUTL2OrderField = {
    "ExchangeID": "char",
    "InstrumentID": "string",
    "ActionDay": "int",
    "Time": "int",
    "ChannelNo": "short",
    "SequenceNo": "long long",
    "Price": "double",
    "Volume": "int",
    "Direction": "char",
    "OrderPriceType": "char",
}

CUTL2TradeField = {
    "ExchangeID": "char",
    "InstrumentID": "string",
    "ActionDay": "int",
    "Time": "int",
    "ChannelNo": "short",
    "SequenceNo": "long long",
    "Price": "double",
    "Volume": "int",
    "TradeExecType": "char",
    "BSFlag": "char",
    "BidSequenceNo": "long long",
    "AskSequenceNo": "long long",
}

CUTMainCenterField = {
    "DRIdentityID": "int",
}

CUTTradeParamField = {
    "TradeParamID": "int",
    "TradeParamValue": "string",
}

CUTAuthPasswordField = {
    "UserProductInfo": "string",
    "UserProductPassword": "string",
}

CUTAuthInvestorField = {
    "InvestorRange": "char",
    "InvestorID": "string",
    "UserProductInfo": "string",
}

CUTAuthIPField = {
    "UserProductInfo": "string",
    "IPAddress": "string",
    "IPMask": "string",
    "MacAddress": "string",
}

CUTInstrumentTradingModeField = {
    "InstrumentID": "string",
    "ExchangeID": "char",
    "TradingMode": "char",
}

CUTInstrumentTradingRightField = {
    "ExchangeID": "char",
    "InstrumentID": "string",
    "InvestorRange": "char",
    "InvestorID": "string",
    "HedgeFlag": "char",
    "TradingRight": "char",
}

CUTMarketDataUpdateTimeField = {
    "ActionDay": "int",
    "UpdateTime": "int",
}

CUTMarketDataStaticField = {
    "OpenPrice": "double",
    "ClosePrice": "double",
    "SettlementPrice": "double",
    "HighestPrice": "double",
    "LowestPrice": "double",
    "InstrumentStatus": "char",
}

CUTMarketDataLastMatchField = {
    "LastPrice": "double",
    "Volume": "long long",
    "Turnover": "double",
    "OpenInterest": "long long",
}

CUTMarketDataBestPriceField = {
    "BidPrice1": "int",
    "AskPrice1": "int",
    "BidVolume1": "long long",
    "AskVolume1": "long long",
}

CUTL2MarketDataBestPriceField = {
    "BidPrice1": "int",
    "AskPrice1": "int",
    "BidVolume1": "long long",
    "AskVolume1": "long long",
    "BidOrderVolume1": "int",
    "AskOrderVolume1": "int",
}

CUTMarketDataForKernelField = {
    "ExchangeID": "char",
    "InstrumentID": "string",
    "ActionDay": "int",
    "UpdateTime": "int",
    "InstrumentStatus": "char",
    "LastPrice": "double",
}

CUTVariableL2DepthMarketDataField = {
    "ActionDay": "int",
    "UpdateTime": "int",
    "OpenPrice": "int",
    "ClosePrice": "int",
    "SettlementPrice": "int",
    "HighestPrice": "int",
    "LowestPrice": "int",
    "InstrumentStatus": "char",
    "LastPrice": "int",
    "Volume": "long long",
    "Turnover": "double",
    "OpenInterest": "long long",
    "BidPrice1": "int",
    "AskPrice1": "int",
    "BidVolume1": "long long",
    "AskVolume1": "long long",
    "BidOrderVolume1": "int",
    "AskOrderVolume1": "int",
}

CUTVariableDepthMarketDataField = {
    "ActionDay": "int",
    "UpdateTime": "int",
    "OpenPrice": "int",
    "ClosePrice": "int",
    "SettlementPrice": "int",
    "HighestPrice": "int",
    "LowestPrice": "int",
    "InstrumentStatus": "char",
    "LastPrice": "int",
    "Volume": "long long",
    "Turnover": "double",
    "OpenInterest": "long long",
    "BidPrice1": "int",
    "AskPrice1": "int",
    "BidVolume1": "long long",
    "AskVolume1": "long long",
    "BidPrice2": "int",
    "AskPrice2": "int",
    "BidVolume2": "long long",
    "AskVolume2": "long long",
    "BidPrice3": "int",
    "AskPrice3": "int",
    "BidVolume3": "long long",
    "AskVolume3": "long long",
    "BidPrice4": "int",
    "AskPrice4": "int",
    "BidVolume4": "long long",
    "AskVolume4": "long long",
    "BidPrice5": "int",
    "AskPrice5": "int",
    "BidVolume5": "long long",
    "AskVolume5": "long long",
}

CUTCenterField = {
    "CenterID": "int",
    "CenterName": "string",
}

CUTTraderCenterField = {
    "ExchangeID": "char",
    "TraderID": "string",
    "CenterID": "int",
}

CUTFundDistributionField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "Ratio": "double",
}

CUTTaxRateField = {
    "ExchangeID": "char",
    "InstrumentID": "string",
    "OpenTaxRatioByMoney": "double",
    "OpenTaxRatioByVolume": "double",
    "CloseTaxRatioByMoney": "double",
    "CloseTaxRatioByVolume": "double",
    "CommByOrder": "double",
    "MinCommByOrder": "double",
}

CUTOptionInstrTradingRightField = {
    "ExchangeID": "char",
    "InstrumentID": "string",
    "InvestorRange": "char",
    "InvestorID": "string",
    "HedgeFlag": "char",
    "PosiDirection": "char",
    "TradingRight": "char",
}

CUTOptionMarginAlgoField = {
    "ExchangeID": "char",
    "InstrumentID": "string",
    "OutRatio": "double",
    "GuaranteeRatio": "double",
}

CUTCurrentTimeField = {
    "CurrDate": "int",
    "CurrTime": "int",
    "ActionDay": "int",
}

CUTRspInfoField = {
    "ErrorID": "int",
    "ErrorMsg": "string",
}

CUTSettlementRefField = {
    "TradingDay": "int",
}

CUTSyncDepositField = {
    "DepositSeqNo": "string",
    "InvestorID": "string",
    "Deposit": "double",
    "IsForce": "short",
    "CurrencyID": "string",
    "AccType": "char",
}

CUTBrokerUserFunctionField = {
    "UserID": "string",
    "BrokerFunctionCode": "char",
}

CUTTradingDayField = {
    "TradingDay": "int",
}

CUTSyncInvestorPositionField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "InstrumentID": "string",
    "HedgeFlag": "char",
    "PosiDirection": "char",
    "YdPosition": "long long",
}

CUTOrderField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "InstrumentID": "string",
    "OrderRef": "int",
    "Direction": "char",
    "OffsetFlag": "char",
    "HedgeFlag": "char",
    "OrderPriceType": "char",
    "VolumeTotalOriginal": "int",
    "LimitPrice": "double",
    "TimeCondition": "char",
    "VolumeCondition": "char",
    "ContingentCondition": "char",
    "GTDDate": "int",
    "MinVolume": "int",
    "IsAutoSuspend": "short",
    "UserForceClose": "short",
    "StopPrice": "double",
    "IsSwapOrder": "short",
    "TraderID": "string",
    "OrderLocalID": "string",
    "ParticipantID": "string",
    "ClientID": "string",
    "TradingDay": "int",
    "UserProductInfo": "string",
    "BranchID": "string",
    "InstallID": "int",
    "IPAddressAsInt": "int",
    "MacAddressAsLong": "long long",
    "OrderSysID": "string",
    "OrderStatus": "char",
    "OrderType": "char",
    "VolumeTraded": "int",
    "VolumeTotal": "int",
    "InsertDate": "int",
    "InsertTime": "int",
    "CancelTime": "int",
    "SequenceNo": "long long",
    "FrontID": "int",
    "SessionID": "long long",
    "ExchangeErrorID": "int",
}

CUTInstrumentStatusField = {
    "ExchangeID": "char",
    "InstrumentID": "string",
    "InstrumentStatus": "char",
    "EnterTime": "int",
    "EnterReason": "char",
    "SequenceNo": "long long",
}

CUTTradeField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "InstrumentID": "string",
    "OrderRef": "int",
    "TradeID": "string",
    "Direction": "char",
    "OrderSysID": "string",
    "ClientID": "string",
    "OffsetFlag": "char",
    "HedgeFlag": "char",
    "Price": "double",
    "Volume": "int",
    "TradeDate": "int",
    "TradeTime": "int",
    "TradeType": "char",
    "TraderID": "string",
    "OrderLocalID": "string",
    "SequenceNo": "long long",
    "TradingDay": "int",
    "InstallID": "int",
    "FrontID": "int",
    "SessionID": "long long",
}

CUTOrderActionField = {
    "OrderActionRef": "int",
    "FrontID": "int",
    "SessionID": "long long",
    "OrderRef": "int",
    "ActionFlag": "char",
    "LimitPrice": "double",
    "VolumeChange": "int",
    "InvestorID": "string",
    "ExchangeID": "char",
    "OrderSysID": "string",
    "InstrumentID": "string",
    "ActionDate": "int",
    "ActionTime": "int",
    "TraderID": "string",
    "OrderLocalID": "string",
    "ActionLocalID": "string",
    "ParticipantID": "string",
    "ClientID": "string",
    "OrderActionStatus": "char",
    "Direction": "char",
    "BranchID": "string",
    "OrderType": "char",
    "InstallID": "int",
    "ExchangeErrorID": "int",
    "ActionFrontID": "int",
    "ActionSessionID": "long long",
    "IPAddressAsInt": "int",
    "MacAddressAsLong": "long long",
}

CUTInputOrderField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "InstrumentID": "string",
    "OrderRef": "int",
    "Direction": "char",
    "OffsetFlag": "char",
    "HedgeFlag": "char",
    "OrderPriceType": "char",
    "VolumeTotalOriginal": "int",
    "LimitPrice": "double",
    "TimeCondition": "char",
    "VolumeCondition": "char",
    "ContingentCondition": "char",
    "GTDDate": "int",
    "MinVolume": "int",
    "IsAutoSuspend": "short",
    "UserForceClose": "short",
    "StopPrice": "double",
    "IsSwapOrder": "short",
    "IPAddressAsInt": "int",
    "MacAddressAsLong": "long long",
}

CUTInputOrderActionField = {
    "OrderActionRef": "int",
    "FrontID": "int",
    "SessionID": "long long",
    "OrderRef": "int",
    "ActionFlag": "char",
    "LimitPrice": "double",
    "VolumeChange": "int",
    "IPAddressAsInt": "int",
    "MacAddressAsLong": "long long",
}

CUTUserSessionField = {
    "UserID": "string",
    "Password": "string",
    "UserProductInfo": "string",
    "UserProductPassword": "string",
    "OneTimePassword": "string",
    "LoginRemark": "string",
    "MacAddress": "string",
    "IPAddress": "string",
    "PrivateSeq": "long long",
    "PublicSeq": "long long",
    "TradingDay": "int",
    "FrontID": "int",
    "SessionID": "long long",
    "LoginTime": "int",
    "SystemName": "string",
    "UserType": "char",
    "IsLogin": "short",
    "Port": "int",
    "OriTerminalInfo": "string",
}

CUTRspLoginField = {
    "TradingDay": "int",
    "LoginTime": "int",
    "UserID": "string",
    "SystemName": "string",
    "FrontID": "int",
    "SessionID": "long long",
    "PrivateSeq": "long long",
    "PublicSeq": "long long",
    "MultiAddress": "string",
}

CUTSubInstrumentField = {
    "ExchangeID": "char",
    "InstrumentID": "string",
}

CUTInputDesignateField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "DesignateRef": "int",
    "DesignateType": "char",
    "TraderID": "string",
    "TransfereeTraderID": "string",
    "OriDesignateLocalID": "string",
}

CUTDesignateField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "DesignateRef": "int",
    "DesignateType": "char",
    "TraderID": "string",
    "DesignateLocalID": "string",
    "ParticipantID": "string",
    "ClientID": "string",
    "DesignateStatus": "char",
    "TradingDay": "int",
    "InsertDate": "int",
    "InsertTime": "int",
    "FrontID": "int",
    "SessionID": "long long",
    "ExchangeErrorID": "int",
    "BranchID": "string",
    "SequenceNo": "long long",
    "InstallID": "int",
    "TransfereeTraderID": "string",
    "OriDesignateLocalID": "string",
}

CUTReqLogoutField = {
    "UserID": "string",
}

CUTExchangeOrderField = {
    "ExchangeID": "char",
    "TraderID": "string",
    "OrderLocalID": "string",
    "Direction": "char",
    "OrderSysID": "string",
    "OrderStatus": "char",
    "VolumeTotal": "int",
    "InsertDate": "int",
    "InsertTime": "int",
    "ExchangeErrorID": "int",
    "InstallID": "int",
    "SequenceNo": "long long",
    "LimitPrice": "double",
}

CUTExchangeOrderActionField = {
    "ExchangeID": "char",
    "TraderID": "string",
    "ActionLocalID": "string",
    "ExchangeErrorID": "int",
}

CUTExchangeDesignateField = {
    "ExchangeID": "char",
    "TraderID": "string",
    "DesignateLocalID": "string",
    "DesignateStatus": "char",
    "InsertDate": "int",
    "InsertTime": "int",
    "SequenceNo": "long long",
    "ExchangeErrorID": "int",
    "InstallID": "int",
}

CUTLoginForbiddenUserIPField = {
    "UserID": "string",
    "IPAddress": "string",
}

CUTIPListField = {
    "IPAddress": "string",
    "IsWhite": "short",
}

CUTSyncRandomStringField = {
    "RandomString": "string",
    "RandomStringType": "char",
}

CUTForceUserLogoutField = {
    "UserID": "string",
    "FrontID": "int",
    "SessionID": "long long",
    "EnableRelogin": "short",
}

CUTUserSessionRefField = {
    "FrontID": "int",
    "SessionID": "long long",
}

CUTUserLoginFailedNumField = {
    "UserID": "string",
    "IPAddress": "string",
    "Volume": "int",
}

CUTIPLoginFailedNumField = {
    "IPAddress": "string",
    "Volume": "int",
}

CUTUserPasswordUpdateField = {
    "UserID": "string",
    "OldPassword": "string",
    "NewPassword": "string",
}

CUTInputTransferField = {
    "InvestorID": "string",
    "TransferRef": "int",
    "TransferType": "char",
    "Deposit": "double",
    "CurrencyID": "string",
    "AccType": "char",
    "BankID": "string",
    "FundPassword": "string",
    "BankPassword": "string",
}

CUTTransferField = {
    "InvestorID": "string",
    "TransferRef": "int",
    "TransferType": "char",
    "Deposit": "double",
    "CurrencyID": "string",
    "AccType": "char",
    "BankID": "string",
    "FundPassword": "string",
    "BankPassword": "string",
    "FrontID": "int",
    "SessionID": "long long",
    "TransferLocalID": "string",
    "TransferSysID": "string",
    "TransferStatus": "char",
    "ExchangeErrorID": "int",
    "InsertDate": "int",
    "InsertTime": "int",
}

CUTExchangeTransferField = {
    "TransferLocalID": "string",
    "TransferSysID": "string",
    "TransferStatus": "char",
    "ExchangeErrorID": "int",
}

CUTSubTopicField = {
    "SubjectID": "int",
    "SequeceNo": "long long",
    "TradingDay": "int",
}

CUTSubMDTopicField = {
    "ExchangeID": "char",
    "InstrumentID": "string",
    "SubDataType": "int",
}

CUTMonitorIndexField = {
    "DelayTimeUnknown": "long long",
    "DelayTimeQueued": "long long",
    "ErrOrderVolume": "long long",
    "ErrOrderActionVolume": "long long",
    "ErrOrderInvestorID": "string",
    "ErrOrderActionInvestorID": "string",
    "Time": "int",
}

CUTSubmitTerminalInfoField = {
    "UserID": "string",
    "LoginSeq": "long long",
    "TerminalInfo": "string",
}

CUTTerminalInfoField = {
    "FrontID": "int",
    "SessionID": "long long",
    "UserID": "string",
    "LoginSeq": "long long",
    "TerminalInfo": "string",
}

CUTMaxOrderVolumeField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "InstrumentID": "string",
    "HedgeFlag": "char",
    "Direction": "char",
    "OffsetFlag": "char",
    "Price": "double",
    "MaxVolume": "int",
    "MaxVolumeOri": "long long",
}

CUTInputFundPaybackField = {
    "InvestorID": "string",
    "CurrencyID": "string",
    "FundPaybackRef": "int",
    "Amount": "double",
    "IPAddressAsInt": "int",
    "MacAddressAsLong": "long long",
}

CUTFundPaybackField = {
    "InvestorID": "string",
    "CurrencyID": "string",
    "FundPaybackRef": "int",
    "Amount": "double",
    "FrontID": "int",
    "SessionID": "long long",
    "FundPaybackLocalID": "string",
    "InsertDate": "int",
    "InsertTime": "int",
    "IPAddressAsInt": "int",
    "MacAddressAsLong": "long long",
}

CUTInputStockPaybackField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "InstrumentID": "string",
    "StockPaybackRef": "int",
    "Volume": "long long",
    "IPAddressAsInt": "int",
    "MacAddressAsLong": "long long",
}

CUTStockPaybackField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "InstrumentID": "string",
    "StockPaybackRef": "int",
    "Volume": "long long",
    "FrontID": "int",
    "SessionID": "long long",
    "TraderID": "string",
    "StockPaybackLocalID": "string",
    "ClientID": "string",
    "InstallID": "int",
    "InsertDate": "int",
    "InsertTime": "int",
    "StockPaybackSysID": "string",
    "StockPaybackStatus": "char",
    "ExchangeErrorID": "int",
    "BranchID": "string",
    "IPAddressAsInt": "int",
    "MacAddressAsLong": "long long",
}

CUTExchangeStockPaybackField = {
    "ExchangeID": "char",
    "TraderID": "string",
    "StockPaybackLocalID": "string",
    "StockPaybackSysID": "string",
    "StockPaybackStatus": "char",
    "ExchangeErrorID": "int",
    "InstallID": "int",
}

CUTPublicCreditFundField = {
    "TotalAmount": "double",
    "FrozenAmount": "double",
}

CUTPositionProfitForKernelField = {
    "AccountInstallID": "int",
    "PositionProfit": "double",
}

CUTCreditFundDetailField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "InstrumentID": "string",
    "OpenDate": "int",
    "TradeID": "string",
    "ExpireDate": "int",
    "Amount": "double",
    "AmountPayback": "double",
    "Volume": "int",
    "VolumePayback": "double",
    "YdAmountPayback": "double",
    "Commission": "double",
    "CreditAmountPayback": "double",
    "FundAmountPayback": "double",
}

CUTCreditStockDetailField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "InstrumentID": "string",
    "OpenDate": "int",
    "TradeID": "string",
    "ExpireDate": "int",
    "Volume": "int",
    "VolumePayback": "int",
    "Amount": "double",
    "AmountPayback": "double",
}

CUTCreditInstrumentField = {
    "ExchangeID": "char",
    "InstrumentID": "string",
    "ConvertRate": "double",
    "IsCreditFund": "short",
    "IsCreditStock": "short",
    "IsGuarantee": "short",
    "IsLiquid": "short",
    "ConcentrationGroupID": "string",
    "AssetPrice": "double",
    "AssetPriceCreditStock": "double",
}

CUTCreditInvestorField = {
    "InvestorID": "string",
    "FundRate": "double",
    "StockRate": "double",
    "GuaranteeRate": "double",
    "TotalLimit": "double",
    "StockLimit": "double",
    "FundLimit": "double",
    "PrivateCreditFund": "double",
}

CUTPrivateCreditStockField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "InstrumentID": "string",
    "Volume": "long long",
    "BeginDate": "int",
    "EndDate": "int",
    "ReserveVolume": "long long",
}

CUTCreditToNormalInvestorField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "NormalInvestorID": "string",
    "NormalClientID": "string",
}

CUTCreditConcentrationField = {
    "InvestorID": "string",
    "ConcentrationBizType": "char",
    "ConcentrationInstrType": "char",
    "ExchangeID": "char",
    "InstrumentID": "string",
    "GuaranteeRateLower": "double",
    "GuaranteeRateUpper": "double",
    "ConcentrationRate": "double",
}

CUTETFInfoField = {
    "ExchangeID": "char",
    "InstrumentID": "string",
    "RedemptionID": "string",
    "CreationRedemptionUnit": "int",
    "MaxCashRatio": "double",
    "PublishIOPV": "short",
    "Creation": "short",
    "Redemption": "short",
    "RecordNum": "int",
    "EstimateCashComponent": "double",
    "NAVperCU": "double",
    "NAV": "double",
    "SubstituteAmount": "double",
    "RedemptionStockVolume": "int",
}

CUTETFComponentField = {
    "ExchangeID": "char",
    "ETFID": "string",
    "InstrumentID": "string",
    "ComponentExchangeID": "char",
    "Volume": "int",
    "SubstituteFlag": "char",
    "CreationPremiumRate": "double",
    "RedemptionDiscountRate": "double",
    "CreationCashSubstitute": "double",
    "RedemptionCashSubstitute": "double",
}

CUTPositionProfitForKernelRefField = {
    "AccountInstallID": "int",
    "CreditTotalValue": "double",
    "CreditStockValue": "double",
    "CreditAvailableParam": "double",
}

CUTPositionProfitForKernelRef1Field = {
    "PositionInstallID": "int",
    "Value": "double",
}

CUTConcentrationPositionField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "InstrumentID": "string",
    "HedgeFlag": "char",
    "ConcentrationInstrType": "char",
    "Value": "double",
}

CUTMDLastPriceRefField = {
    "MDInstallID": "int",
    "LastPrice": "int",
}

CUTDuplicateCountField = {
    "DuplicateCount": "int",
}

CUTSyncPublicCreditFundField = {
    "Amount": "double",
}

CUTLocalIDField = {
    "TransferLocalID": "string",
    "FundPaybackLocalID": "string",
}

CUTBoardInvestorField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "Volume": "int",
}

CUTCreditAvailableDetailField = {
    "AccountID": "string",
    "CreditCollateralValue": "double",
    "CreditFundProfit": "double",
    "CreditStockProfit": "double",
}

CUTGatewayField = {
    "Location": "string",
    "ExchangeID": "char",
}

CUTInvestorLevelField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "Level": "int",
}

CUTSystemNameField = {
    "SystemName": "string",
}

CUTInputLockField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "InstrumentID": "string",
    "LockRef": "int",
    "Volume": "int",
    "LockType": "char",
    "IPAddressAsInt": "int",
    "MacAddressAsLong": "long long",
}

CUTLockField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "InstrumentID": "string",
    "LockRef": "int",
    "Volume": "int",
    "LockType": "char",
    "TraderID": "string",
    "LockLocalID": "string",
    "ClientID": "string",
    "TradingDay": "int",
    "BranchID": "string",
    "InstallID": "int",
    "IPAddressAsInt": "int",
    "MacAddressAsLong": "long long",
    "LockSysID": "string",
    "LockStatus": "char",
    "InsertDate": "int",
    "InsertTime": "int",
    "CancelTime": "int",
    "SequenceNo": "long long",
    "FrontID": "int",
    "SessionID": "long long",
    "ExchangeErrorID": "int",
}

CUTExchangeLockField = {
    "ExchangeID": "char",
    "TraderID": "string",
    "LockLocalID": "string",
    "LockSysID": "string",
    "LockStatus": "char",
    "InsertDate": "int",
    "InsertTime": "int",
    "ExchangeErrorID": "int",
    "InstallID": "int",
    "SequenceNo": "long long",
}

CUTInputExecOrderField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "InstrumentID": "string",
    "ExecOrderRef": "int",
    "Volume": "int",
    "IPAddressAsInt": "int",
    "MacAddressAsLong": "long long",
}

CUTExecOrderField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "InstrumentID": "string",
    "ExecOrderRef": "int",
    "Volume": "int",
    "TraderID": "string",
    "ExecOrderLocalID": "string",
    "ClientID": "string",
    "TradingDay": "int",
    "BranchID": "string",
    "InstallID": "int",
    "IPAddressAsInt": "int",
    "MacAddressAsLong": "long long",
    "ExecOrderSysID": "string",
    "ExecResult": "char",
    "InsertDate": "int",
    "InsertTime": "int",
    "CancelTime": "int",
    "SequenceNo": "long long",
    "FrontID": "int",
    "SessionID": "long long",
    "ExchangeErrorID": "int",
}

CUTExchangeExecOrderField = {
    "ExchangeID": "char",
    "TraderID": "string",
    "ExecOrderLocalID": "string",
    "ExecOrderSysID": "string",
    "ExecResult": "char",
    "InsertDate": "int",
    "InsertTime": "int",
    "ExchangeErrorID": "int",
    "InstallID": "int",
    "SequenceNo": "long long",
}

CUTPosiFreezeField = {
    "ClientID": "string",
    "ExchangeID": "char",
    "InstrumentID": "string",
    "TraderID": "string",
    "PosiFreezeLocalID": "string",
    "Volume": "long long",
    "FreezeReason": "char",
    "FreezeType": "char",
    "SequenceNo": "long long",
}

CUTLockPositionField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "InstrumentID": "string",
    "Volume": "long long",
    "FrozenVolume": "long long",
}

CUTExecOrderActionField = {
    "ExecOrderActionRef": "int",
    "FrontID": "int",
    "SessionID": "long long",
    "ExecOrderRef": "int",
    "InvestorID": "string",
    "ExchangeID": "char",
    "ExecOrderSysID": "string",
    "InstrumentID": "string",
    "ActionDate": "int",
    "ActionTime": "int",
    "TraderID": "string",
    "ExecOrderLocalID": "string",
    "ActionLocalID": "string",
    "ClientID": "string",
    "OrderActionStatus": "char",
    "BranchID": "string",
    "InstallID": "int",
    "ExchangeErrorID": "int",
    "ActionFrontID": "int",
    "ActionSessionID": "long long",
    "IPAddressAsInt": "int",
    "MacAddressAsLong": "long long",
}

CUTInputExecOrderActionField = {
    "ExecOrderActionRef": "int",
    "FrontID": "int",
    "SessionID": "long long",
    "ExecOrderRef": "int",
    "IPAddressAsInt": "int",
    "MacAddressAsLong": "long long",
}

CUTExchangePosiFreezeField = {
    "ExchangeID": "char",
    "TraderID": "string",
    "PosiFreezeLocalID": "string",
    "FreezeReason": "char",
    "ExchangeErrorID": "int",
}

CUTExchangeExecOrderActionField = {
    "ExchangeID": "char",
    "TraderID": "string",
    "ActionLocalID": "string",
    "ExchangeErrorID": "int",
}

CUTOptPosiLimitField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "InstrumentID": "string",
    "TotalVolume": "long long",
    "LongVolume": "long long",
    "OpenVolume": "long long",
    "LongOpenVolume": "long long",
    "TotalVolumeFrozen": "long long",
    "LongVolumeFrozen": "long long",
    "OpenVolumeFrozen": "long long",
    "LongOpenVolumeFrozen": "long long",
}

CUTOptAmountLimitField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "LongAmount": "double",
    "LongAmountFrozen": "double",
}

CUTDllSettingField = {
    "DllName": "string",
    "Enable": "short",
    "ErrorMsg": "string",
}

CUTDllUpdateField = {
    "DllName": "string",
    "SequenceNo": "long long",
    "Content": "string",
    "Size": "int",
    "ErrorMsg": "string",
}

CUTDataDumpField = {
    "ErrorMsg": "string",
}

CUTQryInstrumentField = {
    "ExchangeID": "char",
    "InstrumentID": "string",
}

CUTQryDepthMarketDataField = {
    "ExchangeID": "char",
    "InstrumentID": "string",
}

CUTQryInvestorPositionField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "InstrumentID": "string",
}

CUTQryTradingAccountField = {
    "InvestorID": "string",
    "CurrencyID": "string",
    "AccType": "char",
}

CUTQryOrderField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "InstrumentID": "string",
    "SequenceNo": "long long",
    "Limit": "int",
    "OrderStatus": "char",
}

CUTQryTradeField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "InstrumentID": "string",
    "SequenceNo": "long long",
    "Limit": "int",
}

CUTQryTraderField = {
    "ExchangeID": "char",
    "TraderID": "string",
}

CUTQryOptionInstrMarginByVolumeField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "InstrumentID": "string",
}

CUTOptionInstrMarginByVolumeField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "InstrumentID": "string",
    "HedgeFlag": "char",
    "MarginByVolume": "double",
}

CUTQryOptionInstrCommRateField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "InstrumentID": "string",
}

CUTQrySyncDepositField = {
    "DepositSeqNo": "string",
}

CUTQryBrokerUserFunctionField = {
    "UserID": "string",
}

CUTQryInstrumentCommissionRateField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "InstrumentID": "string",
}

CUTQryInvestorField = {
    "InvestorID": "string",
}

CUTQryUserSessionField = {
    "UserID": "string",
    "FrontID": "int",
    "SessionID": "long long",
}

CUTQryTransferField = {
    "InvestorID": "string",
}

CUTQryBrokerUserPasswordField = {
    "UserID": "string",
}

CUTQryTradingCodeField = {
    "InvestorID": "string",
}

CUTQryInstrumentTradingRightField = {
    "InvestorID": "string",
}

CUTQryAuthPasswordField = {
    "UserProductInfo": "string",
}

CUTQryAuthInvestorField = {
    "InvestorID": "string",
    "UserProductInfo": "string",
}

CUTQryAuthIPField = {
    "UserProductInfo": "string",
}

CUTQryL2OrderTradeField = {
    "ExchangeID": "char",
    "ChannelNo": "short",
    "SequenceNoBegin": "long long",
    "SequenceNoEnd": "long long",
}

CUTQryDesignateField = {
    "InvestorID": "string",
}

CUTQryOrderActionField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "InstrumentID": "string",
}

CUTQryLoginForbiddenUserIPField = {
    "UserID": "string",
}

CUTQryIPListField = {
    "IPAddress": "string",
}

CUTQryMonitorIndexField = {
    "Time": "int",
}

CUTQryTerminalInfoField = {
    "FrontID": "int",
    "SessionID": "long long",
    "LoginSeq": "long long",
}

CUTQryMaxOrderVolumeField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "InstrumentID": "string",
    "HedgeFlag": "char",
    "Direction": "char",
    "OffsetFlag": "char",
    "Price": "double",
}

CUTQryCreditInstrumentField = {
    "ExchangeID": "char",
    "InstrumentID": "string",
}

CUTQryCreditToNormalInvestorField = {
    "InvestorID": "string",
}

CUTQryCreditInvestorField = {
    "InvestorID": "string",
}

CUTQryPrivateCreditStockField = {
    "InvestorID": "string",
}

CUTQryCreditConcentrationField = {
    "InvestorID": "string",
}

CUTQryCreditFundDetailField = {
    "InvestorID": "string",
}

CUTQryCreditStockDetailField = {
    "InvestorID": "string",
}

CUTQryFundPaybackField = {
    "InvestorID": "string",
}

CUTQryStockPaybackField = {
    "InvestorID": "string",
}

CUTQryPublicCreditFundField = {
    "Time": "int",
}

CUTQryETFInfoField = {
    "ExchangeID": "char",
    "InstrumentID": "string",
}

CUTQryETFComponentField = {
    "ExchangeID": "char",
    "ETFID": "string",
    "InstrumentID": "string",
}

CUTQryMDBField = {
    "InstrumentID": "string",
}

CUTQryConcentrationPositionField = {
    "InvestorID": "string",
}

CUTQryCreditAvailableDetailField = {
    "AccountID": "string",
}

CUTQryGatewayField = {
    "Time": "int",
}

CUTQryInvestorLevelField = {
    "InvestorID": "string",
}

CUTQryOptionInstrTradingRightField = {
    "InvestorID": "string",
}

CUTQrySystemNameField = {
    "SystemName": "string",
}

CUTQryLockField = {
    "InvestorID": "string",
}

CUTQryExecOrderField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "InstrumentID": "string",
}

CUTQryLockPositionField = {
    "InvestorID": "string",
}

CUTQryOptPosiLimitField = {
    "InvestorID": "string",
}

CUTQryOptAmountLimitField = {
    "InvestorID": "string",
}

CUTQryExecOrderActionField = {
    "InvestorID": "string",
    "ExchangeID": "char",
    "InstrumentID": "string",
}

CUTQryOptionMarginAlgoField = {
    "ExchangeID": "char",
    "InstrumentID": "string",
}

TUTL2BidAskType = {
    "BidPrice": "double",
    "AskPrice": "double",
    "BidVolume": "long long",
    "AskVolume": "long long",
    "BidOrderVolume": "int",
    "AskOrderVolume": "int",
}

CUTL2DepthMarketDataField = {
    "ExchangeID": "char",
    "InstrumentID": "string",
    "TradingDay": "int",
    "PreSettlementPrice": "double",
    "PreClosePrice": "double",
    "PreOpenInterest": "long long",
    "UpperLimitPrice": "double",
    "LowerLimitPrice": "double",
    "ActionDay": "int",
    "UpdateTime": "int",
    "OpenPrice": "double",
    "ClosePrice": "double",
    "SettlementPrice": "double",
    "HighestPrice": "double",
    "LowestPrice": "double",
    "InstrumentStatus": "char",
    "LastPrice": "double",
    "Volume": "long long",
    "Turnover": "double",
    "OpenInterest": "long long",
    "BidAsk": "string",
}

TUTL2OrderVolumeType = {
    "BidOrderVolume": "int",
    "AskOrderVolume": "int",
}

CUTL2BestOrderField = {
    "ExchangeID": "char",
    "InstrumentID": "string",
    "ActionDay": "int",
    "UpdateTime": "int",
    "BidPrice": "double",
    "AskPrice": "double",
    "OrderNum": "short",
    "OrderVolume": "string",
}

CUTReqLoginField = {
    "UserID": "string",
    "Password": "string",
    "UserProductInfo": "string",
    "UserProductPassword": "string",
    "OneTimePassword": "string",
    "LoginRemark": "string",
}

