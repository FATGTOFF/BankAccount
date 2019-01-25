#include <iostream>
#include "MainMenu.h"

MainMenu::MainMenu()
{
	choice = 0;
}

UINT MainMenu::getChoice() const
{
	return choice;
}

void MainMenu::displayMenu()
{
	std::cout << "\n=====Main Menu=====\n"
		<< "1. Savings Account\n"
		<< "2. Checkings Account\n"
		<< "3. Exit the Program\n"
		<< "Please, make a selection: ";
	std::cin >> choice;
	
}

