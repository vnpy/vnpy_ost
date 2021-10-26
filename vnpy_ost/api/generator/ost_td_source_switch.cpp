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

