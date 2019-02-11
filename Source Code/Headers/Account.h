#ifndef ACCOUNT_H
#define ACCOUNT_H

using USHORT = unsigned short int;

class Account
{
	private:
		double beginningBalance;
		void calcInt();
		
	protected:
		double balance;
		USHORT numOfDeposit;
		USHORT numOfWithdrawals;
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
		double getMonthlyServiceCharges() const;

};
#endif
