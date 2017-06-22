/*
*Program Name: Final Project
*Date: 6/4/2017
*Description: This is the header file for the Pack class.
*/

#ifndef PACK_HPP
#define PACK_HPP
#include "Item.hpp"
#include <vector>

class Pack
{
private:
	int maxCapacity;
	bool full;
	std::vector<std::string> items;
public:
	Pack();
	void printContents();
	int getNumItems();
	std::string getItem(int);
	bool isFull();
	bool checkItems(std::string check);
	std::string discard(int i);
	void add(std::string i);
	void deleteItem(std::string);
};

#endif