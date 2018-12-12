# ShopTask

This is an implementation of shop checkout system that can scan and void items, as well as calculate their total price.
Items are identified using Stock Keeping Units (SKUs) using numbers from range <0, 4,294,967,295>
Items can be priced individually, or multi-priced, buy N of them, and they will cost less in total.

How to use:
First prepare some ShopItem objects, setting their SKU, unitPrice, discountAmount and discountPrice, where:
- SKU is their unique stock keeping unit
- unitPrice is main price for one item, no discount
- discountAmount determines how many items you have to buy to get discountPrice (having this value set to 0 means that there are no discounts for this item)
- discountPrice is total price for discounted items

Next step is to set up PricingRules, so CheckOut system can Scan and Void items correctly.
Add rules using previously created ShopItems.
Remove unnecessary rules using previously created ShopItems.
Adding a ShopItem to rules with existing SKU does nothing. In order to change ShopItem rule with the same SKU, remove this rule first, then add the new one.

Finally create CheckOut object, which takes PricingRules as an argument. Once set PricingRules cannot be changed later.
CheckOut allows you to Scan items, giving ShopItem object as an argument, as well as Void them the same way.
Void no scanned items does nothing.
Once Scanning is done, you can GetTotal price of all scanned items. All items which are missing in PricingRules are skipped.

Example usage:

 	 // set up some ShopItems
	ShopItem itemA(1, 50, 3, 130);
	ShopItem itemB(2, 30, 2, 45);
	ShopItem itemC(3, 20);
	ShopItem itemD(4, 15); // these three items have no discount
	ShopItem itemE(1, 15);

	PricingRules rules; // create rules based on these items
	rules.AddRule(itemA);
	rules.AddRule(itemB);
	rules.AddRule(itemC);
	rules.AddRule(itemD);
	rules.AddRule(itemE);
	rules.RemoveRule(itemE); // we changed our mind, remove this rule

	CheckOut co(rules); // create CheckOut object using previously created PricingRules
	co.Scan(itemA); // scan some items

	co.Void(itemB); // this action does nothing, as we haven't scanned itemB before

	co.Scan(itemA);
	co.Scan(itemA);
	co.Scan(itemA); // scan some more items
	co.Scan(itemA);

	co.Scan(itemB);
	co.Scan(itemB);

	co.Scan(itemC); // and more

	co.Scan(itemD);
	co.Scan(itemD);
	std::cout << "Total price: " << co.GetTotal() << std::endl; // let's see total price
