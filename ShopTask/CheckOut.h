#pragma once
#include <cstdint>

#include "PricingRules.h"


class CheckOut
{
public:
	CheckOut(PricingRules rules);
	void Scan(const ShopItem item);
	void Scan(const std::uint32_t stockKeepingUnits);
	void Void(const ShopItem item);
	void Void(const std::uint32_t stockKeepingUnits);
	const std::uint64_t GetTotal(); // count total price here for all scanned items including discounts

private:
	PricingRules rules; // keep our rules here
	std::map<std::uint32_t, std::uint32_t> scannedItems; // keep how many items with specific SKU are scanned
};