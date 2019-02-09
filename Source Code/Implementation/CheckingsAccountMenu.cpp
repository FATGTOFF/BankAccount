#include <iostream>
#include "CheckingsAccountMenu.h"

CheckingsAccountMenu::CheckingsAccountMenu()
{
	choice = 0;
}

void CheckingsAccountMenu::displayMenu()
{
	std::cout << "\n=====Checking Account Menu=====\n"
		<< "1. Make a Withdrawal\n"
		<< "2. Display Statistics for the Month\n"
		<< "3. Return to Main Menu\n"
		<< "Please, make a selection: ";
	std::cin >> choice;

}

USHORT CheckingsAccountMenu::getChoice() const
{
	return choice;
}

