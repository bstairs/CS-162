/*
***** File: room.hpp
***** Name: Katelyn Nguyen
***** Date: 03/01/2020
***** Description: Header file for room class
*/

#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "bats.hpp"
#include "gold.hpp"
#include "pit.hpp"
#include "wumpus.hpp"

class Room{
	private:
		Event *roomevent;
		char event;
		char player;
	public:
		Room();
		void set_event(char);
		char get_event();
		void set_player(char);
		char get_player();
		string get_message();
		void get_wumpus();
		~Room();
};



#endif
