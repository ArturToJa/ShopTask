#include "CheckOut.h"
#include <iostream>


CheckOut::CheckOut(PricingRules rules) : rules(rules)
{ }

void CheckOut::Scan(const ShopItem item)
{
	Scan(item.GetStockKeepingUnits());
}

void CheckOut::Scan(const std::uint32_t stockKeepingUnits)
{
	if (rules.RuleExists(stockKeepingUnits)) // scan this item only it rule for it exists
	{
		scannedItems[stockKeepingUnits]++;
	}
}

void CheckOut::Void(const ShopItem item)
{
	Void(item.GetStockKeepingUnits());
}

void CheckOut::Void(const std::uint32_t stockKeepingUnits)
{
	if (rules.RuleExists(stockKeepingUnits) && scannedItems[stockKeepingUnits] > 0) // void this item only it rule for it exists
																					// and there are any items of this type scanned
	{
		scannedItems[stockKeepingUnits]--;
	}
}

const std::uint64_t CheckOut::GetTotal()
{
	std::uint64_t totalPrice = 0;
	for (std::map<std::uint32_t, std::uint32_t>::iterator it = scannedItems.begin(); it != scannedItems.end(); it++) // loop through all scanned item types
	{
		const ShopItem * item = rules.GetRule(it->first); // should return pointer to ShopItem only if this rule exist
		if (item != nullptr)
		{
			std::uint32_t discountItems = it->second;
			std::uint32_t noDiscountItems = discountItems;
			if (item->GetDiscountAmount() != 0) // try to apply discount only, if discount amount is different from 0
			{
				noDiscountItems = discountItems % item->GetDiscountAmount(); // how many items are excluded from discount
				discountItems -= noDiscountItems; // how many items are included in discount
				std::uint32_t discountNumber = discountItems / item->GetDiscountAmount(); // how many discounts are there in total
				totalPrice += (discountNumber * item->GetDiscountPrice()); // calculate total discount price for this item type
			}
			totalPrice += (noDiscountItems * item->GetUnitPrice()); // calculate total price for this item type
		}
	}
	return totalPrice;
}