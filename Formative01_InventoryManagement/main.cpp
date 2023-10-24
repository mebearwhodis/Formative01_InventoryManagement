// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

#include "HealthPotion.h"
#include "Map.h"
#include "Save.h"
#include "StrengthPotion.h"
#include "UI.h"
#include "Weapon.h"


int main()
{
	// Check Inventory: shows the whole thing, how many you have, etc.

	// Constructors for different items
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


	backpack.Add(legendaryBow, 1);
	backpack.Add(oldMap, 1);

	backpack.Add(commonSword, 5);
	legendaryBow.Use();
	backpack.Add(hpPotion0,9);
	commonSword.Use();
	backpack.Add(hpPotion2, 21);
	backpack.Add(strPotion1, 52);
	hpPotion2.Use();

	Save(backpack,"save1.json");


	do
	{
		system("cls");

		// Display items
		backpack.Display();

		// Asks the user what item they want to use and use it
		Inventory::UseItem();


	} while (YesNoQuestion("Do you want to play again?"));
	exit(0);
}