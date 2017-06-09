/*
*Program Name: Final Project
*Date: 6/8/2017
*Description: This is the header file for the River class.
*/

#ifndef RIVER_HPP
#define RIVER_HPP

class River: public Space
{
private:
		bool gun;
public:
	~River();
	River();
	Space* spaceInfo(Player*); 
};

#endif