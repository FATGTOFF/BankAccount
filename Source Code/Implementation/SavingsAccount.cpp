#include "SavingsAccount.h"

SavingsAccount::SavingsAccount() : Account()
{
	status = false;
	depositAmount = 0.0;
}

/*
If the balance of a savings account falls 
below $25, it becomes inactive. (The status
member could be a flag variable.) No more 
withdrawals may be made until the balance
is raised above $25, at which time the 
account becomes active again.
*/
SavingsAccount::SavingsAccount(double a, double i) : Account(a, i)
{
	if (a < 25)
		status = false;

	else
		status = true;

	depositAmount = 0.0;
}

/*
A function that checks to see if the account 
is inactive before a withdrawal is made. (No 
withdrawal will be allowed if the account is not
active.) A withdrawal is then made by calling 
the base class version of the function.
*/
void SavingsAccount::withdraw(double w)
{
	if (status)
	{
		Account::withdraw(w);
		withdrawalAmount += w;
	}

	else
		return;
}

/*
A function that checks to see if the account 
is inactive before a deposit is made. If the 
account is inactive and the deposit brings 
the balance above $25, the account becomes 
active again. The deposit is then made by 
calling the base class version of the function.
*/
void SavingsAccount::deposit(double d)
{
	if (status)
	{
		Account::deposit(d);
		depositAmount += d;
	}

	else if (!status)
	{
		balance += d;
		if (balance > 25)
		{
			balance -= d;
			status = true;
			Account::deposit(d);
			depositAmount += d;
		}
		else if (balance < 26)
		{
			balance -= d;
			status = false;
		}
	}

}
/*
Before the base class function is called, 
this function checks the number of withdrawals. 
If the number of withdrawals for the month is
more than 4, a service charge of $1 for each 
withdrawal above 4 is added to the base 
class variable that holds the monthly service 
charges. (Don’t forget to check the account 
balance after the service charge is taken. 
If the balance falls below $25, the account 
becomes inactive.)
*/
void SavingsAccount::monthlyProc()
{
	if (numOfWithdrawals > 4)
	{
		monthlyServiceCharges += 1 * (numOfWithdrawals - 4);
		balance -= monthlyServiceCharges;

		if (balance < 26)
		{
			status = false;
		}
		else if (balance > 25)
		{
			balance += monthlyServiceCharges;
			totalServiceCharges = monthlyServiceCharges;
			Account::monthlyProc(monthlyServiceCharges);
			status = true;
		}
	}

	else
	{
		if (balance < 26)
		{
			status = false;
		}
		else if (balance > 25)
		{
			Account::monthlyProc(monthlyServiceCharges);
			status = true;
		}
	}
	
}

double SavingsAccount::getDepositAmount() const
{
	return depositAmount;
}

double SavingsAccount::getTotalServiceCharges() const
{
	return totalServiceCharges;
}
