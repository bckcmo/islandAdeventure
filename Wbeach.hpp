/*
*Program Name: Final Project
*Date: 6/8/2017
*Description: This is the header file for the Wbeach class.
*/

#ifndef WBEACH_HPP
#define WBEACH_HPP

class Wbeach: public Space
{
private:
	bool bottle;
	std::string useItem;
	bool firstEncounter;
public:
	~Wbeach();
	Wbeach();
	Space* spaceInfo(Player*); 
	void winGameMssg();
};

#endif