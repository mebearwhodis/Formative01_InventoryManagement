#include "Weapon.h"
#include <iostream>

#include "Inventory.h"


Weapon::Weapon(const std::string& name, const WeaponType type, const int damage) : Damage(damage), Type(type)
{
	SetName(name);
}

void Weapon::Use()
{
	std::cout << "You equip " << GetName() << " which can deal up to " << Damage << " damage." << std::endl;
	Inventory::SetEquippedWeapon(this);
}
