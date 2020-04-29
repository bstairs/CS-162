/******************************************************
** Program: list.cpp
** Author: Katelyn Nguyen
** Date: 03/15/2020
** Description: Implementation file for linked list class.
**              Contains functions to manipulate linked list.
** Input: Nodes
** Output: Printed statements, integers, bool, Node*
******************************************************/


#include "list.h"
using namespace std;


/*********************************************************************
** Function: int get_length
** Description: Return the length of the list
** Parameters: none
** Pre-Conditions: A list created
** Post-Conditions: the length of the list returned
*********************************************************************/
int Linked_List::get_length(){
	length = 0;
	if(head != NULL){
                for(temp = head; temp != NULL; temp = temp->next){
			length++;
	        }
	}
	return length;
}


/*********************************************************************
** Function: void print
** Description: prints the content of the list
** Parameters: none
** Pre-Conditions: A list created
** Post-Conditions: the content of the list printed
*********************************************************************/
void Linked_List::print(){
	if(head != NULL){
		for(temp = head; temp != NULL; temp = temp->next){	
			cout << temp->val << " ";
		}
	cout << endl;
	}
	else
		cout << "Empty list!"<< endl;
}


/*********************************************************************
** Function: void clear
** Description: Free all the nodes in the list
** Parameters: none
** Pre-Conditions: A list created
** Post-Conditions: Free all memory, and set head and tail to NULL
*********************************************************************/
void Linked_List::clear(){
	Node* del = head;  
	while (del != NULL)  
	{  
    		temp = del->next;  
    		free(del);  
    		del = temp;  
	}  
	head = NULL;
	tail = NULL;
}


/*********************************************************************
** Function: void push_front
** Description: Push a new node to the front with user's value
** Parameters: int
** Pre-Conditions: A list created, and a value for the node
** Post-Conditions: The list has a new node in the front
*********************************************************************/
unsigned int Linked_List::push_front(int user){
	temp = new Node;
	temp->val = user;
	temp -> next = NULL;
	if(head == NULL){
		temp->next = NULL;
		tail = temp;
	}

	else{	
		temp -> next = head;
		head = temp;
	}
}


/*********************************************************************
** Function: void push_back
** Description: Push a new node in the back with user's value
** Parameters: int
** Pre-Conditions: a list created, and a value for the node
** Post-Conditions: The list has a new node in the back
*********************************************************************/
unsigned int Linked_List::push_back(int user){
	temp = new Node;
        temp -> val = user;
 	temp -> next = NULL;
        if(head == NULL){
                head = temp;
		tail = temp;
        }
        else{
                tail -> next = temp;
                tail = temp;
        }
}


/*********************************************************************
** Function: unsigned int insert
** Description: insert a new node at specified index
** Parameters: int, unsigned int
** Pre-Conditions: a list created, and a value for the node
** Post-Conditions: The list has a new node at specified index 
*********************************************************************/
unsigned int Linked_List::insert(int user, unsigned int index){
	if(index > get_length()+1 || index < 0){
		cout << "Error, position doesn't exist" << endl;
	}
	else{
	Node* temp = (Node*)malloc(get_length());
	temp -> val = user;
		if(head == NULL){
		}
		else if(index == 0){
			push_front(user);
		}
		else{
			Node *current = head;
			while(index - 1 >= 0){
				current = current -> next;
				index--;
			}
			temp -> next = current -> next;
			current -> next = temp;
		}
	}
}


/*********************************************************************
** Function: Node* mergeList
** Description: merges two split lists
** Parameters: Node*
** Pre-Conditions: a list is split, and has more than one node
** Post-Conditions: Two split lists are merged
*********************************************************************/
Node* Linked_List::mergeList(Node* list1, Node* list2) {
	Node* merge = NULL;
	if(list1 == NULL)
		return list2;
	if(list2 == NULL)
		return list1;
	if(list1 -> val <= list2 -> val) {
		merge = list1;
		merge -> next = mergeList(list1->next,list2);
	}
	else{
		merge = list2;
		merge -> next = mergeList(list1,list2->next);
	}
	return merge;
}


/*********************************************************************
** Function: void splitList
** Description: splits a list
** Parameters: Node*, Node**
** Pre-Conditions: a list created, a value for the node, and has more than one node
** Post-Conditions: A list is split
*********************************************************************/
void Linked_List::splitList(Node* start, Node** list1, Node** list2) {
	Node* low = start;
	Node* high = start -> next;

	while(high!= NULL) {
		high = high -> next;
		if(high!= NULL) {
			low = low -> next;
			high = high -> next;
		}
	}

	*list1 = start;
	*list2 = low -> next;
	low -> next = NULL;
}


/*********************************************************************
** Function: void mergeSort
** Description: merge sorts a list
** Parameters: Node**
** Pre-Conditions: a list created, a value for the node, and has more than one node
** Post-Conditions: A list is merge sorted in ascending order
*********************************************************************/
void Linked_List::mergeSort(Node** h) {
	Node* t = *h;
	Node* list1,*list2;
	if(t == NULL || t->next == NULL) {
		return;
	}
	
	splitList(t,&list1,&list2);
	mergeSort(&list1);
	mergeSort(&list2);

	*h = mergeList(list1,list2);
	return;
}


/*********************************************************************
** Function: void sort_ascending
** Description: sorts a list of integers in ascending order
** Parameters: none
** Pre-Conditions: a list created, a value for the node, and has more than one node
** Post-Conditions: A list is sorted in ascending order
*********************************************************************/
void Linked_List::sort_ascending(){
        mergeSort(&head);
}


/*********************************************************************
** Function: void swap
** Description: selection sorts a list by swapping nodes
** Parameters: Node**, Node*
** Pre-Conditions: a list created, a value for the node, and has more than one node
** Post-Conditions: Nodes are swapped
*********************************************************************/

void Linked_List::swap(Node **head, Node* x, Node* y, Node* y2){
	*head = y;
	y2 -> next = x;
	Node* temp = y -> next;
	y -> next = x -> next;
	x -> next = temp;
}


/*********************************************************************
** Function: Node* selectionSort
** Description: selection sorts a list
** Parameters: Node*
** Pre-Conditions: a list created, a value for the node, and has more than one node
** Post-Conditions: A list is selection sorted in ascending order
*********************************************************************/

Node* Linked_List::selectionSort(Node* head){
	Node* min = head;
	Node* prev = NULL;
	Node* temp;

	if(head->next == NULL)
                return head;

	for(temp = head; temp -> next != NULL; temp = temp -> next){
		if(temp -> next -> val < min -> val){
			min = temp -> next;
			prev = temp;
		}
	}
	
	if(min != head)
		swap(&head, head, min, prev);
		
	head -> next = selectionSort(head->next);
	
	return head;

}



/*********************************************************************
** Function: void sort_descending
** Description: sorts a list of integers in descending order
** Parameters: none
** Pre-Conditions: a list created, a value for the node, and has more than one node
** Post-Conditions: A list is sorted in descending order
*********************************************************************/
void Linked_List::sort_descending(){
	if(head == NULL){
		return;
	}
		head = selectionSort(head);

	Node* prev = NULL, *curr = head, *next; 
	while (curr) { 
		next = curr->next; 
        	curr->next = prev; 
        	prev = curr; 
	        curr = next; 
    	} 
   	head = prev;  
}

/*********************************************************************
** Function: bool checkPrime
** Description: checks if integer is a prime number
** Parameters: int
** Pre-Conditions: An integer is entered
** Post-Conditions: A boolean value is returned indicating whether it's a prime number
*********************************************************************/
bool Linked_List::checkPrime(int x){
        for (int i = 2; i <= x/2; i++){
                if(x%i == 0){
                        return false;
                }
        }
        return true;
}


/*********************************************************************
** Function: void countPrime
** Description: Counts amount of prime numbers in list
** Parameters: none
** Pre-Conditions: A list created, a value for the node
** Post-Conditions: Amount of prime numbers in list is printed
*********************************************************************/
void Linked_List::countPrime(){
	int count = 0;

        cout << "Amount of prime numbers: " ;
	if(head != NULL){
               for(temp = head; temp != NULL; temp = temp->next){
                        if (checkPrime(temp->val)){
				count++;
			} 
	       }
	cout << count << endl;
	}
}

