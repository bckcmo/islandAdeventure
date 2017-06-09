/*
*Program Name: Final Project
*Author: Brendan Corazzin
*Date: 5/05/2017
*Description: This is the validateInput function implementation file.
*/

#include <iostream>
#include "validateInput.hpp"

/*
*validateInput takes a string paramater and the address to an int. 
*The function checks if the string contains an int. 
*If the string contains an int, it converts the int and stores the int in the address paramater.
*/

int validateInput(std::string input, int &value)
{	
	//check if string is empty
	if(!input.empty())
	{
		//convert string to array of chars 
		const char *cinput = input.c_str();
		//get size of string
		int inputLength = std::char_traits<char>::length(cinput);

		for(int i = 0; i < inputLength; i++)
		{
			if(!isdigit(cinput[i]))
			{
				//check if int is negative - this is allowed
				if(cinput[i] != '-')
				{
					std::cout << std::endl;
					std::cout << "Invalid Entry" << std::endl;
					return 1;
				}
			}
		}
		
		//now convert string value to int value for menu option
		value = atoi(input.c_str());
		return 0;
	}
	else
	{
		std::cout << std::endl;
		std::cout << "Invalid Entry" << std::endl;
		return 1;
	}
}