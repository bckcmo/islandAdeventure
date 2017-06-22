/*
*Program Name: Final Porject
*Date: 6/8/2017
*Description: This is the implementation file for the Nbeach class.
*/

#include <iostream>
#include "Space.hpp"
#include "Nbeach.hpp"

#define STREN_MAX 8

Nbeach::~Nbeach()
{
	
}

Nbeach::Nbeach()
{
	name = "North Beach";
	//numFish keeps track of the number of fish in this object
	numFish = 2;
	//disc is the item at this space. It can only be collected once
	//"true" indicates it has not been collected
	disc = true;	
	move = ' ';
}

Space* Nbeach:: spaceInfo(Player* player)
{
	std::cout << std::endl;
	std::cout << "The north beach is shaded and rocky." << std::endl;
	std::cout << "From where you are standing, you can see the ocean." << std::endl;
	std::cout << "On either side of the beach are large boulders." << std::endl;
	std::cout << "South of the beach is the forest you came from." << std::endl;
	std::cout << "You can see a path leading into the forest." << std::endl;
	int moveTry = 0;
	do
	{
		if(moveTry > 0)
		{
			std::cout << "Invalid Entry. Try again." << std::endl;
		}
		
		std::cout << std::endl;
		std::cout << "To walk to the ocean enter 'u' " <<std::endl;
		std::cout << "To climb on the boulders on your left enter 'l' " << std::endl;
		std::cout << "To climb on the boulders on your right enter 'r' " << std::endl;
		std::cout << "To walk down the path and into the forest enter 'd' " << std::endl;
		move = getChar();
		moveTry++;
	}while(move != 'u' && move != 'd' && move != 'r' && move != 'l');
	
	if(move == 'u')
	{
		std::cout <<std::endl;
		std::cout << "The ocean is shallow here and you can see " << numFish << " fish in the water." << std::endl;
		if(numFish > 0)
		{
			--numFish;
			std::cout << "You need to use an item from your bag to catch a fish." << std::endl;
			std::cout << "If you catch a fish, you can use one of your matches to" << std::endl;
			std::cout << "start a fire and cook the fish." << std::endl;
			std::cout << "Cooked fish is delicious and it will replinish all of your strength points." << std::endl;
			if(player->checkItems("gun"))
			{
				std::cout <<  std::endl;
				std::cout << "You have a gun in your pack. Would you like to use it?" << std::endl;
				if(getYorN() == 'y')
				{
					std::cout << std::endl;
					std::cout << '\a' << std::endl;
					std::cout << "You shot the gun and hit a fish!." << std::endl;
					std::cout << "Do you want to use a match to start a fire and cook the fish?" << std::endl;
					if(getYorN() == 'y')
					{
						if(player->checkItems("match box"))
						{
							std::cout << std::endl;
							std::cout << "You started a fire. The fish is cooked. You ate it." << std::endl;
							std::cout << "That wonderful meal has replinished your strength!" << std::endl; 
							player->setStrength(STREN_MAX);
						}
						else
						{
							std::cout << std::endl;			
							std::cout << "You don't have any matches. Guess that fish is going to rot." << std::endl;
						}
					}
					else
					{
						std::cout << std::endl;			
						std::cout << "You chose not to use a match. This poor fish will just die." << std::endl;
						std::cout << "Your strength points didn't recover." << std::endl;
						std::cout << "That was a bad decision." << std::endl;
					}
				}
				else
				{
					std::cout << std::endl;			
					std::cout << "Ok. Don't use the gun, don't get a fish." << std::endl;
					std::cout << "Hope you weren't hungry." << std::endl;
				}
			}
			else
			{
				std::cout << std::endl;			
				std::cout << "It looks like there isn't anything in your bag that can help." << std::endl;
				std::cout << "Maybe later you will find an item that be used to kill fish." << std::endl;
			}
		}
		else
		{
			std::cout << "You've caught all the fish from this beach. There is nothing left to do here." << std::endl;
		}
	}
	else if(move == 'l')
	{
		if(disc == true)
		{
			std::cout << std::endl;
			std::cout << "You are climbing on the boulders and you see something shiny." << std::endl;
			std::cout << "You pick it up. It's a gold a silver disc covered in hieroglyphic writing." << std::endl;
			std::cout << "Would you like to put the disc in your backpack?" << std::endl;
			if(getYorN() == 'y')
			{
				if(player->isPackFull())
				{
					std::cout << std::endl;
					std::cout << "You don't have room in your pack." << std::endl;
					std::cout << "Would you like to remove an item to make room?" << std::endl; 
					if(getYorN() == 'y')
					{
						player->removeItem();
						player->addItem("gold and silver disc");
					}
					else
					{
						std::cout << std::endl;
						std::cout << "You didn't pick up the disc." << std::endl;
					}
				}
				else
				{
					player->addItem("gold and silver disc");
				}
				disc= false;
			}
			else
			{
				std::cout << std::endl;
				std::cout << "You didn't pick up the disc." << std::endl;
			}
		}
		else
		{
			std::cout << std::endl;
			std::cout << "There is nothing interesting on the boulders. You return to the beach." << std::endl;
		}
	}
	else if(move == 'r')
	{
		std::cout << std::endl;
		std::cout << "These boulders are very slippery." << std::endl;
		std::cout << "You loose your balance and fall. During the fall you hit your head." << std::endl;
		std::cout << "You died. That's so sad. I'm sorry." << std::endl;
		return nullptr;
	}
	else
	{
		//update player's stats
		player->update();
		//return pointer to Forest object
		return spaces[1];
	}
	
	return this;
}