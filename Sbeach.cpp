/*
*Program Name: Final Porject
*Date: 6/5/2017
*Description: This is the implementation file for the Sbeach class.
*/

#include <iostream>
#include "Space.hpp"
#include "Sbeach.hpp"

#define STREN_MAX 8

Sbeach::~Sbeach()
{
	
}

Sbeach::Sbeach()
{
	name = "South Beach";	
	numFish = 2;
	stone = true;
	move = ' ';
}

Space* Sbeach:: spaceInfo(Player* player)
{
	std::cout << std::endl;
	std::cout << "The south beach is warm and dry." << std::endl;
	std::cout << "From where you are standing, you can see the ocean." << std::endl;
	std::cout << "On either side of the ocean are large boulders." << std::endl;
	std::cout << "North of the beach is a dense forest." << std::endl;
	std::cout << "You can see a path leading into the forest." << std::endl;
	int moveTry = 0;
	do
	{
		if(moveTry > 0)
		{
			std::cout << "Invalid Entry. Try again." << std::endl;
		}
		std::cout << std::endl;
		std::cout << "To walk to the ocean enter 'd' " <<std::endl;
		std::cout << "To climb on the boudlers on your left enter 'l' " << std::endl;
		std::cout << "To climb on the boudlers on your right enter 'r' " << std::endl;
		std::cout << "To walk down the path and into the forest enter 'u' " << std::endl;
		move = getChar();
		moveTry++;
	}while(move != 'u' && move != 'd' && move != 'r' && move != 'l');
	
	if(move == 'd')
	{
		std::cout <<std::endl;
		std::cout << "The ocean is shallow here and you can see " << numFish << " fish in the water." << std::endl;
		if(numFish > 0)
		{
			std::cout << "There is a small spear stuck in the sand." << std::endl; 
			std::cout << "You can use the spear to catch a fish." << std::endl;
			std::cout << "If you catch a fish, you can use one of your matches to" << std::endl;
			std::cout << "start a fire and cook the fish." << std::endl;
			std::cout << "Cooked fish is delicious and it will replinish all of your strength points." << std::endl;
			std::cout << "Do you want to try and catch a fish? Enter 'y' for yes." << std::endl;
			char catchFish = getChar();
			if(catchFish == 'y')
			{
				numFish--;
				std::cout << std::endl;
				std::cout << "You caught a fish! Do you want to use a match to start a fire and cook the fish?"
							   << "Enter 'y' for yes." << std::endl;
				char useMatch = getChar();
				if(useMatch == 'y')
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
				std::cout << "You decide not to catch a fish and walk back to the beach." << std::endl;
			}
		}
		else
		{
			std::cout << "You've caught all the fish from this beach. There is nothing left to do here." << std::endl;
		}
			
		std::cout << std::endl;
		std::cout << "You now walk back to the beach." << std::endl;
	}
	else if(move == 'r')
	{
		if(stone == true)
		{
			std::cout << std::endl;
			std::cout << "You are climbing on the boulders and you see an odd looking stone." << std::endl;
			std::cout << "The stone is round and has decorative engravings all around it." << std::endl;
			std::cout << "Would you like to pick up the stone and put it in your backpack?" << std::endl;
			std::cout << "Enter 'y' for yes." << std::endl;
			char pickUp = getChar();
			if(pickUp == 'y')
			{
				if(player->packIsFull())
				{
					std::cout << std::endl;
					std::cout << "You don't have room in your pack." << std::endl;
					std::cout << "Would you like to remove an item to make room?" << std::endl; 
					std::cout << "Enter 'y' for yes." << std::endl;
					if(getChar() == 'y')
					{
						player->removeItem();
						player->addItem("engraved stone");
					}
					else
					{
						std::cout << std::endl;
						std::cout << "You didn't pick up the stone." << std::endl;
					}
				}
				else
				{
					player->addItem("engraved stone");
				}
				stone = false;
			}
			else
			{
				std::cout << std::endl;
				std::cout << "You didn't pick up the stone." << std::endl;
			}
		}
		else
		{
			std::cout << std::endl;
			std::cout << "There is nothing interesting on the boudlers. You return to the beach." << std::endl;
		}
	}
	else if(move == 'l')
	{
		std::cout << std::endl;
		std::cout << "These boulders are very slippery." << std::endl;
		std::cout << "You loose your balance and fall. During the fall you hit your head." << std::endl;
		std::cout << "You died. That's so sad. I'm sorry." << std::endl;
		player->setStrength(0);
	}
	else if(move == 'u')
	{
		player->update();
		return spaces[0];
	}
	
	return this;
}


