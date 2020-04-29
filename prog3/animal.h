// animal.h
//
// Author: Katelyn Nguyen
//
// Date 2/16/2020
//
// Description: Header file for animal parent class


#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string.h>

using namespace std;



class Animal {
	private:
		string name;
		int age;
		int babies;
		int foodcostx;
		int baseFood;
		float foodcost;
		float cost;
		float revenue;
	public:
		Animal();
		~Animal();
		
		void setName(string);
		string getName();
		void setAge(int);
		int getAge();
		void setBabies(int);
		int getBabies();
		void setFoodcostx(int);
		int getFoodcostx();
		int getBaseFood();
		void setFoodcost();
		float getFoodcost();
		void setCost(float);
		float getCost();
		void setRev(float);
		float getRev();

		void incrementAge();

};

#endif









