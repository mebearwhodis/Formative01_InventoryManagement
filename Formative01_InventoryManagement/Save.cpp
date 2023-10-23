#include "Save.h"

#include <fstream>
#include <nlohmann/json.hpp>

void Save(Inventory& inv, const std::string& fileName)
{
	//Gets inventory and put it in a json var
	nlohmann::json myFile;

	std::map<Item*, int> tempMap = inv.GetInventory();
	for (auto it = tempMap.begin(); it != tempMap.end(); ++it)
	{
		myFile.emplace(it->first->GetName(), it->second);
		//std::cout << it->first->GetName() << "(s) in backpack: " << it->second << std::endl;
	}

	//delete existing save file, recreate it and put the content of myFile in it
	remove(fileName.c_str());
	std::ofstream outFile(fileName);
	outFile << std::setw(4) << myFile << std::endl;

	outFile.close();
}
//
// I tried a lot of different ways but couldn't figure out how to save all the classes and derived classes so that I can then use them in the constructors. Using a map with the amount of item rather than a vector probably did not make things easier for me

//void Load()
//{
//	std::ifstream inFile("save1.json");
//	for (auto& it : inFile)
//	{
//		backpack.Add(it.key, it.value);
//	}
//	inFile.close();
//}
