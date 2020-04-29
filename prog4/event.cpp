/*
***** File: event.cpp
***** Author: Katelyn Nguyen
***** Date: 03/01/2020
***** Description: Source code for event class
*/


#include "event.hpp"

//default constructor
Event::Event(){
	event = ' ';
	message = " ";
}

//Getter for percepts for child classes
string Event::get_message(){
}


//Prints encounters for child classes
void Event::encounter(){
}




