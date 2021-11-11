case ONRSPSUBL2MARKETDATA:
{
	this->processRspSubL2MarketData(&task);
	break;
}

case ONRSPUNSUBL2MARKETDATA:
{
	this->processRspUnSubL2MarketData(&task);
	break;
}

case ONRSPSUBL2ORDERANDTRADE:
{
	this->processRspSubL2OrderAndTrade(&task);
	break;
}

case ONRSPUNSUBL2ORDERANDTRADE:
{
	this->processRspUnSubL2OrderAndTrade(&task);
	break;
}

case ONRSPSUBL2INDEXMARKETDATA:
{
	this->processRspSubL2IndexMarketData(&task);
	break;
}

case ONRSPUNSUBL2INDEXMARKETDATA:
{
	this->processRspUnSubL2IndexMarketData(&task);
	break;
}

case ONRTNL2MARKETDATA:
{
	this->processRtnL2MarketData(&task);
	break;
}

case ONRTNL2INDEXMARKETDATA:
{
	this->processRtnL2IndexMarketData(&task);
	break;
}

case ONRTNL2ORDER:
{
	this->processRtnL2Order(&task);
	break;
}

case ONRTNL2TRADE:
{
	this->processRtnL2Trade(&task);
	break;
}

