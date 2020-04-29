/*
***** File: gold.cpp
***** Author: Katelyn Nguyen
***** Date: 03/01/2020
***** Description: Source code for gold class
*/

#include "gold.hpp"

//default constructor
Gold::Gold(){
	message =  "You see a glimmer nearby.";
	event = 'g';
}

/*** Function: get_message
 *** Input: message
 *** Output: message
 *** Description: Outputs message when player is nearby gold.
 ***/ 
string Gold::get_message(){
	return message;
}


/*** Function: encounter
 *** Input: none
 *** Output: encounter message
 *** Description: Print message when player enters a room with gold.
 ***/
void Gold::encounter(){
	cout << "You have entered the room with gold!" << endl;
}

