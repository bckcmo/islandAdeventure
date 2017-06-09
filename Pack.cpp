/*
*Program Name: Final Porject
*Date: 6/5/2017
*Description: This is the implementation file for the Pack class.
*/

#include <iostream>
#include "Pack.hpp"

#define PACK_MAX 4

Pack::Pack()
{
	maxCapacity = PACK_MAX;
	items.push_back("canteen");
	items.push_back("match box");
}

void Pack::printContents()
{
	std::cout << std::endl;
	std::cout << "Currently you have " << items.size() << " items in your bag: " << std::endl;
	for(unsigned int i = 0; i < items.size(); i++)
	{
		std::cout << i + 1 << ". " << items[i] << std::endl;; 
	}
}

bool Pack::checkItems(std::string check)
{
	bool present = false;
	
	for(unsigned int i = 0; i < items.size(); i++)
	{
		if(items[i] == check)
		{
			present = true;
		}
	}
	
	return present;
}

int Pack::getCapacity()
{
	return items.size();
}

bool Pack::isFull()
{
	if(items.size() == PACK_MAX)
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::string Pack::discard(int i)
{
	std::cout << "You have removed the " << items.at(i) << " from your pack." << std::endl;
	std::string item = items.at(i);
	items.erase(items.begin() + i);
	return item;
}

void Pack::add(std::string i)
{
	items.push_back(i);
}

void Pack::deleteItem(std::string item)
{
	for(unsigned int i = 0; i < items.size(); i++)
	{
		if(item == items[i])
		{
			std::cout << "The " << items.at(i) << " has been removed from your pack." << std::endl;
			items.erase(items.begin() + i);
		}
	}
}

std::string Pack::getItem(int i)
{
	return items.at(i);
}