#pragma once

#include <string>
#include "Container.h"

class Room
{
public:
	Room();
	Room(std::string aName, std::string aDesc);
	~Room();
	void PlayerEntry();
	void PrintDescription();
	void SetInfo(std::string aName, std::string aDesc);
	bool AddContainer(Container aContainer);
	bool RemoveContainer(Container aContainer);

	std::string name;
	std::string description;

	//container array
	Container containers[5];
	//portal array
};

