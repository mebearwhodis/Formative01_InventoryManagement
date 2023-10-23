#include "StrengthPotion.h"

StrengthPotion::StrengthPotion(const PotionSize potSize) : Potion(potSize)
{
	SizeValue = { {Small, 5}, { Medium, 10},{ Large, 30 } };

	Stat = "temporary strength";

	SetDescription("Gain temporary strength (5/10/30)");
	SetName(SizeName.at(potSize) + " strength potion");
}
