/*
*Program Name: Final Porject
*Date: 6/5/2017
*Description: This is the implementation file for the Forest class.
*/

#include <iostream>
#include "Space.hpp"
#include "Forest.hpp"

Forest::~Forest()
{
	
}

Forest::Forest()
{
	name = "Forest";	
	move = ' ';
}

Space* Forest::spaceInfo(Player* player)
{
	std::cout << std::endl;
	std::cout << "The forest is cool and calm. It feels refreshing." << std::endl;
	std::cout << "Up ahead of you is a path that heads out of the forest." << std::endl;
	std::cout << "To the right of you is another path. It looks like it continues into the forest." << std::endl;
	std::cout << "To left is a path that looks similar to the one to your right." << std::endl;
	std::cout << "Behind you is a path that leads back to the south beach." << std::endl;
	int moveTry = 0;
	do
	{
		if(moveTry > 0)
		{
			std::cout << "Invalid Entry. Try again." << std::endl;
		}
		
		std::cout << std::endl;
		std::cout << "To walk down the path that leads to the south beach enter 'd' " <<std::endl;
		std::cout << "To walk down the path to your left enter 'l' " << std::endl;
		std::cout << "To walk down the path to your right enter 'r' " << std::endl;
		std::cout << "To walk down the path in front of you enter 'u' " << std::endl;
		move = getChar();
		moveTry++;
	}while(move != 'u' && move != 'd' && move != 'r' && move != 'l');
	
	if(move == 'd')
	{
		player->update();
		return spaces[1];
	}
	else if(move == 'r')
	{
		player->update();
		return spaces[2];
	}
	else if(move == 'l')
	{
		player->update();
		return spaces[3];
	}
	else
	{
		player->update();
		return spaces[0];
	}
	
	return this;
}