/*
*Program Name: Final Porject
*Date: 6/5/2017
*Description: This is the implementation file for the Game class.
*/

#include <iostream>
#include "Game.hpp"

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
	this->initSpaces();
	this->currSpace = sBeach;
	std::cout << std::endl;
	std::cout << "You've just woken up on the beach of a tropical island." << std::endl;
	std::cout << "You are a little thirsity and a little hungry. You also have a backpack." << std::endl;
	std::cout << "How did you get here? It doesn't really matter... because you ARE here." << std::endl;
	std::cout << "Your goal now is to make it off the island alive." << std::endl;
	std::cout << "Don't run out of water. Don't starve. And don't accidently die." << std::endl;
	
	do
	{
		std::cout << std::endl;
		std::cout << "You are at the " << currSpace->getSpaceName() << "." <<std::endl;
		player->printInfo();
		this->currSpace = currSpace->spaceInfo(player);
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

/*
In function play
	do:
		call getSpaceName() (member of space) and print
		Print player stats
		Ask user if they want to look in their backpack
		if y - print contents, else continue
		call spaceInfo() (member of space)
	while: spaceInfo() == 1 and water > 0 and strength > 0
		
		
In spaceInfo()
	print info on space
	prompt user to interact with space, print info on edges and paths
		walk to edge?
			if yes, walk to edge
				if death
					end game
				else if item
					print "room in bag"
					if full
						prompt to swap
						if yes, swap, else leave item in place
					else
						promt to take item
						if yes, add to bag, else leave in place
				walk back to space
				call spaceInfo()
		walk down path?	
			update player info based on selection
				space player is in	
				food amount
				water amount
			return 1
			

			
*/