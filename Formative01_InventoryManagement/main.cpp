// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "HealthPotion.h"
#include "Map.h"
#include "Save.h"
#include "StrengthPotion.h"
#include "Utils.h"
#include "Weapon.h"


int main()
{
	// Constructs different items
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

	if (YesNoQuestion("Do you want to load your previous inventory?")) 
	{
		LoadGame("mysave.json");
	}
	else
	{
		// Adds some random items in case we don't load a save
		backpack.Add(legendaryBow, 1);
		backpack.Add(oldMap, 1);
		backpack.Add(commonSword, 1);
		backpack.Add(hpPotion0, 9);
		backpack.Add(hpPotion2, 1);
		backpack.Add(strPotion1, 12);
		backpack.Add(strPotion0, 5);

	}
	do
	{
		system("cls");

		// Check Inventory: shows the whole thing, how many you have, etc.
		// Display items
		backpack.Display();

		// Asks the user what item they want to use and use it
		Inventory::UseItem();

	} while (YesNoQuestion("Do you want to use an item again?"));
	if(YesNoQuestion("Do you want to save your inventory?"))
	{
		SaveGame("mysave.json");
	}
	exit(0);
}