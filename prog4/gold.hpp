/*
***** File: gold.hpp
***** Name: Katelyn Nguyen
***** Date: 03/01/2020
***** Description: Header file for gold class
*/

#ifndef GOLD_H
#define GOLD_H

#include "event.hpp"
#include <iostream>
using namespace std;


class Gold: public Event{
	private:
		string message;
		char event;
	public:
		Gold();
		string get_message();
		void encounter();
};
#endif



