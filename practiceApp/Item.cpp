#include "stdafx.h"
#include "Item.h"
#include <string>


Item::Item()
{
	name = "";
	description = "";
	quantity = 0;
}

Item::Item(std::string aName)
{
	name = aName;
	description = "defaultDescription";
	quantity = 1;
}

Item::Item(std::string aName, std::string aDesc, int aNum)
{
	name = aName;
	description = aDesc;
	quantity = aNum;
}


Item::~Item()
{
}
