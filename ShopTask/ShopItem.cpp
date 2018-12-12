#include "ShopItem.h"

SpecialPrice::SpecialPrice() : discountAmount(0), discountPrice(0)
{ }

SpecialPrice::SpecialPrice(const std::uint32_t discountAmount, const std::uint32_t discountPrice)
					: discountAmount(discountAmount), discountPrice(discountPrice)
{ }



ShopItem::ShopItem(const std::uint32_t stockKeepingUnits, const std::uint32_t unitPrice)
					: stockKeepingUnits(stockKeepingUnits), unitPrice(unitPrice)
{ }

ShopItem::ShopItem(const std::uint32_t stockKeepingUnits, const std::uint32_t unitPrice, SpecialPrice specialPrice)
					: stockKeepingUnits(stockKeepingUnits), unitPrice(unitPrice), specialPrice(specialPrice)
{ }

ShopItem::ShopItem(const std::uint32_t stockKeepingUnits, const std::uint32_t unitPrice, const std::uint32_t discountAmount, const std::uint32_t discountPrice)
					: stockKeepingUnits(stockKeepingUnits), unitPrice(unitPrice), specialPrice(SpecialPrice(discountAmount, discountPrice))
{ }

const std::uint32_t ShopItem::GetStockKeepingUnits() const
{
	return stockKeepingUnits;
}

const std::uint32_t ShopItem::GetUnitPrice() const
{
	return unitPrice;
}

const std::uint32_t ShopItem::GetDiscountAmount() const
{
	return specialPrice.discountAmount;
}

const std::uint32_t ShopItem::GetDiscountPrice() const
{
	return specialPrice.discountPrice;
}
