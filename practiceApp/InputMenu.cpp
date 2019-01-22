#include "stdafx.h"
#include "InputMenu.h"


InputMenu::InputMenu() {
	inputVerbs[0] = "help";
	inputVerbs[1] = "exit";
	inputVerbs[2] = "check";
	inputVerbs[3] = "open";
	inputVerbs[4] = "";
	inputVerbs[5] = "";
	inputVerbs[6] = "";
	inputVerbs[7] = "";
	inputVerbs[8] = "";
	inputVerbs[9] = "";

}

InputMenu::~InputMenu()
{
}

//If valid input, return the index of the verb for further processing
//If invalid, return -1
int InputMenu::ValidateInput(std::string aInputVerb) {

	for (int i = 0; i < 10; ++i) {
		if (inputVerbs[i] == aInputVerb) {
			return i;
		}
	}

	return -1;
}

void InputMenu::PrintInputVerbs() {
	std::string outString = "Command options:";

	for (int i = 0; i < 10; ++i) {
		if (inputVerbs[i] != "") {
			outString += "   " + inputVerbs[i];
		}
	}

	std::cout << outString << std::endl;

}
