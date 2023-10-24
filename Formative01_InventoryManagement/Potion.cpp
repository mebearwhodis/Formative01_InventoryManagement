#include "Potion.h"

#include <iostream>

#include "Inventory.h"


Potion::Potion(const PotionSize potSize) : Size(potSize)
{
}

void Potion::Use()
{
	std::cout << "You use a " << GetName() << " and gain " << SizeValue.at(Size) << " " << Stat << std::endl;
	backpack.Add(*this, -1);
}
