#include "stdafx.h"
#include "Room.h"
#include <iostream>


Room::Room() {
	name = "defaultRoom";
	description = "It's an empty room with no doors or windows.";

	containers[0] = Container();
	containers[1] = Container();
	containers[2] = Container();
	containers[3] = Container();
	containers[4] = Container();
}

Room::Room(std::string aName, std::string aDesc) {
	name = aName;
	description = aDesc;
}

Room::~Room()
{
}

void Room::PlayerEntry() {
	std::cout << "You have entered the " << name << std::endl;
}

void Room::PrintDescription() {
	std::cout << "You see " << description << std::endl;
}

void Room::SetInfo(std::string aName, std::string aDesc) {
	name = aName;
	description = aDesc;
}

bool Room::AddContainer(Container aContainer) {
	//TODO: stub
}

bool Room::RemoveContainer(Container aContainer) {
	//TODO: stub
}