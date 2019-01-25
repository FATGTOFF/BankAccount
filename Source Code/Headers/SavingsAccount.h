#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "Account.h"

class SavingsAccount : public Account
{
	private:
		bool status; // To represent active or inactive account.
		double depositAmount;

	public:
		SavingsAccount();
		SavingsAccount(double, double);

		void withdraw(double);
		void deposit(double);
		void monthlyProc();
		double getDepositAmount() const;
		double getTotalServiceCharges() const;
};
#endif
