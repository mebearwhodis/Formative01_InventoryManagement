#pragma once
#include "Item.h"

class Weapon final : public Item
{
	int Damage;

public:

	enum WeaponType { Sword, Axe, Bow };
	WeaponType Type;

	Weapon(const std::string& name, WeaponType type, int damage);

	void Use() override;
};

