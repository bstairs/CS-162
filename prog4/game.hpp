/*
***** File: game.hpp
***** Author: Katelyn Nguyem
***** Date: 03/01/2020
***** Description: Header file for game class
*/

#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "room.hpp"
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

class Game: public Room{
	private:
		vector<vector<Room*> > grid;
		int grid_size, arrows;
		int start_x, start_y, player_x, player_y, position;	
		char move;
		bool back2start, alive, win, hasgold, wumpus_dead;
		Wumpus wumpus;
		Bats bats;
		Gold gold;
		Pit pit;
	public:
		Game();
		Game(int);
		~Game();
		void setPlayer();
		void playerMove();
		void wakeWumpus();
		void shootArrow();
		void batsRoom(int);
		void checkRoom(int);
		void escape();
		void eventNearby();
		void printGrid();
		void setRandomEvents();
		void runGame(int);
};

#endif




