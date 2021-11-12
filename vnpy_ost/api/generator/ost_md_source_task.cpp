void MdApi::OnRspSubL2MarketData(const CSecurityDntRspInfoField& reply) 
{
	Task task = Task();
	task.task_name = ONRSPSUBL2MARKETDATA;
	CSecurityDntRspInfoField *task_data = new CSecurityDntRspInfoField();
	*task_data = reply;
	task.task_data = task_data;
	this->task_queue.push(task);
};

void MdApi::OnRspUnSubL2MarketData(const CSecurityDntRspInfoField& reply) 
{
	Task task = Task();
	task.task_name = ONRSPUNSUBL2MARKETDATA;
	CSecurityDntRspInfoField *task_data = new CSecurityDntRspInfoField();
	*task_data = reply;
	task.task_data = task_data;
	this->task_queue.push(task);
};

void MdApi::OnRspSubL2OrderAndTrade(const CSecurityDntRspInfoField& reply) 
{
	Task task = Task();
	task.task_name = ONRSPSUBL2ORDERANDTRADE;
	CSecurityDntRspInfoField *task_data = new CSecurityDntRspInfoField();
	*task_data = reply;
	task.task_data = task_data;
	this->task_queue.push(task);
};

void MdApi::OnRspUnSubL2OrderAndTrade(const CSecurityDntRspInfoField& reply) 
{
	Task task = Task();
	task.task_name = ONRSPUNSUBL2ORDERANDTRADE;
	CSecurityDntRspInfoField *task_data = new CSecurityDntRspInfoField();
	*task_data = reply;
	task.task_data = task_data;
	this->task_queue.push(task);
};

void MdApi::OnRspSubL2IndexMarketData(const CSecurityDntRspInfoField& reply) 
{
	Task task = Task();
	task.task_name = ONRSPSUBL2INDEXMARKETDATA;
	CSecurityDntRspInfoField *task_data = new CSecurityDntRspInfoField();
	*task_data = reply;
	task.task_data = task_data;
	this->task_queue.push(task);
};

void MdApi::OnRspUnSubL2IndexMarketData(const CSecurityDntRspInfoField& reply) 
{
	Task task = Task();
	task.task_name = ONRSPUNSUBL2INDEXMARKETDATA;
	CSecurityDntRspInfoField *task_data = new CSecurityDntRspInfoField();
	*task_data = reply;
	task.task_data = task_data;
	this->task_queue.push(task);
};

void MdApi::OnRtnL2MarketData(const CSecurityDntMarketDataField& reply) 
{
	Task task = Task();
	task.task_name = ONRTNL2MARKETDATA;
	CSecurityDntMarketDataField *task_data = new CSecurityDntMarketDataField();
	*task_data = reply;
	task.task_data = task_data;
	this->task_queue.push(task);
};

void MdApi::OnRtnL2IndexMarketData(const CSecurityDntL2IndexField& reply) 
{
	Task task = Task();
	task.task_name = ONRTNL2INDEXMARKETDATA;
	CSecurityDntL2IndexField *task_data = new CSecurityDntL2IndexField();
	*task_data = reply;
	task.task_data = task_data;
	this->task_queue.push(task);
};

void MdApi::OnRtnL2Order(const CSecurityDntL2OrderField& pL2Order) 
{
	Task task = Task();
	task.task_name = ONRTNL2ORDER;
	CSecurityDntL2OrderField *task_data = new CSecurityDntL2OrderField();
	*task_data = reply;
	task.task_data = task_data;
	this->task_queue.push(task);
};

void MdApi::OnRtnL2Trade(const CSecurityDntL2TradeField& pL2Trade) 
{
	Task task = Task();
	task.task_name = ONRTNL2TRADE;
	CSecurityDntL2TradeField *task_data = new CSecurityDntL2TradeField();
	*task_data = reply;
	task.task_data = task_data;
	this->task_queue.push(task);
};

