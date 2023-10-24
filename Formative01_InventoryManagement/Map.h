#pragma once
#include "Item.h"

class Map : public Item
{
	std::string Area;

public:

	Map(const std::string& name, const std::string& area);
	Map();

	std::string GetMapArea() { return Area; }
	void SetArea(const std::string& area) { Area = area; }

	nlohmann::json Serialize() override;
	void Deserialize(const nlohmann::json& itemData) override;

	void Use() final;
};

