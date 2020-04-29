/******************************************************
** Program: driver.cpp
** Author: Katelyn Nguyen
** Date: 03/15/2020
** Description: Contains main function to test and run linked list functions. 
** Input: integers, chars to indicate yes or no to continue
** Output: Sorted list and amount of prime numbers in linked list.
******************************************************/


#include "list.h"
#include "node.h"
using namespace std;


/*********************************************************************
** Function: int main
** Description: Main function to run program and test list functions
** Parameters: none
** Pre-Conditions: User inputs integers or characters
** Post-Conditions: List created, printed statements
*********************************************************************/
int main (){
        Linked_List list;

        int num;
        char choice = 'y', sort;

while (choice == 'y'){
        while(choice == 'y'){

                cout << "Please enter a number: ";
                cin >> num;
                list.push_back(num);
                cout << "Do you want another num (y or n): ";
                cin >> choice;
        }

        cout << "Sort ascending or descending (a or d)? ";
        cin >> sort;

        if (sort == 'a'){
                list.sort_ascending();
        }
        if (sort == 'd'){
                list.sort_descending();
        }

        cout << "Your linked list is: ";
        list.print();
        list.countPrime();
        list.clear();
        cout << "Do you want to do this again (y or n)? ";
        cin >> choice;
        cout << endl;
}
}




/*************
** TESTING ALL FUNCTIONS
*
        list.push_back(647);
        list.push_back(1547);
        list.push_back(3);
        list.push_front(1);
        list.insert(10, 0);     
        cout << "Before sorting: ";
        list.print();   
        cout << "Length of list: " << list.get_length() << endl;
        cout << "After sorting ascending: ";
        list.sort_ascending();
        list.print();
        cout << "After sorting descending: ";
        list.sort_descending();
        list.print();
        list.countPrime();
        list.clear();   
        list.print();
*
**************/
