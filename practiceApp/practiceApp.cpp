// practiceApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

#include "Item.h"
#include "FileArt.h"
#include "Room.h"
#include "InputMenu.h"
#include "Inventory.h"

using namespace std;

//Variables
FileArt testFileArt;
InputMenu gameMenu;
Room firstRoom;
Inventory playerInv;
bool bKeepGoing;


void sayHi() {
	cout << "Welcome to the game.  Enter \'help\' to view commands.  You can pair commands with nouns such as \'room\' and \'inventory\'\." << endl;
}

//TODO: placeholder, need to find a less invasive way to let player know their input was invalid
void sayBadInput() {
	cout << "Invalid input" << endl;
}

void verbExit() {
	cout << "Ending game..." << endl;
	bKeepGoing = false;
}

string captureInput() {
	string input;
	getline(cin, input);
	return input;
}

/*
Extract noun.  If any found, attempt to call the verb function on it.  If none found, call
the main's verb function.
*/
void processInput(int aVerbNum, string aFullString) {
	int nounIndex = aFullString.find(" ");
	string noun;

	//assume anything after first white space is the noun
	if (nounIndex > 0 && (nounIndex + 1 < aFullString.size())) {
		noun = aFullString.substr(nounIndex + 1, aFullString.size());
	} else {
		noun = "";
	}

	//assume anything after the second white space is junk and discard
	noun = noun.substr(0, noun.find(" "));

	//No noun, so call verb on main
	if (noun == "") {
		switch (aVerbNum)
		{
		case 0:
			//call help function
			gameMenu.PrintInputVerbs();
			break;
		case 1:
			//close program
			verbExit();
			break;
		default:
			sayBadInput();
			break;
		}
		return;
	} else {
		if (noun == "room") {
			switch (aVerbNum)
			{
			case 2:
				firstRoom.PrintDescription();
				break;
			default:
				sayBadInput();
				break;
			}
			return;
		}
		if (noun == "inventory") {
			switch (aVerbNum)
			{
			case 2:
				playerInv.PrintInventory();
				break;
			default:
				sayBadInput();
				break;
			}
			return;
		}

		int foundItemIndex = playerInv.CheckItem(noun);
		if (foundItemIndex > -1) {
			//Found the item, now try the verb on it
			switch (aVerbNum)
			{
			case 2:
				//TODO: check if this returned null somehow
				playerInv.PrintDescription(foundItemIndex);
				break;
			default:
				sayBadInput();
				break;
			}
			return;
		} else {
			//TODO: need to check against things in the room if didn't find item
		}
		
	}
}

int main()
{
	testFileArt = FileArt();
	testFileArt.printContents();

	gameMenu = InputMenu();
	playerInv = Inventory();
	bool bAddGood = playerInv.AddItem(Item("flashlight", "a small flashlight", 1));
	//cout << "Added item: " << bAddGood << endl;

	bKeepGoing = true;
	sayHi();

	firstRoom = Room("hallway", "a long, dark hallway, the end of which cannot be seen in the darkness.");
	firstRoom.PlayerEntry();

	while (bKeepGoing) {
		string playerInput = captureInput();
		int trimIndex = playerInput.find(" ");

		string playerVerb;
		if (trimIndex > 0) {
			playerVerb = playerInput.substr(0, trimIndex);
		} else {
			playerVerb = playerInput;
		}

		int verbOption = gameMenu.ValidateInput(playerVerb);
		if (verbOption >= 0) {
			processInput(verbOption, playerInput);
		} else {
			sayBadInput();
		}
	}

    //return 0;
}

