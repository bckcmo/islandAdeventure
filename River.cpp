/*
*Program Name: Final Porject
*Date: 6/8/2017
*Description: This is the implementation file for the River class.
*/

#include <iostream>
#include "Space.hpp"
#include "River.hpp"

River::~River()
{
	
}

River::River()
{
	name = "River";	
	gun = true;
	//gun is the item at this space. It can only be collected once
	//"true" indicates it has not been collected
	move = ' ';
}

Space* River::spaceInfo(Player* player)
{
	std::cout << std::endl;
	std::cout << "The water looks nice, but kind of muddy." << std::endl;
	std::cout << "To the left of you is a fresh spring. That water looks safe to drink." << std::endl;
	std::cout << "Up ahead of are mountains. They look impassible." << std::endl;
	std::cout << "To the right of you is a cliff that falls off into a deep valley." << std::endl;
	std::cout << "Behind you is the path leading back to the forest." << std::endl;
	int moveTry = 0;
	do
	{
		if(moveTry > 0)
		{
			std::cout << "Invalid Entry. Try again." << std::endl;
		}
		
		std::cout << std::endl;
		std::cout << "To walk to the spring enter 'l' " <<std::endl;
		std::cout << "To walk closer to the mountains enter 'u' " << std::endl;
		std::cout << "To walk over to the cliff enter 'r' " << std::endl;
		std::cout << "To walk back to the forest enter 'd' " << std::endl;
		move = getChar();
		moveTry++;
	}while(move != 'u' && move != 'd' && move != 'r' && move != 'l');
	
	if(move == 'l')
	{
		std::cout <<std::endl;
		std::cout << "The water from the spring is cold and fresh." << std::endl;
		std::cout << "It looks safe to drink. Do you want to refill your canteen?" << std::endl;
		if(getYorN() == 'y')
		{
			if(player->checkItems("canteen"))
			{
				std::cout << std::endl;
				std::cout << "Your canteen is full. Sweeeet." << std::endl; 
				player->refillWater();
			}
			else
			{
				std::cout <<std::endl;
				std::cout << "You removed your canteen from you pack." << std::endl;
				std::cout << "That was silly. Now you are going to run out of water." << std::endl;
			}
		}
	}
	else if(move == 'u')
	{
		if(gun == true)
		{
			std::cout << std::endl;
			std::cout << "You've walked as close to the mountains as you can get." << std::endl;
			std::cout << "While looking at the ground, you see a handgun." << std::endl;
			std::cout << "Would you like to pick up the gun and put it in your backpack?" << std::endl;
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
						player->addItem("gun");
					}
					else
					{
						std::cout << std::endl;
						std::cout << "You didn't pick up the gun" << std::endl;
					}
				}
				else
				{
					player->addItem("gun");
				}
				gun = false;
			}
			else
			{
				std::cout << std::endl;
				std::cout << "You didn't pick up the gun" << std::endl;
			}
		}
		else
		{
			std::cout << std::endl;
			std::cout << "You've walked as close to the mountains as you can get." << std::endl;
			std::cout << "There is nothing else of interest here. You return to the river." << std::endl;
		}
	}
	else if(move == 'r')
	{
		std::cout << std::endl;
		std::cout << "You are standing at the edge of the cliff." << std::endl;
		std::cout << "You lose your footing and stumble down off the edge." << std::endl;
		std::cout << "You fell hundreds of feet and died on impact. Sad!" << std::endl;
		return nullptr;
	}
	else if(move == 'd')
	{
		//update player's stats
		player->update();
		//return pointer to Forest object
		return spaces[2];
	}
	
	return this;
}