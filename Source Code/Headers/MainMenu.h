#ifndef MAINMENU_H
#define MAINMENU_H

typedef unsigned int UINT;

class MainMenu
{
	private:
		UINT choice;

	public:
		MainMenu();
		UINT getChoice() const;
		void displayMenu();
};
#endif