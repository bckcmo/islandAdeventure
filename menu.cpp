/*
*Program Name: Final Porject
*Date: 6/5/2017
*Description: This is the implementation file for the menu function.
*/

#include <iostream>
#include "getChar.hpp"

/*
*The menu function prints options to the console and prompts the user to select an int 
*value which corresponds to each option. The function returns the value selected.
*/

int menu()
{
		std::cout << std::endl;
		std::cout << "Would you like to continue with the game?" << std::endl;
		std::cout << "Enter 'c' to continue or 'q' to quit: " << std::endl;
		char menuOption = getChar();
		
		if(menuOption != 'c' && menuOption != 'q')
		{
			menuOption = menu();
		}

		return menuOption;
}