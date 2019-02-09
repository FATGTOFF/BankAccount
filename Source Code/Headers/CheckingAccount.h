#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "Account.h"
#include "CheckingsAccountMenu.h"

class CheckingAccount : public Account, public CheckingsAccountMenu
{
	private:
		double serviceCharge;
		int overdraftCounter;

	public:
		CheckingAccount();
		CheckingAccount(double);

		void withdraw(double);
		void monthlyProc();
		double getTotalServiceCharges() const;
};
#endif