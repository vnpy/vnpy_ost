
.def("onRspSubL2MarketData", &MdApi::onRspSubL2MarketData)
.def("onRspUnSubL2MarketData", &MdApi::onRspUnSubL2MarketData)
.def("onRspSubL2OrderAndTrade", &MdApi::onRspSubL2OrderAndTrade)
.def("onRspUnSubL2OrderAndTrade", &MdApi::onRspUnSubL2OrderAndTrade)
.def("onRspSubL2IndexMarketData", &MdApi::onRspSubL2IndexMarketData)
.def("onRspUnSubL2IndexMarketData", &MdApi::onRspUnSubL2IndexMarketData)
.def("onRtnL2MarketData", &MdApi::onRtnL2MarketData)
.def("onRtnL2IndexMarketData", &MdApi::onRtnL2IndexMarketData)
.def("onRtnL2Order", &MdApi::onRtnL2Order)
.def("onRtnL2Trade", &MdApi::onRtnL2Trade)
;
