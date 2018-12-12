#pragma once
#include <map>

#include "ShopItem.h"

class PricingRules
{
public:
	PricingRules();
	void AddRule(const ShopItem item); // adds new rule to our map, does not override existing rules
	void RemoveRule(const ShopItem item); // removes existing rule
	const ShopItem * GetRule(const std::uint32_t stockKeepingUnits); // returns specific rule if exists in shopItems map
	const bool RuleExists(const std::uint32_t stockKeepingUnits) const; // check if this rule exist in shopItems map
	~PricingRules();

private:
	std::map<std::uint32_t, ShopItem> shopItems; // map of shopItems, keys are SKUs, values are shopItems themselves
};