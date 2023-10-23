#include "Inventory.h"

Inventory backpack;

//adds the item and the amount to the map
void Inventory::Add(Item& item, int amount)
{
	if (Storage.find(&item) == Storage.end())
	{
		Storage.emplace(&item, amount);
	}
	else
	{
		Storage[&item] += amount;
	}
}

//intended for Potions and other consumables, removes one from the inventory when used
void Inventory::UseConsumable(Item& item)
{
	item.Use();
	backpack.Add(item, -1);
}