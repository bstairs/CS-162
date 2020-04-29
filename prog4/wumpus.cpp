/*
***** File: wumpus.cpp
***** Author: Katelyn Nguyen
***** Date: 03/01/2020
***** Description: Source code for wumpus class
*/

#include "wumpus.hpp"

//default constructor
Wumpus::Wumpus(){
	alive = true;
	message = "You smell a terrible stench.";
	event = 'w';
}

/*** Function: get_message
 *** Input: message
 *** Output: message
 *** Description: Outputs message when player is nearby the Wumpus.
 ***/
string Wumpus::get_message(){
	return message;
}

/*** Function: get_alive
 *** Input: bool alive
 *** Output: bool alive
 *** Description: returns whether Wumpus is alive or dead
 ***/
bool Wumpus::get_alive(){
	return alive;
}

/*** Function: encounter
 *** Input: none
 *** Output: encounter message
 *** Description: Print message when player enters a room with the Wumpus.
 ***/
void Wumpus::encounter(){
	cout << "The Wumpus is in the room and eats you!" << endl;
}

