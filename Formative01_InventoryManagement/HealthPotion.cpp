#include "HealthPotion.h"

HealthPotion::HealthPotion(const PotionSize potSize) : Potion(potSize)
{
	SetSizeValue({ {Small, 20}, { Medium, 50},{ Large, 100 } });
	SetStat("hitpoints");

	SetDescription("Regain health (20/50/100)");
	SetName(SizeName.at(potSize) + " health potion");
	SetSubType("Health");
}