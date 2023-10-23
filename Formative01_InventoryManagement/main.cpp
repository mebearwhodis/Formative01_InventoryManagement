// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

#include "HealthPotion.h"
#include "Map.h"
#include "Save.h"
#include "StrengthPotion.h"
#include "Weapon.h"


int main()
{
	//Check Inventory: shows the whole thing, how many you have, etc.

	//constructors for different items
	HealthPotion hpPotion0(Potion::Small);
	HealthPotion hpPotion1(Potion::Medium);
	HealthPotion hpPotion2(Potion::Large);
	StrengthPotion strPotion0(Potion::Small);
	StrengthPotion strPotion1(Potion::Medium);
	StrengthPotion strPotion2(Potion::Large);
	Weapon legendaryBow("Thori'dal", Weapon::Bow, 250);
	Weapon commonSword("Claymore", Weapon::Sword, 100);
	Weapon rareAxe("Random Axe Name", Weapon::Axe, 150);
	Map oldMap("Old map", "Queen's Gardens");


	std::cout << hpPotion2.GetDescription() << std::endl;
	backpack.Add(legendaryBow, 1);
	backpack.Add(oldMap, 1);
	legendaryBow.Use();
	backpack.Add(hpPotion0,9);
	backpack.Add(hpPotion2, 21);
	backpack.Add(strPotion1, 52);
	Inventory::UseConsumable(hpPotion2);

	Save(backpack,"save1.json");
}
