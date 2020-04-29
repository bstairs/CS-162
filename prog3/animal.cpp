// animal.cpp
//
// Author: Katelyn Nguyen
//
// Date: 2/16/2020
//
// Description: Source code for Animal parent class
//              Defines setters and getters for child classes




#include <iostream>
#include "animal.h"


// default constructor
Animal::Animal(){

}

// sets name
void Animal::setName(string n){
	name = n;
}

//returns name
string Animal::getName(){
	return name;
}

// sets age
void Animal::setAge(int a){
	age = a;
}

// returns age
int Animal::getAge(){
	return age;
}

// sets babies
void Animal::setBabies(int b){
	babies = b;
}

// returns babies
int Animal::getBabies(){
	return babies;
}

// sets food cost multiplier
void Animal::setFoodcostx(int f){
	foodcostx = f;
}

// returns food cost multiplier
int Animal::getFoodcostx(){
	return foodcostx * 80;
}	

// sets base food to 80
// returns base food cost
int Animal::getBaseFood(){
	baseFood = 80;
	return baseFood;
}

void Animal::setFoodcost(){
	foodcost = baseFood * foodcostx;
}

float Animal::getFoodcost(){
	return foodcost;
}

void Animal::setCost(float c){
	cost = c;
}

float Animal::getCost(){
	return cost;
}

void Animal::setRev(float r){
	revenue = r;
}

float Animal::getRev(){
	return revenue;
}

void Animal::incrementAge(){
	age++;
}

Animal::~Animal(){

}







