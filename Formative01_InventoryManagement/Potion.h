#pragma once
#include <map>
#include "Item.h"


class Potion : public Item
{
public:

	enum PotionSize { Small, Medium, Large };
	static std::map<PotionSize, std::string> SizeName;

private:

	std::string SubType;
	PotionSize Size;
	std::string Stat;
	std::map<PotionSize, int> SizeValue;

public:

	Potion(PotionSize potSize);
	Potion();

	std::string GetSubType() { return SubType; }
	void SetSubType(const std::string& subType) { SubType = subType; }

	std::string GetPotionSize() const { return SizeName.at(Size); }
	void SetPotionSize(const PotionSize size) { Size = size; }

	std::string GetStat() { return Stat; }
	void SetStat(const std::string& stat) { Stat = stat; }

	std::map<PotionSize, int> GetSizeValue() { return SizeValue; }
	PotionSize GetSize() const { return Size; }
	void SetSizeValue(const std::map<PotionSize, int>& sizeValue) { SizeValue = sizeValue; }

	nlohmann::json Serialize() final;
	void Deserialize(const nlohmann::json& itemData) final;

	void Use() final;

};

