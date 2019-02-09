#include <iostream>
#include "SavingsAccountMenu.h"

SavingsAccountMenu::SavingsAccountMenu()
{
	choice = 0;
}

void SavingsAccountMenu::displayMenu()
{
	std::cout << "\n=====Savings Account Menu=====\n"
		<< "1. Make a Deposit\n"
		<< "2. Make a Withdrawal\n"
		<< "3. Display Statistics for the Month\n"
		<< "4. Return to Main Menu\n"
		<< "Please, make a selection: ";

	std::cin >> choice;

}

USHORT SavingsAccountMenu::getChoice() const
{
	return choice;
}

