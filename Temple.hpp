/*
*Program Name: Final Project
*Date: 6/8/2017
*Description: This is the header file for the Temple class.
*/

#ifndef TEMPLE_HPP
#define TEMPLE_HPP

class Temple: public Space
{
private:
	bool pouch;
	bool doorOpen;
public:
	~Temple();
	Temple();
	Space* spaceInfo(Player*); 
};

#endif