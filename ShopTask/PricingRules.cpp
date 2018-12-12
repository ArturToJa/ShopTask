#include "PricingRules.h"


PricingRules::PricingRules()
{
}

void PricingRules::AddRule(const ShopItem item)
{
	shopItems.insert(std::pair(item.GetStockKeepingUnits(), item));
}

void PricingRules::RemoveRule(const ShopItem item)
{
	shopItems.erase(item.GetStockKeepingUnits());
}

const ShopItem * PricingRules::GetRule(const std::uint32_t stockKeepingUnits)
{
	std::map<std::uint32_t, ShopItem>::iterator it = shopItems.find(stockKeepingUnits); //try to find this rule
	if (it != shopItems.end()) // check here whether this rule exists
		return &it->second; // this rule exists, return it
	else
		return nullptr; // oops, this rule does not exist, return nullptr
}

const bool PricingRules::RuleExists(const std::uint32_t stockKeepingUnits) const
{
	return shopItems.find(stockKeepingUnits) != shopItems.end(); // find() method is equal to end() only, when this rule does not exist
}


PricingRules::~PricingRules()
{
}
