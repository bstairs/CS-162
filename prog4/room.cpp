/*
***** File: room.cpp
***** Author: Katelyn Nguyen
***** Date: 03/01/2020
***** Description: Source code for room class
*/

#include "room.hpp"

//default constructor
Room::Room(){
	event = ' ';
	player = 'x';	
}

/*** Function: set_event
 *** Input: char event type
 *** Output: sets event
 *** Description: sets event for grid array
 ***/ 
void Room::set_event(char e){
	if (e == 'w'){
		roomevent = new Wumpus;
		event = e;
	}

	if (e == 'b'){
        	roomevent = new Bats;
        	event = e;
	}
	
	if (e == 'p'){
        	roomevent = new Pit;
        	event = e;
	}

	if (e == 'g'){
        	roomevent = new Gold;
		event = e;
        }
	if (e == ' '){
		event = ' ';
	}
}

// getter function for event
char Room::get_event(){
	return event;
}

//setter function for player
void Room::set_player(char p){
	player = p;
}

//getter function for player
char Room::get_player(){
	return player;
}

//getter function for percepts
string Room::get_message(){
	return roomevent->get_message();
}

//default destructor
Room::~Room(){
	delete [] roomevent;
}



