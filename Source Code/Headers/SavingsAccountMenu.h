#ifndef SAVINGSACCOUNTMENU_H
#define SAVINGSACCOUNTMENU_H

using USHORT = unsigned short int;

class SavingsAccountMenu
{
	private:
		USHORT choice;

	public:
		SavingsAccountMenu();

		void displayMenu();
		USHORT getChoice() const;

};
#endif
