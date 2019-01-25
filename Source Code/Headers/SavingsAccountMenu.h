#ifndef SAVINGSACCOUNTMENU_H
#define SAVINGSACCOUNTMENU_H

typedef unsigned int UINT;

class SavingsAccountMenu
{
	private:
		int choice;

	public:
		SavingsAccountMenu();

		void displayMenu();
		UINT getChoice() const;

};
#endif
