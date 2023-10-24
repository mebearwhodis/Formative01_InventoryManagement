#include "StrengthPotion.h"

StrengthPotion::StrengthPotion(const PotionSize potSize) : Potion(potSize)
{
	SetSizeValue({ {Small, 5}, { Medium, 10},{ Large, 30 } });
	SetStat("temporary strength");

	SetDescription("Gain temporary strength (5/10/30)");
	SetName(SizeName.at(potSize) + " strength potion");
	SetSubType("Strength");
}

StrengthPotion::StrengthPotion()
{
	SetSizeValue({ {Small, 5}, { Medium, 10},{ Large, 30 } });
	SetStat("temporary strength");
	SetDescription("Gain temporary strength (5/10/30)");
}
