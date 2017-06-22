/*
*Program Name: Lab 9
*Author: Brendan Corazzin
*Date: 6/4/2017
*Description: This is the main function for the STL program.
*/

#include <iostream>
#include "Game.hpp"
#include "Player.hpp"
#include "Pack.hpp"
#include "menu.hpp"
#include "getChar.hpp"
#include "Space.hpp"
#include "Sbeach.hpp"


int main(void)
{
	/*
	*The menu function prints the following options and prompts 
	*the user to input a char value which is then returned by the function.
	*Play game - Returns 'c'
	*Exit program - Returns 'q'
	*imenuReturn holds the return value.
	*/
	
	//Print welcome message
	std::cout << std::endl;
	std::cout << "Welcome to Island Adventures, a text-based strategy game." << std::endl;
	std::cout << "You will be challenged to find your way off a remote tropical island " << std::endl;
	std::cout << "without running out of food or water and without succumbing to death." << std::endl;
	
	char menuReturn = menu();
	
	//repeat until user quits game: create game object, call play
	while(menuReturn != 'q')
	{
		Game game;
		game.play();
		menuReturn = menu();
	}
	
	return 0;
}
