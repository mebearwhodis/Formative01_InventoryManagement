#pragma once
#include <map>
#include "Item.h"

class Inventory
{
	std::map<Item*, int> Storage;

public:
	void Add(Item& item, int amount);
	static void UseConsumable(Item& item);

	//getter
	std::map<Item*, int> GetInventory() { return Storage; }
};

extern Inventory backpack;
