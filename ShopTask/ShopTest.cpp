#include <cassert>
#include "ShopTest.h"



ShopTest::ShopTest()
{ }



ShopTest::~ShopTest()
{
}

void ShopTest::RunAllTests()
{
	TestNoDiscount();
	TestSingleDiscount();
	TestAllDiscount();
}

void ShopTest::TestNoDiscount()
{
	const std::uint32_t itemAPrice = 100;
	const std::uint32_t itemBPrice = 150;
	const std::uint32_t itemCPrice = 250;
	PricingRules rules;
	ShopItem itemA(1, itemAPrice, 0, 0);
	ShopItem itemB(2, itemBPrice, 0, 0);
	ShopItem itemC(3, itemCPrice, 0, 0);
	rules.AddRule(itemA);
	rules.AddRule(itemB);
	rules.AddRule(itemC);
	CheckOut co(rules);
	co.Scan(itemA);
	assert(itemAPrice == co.GetTotal());
	co.Scan(itemB);
	assert((itemAPrice + itemBPrice) == co.GetTotal());
	co.Scan(itemC);
	assert((itemAPrice + itemBPrice + itemCPrice) == co.GetTotal());
	co.Void(itemA);
	assert((itemBPrice + itemCPrice) == co.GetTotal());
	co.Void(itemB);
	assert(itemCPrice == co.GetTotal());
}

void ShopTest::TestSingleDiscount()
{
	const std::uint32_t itemAPrice = 100;
	const std::uint32_t itemAAmount = 3;
	const std::uint32_t itemADiscount = 250;
	const std::uint32_t itemBPrice = 150;
	const std::uint32_t itemCPrice = 250;
	PricingRules rules;
	ShopItem itemA(1, itemAPrice, itemAAmount, itemADiscount);
	ShopItem itemB(2, itemBPrice, 0, 0);
	ShopItem itemC(3, itemCPrice, 0, 0);
	rules.AddRule(itemA);
	rules.AddRule(itemB);
	rules.AddRule(itemC);
	CheckOut co(rules);
	co.Scan(itemA);
	co.Scan(itemA);
	co.Scan(itemA);
	assert(itemADiscount == co.GetTotal());
	co.Void(itemA);
	assert(2 * itemAPrice == co.GetTotal());
	co.Scan(itemA);
	co.Scan(itemB);
	co.Scan(itemB);
	co.Scan(itemB);
	co.Scan(itemC);
	co.Scan(itemC);
	co.Scan(itemC);
	assert(itemADiscount + 3 * itemBPrice + 3 * itemCPrice == co.GetTotal());
}

void ShopTest::TestAllDiscount()
{
	const std::uint32_t itemAPrice = 100;
	const std::uint32_t itemAAmount = 3;
	const std::uint32_t itemADiscount = 250;
	const std::uint32_t itemBPrice = 150;
	const std::uint32_t itemBAAmount = 4;
	const std::uint32_t itemBDiscount = 550;
	const std::uint32_t itemCPrice = 250;
	const std::uint32_t itemCAmount = 5;
	const std::uint32_t itemCDiscount = 1000;
	PricingRules rules;
	ShopItem itemA(1, itemAPrice, itemAAmount, itemADiscount);
	ShopItem itemB(2, itemBPrice, itemBAAmount, itemBDiscount);
	ShopItem itemC(3, itemCPrice, itemCAmount, itemCDiscount);
	rules.AddRule(itemA);
	rules.AddRule(itemB);
	rules.AddRule(itemC);
	CheckOut co(rules);
	co.Scan(itemA);
	co.Scan(itemA);
	co.Scan(itemA);
	co.Scan(itemB);
	co.Scan(itemB);
	co.Scan(itemB);
	co.Scan(itemB);
	co.Scan(itemC);
	co.Scan(itemC);
	co.Scan(itemC);
	co.Scan(itemC);
	co.Scan(itemC);
	assert(itemADiscount + itemBDiscount + itemCDiscount == co.GetTotal());
}