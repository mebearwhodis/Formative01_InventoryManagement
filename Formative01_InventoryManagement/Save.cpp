#include "Save.h"

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

#include "HealthPotion.h"
#include "Map.h"
#include "Potion.h"
#include "StrengthPotion.h"

void SaveGame(const std::string& saveFileName) {
	nlohmann::json saveData;

	// Create a JSON array for storing item data
	nlohmann::json inventoryArray = nlohmann::json::array();

	for (const auto& item : backpack.GetInventory()) {

		nlohmann::json itemData;

		// Serialize the item and add it to the item's JSON object, then add the amount
		itemData["Item"] = item.first->Serialize();
		itemData["Amount"] = item.second;

		// Add the object to array
		inventoryArray.push_back(itemData);
	}

	// Add the inventory array to the JSON object
	saveData["Inventory"] = inventoryArray;

	// Write it to a file
	std::ofstream saveFile(saveFileName);
	saveFile << std::setw(1) << saveData;
	saveFile.close();
}

void LoadGame(const std::string& saveFileName) {
	nlohmann::json saveData;

	// Read the save file and put it in a variable to then close it
	std::ifstream saveFile(saveFileName);
	saveFile >> saveData;
	saveFile.close();

	// Deserialize and create items for the player's inventory and get the Amount
	for (const auto& itemData : saveData["Inventory"]) {
		const int amount = itemData["Amount"];

		// Deserialize the item properties.
		nlohmann::json itemProperties = itemData["Item"];

		// Depending on the item type, create the corresponding item
		Item* item = nullptr;
		if (itemProperties["Type"] == "Potion")
		{
			if(itemProperties["SubType"] == "Health")
			{
				item = new HealthPotion();
				item->Deserialize(itemProperties);
			}
			else if(itemProperties["SubType"] == "Strength")
			{
				item = new StrengthPotion();
				item->Deserialize(itemProperties);
			}
		}
		else if (itemProperties["Type"] == "Weapon")
		{
			item = new Weapon();
			item->Deserialize(itemProperties);
		}
		else if (itemProperties["Type"] == "Map")
		{
			item = new Map();
			item->Deserialize(itemProperties);
		}
		// Add the item to the player's inventory with the specified amount
		backpack.Add(*item, amount);
	}
}
