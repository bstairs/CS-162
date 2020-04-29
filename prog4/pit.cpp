/*
***** File: pit.cpp
***** Author: Katelyn Nguyen
***** Date: 03/01/2020
***** Description: Source code for pit class
*/

#include "pit.hpp"

//default constructor
Pit::Pit(){
	message = "You feel a breeze.";
	event = 'p';
}

/*** Function: get_message
 *** Input: message
 *** Output: message
 *** Description: Outputs message when player is nearby a pit.
 ***/ 
string Pit::get_message(){
	return message;
}


/*** Function: encounter
 *** Input: none
 *** Output: encounter message
 *** Description: Print message when player enters a room with a pit.
 ***/
void Pit::encounter(){
	cout << "You fell down a pit and died there alone." << endl;
}

