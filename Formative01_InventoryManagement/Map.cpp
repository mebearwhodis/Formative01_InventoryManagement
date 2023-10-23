#include "Map.h"
#include <iostream>

Map::Map(const std::string& name, const std::string& area) : Area(area)
{
	SetName(name);
}

void Map::Use()
{
	std::cout << "You use your " << GetName() << " and reveal the " << Area << " area." << std::endl;
}