#pragma once

#include <string>

class Item
{
public:
	Item();
	~Item();
	Item(std::string aName);
	Item(std::string aName, std::string aDesc, int aNum);

	std::string name;
	std::string description;
	int quantity;
	
};

