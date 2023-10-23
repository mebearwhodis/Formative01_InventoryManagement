#pragma once
#include "Item.h"

class Map : public Item
{
	std::string Area;

public:

	Map(const std::string& name, const std::string& area);
	std::string GetMapArea() { return Area; }

	void Use() final;
};

