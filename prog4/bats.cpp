/*
***** File: bats.cpp
***** Author: Katelyn Nguyen
***** Date: 03/01/2020
***** Description: Source code for bats class
*/

#include "bats.hpp"

//default constructor
Bats::Bats(){
        message = "You hear wings flapping.";
        event = 'b';
}

/*** Function: get_message
 *** Input: message
 *** Output: message
 *** Description: Outputs message when player is nearby bats.
 ***/ 
string Bats::get_message(){
        return message;
}

/*** Function: encounter
 *** Input: none
 *** Output: encounter message
 *** Description: Print message when player enters a room with bats.
 ***/
void Bats::encounter(){
	cout << "There are super bats in this room! They have carried you to a random room." << endl;
}




