CUDPAddrInfo = {
    "Addr": "string",
    "Port": "int32_t",
}

CMulitcastInfo = {
    "MDType": "uint16_t",
    "RemoteAddr": "dict",
    "LocalAddr": "dict",
}

CSecurityDntSubscribeReq = {
    "SecuritySource": "uint16_t",
    "SecurityId": "string",
}

CSecurityDntRspInfoField = {
    "ErrorID": "int32_t",
    "ErrorMsg": "string",
}

EntryInfo = {
    "Level": "uint16_t",
    "Price": "int64_t",
    "OrderQty": "int64_t",
}

CSecurityDntMarketDataField = {
    "OrigTime": "int64_t",
    "ChannelNo": "uint16_t",
    "MarketId": "uint16_t",
    "MDStreamId": "enum",
    "MDStreamType": "enum",
    "SecurityId": "string",
    "PreClosePx": "int64_t",
    "OpenPx": "int64_t",
    "ClosePx": "int64_t",
    "LastPx": "int64_t",
    "HighPx": "int64_t",
    "LowPx": "int64_t",
    "UpperLimit": "int64_t",
    "LowerLimit": "int64_t",
    "TradingPhase": "char",
    "TradeNums": "int64_t",
    "TradeVolumn": "int64_t",
    "TradeValue": "int64_t",
    "BuyLength": "uint16_t",
    "BuyEntry": "dict",
    "SellLength": "uint16_t",
    "SellEntry": "dict",
}

CSecurityDntL2TradeField = {
    "ChannelNo": "uint16_t",
    "MarketId": "uint16_t",
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
    "MarketId": "uint16_t",
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
    "TimeStamp": "int64_t",
    "MarketId": "uint16_t",
    "SecurityID": "string",
    "PreCloseIndex": "int64_t",
    "OpenIndex": "int64_t",
    "CloseIndex": "int64_t",
    "HighIndex": "int64_t",
    "LowIndex": "int64_t",
    "LastIndex": "int64_t",
    "TurnOver": "int64_t",
    "TotalVolume": "int64_t",
}
