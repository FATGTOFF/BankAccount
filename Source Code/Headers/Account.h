#ifndef ACCOUNT_H
#define ACCOUNT_H

typedef unsigned int UINT;

class Account
{
	private:
		double beginningBalance;
		virtual void calcInt();
		
	protected:
		double balance;
		UINT numOfDeposit;
		UINT numOfWithdrawals;
		double annualInterestRate;
		double monthlyServiceCharges;
		double withdrawalAmount;
		double totalServiceCharges;

	public:
		Account();
		Account(double);
		Account(double, double);

		virtual void deposit(double);
		virtual void withdraw(double);
		virtual void monthlyProc(double);
		virtual void setInterestRate(double);
		virtual double getTotalServiceCharges() const;
		double getBeginningBalance() const;
		double getBalance() const;
		double getWithdrawalAmount() const;
		double getInterestRate() const;


};
#endif
