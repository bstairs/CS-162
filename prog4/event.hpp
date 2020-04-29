/*
*****  File name: event.hpp
*****  Author: Katelyn Nguyen
*****  Date: 03-1-2020
*****  Description: Event Class
*/


#ifndef EVENT_H
#define EVENT_H
#include <cstring>
#include <string>
using namespace std;



class Event{
	private:
		char event;
		string message;
	public: 
		Event();
		virtual string get_message();
		virtual void encounter();
};

#endif



