/*
*Program Name: Final Porject
*Date: 6/8/2017
*Description: This is the implementation file for the Wbeach class.
*/

#include <iostream>
#include "Space.hpp"
#include "Wbeach.hpp"
#include <stdlib.h>
#include <time.h>

Wbeach::~Wbeach()
{
	
}

Wbeach::Wbeach()
{
	name = "West Beach";
	//bottle is the item at this space. It can only be collected once
	//"true" indicates it has not been collected
	bottle = true;	
	//firstEncounter inidicates if user has interacted with the men on the beach
	firstEncounter = true;
	move = ' ';
	srand (time(NULL));
}

Space* Wbeach:: spaceInfo(Player* player)
{
	std::cout << std::endl;
	std::cout << "The west beach is windy and the water is deep." << std::endl;
	std::cout << "From where you are stading, you can see the ocean." << std::endl;
	std::cout << "On either side of the ocean are large boulders." << std::endl;
	std::cout << "Down by the water, there is a small sail boat." << std::endl;
	std::cout << "East of the beach is the temple you just came from." << std::endl;
	int moveTry = 0;
	do
	{
		if(moveTry > 0)
		{
			std::cout << "Invalid Entry. Try again." << std::endl;
		}
		
		std::cout << std::endl;
		std::cout << "To walk to the boat enter 'u' " <<std::endl;
		std::cout << "To climb on the boulders on your left enter 'l' " << std::endl;
		std::cout << "To climb on the boulders on your right enter 'r' " << std::endl;
		std::cout << "To walk down the path and back to the temple enter 'd' " << std::endl;
		move = getChar();
		moveTry++;
	}while(move != 'u' && move != 'd' && move != 'r' && move != 'l');
	
	if(move == 'u')
	{
		if(firstEncounter == true)
		{
			std::cout <<std::endl;
			std::cout << "You get up close to the boat and two men come out of the cabin." << std::endl;
			std::cout << "They are pretty rough looking dudes." << std::endl;
			std::cout << "They get off the boat and walk closer to you." << std::endl;
		}
		else
		{
			std::cout <<std::endl;
			std::cout << "Those rough looking dudes are still standing by the fire." << std::endl;
			std::cout << "Good thing you've had a chance to think." << std::endl;
			std::cout << "Maybe you even collected some more useful items." << std::endl;
			std::cout << "You walk up towards the men." << std::endl;
		}
		
		std::cout << "There is a smoldering fire between you and the men." << std::endl;
		std::cout << "You think about the situation. Perhaps something in your bag could help?" << std::endl;
		useItem = player->useItems();

		if(useItem == "gun")
		{
			std::cout << std::endl;
			std::cout << "You pull out the gun." << std::endl;
			std::cout << "One of the men also pulls out a gun." << std::endl;
			std::cout << '\a' << std::endl;
			std::cout << "BANG BANG BANG" << std::endl;
			if((rand() % 2) == 1)
			{
				std::cout << std::endl;
				std::cout << "Hey there sharp shooter, you shot both men!" << std::endl;
				winGameMssg();
				return nullptr;
			}
			else
			{
				std::cout <<  std::endl;
				std::cout << "Turns out the gun was a bad idea. They shot you right in the heart." << std::endl;
				std::cout << "You were so close, but you died." << std::endl;
				return nullptr;
			}
		}
		else if(useItem == "leather pouch")
		{
			std::cout << std::endl;
			std::cout << "You pull out the leather pouch." << std::endl;
			std::cout << "Then men laugh at you." << std::endl;
			std::cout << "You think quickly and decide to throw the pouch in the fire." << std::endl;
			std::cout << "POOF! A cloud of smoke appears." << std::endl;
			if((rand() % 2) == 1)
			{
				std::cout << std::endl;
				std::cout << "The wind blows the smoke towards the men." << std::endl;
				std::cout << "When it hits their faces, they instantly pass out." << std::endl;
				std::cout << "It must have been poisonous." << std::endl;
				winGameMssg();
				return nullptr;
			}
			else
			{
				std::cout << std::endl;
				std::cout << "The wind blows the smoke towards you." << std::endl;
				std::cout << "The smoke is very harsh. You feel your chest tighten." << std::endl;
				std::cout << "Oh no! You died!" << std::endl;
				return nullptr;
			}
		}
		else if(useItem == "gold and silver disc")
		{
			std::cout << std::endl;
			std::cout << "You pull out the gold and silver disc." << std::endl;
			std::cout << "You present it to the men as a gift." << std::endl;
			std::cout << "Their eyes light up. They take the gift and run into the forest." << std::endl;
			std::cout << "You are not quite sure what happened. But that's ok." << std::endl;
			winGameMssg();
			return nullptr;
		}
		else
		{
			std::cout << std::endl;
			std::cout << "That item is not helpful." << std::endl;
			std::cout << "The men stay standing on the beach." << std::endl;
			std::cout << "You drop the " << useItem << " and walk away slowly." << std::endl;
			firstEncounter = false;
		}
	}
	else if(move == 'r')
	{
		if(bottle == true)
		{
			std::cout << std::endl;
			std::cout << "The boulders here are very rough looking." << std::endl;
			std::cout << "You are inspecting them to see if it would be wise to climb on them." << std::endl;
			std::cout << "As you are looking, you notice a glass bottle wedged between some rocks." << std::endl;
			std::cout << "Would you like to pick up the bottle and put it in your backpack?" << std::endl;
			if(getYorN() == 'y')
			{
				if(player->isPackFull())
				{
					std::cout << std::endl;
					std::cout << "You don't have room in your pack." << std::endl;
					std::cout << "Would you like to remove an item to make room?" << std::endl; 
					std::cout << "Enter 'y' for yes." << std::endl;
					if(getYorN() == 'y')
					{
						player->removeItem();
						player->addItem("glass bottle");
					}
					else
					{
						std::cout << std::endl;
						std::cout << "You didn't pick up the bottle." << std::endl;
					}
				}
				else
				{
					player->addItem("glass bottle");
				}			
				bottle = false;
			}
			else
			{
				std::cout << std::endl;
				std::cout << "You didn't pick up the bottle." << std::endl;
			}
		}
		else
		{
			std::cout << std::endl;
			std::cout << "There is nothing interesting on the boulders. You return to the beach." << std::endl;
		}
	}
	else if(move == 'l')
	{
		std::cout << std::endl;
		std::cout << "These boulders look dangerous and you decide not to climb on them." << std::endl;
		std::cout << "While walking back to the beach, you trip on a fallen tree and hit your head." << std::endl;
		std::cout << "You died. You were so close to getting off the island. Darn." << std::endl;
		return nullptr;
	}
	else
	{
		//update player stats
		player->update();
		//return pointer to Temple object
		return spaces[2];
	}
	
	return this;
}

void Wbeach::winGameMssg()
{
	std::cout << std::endl;
	std::cout << "You walk towards the boat and get inside." << std::endl;
	std::cout << "Good thing you know how to sail." << std::endl;
	std::cout << "You lift up the main sail and ride off into the horizon." << std::endl;
	std::cout << "Congratulations, you got off the island!!!" << std::endl;
}
