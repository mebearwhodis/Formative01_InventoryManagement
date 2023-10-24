#pragma once
#include <string>
#include <nlohmann/json.hpp>

class Item
{
	std::string Name;
	std::string Description;
	std::string Type;

public:

	virtual ~Item() = default;

	std::string GetName() { return Name; }
	void SetName(const std::string& name) { Name = name; }

	std::string GetDescription() { return Description; }
	void SetDescription(const std::string& description) { Description = description; }

	std::string GetType() { return Type; }
	void SetType(const std::string& type) { Type = type; }

	virtual nlohmann::json Serialize();
	virtual void Deserialize(const nlohmann::json& itemData);

	virtual void Use();
};


