#include "Weapon.h"
#include <iostream>
#include "Inventory.h"

std::map<Weapon::WeaponType, std::string> Weapon::WeaponTypeName{ {Axe, "Axe"}, {Bow, "Bow"}, {Sword, "Sword"} };

Weapon::Weapon(const std::string& name, const WeaponType subType, const int damage) : Damage(damage), SubType(subType)
{
	SetName(name);
	SetType("Weapon");
	SetDescription("Anything can be a weapon if you try hard enough.");
}

Weapon::Weapon()
{
	SetDescription("Anything can be a weapon if you try hard enough.");
}

void Weapon::Use()
{
	system("cls");

	Inventory::SetEquippedWeapon(this);
	backpack.Display();
	std::cout << "You equip " << GetName() << " which can deal up to " << Damage << " damage." << std::endl;
}

nlohmann::json Weapon::Serialize()
{
	nlohmann::json itemData;
	itemData["Name"] = GetName();
	itemData["Type"] = GetType();
	itemData["SubType"] = GetSubType();
	itemData["Damage"] = GetDamage();

	return itemData;
}

void Weapon::Deserialize(const nlohmann::json& itemData) {

	WeaponType tempType = {};
	for (const auto& pair : WeaponTypeName)
	{
		if (pair.second == itemData["SubType"])
		{
			tempType = pair.first;
		}
	}

	SetName(itemData["Name"]);
	SetType(itemData["Type"]);
	SetSubType(tempType);
	SetDamage(itemData["Damage"]);

}
