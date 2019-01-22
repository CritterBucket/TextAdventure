#pragma once

#include "Item.h"

class Container
{
public:
	Container();
	~Container();

	std::string name;
	std::string description;
	Item contents[3];
	bool bIsLocked;
	std::string keyName;
};

