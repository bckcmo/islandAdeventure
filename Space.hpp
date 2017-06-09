/*
*Program Name: Final Project
*Date: 6/4/2017
*Description: This is the header file for the Space class.
*/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <vector>
#include "Player.hpp"
#include "validateInput.hpp"

class Space
{
protected:
	Space* spaces[4]; 
	std::string name;
	char move;
public:
	virtual ~Space() = 0;
	virtual std::string getSpaceName();
	virtual Space* spaceInfo(Player*) = 0; 
	virtual void initPtrs(Space* up, Space* down, Space* right, Space* left);
};

#endif