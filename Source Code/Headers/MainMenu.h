#ifndef MAINMENU_H
#define MAINMENU_H

using USHORT = unsigned short int;

class MainMenu
{
	private:
		USHORT choice;

	public:
		MainMenu();
		USHORT getChoice() const;
		void displayMenu();
};
#endif