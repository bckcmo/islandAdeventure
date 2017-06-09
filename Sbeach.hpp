/*
*Program Name: Final Project
*Date: 6/4/2017
*Description: This is the header file for the Sbeach class.
*/

#ifndef SBEACH_HPP
#define SBEACH_HPP

#include "Space.hpp"
#include "Forest.hpp"

class Sbeach: public Space
{
private:
	int numFish;
	bool stone;
public:
	~Sbeach();
	Sbeach();
	Space* spaceInfo(Player*); 
};

#endif