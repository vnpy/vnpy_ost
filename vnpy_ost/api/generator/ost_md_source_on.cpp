void onRspSubL2MarketData(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onRspSubL2MarketData, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspUnSubL2MarketData(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onRspUnSubL2MarketData, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspSubL2OrderAndTrade(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onRspSubL2OrderAndTrade, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspUnSubL2OrderAndTrade(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onRspUnSubL2OrderAndTrade, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspSubL2IndexMarketData(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onRspSubL2IndexMarketData, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspUnSubL2IndexMarketData(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onRspUnSubL2IndexMarketData, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnL2MarketData(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onRtnL2MarketData, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnL2IndexMarketData(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onRtnL2IndexMarketData, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnL2Order(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onRtnL2Order, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnL2Trade(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onRtnL2Trade, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

