/*
***** File: bats.hpp
***** Author: Katelyn Nguyen
***** Date: 03/01/2020
***** Description: Header file for bats class
*/

#ifndef BATS_H
#define BATS_H

#include "event.hpp"
#include <iostream>
using namespace std;

class Bats: public Event{
	private:
		string message;
		char event;
	public: 
		Bats();
		string get_message();
		void encounter();
};

#endif


