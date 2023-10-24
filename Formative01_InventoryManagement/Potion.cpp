#include "Potion.h"

#include <iostream>

#include "Inventory.h"

std::map<Potion::PotionSize, std::string> Potion::SizeName = {{Small, "Small"},	{Medium, "Medium"},	{Large, "Large"}};


Potion::Potion(const PotionSize potSize) : Size(potSize)
{
	SetType("Potion");
}

Potion::Potion()
= default;

void Potion::Use()
{
	std::cout << "You use a " << GetName() << " and gain " << SizeValue.at(Size) << " " << Stat << std::endl;
	backpack.Add(*this, -1);
}

nlohmann::json Potion::Serialize()
{
	nlohmann::json itemData;
	itemData["Name"] = GetName();
	itemData["Type"] = GetType();
	itemData["SubType"] = GetSubType();
	itemData["Size"] = GetPotionSize();

	return itemData;
}

void Potion::Deserialize(const nlohmann::json& itemData) {

	PotionSize tempSize = {};
	for (const auto& pair : SizeName)
	{
		if (pair.second == itemData["SubType"])
		{
			tempSize = pair.first;
		}
	}
	SetName(itemData["Name"]);
	SetType(itemData["Type"]);
	SetSubType(itemData["SubType"]);
	SetPotionSize(tempSize);
}
