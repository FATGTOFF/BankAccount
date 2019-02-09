#ifndef CHECKINGSACCOUNTMENU_H
#define CHECKINGSACCOUNTMENU_H

using USHORT = unsigned short int;

class CheckingsAccountMenu
{
	private:
		USHORT choice;

	public:
		CheckingsAccountMenu();

		void displayMenu();
		USHORT getChoice() const;

};
#endif
