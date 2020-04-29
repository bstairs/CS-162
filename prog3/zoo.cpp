// zoo.cpp
//
// Author: Katelyn Nguyen
//
// Date: 2/16/2020
//
// Description: Source code for Zoo class and game functions




#include "zoo.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

// default constructor
Zoo::Zoo(){
	month = 1;
	money = 100000;
	monthlyFoodCost = 0;
	bankrupt = false;

	sealions = new Sealion *[10];
	blackbears = new Blackbear *[10];
	tigers = new Tiger *[10];

	arraysizeS = 10;
	arraysizeB = 10;
	arraysizeT = 10;

	numSealions = 0;
	numBlackbears = 0;
	numTigers = 0;
}

//returns how much money is left
//Input: 
//Output: float 
float Zoo::getMoney(){

	return money;
}

//game menu at the start of the game
//player chooses to start game or exit
//Input: int choice
//Output: calls setup function or exits game
int Zoo::begin(){
	int choice;

	cout << "Zoo Tycoon starting..." << endl;
	cout << "(1) Start game" << endl;
	cout << "(2) Exit" << endl;
	cout << "Enter your choice: ";

	cin >> choice;

	while (cin.fail() || cin.get() != '\n' || choice < 1 || choice > 2){
		cout << endl << "Invalid input!" << endl;	
		cout << endl;
		cout << "(1) Start game" << endl;
        	cout << "(2) Exit" << endl;
 		cin.clear();
	       	cout << "Enter your choice: ";
		cin >> choice;
	}  

	if(choice == 1){
		setup();
		return 1;
	}

	if(choice == 2){
		cout << endl << "Exiting game..." << endl;
		return 0;
	}
	
	return 0;
}

//Sets up game at the beginning
//Allows user to purchase 1 or 2 animals
//Input: int species, int num
//Output: calls the add Sea Lion, Black bear, or Tiger function 
//////// Prints money balance
void Zoo::setup(){
	Zoo zoo;
	int species;
	int num;
	cout << endl << "Your bank balance is: $" << money << endl;
	cout << "Which species would you like to purchase to begin?" << endl;
	cout << "(1) Sea Lion     $700" << endl;
	cout << "(2) Black Bear   $5000" << endl;
	cout << "(3) Tiger        $12000" << endl;
	cout << "(4) None" << endl;
	cout << "Enter your choice: ";

	cin >> species;

	while (cin.fail() || cin.get() != '\n' || species < 1 || species > 4){

		cout << endl << "Invalid input!" << endl;
                cout << endl;
		cout << "Which species would you like to purchase?" << endl;
        	cout << "(1) Sea Lion     $700" << endl;
        	cout << "(2) Black Bear   $5000" << endl;
        	cout << "(3) Tiger        $12000" << endl;
        	cout << "(4) None" << endl;
		
		cin.clear();
                cout << "Enter your choice: ";
		cin >> species;
	}
	if (species < 4){
	cout << "Would you like to purchase 1 or 2?" << endl;
	cout << "Enter your choice: ";
	cin >> num;

	 while (cin.fail() || cin.get() != '\n' || num < 1 || num > 2){

                cout << endl << "Invalid input!" << endl;
                cout << endl;
		cout << "Would you like to purchase 1 or 2?" << endl;
       		cin.clear();
		cout << "Enter your choice: ";
        	cin >> num;
	}
	}
	if (species == 1 && num == 1){
		addSealion();
	}

	if (species == 1 && num == 2){
                addSealion();
		addSealion();
        }

	if (species == 2 && num == 1){
                addBlackbear();
        }

	if (species == 2 && num == 2){
                addBlackbear();
		addBlackbear();
        }

	if (species == 3 && num == 1){
                addTiger();
        }

	if (species == 3 && num == 2){
                addTiger();
		addTiger();
        }

	cout << endl << "Your bank balance is: $" << money << endl;
}

// Adds another sea lion
// If array is full, double array size
// Input: number of sea lions
// Output: Bigger array with a new sea lion created
void Zoo::addSealion(){
	
	if(numSealions == arraysizeS){
		Sealion ** temp;
		temp = new Sealion *[2*arraysizeS];
		for(int i = 0; i < numSealions; i++){
			temp[i] = sealions[i];
		}
		arraysizeS = arraysizeS * 2;
		delete [] sealions;
		sealions = temp;
	}

	sealions[numSealions] = new Sealion();
	numSealions++;
	money = money - (sealions[0] -> getCost()); 
}

// Adds another black bear
// // If array is full, double array size
// // Input: number of black bears
// // Output: Bigger array with a new black bear created
void Zoo::addBlackbear(){

        if(numBlackbears == arraysizeB){
                Blackbear ** temp;
                temp = new Blackbear *[2*arraysizeS];
                for(int i = 0; i < numBlackbears; i++){
                        temp[i] = blackbears[i];
                }
                arraysizeB = arraysizeB * 2;
                delete [] blackbears;
                blackbears = temp;
        }

        blackbears[numBlackbears] = new Blackbear();
        numBlackbears++;
        money = money - (blackbears[0] -> getCost());
}

// Adds another tiger
// // If array is full, double array size
// // Input: number of tigers
// // Output: Bigger array with a new tiger created
void Zoo::addTiger(){
        if(numTigers == arraysizeT){
                Tiger ** temp;
                temp = new Tiger *[2*arraysizeT];
                for(int i = 0; i < numTigers; i++){
                        temp[i] = tigers[i];
                }
                arraysizeT = arraysizeT * 2;
                delete [] tigers;
                tigers = temp;
        }
        tigers[numTigers] = new Tiger();
        numTigers++;
        money = money - (tigers[0] -> getCost());

}


// deletes a sea lion, decreases number of sealions
// Input: sealion array, number of sealions
// Output: deletes element in array, decreases numSealions by 1
void Zoo::removeSealion(){
	
	if (numSealions > 0){
		delete sealions[numSealions - 1];
		numSealions--;
	}

}


// deletes a blackbear, decreases number of blackbears
// // Input: blackbear array, number of blackbears
// // Output: deletes element in array, decreases numBlackbears by 1
void Zoo::removeBlackbear(){

        if (numBlackbears > 0){
                delete blackbears[numBlackbears - 1];
                numBlackbears--;
        }

}


// deletes a tiger, decreases number of tigers
// Input: tiger array, number of tigers
// Output: deletes element in array, decreases numTigers by 1
void Zoo::removeTiger(){

        if (numTigers > 0){
                delete tigers[numTigers - 1];
                numTigers--;
        }
}


//Function that randomly selects an animal to die
//Input: Three animals, random number 1-3
//Output: Sick animal

void Zoo::sick(){
	srand (time(NULL));
	int sick = (rand() % 3) + 1;
	int choice;
	switch (sick)
	{
		case 1:
			if(numSealions > 0){
			
			//if animal is baby, then cost of sickness is same as animal cost
			if((sealions[0]->getAge()) <= 6){
				cout << "A baby sea lion has gotten sick!" << endl;
				cout << "You must pay $" << ((sealions[0]->getCost())) 
				<< " to save it" << endl;
			
				//subtract sickness cost from total money balance 			
				if((sealions[0]->getCost()) <= money){
                                money = money - (sealions[0]->getCost());
				}

                        	if((sealions[0]->getCost()) > money){
                        	cout << "You do not have enough money. One of your sealions has died!" 
				<< endl;
                        	removeSealion();
                        	}
			}
			//if animal is not baby, then cost of sickness is half of animal cost
			if((sealions[0]->getAge()) > 6){
				cout << "One of your sea lions has gotten sick!" << endl;
				cout << "You must pay $" << ((sealions[0]->getCost())/2) 
				<< " to save it" << endl;
		
				//subtract sickness cost from total money balance 
				if(((sealions[0]->getCost())/2) <= money){
					money = money - ((sealions[0]->getCost())/2);
				}

                                if(((sealions[0]->getCost())/2) > money){
				cout << "You do not have enough money. One of your sealions has died!" 
				<< endl;
				removeSealion();
				}
				}
			}
			else{
				cout << "No special event has occurred this month." << endl;
			}
			break;

		case 2:
			if(numBlackbears > 0){
			//if animal is baby, then cost of sickness is same as animal cost
			if((blackbears[0]->getAge()) <= 6){
                                cout << "A baby black bear has gotten sick!" << endl;
                                cout << "You must pay $" << ((blackbears[0]->getCost())) 
				<< " to save it" << endl;
 			
				//subtract sickness cost from total money balance                       
                                if((blackbears[0]->getCost()) <= money){
                                money = money - (blackbears[0]->getCost());
                                }

                                else{
                                cout << "You do not have enough money. One of your black bears has died!" 
				<< endl;
                                removeBlackbear();
                                }
                        }
			//if animal is not baby, then cost of sickness is half of animal cost
			if((blackbears[0]->getAge()) > 6){
				cout << "One of your black bears has gotten sick!" << endl;
                        	cout << "You must pay $" << ((blackbears[0]->getCost())/2) 
				<< " to save it" << endl;
                        
				//subtract sickness cost from total money balance 
 	                        if(((blackbears[0]->getCost())/2) <= money){
       	                        money = money - ((blackbears[0]->getCost())/2);
                	        }

             	        	else{
                	       	cout << "You do not have enough money. One of your black bears has died!" 
				<< endl;
               	        	removeBlackbear();
                 	        }
			}
			}

			else{
				cout << "No special event has occurred this month." << endl;
			}
			break;

		case 3:
			if(numTigers > 0){
			//if animal is baby, then cost of sickness is same as animal cost
			if((tigers[0]->getAge()) <= 6){
                                cout << "A baby tiger has gotten sick!" << endl;
                                cout << "You must pay $" << ((tigers[0]->getCost())) << " to save it" << endl;

				//subtract sickness cost from total money balance 
                                if((tigers[0]->getCost()) <= money){
                                money = money - (tigers[0]->getCost());
                                }

                                else{
                                cout << "You do not have enough money. One of your tigers has died!" << endl;
                                removeTiger();
                                }
                        }
			//if animal is not baby, then cost of sickness is half of animal cost
			if((tigers[0]->getAge()) > 6){
				cout << "One of your tigers has gotten sick!" << endl;
              	        	cout << "You must pay $" << ((tigers[0]->getCost())/2) 
				<< " to save it" << endl;

				//subtract sickness cost from total money balance 
                        	if(((tigers[0]->getCost())/2) >= money){
                                	money = money - ((tigers[0]->getCost())/2);
                        	}

	                        else{
        	                cout << "You do not have enough money. One of your tigers has died!" << endl;
                	        removeTiger();
                        	}
			}
			}
			cout << "No special event has occurred this month." << endl;
			break;	
		}
}


// random sea lion bonus from $150-400
// Input: Random number, number of sealions
// Output: Sea lion bonus
void Zoo::bonus(){
	sealionBonus = 0;
	int bonus;
	srand (time(NULL));
	int num = (rand() % 3) + 1;
	cout << "A boom in zoo attendance occurs!" << endl;
	
	switch (num){
		case 1:
			bonus = 150;
			sealionBonus = bonus * numSealions;
			break;
		case 2:
			bonus = 300;
			sealionBonus = bonus * numSealions;
			break;
		case 3:
			bonus = 400;
			sealionBonus = bonus * numSealions;
			break;
	}
	cout << "Your zoo has earned a bonus of $" << sealionBonus << endl;
	
	//adds sea lion bonus to total money balance
	money = money + sealionBonus;	
}


// chooses a random animal to give birth
// Input: random number, sea lions, tigers, blackbears
// Output: Random animal gives birth - adds 1 to that animal array
void Zoo::baby(){
	srand (time(NULL));
	int num = (rand() % 3) + 1;
	bool born = false;

	switch(num){
		case 1:
			for (int i = 0; i < numSealions; i++){
				// loops through animal array to find next adult
				// calls the add function to add an animal
				if (born == false && (sealions[i]->getAge()) >= 48)
				{
					addSealion();
					born = true;
					cout << "Congratulations! Your zoo now has a new baby sealion!" 
					<< endl;
					cout << "You now have " << numSealions << 
					" sea lions in your zoo."<< endl;
					sealions[numSealions - 1]->setAge(0); 
					break;
				}
			}
			// if no adults give birth, then there is no special event
			if(born == false){
				cout << "No special event has occurred this month." << endl;
			}
			break;

		case 2:
                        for (int i = 0; i < numBlackbears; i++){
                         	// loops through animal array to find next adult
                         	// calls the add function to add an animal
			        if (born == false && (blackbears[i]->getAge()) >= 48)
                                {
                                        addBlackbear();
                                        born = true;
                                        cout << "Congratulations! Your zoo now has a new baby black bear!" 
					<< endl;
                                        cout << "You now have " << numBlackbears 
					<< " black bears in your zoo."<< endl;
                                        blackbears[numBlackbears - 1]->setAge(0);
                                        break;
                                }
                        }
			// if no adults give birth, then there is no special event
			if (born == false)
 				cout << "No special event has occurred this month." << endl;
                        break;


		case 3:
                        for (int i = 0; i < numTigers; i++){
        			// loops through animal array to find next adult
        			// calls the add function to add an animal 
	                       if (born == false && (tigers[i]->getAge()) >= 48)
                                {
                                        addTiger();
                                        born = true;
                                        cout << "Congratulations! Your zoo now has a new baby tiger!" << endl;
                                        cout << "You now have " << numTigers << " tigers in your zoo."<< endl;
                                        tigers[numTigers - 1]->setAge(0);
                                        break;
                                }
                        }
			// if no adults give birth, then there is no special event
			if(born == false)
				cout << "No special event has occurred this month." << endl;
                        break;
	}
}


//Randomly selects a special event
//Input: Random number 1-4
//Output: One of the event functions, or prints no event occurred
void Zoo::special(){
	srand (time(NULL));
	int num = (rand() % 4)+1;
	cout << endl;
	switch (num){
		case 1:
			sick();
			break;
		case 2:
			if(numSealions > 0)
				bonus();
			else
				cout << "No special event has occurred this month." << endl;
			break;
		case 3:
			baby();
			break;
		case 4:
			cout << "No special event has occurred this month." << endl;
			break;
	}
}


//Computes monthly revenue
//Input: number of each animal, number of babies, revenue per animal
//Output: Revenue produced by each species, total revenue for the month
void Zoo::monthlyRev(){
	int revS = 0, revB = 0, revT = 0;
	int monthlyRevenue = 0;
	int babyS = 0, babyB = 0, babyT = 0;

	if (numSealions > 0){
		//Counts how many babies there are
		for (int i = 0; i < numSealions; i++){
			if (sealions[i]->getAge() <= 6)
				babyS ++;			
		}
		
		revS = (sealions[0] -> getRev() * (numSealions - babyS)); 
		revS = revS + ((sealions[0] -> getRev() * (babyS)) * 2);
	}

	if (numBlackbears > 0){
        	//Counts how many babies there are 
	       for (int i = 0; i < numBlackbears; i++){
                        if (blackbears[i]->getAge() <= 6)
                                babyB ++;
                }

                revB = (blackbears[0] -> getRev() * (numBlackbears - babyB));
                revB = revB + ((blackbears[0] -> getRev() * (babyB)) * 2);
	}

	if (numTigers > 0){
        	//Counts how many babies there are 
	       for (int i = 0; i < numTigers; i++){
                        if (tigers[i]->getAge() <= 6)
                                babyT ++;
                }

                revT = (tigers[0] -> getRev() * (numTigers - babyT));
                revT = revT + ((tigers[0] -> getRev() * (babyT)) * 2);
        }
        else{
                revT = 0;
        }

	// Prints revenue for each species
	cout << endl;
	cout << "Sea lion revenue this month: $" << revS << endl;
	cout << "Black bear revenue this month: $" << revB << endl;
	cout << "Tiger revenue this month: $" << revT << endl;
	cout << endl;
	
	monthlyRevenue = revS + revB + revT;	

	money = money + monthlyRevenue;
	
	// Prints total revenue
	cout << "This month's revenue is $" << monthlyRevenue << endl;
	cout << "Your bank balance is: $" << money << endl;
}


// Prompts user for which species and how many animals to purchase
// Input: int species, int num
// Output: calls add animal function
void Zoo::buyAnimal(){
	int num, species;
        cout << endl << "Which species would you like to purchase?" << endl;
        cout << "(1) Sea Lion     $700" << endl;
        cout << "(2) Black Bear   $5000" << endl;
        cout << "(3) Tiger        $12000" << endl;
        cout << "(4) None" << endl;
        cout << "Enter your choice: ";

        cin >> species;

	// Error handling
        while (cin.fail() || cin.get() != '\n' || species < 1 || species > 4){

                cout << endl << "Invalid input!" << endl;
                cout << endl;
                cout << "Which species would you like to purchase?" << endl;
                cout << "(1) Sea Lion     $700" << endl;
                cout << "(2) Black Bear   $5000" << endl;
                cout << "(3) Tiger        $12000" << endl;
                cout << "(4) None" << endl;

                cin.clear();
                cout << "Enter your choice: ";
                cin >> species;
        }
	if (species < 4){
        cout << "Would you like to purchase 1 or 2?" << endl;
        cout << "Enter your choice: ";
        cin >> num;

	//Error handling
        while (cin.fail() || cin.get() != '\n' || num < 1 || num > 2){

                cout << endl << "Invalid input!" << endl;
                cout << endl;
                cout << "Would you like to purchase 1 or 2?" << endl;
                cin.clear();
                cout << "Enter your choice: ";
                cin >> num;
        }
	}

	// The following if statements add an animal and sets their age to 48 months
	if (species == 1 && num == 1){
                addSealion();
        	sealions[numSealions - 1]->setAge(48);
	}

        if (species == 1 && num == 2){
                addSealion();
                addSealion();
        	sealions[numSealions - 2]->setAge(48);
		sealions[numSealions - 1]->setAge(48);
	}

        if (species == 2 && num == 1){
                addBlackbear();
        	blackbears[numBlackbears - 1]->setAge(48);
	}

        if (species == 2 && num == 2){
                addBlackbear();
                addBlackbear();
		blackbears[numBlackbears - 2]->setAge(48);
        	blackbears[numBlackbears - 1]->setAge(48);
	}

        if (species == 3 && num == 1){
                addTiger();
        	tigers[numTigers - 1]->setAge(48);
	}

        if (species == 3 && num == 2){
                addTiger();
                addTiger();
		tigers[numTigers - 2]->setAge(48);
        	tigers[numTigers - 1]->setAge(48);
	}
}


//Calculates monthly food cost
//Input: food cost per animal, number of animals
//Output: Food cost for each species, total food cost for the month
void Zoo::getFoodCost(){
	int foodS = 0, foodB = 0, foodT = 0;

	if(numSealions > 0){
		foodS = (sealions[0]->getFoodcostx() * numSealions);
	}

	if(numBlackbears > 0){
		foodB = (blackbears[0]->getFoodcostx() * numBlackbears);
	}
	
	if(numTigers > 0){
		foodT = (tigers[0]->getFoodcostx() * numTigers);
	}
	cout << "Sea lion food cost: $" << foodS << endl;
	cout << "Black bear food cost: $" << foodB << endl;
	cout << "Tiger food cost: $" << foodT << endl;
	monthlyFoodCost = foodS + foodB + foodT;
	cout << endl << "Your monthly food cost: $" << monthlyFoodCost << endl;
	money = money - monthlyFoodCost;
}


// increments every thing by one month
// Input: animal arrays, month
// Output: increase animal age by 1, count of adults and babies, month #
void Zoo::nextMonth(){
	int choice;
	month++;
	int adultS=0, adultB=0, adultT=0;
	int babyS=0, babyB=0, babyT=0;
	for (int i = 0; i < numSealions; i++){
		sealions[i]->setAge(sealions[i]->getAge()+1);
	
		// tracks babies and adults
		if(sealions[i]->getAge() <= 6)
			babyS++;
		if(sealions[i]->getAge() >= 48)
			adultS++;
	}

	for (int i = 0; i < numBlackbears; i++){
                blackbears[i]->setAge(blackbears[i]->getAge()+1);
        
		// tracks babies and adults	
		if(blackbears[i]->getAge() <= 6)
                        babyB++;
                if(blackbears[i]->getAge() >= 48)
                        adultB++;
	}

	for (int i = 0; i < numTigers; i++){
		tigers[i]->setAge(tigers[i]->getAge()+1);
	
		// tracks babies and adults
		if(tigers[i]->getAge() <= 6)
                        babyT++;
                if(tigers[i]->getAge() >= 48)
                        adultT++;
	}
	
	cout << endl << endl << endl << endl;
	cout << "MONTH " << month << " HAS BEGUN!" << endl;
	cout << "_________________________________" << endl;
	cout << endl << "Your Zoo: "<< endl << endl;
	cout << endl << "Your bank balance is: $" << money << endl << endl;
	cout << "Sea lions: " << numSealions << endl;
	cout << "Adult sea lions: " << adultS << endl;
	cout << "Baby sea lions: " << babyS << endl << endl;

	cout << "Black bears: " << numBlackbears << endl;
	cout << "Adult black bears: " << adultB << endl;
        cout << "Baby black bears: " << babyB << endl << endl;

	cout << "Tigers: " << numTigers << endl;
	cout << "Adult tigers: " << adultT << endl;
        cout << "Baby tigers: " << babyT << endl;

	cout << endl << "(1) Continue playing" << endl;
	cout << "(2) Exit game" << endl;
	cout << "Enter a choice: " << endl;

	cin >> choice;

	while (cin.fail() || cin.get() != '\n' || choice < 1 || choice > 2){
                cout << endl << "Invalid input!" << endl;
                cout << endl;
                cout << "(1) Continue playing" << endl;
                cout << "(2) Exit game" << endl;
                cin.clear();
                cout << "Enter your choice: ";
                cin >> choice;
        }


        if(choice == 2){
                cout << endl << "Exiting game..." << endl;
                exit(1);
        }




}


//Determines if player has run out of money
//Input: money
//Output: money
bool Zoo::isBankrupt(){
	if (money < 0){
		bankrupt = true;
	}
	else{
		bankrupt = false;
	}
	
	return bankrupt;
}


//Calls game functions in order
//Input: none
//Output: calls game functions and ends game
void Zoo::continueGame(){
	while(bankrupt == false){
		special();
		monthlyRev();	
		buyAnimal();
		getFoodCost();
		isBankrupt();
		nextMonth();
	}
	
	if (bankrupt == true){
		cout << "Game over. You ran out of monay." << endl;
	}
}


// destructor
Zoo::~Zoo(){
	for (int i = 0; i < numTigers; i++)
	{
		delete [] tigers[i];
	}
	delete [] tigers;

	for (int i = 0; i < numSealions; i++)
	{
		delete [] sealions[i];
	}
	delete [] sealions;

	for (int i = 0; i < numBlackbears; i++)
	{
		delete [] blackbears[i];
	}
	delete [] blackbears;
}













