#pragma once

#include <iostream>

#include "Item.h"

class Inventory
{
public:
	Inventory();
	~Inventory();

	bool AddItem(Item aItem);
	bool RemoveItem(int aIndex);
	int CheckItem(std::string aItemName);
	bool PrintDescription(int aIndex);
	void PrintInventory();

	Item invContents[5];
};

