#pragma once
#include "CheckOut.h"

class ShopTest
{
public:
	ShopTest();
	~ShopTest();
	void RunAllTests();
	void TestNoDiscount();
	void TestSingleDiscount();
	void TestAllDiscount();
};