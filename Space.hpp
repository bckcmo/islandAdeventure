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
#include "getYorN.hpp"

class Space
{
protected:
	Space* spaces[4]; 
	std::string name;
	char move;
public:
	virtual ~Space() = 0;
	virtual std::string getSpaceName();
	
	/*
	*spaceInfo is the function that prints all of the game text for each spaceInfo
	*there are also objects in each space that the user can collect and place into 
	*the player's items vector. Each space has it's own unique implementation
	*of this function.
	*/
	virtual Space* spaceInfo(Player*) = 0; 
	
	virtual void initPtrs(Space* up, Space* down, Space* right, Space* left);
};

#endif