/*
*Program Name: Final Project
*Author: Brendan Corazzin
*Date: 6/4/2017
*Description: This is the validateInput function implementation file.
*/

#include <iostream>
#include "getChar.hpp"

/*
*getChar gets a string from the console and verifies that the user 
*only entered a single character. If more than one character was entered,
*and error message is printed, else the char is convereted to lower case and returned.
*If there is an error, the function returns '0'.
*/

char getChar()
{	
	char c;
	std::string input;
	getline(std::cin, input);
	//flush input stream
	//std::cin.clear();
	//std::cin.ignore(999, '\n');
	
	//check if string is empty, if not, continue
	if(!input.empty())
	{
		//check if string contains more than one character, if yes, print error
		if(input.length() != 1)
		{
			std::cout << std::endl;
			std::cout << "Invalid Entry. Try Again." << std::endl;
			getChar();
		}
		else
		{
			//get only char
			c = input[0];
			//convert to lowercase
			c = std::tolower(c);
		}
	
	}
	else
	{
		std::cout << std::endl;
		std::cout << "Invalid Entry. Try Again." << std::endl;
		getChar();
	}
	
	return c;
}