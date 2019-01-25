#ifndef CHECKINGSACCOUNTMENU_H
#define CHECKINGSACCOUNTMENU_H

typedef unsigned int UINT;

class CheckingsAccountMenu 
{
private:
	int choice;

public:
	CheckingsAccountMenu();

	void displayMenu();
	UINT getChoice() const;

};
#endif
