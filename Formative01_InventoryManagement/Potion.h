#pragma once
#include <map>
#include "Item.h"


class Potion : public Item
{
public:
	enum PotionSize { Small, Medium, Large };
	PotionSize Size;
	// Make a to string to use on other item types too
	std::map<PotionSize, std::string> SizeName{ {Small, "Small"}, {Medium, "Medium"}, {Large, "Large"} };
	std::map<PotionSize, int> SizeValue{};
	std::string Stat;

	Potion(PotionSize potSize);


	void Use() final;
};

