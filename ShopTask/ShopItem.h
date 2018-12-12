#pragma once
#include <cstdint>

struct SpecialPrice
{
	const std::uint32_t discountAmount;
	const std::uint32_t discountPrice;
	SpecialPrice();
	SpecialPrice(const std::uint32_t discountAmount, const std::uint32_t discountPrice);
};

class ShopItem
{
public:
	ShopItem(const std::uint32_t stockKeepingUnits, const std::uint32_t unitPrice);
	ShopItem(const std::uint32_t stockKeepingUnits, const std::uint32_t unitPrice, SpecialPrice specialPrice);
	ShopItem(const std::uint32_t stockKeepingUnits, const std::uint32_t unitPrice, const std::uint32_t discountAmount, const std::uint32_t discountPrice);
	const std::uint32_t GetStockKeepingUnits() const;
	const std::uint32_t GetUnitPrice() const;
	const std::uint32_t GetDiscountAmount() const;
	const std::uint32_t GetDiscountPrice() const;

private:
	const std::uint32_t stockKeepingUnits;
	const std::uint32_t unitPrice;
	const SpecialPrice specialPrice;
};