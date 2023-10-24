#include "Inventory.h"

#include <iostream>

#include "Weapon.h"

Inventory backpack;

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
	int itemNb;
	std::cout << "Which item do you want to use?" << std::endl;
	std::cin >> itemNb;

	// Check if itemNb is a valid index in the inventory
	if (itemNb >= 0 && itemNb < backpack.Storage.size())
	{
		// Iterate through the inventory to find the item at the specified index
		auto it = backpack.Storage.begin();
		std::advance(it, itemNb);

		Item* itemToUse = it->first;
		const int& itemAmount = it->second;

		if (itemAmount > 0)
		{
			// Use the selected item
			itemToUse->Use();

			// If the item amount reaches 0, remove it from the inventory
			if (itemAmount == 0)
			{
				backpack.Storage.erase(it);
			}
		}
		else
		{
			std::cout << "You don't have any of that item." << std::endl;
		}
	}
	else
	{
		std::cout << "Please enter a valid number." << std::endl;
	}
}

void Inventory::Display() const
{
	int idx = 0;
	std::string nbItem;
	Weapon* currentlyEquipped = GetEquippedWeapon();
	for (const auto& oneItem : Storage)
	{
		if(oneItem.first->GetName() == currentlyEquipped->GetName())
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

