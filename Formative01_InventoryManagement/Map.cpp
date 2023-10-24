#include "Map.h"
#include <iostream>

#include "Inventory.h"

Map::Map(const std::string& name, const std::string& area) : Area(area)
{
	SetName(name);
	SetType("Map");
	SetDescription("Yup. That's a map. But where's the north?");
}

Map::Map()
{
	SetDescription("Yup. That's a map. But where's the north?");
}

void Map::Use()
{
	system("cls");
	backpack.Display();
	std::cout << "You use your " << GetName() << " and reveal the " << Area << " area." << std::endl;
}

nlohmann::json Map::Serialize()
{
	nlohmann::json itemData;
	itemData["Name"] = GetName();
	itemData["Type"] = GetType();
	itemData["Area"] = GetMapArea();

	return itemData;
}

void Map::Deserialize(const nlohmann::json& itemData) {
	SetName(itemData["Name"]);
	SetType(itemData["Type"]);
	SetArea(itemData["Area"]);
}