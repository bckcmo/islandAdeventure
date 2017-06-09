/*
*Program Name: Final Project
*Date: 6/4/2017
*Description: This is the header file for the Forest class.
*/

#ifndef FOREST_HPP
#define FOREST_HPP

class Forest: public Space
{
private:

public:
	~Forest();
	Forest();
	Space* spaceInfo(Player*); 
};

#endif