/******************************************************
** Program: node.h
** Author: Katelyn Nguyen
** Date: 03/15/2020
** Description: Header file to create linked list class.
** Input: none
** Output:none
******************************************************/

#ifndef LIST_H
#define LIST_H
#include "node.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Linked_List {
	private:
		unsigned int length;
		Node *head;
		Node *tail;
		Node *temp;
	public:
		//default constructor (wouldn't compile in implementation file?)
		Linked_List(){
        		head = NULL;
        		tail = NULL;
		}
		int get_length();
		void print();
		void clear();
		unsigned int push_front(int);
		unsigned int push_back(int);
		unsigned int insert(int val, unsigned int index);
		void sort_ascending();
		void sort_descending();
		Node* mergeList(Node* ll1, Node* ll2);
		void splitList(Node* start, Node** ll1,Node** ll2);
		void mergeSort(Node**);
		void swap(Node **head, Node* x, Node* y, Node* y2);		
		Node* selectionSort(Node* head);
		bool checkPrime(int x);
		void countPrime();

};
#endif



