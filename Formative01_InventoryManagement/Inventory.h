#pragma once
#include <map>
#include "Item.h"
#include "Weapon.h"


class Inventory
{
	std::map<Item*, int> Storage;
	static Weapon* EquippedWeapon;

public:
	void Add(Item& item, int amount);
	
	static void UseItem();

	// Getters
	std::map<Item*, int> GetInventory() { return Storage; }
	static Weapon* GetEquippedWeapon() { return EquippedWeapon; }

	// Setters
	static void SetEquippedWeapon(Weapon* weapon) { EquippedWeapon = weapon; }


	void Display() const;
};

extern Inventory backpack;
extern std::map<int, Item*> displayMap;
