/*
*Program Name: Final Porject
*Date: 6/5/2017
*Description: This is the implementation file for the Player class.
*/

#include <iostream>
#include "Player.hpp"
#include "validateInput.hpp"

#define PACK_MAX 4
#define WATER_MAX 12
#define STREN_MAX 8

Player::Player()
{
	strength = STREN_MAX;
	water = WATER_MAX;
}

void Player::setStrength(int newS)
{
	strength = newS;
}

void Player::refillWater()
{
	water = WATER_MAX;
}

int Player::getStrength()
{
	return strength;
}

int Player::getWater()
{
	return water;
}

//used to update player's stats. each time the user moves
//to a new object, one strength point and one water is removed
void Player::update()
{
	strength--;
	water--;
}

//prints players strength, water, and backpack contents
void Player::printInfo()
{
	std::cout << std::endl;
	std::cout << "You currently have " << water << " sips of water in your canteen." << std::endl;
	if(water == 0)
	{
		std::cout << "If you don't drink something right away, you will die." << std::endl;
	}
	
	std::cout << "You have " << strength << " strength points." << std::endl;
	if(strength == 0)
	{
		std::cout << "If you don't eat something right away you will die." << std::endl;
	}
	
	std::cout << "Would you like to look in your backpack?" << std::endl;

	if(getYorN() == 'y')
	{
		std::cout << "This pack is pretty small. You can only fit " << PACK_MAX << " items in it." << std::endl;
		//print info on backapck
		pack.printContents();
	}
}

bool Player::checkItems(std::string check)
{
	return pack.checkItems(check);
}

bool Player::isPackFull()
{
	return pack.isFull();
}

//removes item from player's pack based on user input
void Player::removeItem()
{
	pack.printContents();
	int input;
	std::string strInput;
	do
	{
		std::cout << std::endl;
		std::cout << "Enter the number of the item you would like to remove: " << std::endl;
		getline(std::cin, strInput);
	}while(validateInput(strInput, input) != 0 || input < 1 || input > pack.getNumItems());
	
	if(pack.discard(input - 1) == "canteen")
	{
		water = 0;
	}
	
}

void Player::deleteItem(std::string i)
{
	pack.deleteItem(i);
}

void Player::addItem(std::string item)
{
	pack.add(item);
	std::cout << std::endl;
	std::cout << "You've added the " << item << " to your pack." << std::endl;
}

std::string Player::useItems()
{
	if(pack.getNumItems() == 0)
	{
		std::cout << "Uh oh, your bag is empty..." << std::endl;
		return "empty";
	}
	else
	{
		pack.printContents();
		int input;
		std::string strInput;
		do
		{
			std::cout << std::endl;
			std::cout << "Enter the number of the item you would like to use: " << std::endl;
			getline(std::cin, strInput);
		}while(validateInput(strInput, input) != 0 || input < 1 || input > pack.getNumItems());
		
		std::string item = pack.getItem(input - 1);
		pack.deleteItem(item);
		
		if(item == "canteen")
		{
			water = 0;
		}
		
		return item;
	}
}