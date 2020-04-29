/******************************************************
** Program: node.h
** Author: Katelyn Nguyen
** Date: 03/15/2020
** Description: Header file to create node class.
** Input: none
** Output:none
******************************************************/

#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;


class Node{
	public:
		int val;
		Node *next;
		Node *prev;
};
#endif


