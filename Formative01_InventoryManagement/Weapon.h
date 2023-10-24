#pragma once
#include <map>
#include "Item.h"

class Weapon final : public Item
{
public:

	enum WeaponType { Axe, Bow, Sword };
	static std::map<WeaponType, std::string> WeaponTypeName;

private:

	WeaponType SubType;
	int Damage;

public:

	Weapon(const std::string& name, WeaponType subType, int damage);
	Weapon();

	std::string GetSubType() const { return WeaponTypeName.at(SubType); }
	void SetSubType(const WeaponType type) { SubType = type; }

	int GetDamage() const { return Damage; }
	void SetDamage(const int damage) { Damage = damage; }

	nlohmann::json Serialize() override;
	void Deserialize(const nlohmann::json& itemData) override;

	void Use() override;

};

