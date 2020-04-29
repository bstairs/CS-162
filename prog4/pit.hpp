/*
***** File: pit.hpp
***** Author: Katelyn Nguyen
***** Date: 03/01/2020
***** Description: Header file for pit class
*/

#ifndef PIT_H
#define PIT_H

#include "event.hpp"
#include <iostream>
using namespace std;

class Pit: public Event{
	private:
		string message;
		char event;
	public:
		Pit();
		string get_message();
		void encounter();
};
	
#endif
