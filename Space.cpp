/*
*Program Name: Final Porject
*Date: 6/5/2017
*Description: This is the implementation file for the Space class.
*/

#include <iostream>
#include "Space.hpp"

Space::~Space()
{
	
}

std::string Space::getSpaceName()
{
	return name;
}

void Space::initPtrs(Space* up, Space* down, Space* right, Space* left)
{
	spaces[0] = up;
	spaces[1] = down;
	spaces[2] = right;
	spaces[3] = left;
}

