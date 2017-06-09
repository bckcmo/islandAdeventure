/*
*Program Name: Final Project
*Date: 6/8/2017
*Description: This is the header file for the Nbeach class.
*/

#ifndef NBEACH_HPP
#define NBEACH_HPP

class Nbeach: public Space
{
private:
	bool disc;
	int numFish;
public:
	~Nbeach();
	Nbeach();
	Space* spaceInfo(Player*); 
};

#endif