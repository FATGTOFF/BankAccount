#include "CheckingAccount.h"

CheckingAccount::CheckingAccount() : Account(), CheckingsAccountMenu()
{
	serviceCharge = 15;
	overdraftCounter = 0;
}

CheckingAccount::CheckingAccount(double b) : Account(b)
{
	serviceCharge = 15;
	overdraftCounter = 0;
}

/*
Before the base class function is called, 
this function will determine if a withdrawal 
(a check written) will cause the balance to 
go below $0. If the balance goes below $0, 
a service charge of $15 will be taken from
the account. (The withdrawal will not be 
made.) If there isn’t enough in the account 
to pay the service charge, the balance will 
become negative and the customer will owe 
the negative amount to the bank.
*/
void CheckingAccount::withdraw(double w)
{
	balance -= w;
	if (balance < 0)
	{
		balance += w;
		balance -= serviceCharge;
		overdraftCounter++;
	}
	else
	{
		balance += w;
		Account::withdraw(w);
		withdrawalAmount += w;
	}
}

/*
Before the base class function is called, 
this function adds the monthly fee of $5 
plus $0.10 per withdrawal (check written) 
to the base class variable that holds 
the monthly service charges.
*/
void CheckingAccount::monthlyProc()
{
	monthlyServiceCharges = 5 + (0.10 * numOfWithdrawals);
	totalServiceCharges = monthlyServiceCharges + (overdraftCounter * serviceCharge);
	Account::monthlyProc(monthlyServiceCharges);
}

double CheckingAccount::getTotalServiceCharges() const
{
	return totalServiceCharges;
}

