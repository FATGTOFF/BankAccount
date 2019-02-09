#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "Account.h"
#include "CheckingsAccountMenu.h"

using USHORT = unsigned short int;

class CheckingAccount : public Account, public CheckingsAccountMenu
{
	private:
		double serviceCharge;
		USHORT overdraftCounter;

	public:
		CheckingAccount();
		CheckingAccount(double);

		void withdraw(double);
		void monthlyProc();
		double getTotalServiceCharges() const;
};
#endif