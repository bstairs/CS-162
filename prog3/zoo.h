// zoo.h
//
// Author: Katelyn Nguyen
//
// Date: 2/16/2020
//
// Header file for Zoo class

#ifndef ZOO_H
#define ZOO_H

#include "animal.h"
#include "sealion.h"
#include "blackbear.h"
#include "tiger.h"


class Zoo{
	private:
		int sealionBonus;
		int month;
		float money;
		float monthlyFoodCost;
		bool bankrupt;

		Sealion **sealions;
		Blackbear **blackbears;
		Tiger **tigers;
		
		int numSealions, arraysizeS;
		int numBlackbears, arraysizeB;
		int numTigers, arraysizeT;

	public:
		Zoo();
		~Zoo();
		float getMoney();
		int begin();
		void setup();
		void addSealion();
		void addBlackbear();
		void addTiger();
		void removeSealion();
		void removeBlackbear();
		void removeTiger();
		void sick();
		void bonus();
		void baby();
		void special();
		void monthlyRev();
		void continueGame();
		void buyAnimal();
		void getFoodCost();
		void nextMonth();
		bool isBankrupt();

};

#endif

