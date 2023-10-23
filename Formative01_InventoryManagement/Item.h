#pragma once
#include <string>

class Item
{
	std::string Name;
	std::string Description;

public:

	virtual ~Item() = default;

	std::string GetName() { return Name; }
	void SetName(const std::string& name) { Name = name; }
	std::string GetDescription() { return Description; }
	void SetDescription(const std::string& description) { Name = description; }

	virtual void Use();
};


