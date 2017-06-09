/*
*Program Name: Final Porject
*Date: 6/8/2017
*Description: This is the implementation file for the Temple class.
*/

#include <iostream>
#include "Space.hpp"
#include "Temple.hpp"

Temple::~Temple()
{
	
}

Temple::Temple()
{
	name = "Temple";	
	doorOpen = false;
	pouch = true;
	move = ' ';
}

Space* Temple::spaceInfo(Player* player)
{
	std::cout << std::endl;
	std::cout << "You are standing in front of an old temple made of stones." << std::endl;
	std::cout << "There are stone walls stretching as far as you can see in both directions." << std::endl;
	std::cout << "In the middle of the temple, there is some sort of doorway." << std::endl;
	std::cout << "Behind you is the path that leads back into the forest." << std::endl;
	int moveTry = 0;
	do
	{
		if(moveTry > 0)
		{
			std::cout << "Invalid Entry. Try again." << std::endl;
		}
		
		std::cout << std::endl;
		std::cout << "To walk up to the temple door enter 'u' " <<std::endl;
		std::cout << "To walk over to the wall on your left enter 'l' " << std::endl;
		std::cout << "To walk over to the wall on your right enter 'r' " << std::endl;
		std::cout << "To walk down the path that leads back into the forest enter 'd' " << std::endl;
		move = getChar();
		moveTry++;
	}while(move != 'u' && move != 'd' && move != 'r' && move != 'l');
	
	if(move == 'u')
	{
		if(doorOpen == false)
		{
			std::cout << std::endl;
			std::cout << "The doorway appears to be blocked by a large stone door." << std::endl;
			std::cout << "It doesn't look like we can do anything about that..." << std::endl;
		}
		else
		{
			std::cout << std::endl;
			std::cout << "The door is open. And you can see straight thru the temple." << std::endl;
			std::cout << "On the other side is a path that leads to another beach." << std::endl;
			std::cout << "Would you like to walk through the door and down to the beach?" << std::endl;
			std::cout << "Enter 'y' for yes." << std::endl;
			if(getChar() == 'y')
			{
				player->update();
				return spaces[3];
			}
		}
	}
	else if(move == 'l')
	{
		if(pouch == true)
		{
			std::cout << std::endl;
			std::cout << "You are walking along the wall on the south side of the temple." << std::endl;
			std::cout << "Hidden up agains the wall, you notice a leather pouch." << std::endl;
			std::cout << "You look inside and there appears to be some sort of grey powder." << std::endl;
			std::cout << "Would you like to pick up the pouch and put it in your backpack?" << std::endl;
			std::cout << "Enter 'y' for yes." << std::endl;
			if(getChar() == 'y')
			{
				if(player->packIsFull())
				{
					std::cout << std::endl;
					std::cout << "You don't have room in your pack." << std::endl;
					std::cout << "Would you like to remove an item to make room?" << std::endl; 
					std::cout << "Enter 'y' for yes." << std::endl;
					if(getChar() == 'y')
					{
						player->removeItem();
						player->addItem("leather pouch");
					}
					else
					{
						std::cout << std::endl;
						std::cout << "You didn't pick up the pouch." << std::endl;
					}
				}
				else
				{
					player->addItem("leather pouch");
				}
				pouch = false;
			}
			else
			{
				std::cout << std::endl;
				std::cout << "You didn't pick up the pouch." << std::endl;
			}
		}
		else
		{
			std::cout << std::endl;
			std::cout << "It just looks like a really big wall. You can't get around it or climb it." << std::endl;
		}
	}
	else if(move == 'r')
	{
		if(doorOpen == false)
		{
			std::cout << std::endl;
			std::cout << "You are walking along the wall on the north side of the temple." << std::endl;
			std::cout << "You notice a round indention in the wall." << std::endl;
			std::cout << "The indention is surrounded by elaborate carvings." << std::endl;
			std::cout << "Maybe something in your pack would fit in the indention. Do you want to see?" << std::endl;
			std::cout << "Enter 'y' to check your pack." << std::endl;
			if(getChar() == 'y')
			{
				if(player->checkItems("engraved stone"))
				{
					std::cout <<  std::endl;
					std::cout << "You have the engraved stone in your pack." << std::endl;
					std::cout << "It looks like it will fit in the indention." << std::endl;
					std::cout << "The engravings on the stone are similar to the ones on the wall." << std::endl;
					std::cout << "Do you want to try inserting the stone in the indention?" << std::endl;
					std::cout << "Enter 'y' for yes." << std::endl;
					if(getChar() == 'y')
					{
						std::cout << std::endl;
						player->deleteItem("engraved stone");
						std::cout << "The stone fits perfectly in the wall!" << std::endl;
						std::cout << "You hear loud grinding noises coming from the temple." << std::endl;
						std::cout << "You look over towards the temple and you see light coming through the doorway." << std::endl;
						std::cout << "This is very very exciting." << std::endl;
						doorOpen = true;
					}
					else
					{
						std::cout << std::endl;			
						std::cout << "Ok, don't try inserting the stone." << std::endl;
						std::cout << "You may be stuck on this island forever. No big deal." << std::endl;
					}
				}
				else
				{
					std::cout << std::endl;			
					std::cout << "There is nothing in your pack to help with this situation." << std::endl;
					std::cout << "Perhaps you should keep searching on other parts of the island." << std::endl;
				}
			}
			else
			{
				std::cout << std::endl;			
				std::cout << "You don't want to check in your bag do you head back to the temple." << std::endl;
			}
		}
		else
		{
			std::cout << std::endl;			
			std::cout << "It's the same wall that you looked at earlier." << std::endl;
			std::cout << "You put the round stone in the wall and opened the door..." << std::endl;			
			std::cout << "Nothing left to see here." << std::endl;
		}
	}
	else
	{
		player->update();
		return spaces[2];		
	}
	
	return this;
}