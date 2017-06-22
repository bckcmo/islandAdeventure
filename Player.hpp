/*
*Program Name: Final Project
*Date: 6/4/2017
*Description: This is the header file for the Player class.
*/

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Pack.hpp"
#include "getChar.hpp"
#include "getYorN.hpp"

class Player
{
private:
	int strength;
	int water;
	Pack pack;
public:
	Player();
	int getStrength();
	int getWater();
	void setStrength(int newS);
	void refillWater();
	void printInfo();
	bool checkItems(std::string check);
	bool isPackFull();
	void removeItem();
	void deleteItem(std::string i);
	void addItem(std::string item);
	void update();
	std::string useItems();
};

#endif