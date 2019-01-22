#include "stdafx.h"
#include "Inventory.h"
//#include "Item.h"


Inventory::Inventory()
{
	invContents[0] = Item();
	invContents[1] = Item();
	invContents[2] = Item();
	invContents[3] = Item();
	invContents[4] = Item();
}

Inventory::~Inventory()
{
}

//Return true if item added, false if there wasn't room
//TODO: may want to add item stacking in the future
bool Inventory::AddItem(Item aItem) {
	for (int i = 0; i < 5; ++i) {
		std::string slotItem = invContents[i].name;

		if (slotItem == "") {
			invContents[i] = aItem;
			return true;
		}
	}
	return false;
}

bool Inventory::RemoveItem(int aIndex) {
	//TODO: stub
}

//If matching item found, print its description and return index; else return -1
int Inventory::CheckItem(std::string aItemName) {
	for (int i = 0; i < 5; ++i) {
		std::string slotItem = invContents[i].name;

		if (slotItem == aItemName) {
			//std::cout << "Found the item" << std::endl;
			return i;
		}
	}
	return -1;
}

//TODO: return false if invalid index
bool Inventory::PrintDescription(int aIndex) {
	std::cout << invContents[aIndex].description << std::endl;
	return true;
}

//TODO: see if this actually works or if you just can't see the empty strings because they're empty
void Inventory::PrintInventory() {
	std::string outString = "Inventory items:";

	for (int i = 0; i < 5; ++i) {
		if (invContents[i].name != "") {
			outString += "   " + invContents[i].name;
		}
	}

	std::cout << outString << std::endl;
}
