#include "Weapon.h"
#include <iostream>


Weapon::Weapon(const std::string& name, const WeaponType type, const int damage) : Damage(damage), Type(type)
{
	SetName(name);
}

void Weapon::Use()
{
	std::cout << "You use " << GetName() << " and deal " << Damage << " damage." << std::endl;
}
