#pragma once

#include <string>
#include <iostream>

class InputMenu
{
public:
	InputMenu();
	~InputMenu();
	int ValidateInput(std::string aInputVerb);
	void PrintInputVerbs();

	std::string inputVerbs[10];
};

