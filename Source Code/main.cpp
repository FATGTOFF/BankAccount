#include <iostream>
#include <iomanip>
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "MainMenu.h"
#include "SavingsAccountMenu.h"
#include "CheckingsAccountMenu.h"

typedef unsigned int UINT;

void mainMenu(MainMenu&, SavingsAccountMenu&, 
CheckingsAccountMenu&, SavingsAccount&, 
CheckingAccount&, UINT);
void savingsMenu(SavingsAccountMenu&, SavingsAccount&, UINT);
void checkingMenu(CheckingsAccountMenu&, CheckingAccount&, UINT);
double makeDeposit();
double makeWithdrawal();
void displayStatistics(SavingsAccount);
void displayStatistics(CheckingAccount);

int main()
{
	MainMenu mainMenuObj;
	SavingsAccountMenu savingsMenuObj;
	CheckingsAccountMenu checkingsMenuObj;
	SavingsAccount savingsAcctObj(200, 12);
	CheckingAccount checkingAcctObj(500);

	std::cout << std::fixed << std::setprecision(2);

	mainMenu(mainMenuObj, savingsMenuObj, checkingsMenuObj,
	savingsAcctObj, checkingAcctObj, mainMenuObj.getChoice());

	return 0;
}
void mainMenu(MainMenu& mainMenuObj, SavingsAccountMenu& savingsMenuObj,
	CheckingsAccountMenu& checkingsMenuObj, SavingsAccount& savingsAcctObj, 
	CheckingAccount& checkingAcctObj, UINT choice)
{
	bool keepLooping{true};

	while (keepLooping)
	{ 
		mainMenuObj.displayMenu();

		switch (mainMenuObj.getChoice())
		{
			case 1:
				savingsMenu(savingsMenuObj, savingsAcctObj, choice);
				keepLooping = true;
				break;

			case 2:
				checkingMenu(checkingsMenuObj,checkingAcctObj, choice);
				keepLooping = true;
				break;

			case 3:
				std::cout << "Program ending.\n";
				keepLooping = false;
				break;

			default:
				std::cout << "Your choice is not correct.\n";
				keepLooping = true;			
		}
	}
}

void savingsMenu(SavingsAccountMenu& savingsMenuObj, SavingsAccount& accountObj, UINT choice)
{
	bool keepLooping{true};
	
	while (keepLooping)
	{
		savingsMenuObj.displayMenu();

		switch (savingsMenuObj.getChoice())
		{
			case 1:
				accountObj.deposit(makeDeposit());
				keepLooping = true;
				break;

			case 2:
				accountObj.withdraw(makeWithdrawal());
				keepLooping = true;
				break;

			case 3:
				displayStatistics(accountObj);
				keepLooping = true;
				break;

			case 4:
				return;
				break;

			default:
				std::cout << "Your choice is not correct.\n";
				keepLooping = true;
		}
	}
}

void checkingMenu(CheckingsAccountMenu& checkingsMenuObj, CheckingAccount& accountObj, UINT choice)
{
	bool keepLooping{ true };

	while (keepLooping)
	{
		checkingsMenuObj.displayMenu();

		switch (checkingsMenuObj.getChoice())
		{
		case 1:
			accountObj.withdraw(makeWithdrawal());
			keepLooping = true;
			break;

		case 2:
			displayStatistics(accountObj);
			keepLooping = true;
			break;

		case 3:
			return;
			break;

		default:
			std::cout << "Your choice is not correct.\n";
			keepLooping = true;
		}
	}
}

double makeDeposit()
{
	double amount{};
	std::cout << "\nAmount to Deposit: ";
	std::cin >> amount;

	return amount;
}

double makeWithdrawal()
{
	double amount{};
	std::cout << "\nAmount to Withdraw: ";
	std::cin >> amount;

	return amount;
}

void displayStatistics(SavingsAccount accountObj)
{
	accountObj.monthlyProc();
	std::cout << "\n=====Savings Account Statistics=====\n";
	std::cout << "Beginning Balance: $" << 
		accountObj.getBeginningBalance() << std::endl;
	std::cout << "Total Amount of Deposits: $" <<
		accountObj.getDepositAmount() << std::endl;
	std::cout << "Total Amount of Withdrawals: $" << 
		accountObj.getWithdrawalAmount() << std::endl;
	std::cout << "Total Service Charges: $" << 
		accountObj.getTotalServiceCharges() << std::endl;
	std::cout << "Ending Balance: $" << accountObj.getBalance()
		<< std::endl;
}

void displayStatistics(CheckingAccount accountObj)
{
	accountObj.monthlyProc();

	std::cout << "\n=====Checking Account Statistics=====\n";
	std::cout << "Beginning Balance: $" <<
		accountObj.getBeginningBalance() << std::endl;
	std::cout << "Total Amount of Withdrawals: $" <<
		accountObj.getWithdrawalAmount() << std::endl;
	std::cout << "Total Service Charges: $" <<
		accountObj.getTotalServiceCharges() << std::endl;
	std::cout << "Ending Balance: $" << accountObj.getBalance()
		<< std::endl;
}