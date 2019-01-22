#include "stdafx.h"
#include "FileArt.h"

#include <iostream>
#include <array>


FileArt::FileArt()
{
	setContents();
}


FileArt::~FileArt()
{
}

void FileArt::setContents() {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			fileContents[i][j] = '*';
		}
	}
}

void FileArt::printContents() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; ++j) {
			std::cout << fileContents[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

}
