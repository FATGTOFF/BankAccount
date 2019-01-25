#include "Account.h"

Account::Account()
{
	balance = 0.0;
	annualInterestRate = 0.0;
	numOfDeposit = 0;
	numOfWithdrawals = 0;
	monthlyServiceCharges = 0.0;
	withdrawalAmount = 0.0;
	totalServiceCharges = 0.0;

	beginningBalance = 0.0;
}

Account::Account(double b)
{
	balance = b;
	annualInterestRate = 0.0;
	numOfDeposit = 0;
	numOfWithdrawals = 0;
	monthlyServiceCharges = 0.0;
	withdrawalAmount = 0.0;
	totalServiceCharges = 0.0;

	beginningBalance = b;
}

/*
Accepts arguments for the balance and 
annual interest rate.
*/
Account::Account(double b, double a)
{
	balance = b;
	annualInterestRate = a;
	numOfDeposit = 0;
	numOfWithdrawals = 0;
	monthlyServiceCharges = 0.0;
	withdrawalAmount = 0.0;
	totalServiceCharges = 0.0;

	beginningBalance = b;
}

/*
A virtual function that accepts an argument 
for the amount of the deposit. The function 
should add the argument to the account balance.
It should also increment the variable holding 
the number of deposits.
*/
void Account::deposit(double d)
{
	balance += d;
	numOfDeposit++;
}

/*
A virtual function that accepts an argument 
for the amount of the withdrawal. The function 
should subtract the argument from the balance. 
It should also increment the variable holding 
the number of withdrawals.
*/
void Account::withdraw(double a)
{
	balance -= a;
	numOfWithdrawals++;
}

/*
A virtual function that updates the balance 
by calculating the monthly interest earned 
by the account, and adding this interest to 
the balance. This is performed by the following 
formulas:
	Monthly Interest Rate = (Annual Interest Rate / 12)
	Monthly Interest = Balance * Monthly Interest Rate
	Balance = Balance + Monthly Interest
*/
void Account::calcInt()
{
	double monthlyInterestRate = annualInterestRate / 12;
	double monthlyInterest = balance * monthlyInterestRate;
	balance += monthlyInterest;
}

/*
A virtual function that subtracts the monthly 
service charges from the balance, calls the 
calcInt function, and then sets the variables that
hold the number of withdrawals, number of deposits, 
and monthly service charges to zero.
*/
void Account::monthlyProc(double m)
{
	balance -= m;
	calcInt();
	numOfWithdrawals = 0;
	numOfDeposit = 0;
	monthlyServiceCharges = 0.0;
}

void Account::setInterestRate(double i)
{
	annualInterestRate = i;
}

double Account::getBeginningBalance() const
{
	return beginningBalance;
}

double Account::getBalance() const
{
	return balance;
}

double Account::getWithdrawalAmount() const
{
	return withdrawalAmount;
}

double Account::getInterestRate() const
{
	return annualInterestRate;
}

double Account::getTotalServiceCharges() const
{
	return monthlyServiceCharges;
}
