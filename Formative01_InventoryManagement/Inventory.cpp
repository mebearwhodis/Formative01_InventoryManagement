#include "Inventory.h"

#include <iostream>

#include "Utils.h"
#include "Weapon.h"

Inventory backpack;
std::map<int, Item*> displayMap;

// By default, a knife is equipped - could also have checked if something is equipped or not
Weapon baseKnife("A kitchen knife", Weapon::Sword, 1);
Weapon* Inventory::EquippedWeapon = &baseKnife;

// Adds the item and the amount to the Inventory map
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

void Inventory::UseItem()
{
	const int itemNb = ValidNumber("Which item would you like to use?", 0, backpack.Storage.size() - 1);
	Item* itemToUse = displayMap.at(itemNb);

	const int& itemAmount = backpack.Storage.at(itemToUse);
	if (itemAmount > 0)
	{
		// Use the selected item
		itemToUse->Use();
	}
	else
	{
		std::cout << "You don't have any of that item." << std::endl;
	}

}

void Inventory::Display() const
{
	int idx = 0;
	std::string nbItem;
	Weapon* currentlyEquipped = GetEquippedWeapon();
	for (const auto& oneItem : Storage)
	{
		displayMap.emplace(idx, oneItem.first);
		if (oneItem.first->GetName() == currentlyEquipped->GetName())
		{
			nbItem = " -Equipped";
		}
		else
		{
			nbItem = " *" + std::to_string(oneItem.second);
		}
		std::cout << idx++ << ". " << oneItem.first->GetName() << nbItem << std::endl;
	}
}

