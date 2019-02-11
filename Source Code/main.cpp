#include <iostream>
#include <iomanip>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "MainMenu.h"

using USHORT = unsigned short int;

void mainMenu(Account *,MainMenu&, SavingsAccount&, CheckingAccount&, USHORT);
void savingsMenu(Account *, SavingsAccount&, USHORT);
void checkingMenu(Account *, CheckingAccount&, USHORT);
double makeDeposit();
double makeWithdrawal();
void displayStatistics(Account *, SavingsAccount);
void displayStatistics(Account *, CheckingAccount);

int main()
{
	MainMenu mainMenuObj;
	Account *acctPtr = nullptr;
	SavingsAccount savingsAcctObj(200, 12);
	CheckingAccount checkingAcctObj(500);

	std::cout << std::fixed << std::setprecision(2);

	mainMenu(acctPtr, mainMenuObj, savingsAcctObj, checkingAcctObj, mainMenuObj.getChoice());

	return 0;
}
void mainMenu(Account *acctPtr, MainMenu& mainMenuObj, SavingsAccount& savingsAcctObj, 
	CheckingAccount& checkingAcctObj, USHORT choice)
{
	bool keepLooping{true};

	while (keepLooping)
	{ 
		mainMenuObj.displayMenu();

		switch (mainMenuObj.getChoice())
		{
			case 1:
				savingsMenu(acctPtr, savingsAcctObj, choice);
				keepLooping = true;
				break;

			case 2:
				checkingMenu(acctPtr, checkingAcctObj, choice);
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

void savingsMenu(Account *acctPtr, SavingsAccount& accountObj, USHORT choice)
{
	acctPtr = &accountObj;
	bool keepLooping{true};
	
	while (keepLooping)
	{
		accountObj.displayMenu();

		switch (accountObj.getChoice())
		{
			case 1:
				acctPtr->deposit(makeDeposit());
				keepLooping = true;
				break;

			case 2:
				acctPtr->withdraw(makeWithdrawal());
				keepLooping = true;
				break;

			case 3:
				displayStatistics(acctPtr, accountObj);
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

void checkingMenu(Account *acctPtr, CheckingAccount& accountObj, USHORT choice)
{
	acctPtr = &accountObj;
	bool keepLooping{ true };

	while (keepLooping)
	{
		accountObj.displayMenu();

		switch (accountObj.getChoice())
		{
		case 1:
			acctPtr->withdraw(makeWithdrawal());
			keepLooping = true;
			break;

		case 2:
			displayStatistics(acctPtr, accountObj);
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

void displayStatistics(Account *acctPtr, SavingsAccount accountObj)
{
	acctPtr = &accountObj;
	accountObj.monthlyProc();

	std::cout << "\n=====Savings Account Statistics=====\n";
	std::cout << "Beginning Balance: $" << 
		acctPtr->getBeginningBalance() << std::endl;
	std::cout << "Total Amount of Deposits: $" <<
		accountObj.getDepositAmount() << std::endl;
	std::cout << "Total Amount of Withdrawals: $" << 
		acctPtr->getWithdrawalAmount() << std::endl;
	std::cout << "Total Service Charges: $" << 
		acctPtr->getTotalServiceCharges() << std::endl;
	std::cout << "Ending Balance: $" << acctPtr->getBalance()
		<< std::endl;
}

void displayStatistics(Account *acctPtr, CheckingAccount accountObj)
{
	acctPtr = &accountObj;
	accountObj.monthlyProc();

	std::cout << "\n=====Checking Account Statistics=====\n";
	std::cout << "Beginning Balance: $" <<
		acctPtr->getBeginningBalance() << std::endl;
	std::cout << "Total Amount of Withdrawals: $" <<
		acctPtr->getWithdrawalAmount() << std::endl;
	std::cout << "Total Service Charges: $" <<
		acctPtr->getTotalServiceCharges() << std::endl;
	std::cout << "Ending Balance: $" << acctPtr->getBalance()
		<< std::endl;
}
