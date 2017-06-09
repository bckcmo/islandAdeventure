/*
*Program Name: Final Project
*Date: 6/4/2017
*Description: This is the header file for the Game class.
*/

#ifndef GAME_HPP
#define GAME_HPP
#include "Player.hpp"
#include "Space.hpp"
#include "Sbeach.hpp"
#include "River.hpp"
#include "Wbeach.hpp"
#include "Temple.hpp"
#include "Nbeach.hpp"

class Game
{
private:
	Player* player;
	Space* nBeach;
	Space* sBeach;
	Space* wBeach;
	Space* forest;
	Space* river;
	Space* temple;
	Space* currSpace;
	bool gameWin;
public:
	Game();
	~Game();
	int play();
	void setSpace();
	void initSpaces();
};

#endif