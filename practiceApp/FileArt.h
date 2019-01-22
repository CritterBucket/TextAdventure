#pragma once

#include <string>
#include <array>

class FileArt
{
public:
	FileArt();
	~FileArt();
	void setContents();
	void printContents();

	std::string internalName;

	//TODO: currently hard-coding array sizes, not ideal due to possible user error
	//std::array<std::array < char, 5>, 5> fileContents;
	char fileContents[5][5];
};