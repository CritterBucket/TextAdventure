#include "stdafx.h"
#include "Container.h"


Container::Container()
{
	name = "containerName";
	description = "defaultDescription";
	bIsLocked = false;
	keyName = "";

	contents[0] = Item();
	contents[1] = Item();
	contents[2] = Item();
}


Container::~Container()
{
}
