/*
***** File: wumpus.hpp
***** Author: Katelyn Nguyen
***** Date: 03/01/2020
***** Description: Wumpus class header file
*/

#ifndef WUMPUS_H
#define WUMPUS_H

#include "event.hpp"
#include <iostream>
using namespace std;

class Wumpus: public Event{
	private:
		bool alive;
		string message;
		char event;
	public:
		Wumpus();
		string get_message();
		bool get_alive();
		void encounter();
};









#endif
