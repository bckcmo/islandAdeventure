/*
*Program Name: Final Porject
*Date: 6/5/2017
*Description: This is the implementation file for the Game class.
*/

#include <iostream>
#include "Game.hpp"

//constructor - create pointers to spaces
Game::Game()
{
	nBeach = new Nbeach;
	sBeach = new Sbeach;
	wBeach = new Wbeach;
	forest = new Forest;
	river = new River;
	temple = new Temple;
	player = new Player;
}

//destructor - delete pointers to spaces
Game::~Game()
{
	delete nBeach;
	delete sBeach;
	delete wBeach;
	delete forest;
	delete river;
	delete temple;
	delete player;
}

//initalize pointer values for each of the space object's directional pointers
void Game::initSpaces()
{
	nBeach->initPtrs(nullptr, forest, nullptr, nullptr);
	sBeach->initPtrs(forest, nullptr, nullptr, nullptr);
	wBeach->initPtrs(nullptr, nullptr, temple, nullptr);
	forest->initPtrs(nBeach, sBeach, river, temple);
	river->initPtrs(nullptr, nullptr, forest, nullptr);
	temple->initPtrs(nullptr, nullptr, forest, wBeach);
}

int Game::play()
{
	//print welcome message
	initSpaces();
	currSpace = sBeach;
	std::cout << std::endl;
	std::cout << "You've just woken up on the beach of a tropical island." << std::endl;
	std::cout << "You are a little thirsity and a little hungry. You also have a backpack." << std::endl;
	std::cout << "How did you get here? It doesn't really matter... because you ARE here." << std::endl;
	std::cout << "Your goal now is to make it off the island alive." << std::endl;
	std::cout << "Don't run out of water. Don't starve. And don't accidentally die." << std::endl;
	std::cout << std::endl;
	std::cout << "**************SPOILER ALERT**************" << std::endl;
	std::cout << "There are three items you can use to win the game." << std::endl;
	std::cout << "Only the gold and silver disc will get you off the island everytime." << std::endl;
	std::cout << "**************SPOILER ALERT**************" << std::endl;
	
	/*
	*continue game by looping through to different spaces
	*user input determines current space space
	*nullptr indicates end of game
	*/
	do
	{
		std::cout << std::endl;
		std::cout << "You are at the " << currSpace->getSpaceName() << "." <<std::endl;
		player->printInfo();
		currSpace = currSpace->spaceInfo(player);
	}while(player->getStrength() != 0 && player->getWater() != 0 && currSpace != nullptr);
	
	if(player->getStrength() == 0)
	{
		std::cout << std::endl;
		std::cout << "You ran out of strength and you died. Sorry." << std::endl;
	}
	
	if(player->getWater() == 0)
	{
		std::cout << std::endl;
		std::cout << "You ran out of water and you died. Should have been more careful." << std::endl;
	}
	
	return 0;
}

