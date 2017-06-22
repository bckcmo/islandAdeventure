/*
*Program Name: Final Project
*Author: Brendan Corazzin
*Date: 6/11/2017
*Description: This is the getYorN function implementation file.
*/

#include <iostream>
#include "getChar.hpp"

/*
*getYorN calls getChar and then checks if a 'y' or 'n' 
* was returned. The function loops until and 'y' or 'n' is entered.
*The value entered by the user is then returned.
*/

char getYorN()
{	
	int count = 0;
	char c;
	std::cout << "Enter 'y' for yes or 'n' for no." << std::endl;
	do{
		if(count > 0)
		{
			std::cout << "You must enter 'y' or 'n'." << std::endl;
		}
		c  = getChar();
		count++;
	}while(c != 'y' && c != 'n');
	
	return c;
}