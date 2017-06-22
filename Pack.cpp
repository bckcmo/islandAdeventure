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

//prints the "items" vector
void Pack::printContents()
{
	std::cout << std::endl;
	std::cout << "Currently you have " << items.size() << " items in your bag: " << std::endl;
	for(unsigned int i = 0; i < items.size(); i++)
	{
		std::cout << i + 1 << ". " << items[i] << std::endl;; 
	}
}

//check the "items" vector for a specific item
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

int Pack::getNumItems()
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

std::string Pack::getItem(int i)
{
	return items.at(i);
}

void Pack::add(std::string i)
{
	items.push_back(i);
}

/*
*discard and deleteItem are provide different uses, but the result is the same - an item is deleted from the "items" vector
*discard  takes an int and deletes the value based off it's index in the vector
*deleteItem takes a string and deletes the item by name
*/

std::string Pack::discard(int i)
{
	std::cout << "You have removed the " << items.at(i) << " from your pack." << std::endl;
	std::string item = items.at(i);
	items.erase(items.begin() + i);
	return item;
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

