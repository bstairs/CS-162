/*
***** File: game.cpp
***** Author: Katelyn Nguyen
***** Date: 03/01/2020
***** Description: Source code for game class
*/

#include "game.hpp"

//default constructor
Game::Game(){
	grid_size = 4;
	arrows = 3;
	start_x = 0;
	start_y = 0;
	player_x = 0;
	player_y = 0;	
	wumpus_dead = false;
	hasgold = false;
	alive = false;
	win = false;
}

//constructor
Game::Game(int size){
	grid_size = size;
	for (int i = 0; i < size; i++){
		vector<Room*> row;
		for (int j = 0; j < size; j++){
			row.push_back(new Room);
		}
		grid.push_back(row);
	}

	arrows = 3;
        start_x = 0;
        start_y = 0;
        player_x = 0;
        player_y = 0;
        wumpus_dead = false;
        hasgold = false;
	alive = false;
}

/*** Function: set_player
 *** Input: none
 *** Output: random player coordinates
 *** Description: Randomly places player on the board
 ***/
void Game::setPlayer(){
	srand (time(NULL));	
	player_x = rand() % (grid_size-1);
	player_y = rand() & (grid_size-1);
	start_x = player_x;
	start_y = player_y;
}

/*** Function: setRandomEvents
 *** Input: none
 *** Output: Random events placed on board
 *** Description: Randomly places events on the board
 ***/
void Game::setRandomEvents(){
	int wumpus = 0, gold = 0, bats = 0, pit = 0;
	srand (time(NULL));	

	for (int i = 0; i < grid_size; i++){
                for (int j = 0; j < grid_size; j++){
        		if( i == player_x && j == player_y){

			}

			else{

	   		int num = rand() % 5;		
			switch (num){
				case 1:
					if (wumpus == 0){
						grid[i][j]->set_event('w');
						wumpus ++;
					}
					else
						grid[i][j]->set_event(' ');	
					break;
				case 2:
					if (gold == 0){
						grid[i][j]->set_event('g');
						gold ++;
					}
					else
                                                grid[i][j]->set_event(' ');
                                        break;
				case 3:
					if (bats < 2){
					grid[i][j]->set_event('b');
					bats++;
					break;
					}
				case 4:
					if (pit < 2){
					grid[i][j]->set_event('p');		
					pit++;
					break;
					}
				case 5:
					grid[i][j]->set_event(' ');
                                        break;
			}
			} 
		}
        }
}


/*** Function: playerMove
 *** Input: char
 *** Output: changed player coordinates
 *** Description: allows player to move around the board
 ***/
void Game::playerMove(){
	char move;
	int input = 0;
	cout << "Which direction would you like to move?" << endl;
	cout << "w - North" << endl;
	cout << "a - West" << endl;
	cout << "s = South" << endl;
	cout << "d - East" << endl;

	cin >> move;

	while (cin.fail() || cin.get() != '\n' || (move != 'w' && move!= 'a' && move != 's' && move != 'd')){

                cout << endl << "Invalid input!" << endl;
                cout << endl;
                
		cin.clear();
                cout << "Enter your choice: ";
                cin >> move;
        }
    

	if(move == 'w'){
		if(player_x-1<0|| player_x-1>grid_size-1|| player_y<0|| player_y>grid_size-1){
			cout << "Out of bounds! Try again" << endl;
			playerMove();
		}
		else{
			player_x--;
		}
	} 

	if(move == 'a'){
                if(player_x<0|| player_x>grid_size-1|| player_y-1<0|| player_y-1>grid_size-1){
                        cout << "Out of bounds! Try again" << endl;
                	playerMove();
		}
		else{
                        player_y--;
		}
	}

	if(move == 's'){
                if(player_x+1<0|| player_x+1>grid_size-1|| player_y<0|| player_y>grid_size-1){
                        cout << "Out of bounds! Try again" << endl;
         		playerMove();
	 	}
	        else{
                        player_x++;
		}	
	}

	if(move == 'd'){
                if(player_x<0|| player_x>grid_size-1|| player_y+1<0|| player_y+1>grid_size-1){
                        cout << "Out of bounds! Try again" << endl;
                	playerMove();
		}
		else{
                        player_y++;
		}
        }
}

/*** Function: shootArrow
 *** Input: char direction
 *** Output: Wumpus killed or woken up
 *** Description: Allows player to shoot arrow up to three rooms
 ***/
void Game::shootArrow(){
	arrows --;
	char fire;
	int wake = 0;
	wumpus_dead = 0;
	cout << "Which direction would you like to fire the arrow?" << endl;
        cout << "w - North" << endl;
        cout << "a - West" << endl;
        cout << "s = South" << endl;
        cout << "d - East" << endl;
	cin >> fire;
	if (fire == 'w'){
		for (int i = 1; i <= 3; i++){
			if(player_x - i < 0){
				cout << "You missed the Wumpus!" << endl;
                     		wake++;
			   	wakeWumpus();
				break;
			}
			else if (grid[player_x - i][player_y]->get_event() == 'w'){
				wumpus_dead = 1;
				cout << "You have killed the Wumpus!" << endl;
				grid[player_x - i][player_y]->set_event(' ');
				break;
			}
			else{  
				if (wumpus_dead != 1){ 
                                	wumpus_dead = 0;
                        	}	
			}
		}
		if (wake == 0 && wumpus_dead == 0){
                        cout << "You missed the Wumpus!" << endl;
                        wakeWumpus();
		}
	}

        if (fire == 'a'){
                for (int i = 1; i <= 3; i++){
			if(player_y - i < 0){
                                cout << "You missed the Wumpus!" << endl;
         			wake++;
	                        wakeWumpus();
         			break;
	                }
	                else if (grid[player_x][player_y - i]->get_event() == 'w'){
                                wumpus_dead == 1;
                                cout << "You have killed the Wumpus!" << endl;
         			grid[player_x - i][player_y]->set_event(' ');
	                        break;
                        }
	       		else{   
                                wumpus_dead = 0;
                        }
		
		}
		if (wake == 0 && wumpus_dead == 0){
                        cout << "You missed the Wumpus!" << endl;
                        wakeWumpus();
                }
        }

        if (fire == 's'){
                for (int i = 1; i <= 3; i++){
			if(player_x + i >= grid_size){
                                cout << "You missed the Wumpus!" << endl;
                                wakeWumpus();
        			wake++; 
				break;
	                }
	                else if (grid[player_x + i][player_y]->get_event() == 'w'){
                                wumpus_dead == 1;
                                cout << "You have killed the Wumpus!" << endl;
         			grid[player_x - i][player_y]->set_event(' ');
	                        break;
                        }
        		else{
                                wumpus_dead = 0; 
			}
		}
        	if (wake == 0 && wumpus_dead == 0){
                        cout << "You missed the Wumpus!" << endl;
                        wakeWumpus();
                }
	}

        if (fire == 'd'){
                for (int i = 1; i <= 3; i++){
			if((player_y + i) >= grid_size){
                                cout << "You missed the Wumpus!" << endl;
                                wakeWumpus();
                        	wake++;
				break;
			}
                        else if (grid[player_x][player_y + i]->get_event() == 'w'){
                                wumpus_dead == 1;
                                cout << "You have killed the Wumpus!" << endl;
 				grid[player_x - i][player_y]->set_event(' ');
                                break;
                        }
	       		else{   
                                wumpus_dead = 0;
                        }
		
		}
		if (wake == 0 && wumpus_dead == 0){
                        cout << "You missed the Wumpus!" << endl;
                        wakeWumpus();
                }
	}
	cin.clear();
}

/*** Function: wakeWumpus
 *** Input: none
 *** Output: random Wumpus events
 *** Description: If player misses shooting the Wumpus, 
 *** there's a 75% chance it will wake up and move
 ***/
void Game::wakeWumpus(){
	srand (time(NULL));
	int wake = rand() % 4;
	int moveX = rand() % grid_size;
	int moveY = rand() % grid_size;
	if (wake == 1){
		cout << "Nothing happens, the Wumpus is still sleeping..." << endl;
	}
	
	else{
		cout << "The Wumpus has awakened and moved to another room!" << endl;
		for (int i = 0; i < grid_size; i++){
	                for (int j = 0; j < grid_size; j++){
                                if (grid[i][j]->get_event() == 'w'){
					grid[i][j]->set_event(' ');
				}
			}
                }

		if(moveX == player_x && moveY == player_y){
			moveX = rand() % grid_size;
        		moveY = rand() % grid_size;
		}	
		
		grid[moveX][moveY]->set_event('w');					
	}

}

/*** Function: checkRoom
 *** Input: Room coordinates
 *** Output: Event message in room
 *** Description: Check to see if player is in a room 
 *** with an event and prints corresponding message.
 ***/
void Game::checkRoom(int debug){
	if(grid[player_x][player_y]->get_event() == 'w'){
		wumpus.encounter();
		alive = true;
	}

	if(grid[player_x][player_y]->get_event() == 'g'){
		gold.encounter();
		hasgold = true;
		grid[player_x][player_y]->set_event(' ');
	}
	if(grid[player_x][player_y]->get_event() == 'p'){
		pit.encounter();
		alive = true;
	}
	if(grid[player_x][player_y]->get_event() == 'b'){
		bats.encounter();
		batsRoom(debug);
	}
}


/*** Function: batsRoom
 *** Input: debug mode
 *** Output: randomly places player on the board
 on *** Description: Super bats carry player to random room
 ***/
void Game::batsRoom(int debug){
	srand (time(NULL));
	int moveX = rand() % grid_size;
        int moveY = rand() % grid_size;	

	grid[player_x][player_y]->set_event(' ');
	player_x = moveX;
	player_y = moveY;

	if (debug == 1)
		printGrid();
}


/*** Function: escape
 *** Input: none
 *** Output: bool
 *** Description: True if player has returned back to starting point
 ***/
void Game::escape(){
	if (player_x == start_x && player_y == start_y)
		back2start = true;
	else
		back2start = false;
}


/*** Function: eventNearby
 *** Input: none
 *** Output: string event message 
 *** Description: Checks surrounding rooms for events and prints perceptions
 ***/
void Game::eventNearby(){
	for(int i = player_x-1; i < player_x+1; i++){
		for(int j = player_y-1; j < player_y+1; j++){
			if(i >=0 && i < grid_size && j >=0 && j < grid_size){
					if (grid[i][j]->get_event() == 'w')
						cout << wumpus.get_message() << endl;
					if (grid[i][j]->get_event() == 'g') 
						cout << gold.get_message() << endl;;
					if (grid[i][j]->get_event() == 'p')	
						cout << pit.get_message() << endl;
					if (grid[i][j]->get_event() == 'b')
						cout << bats.get_message() << endl;
			}
		}
	}	              
}

/*** Function: printGrid
 *** Input: none
 *** Output: array
 *** Description: Prints board for debug mode.
 ***/
void Game::printGrid(){
	for (int i = 0; i < grid_size; i++){
		for (int j = 0; j < grid_size; j++){
			cout << " | ";
			if (i == start_x && j == start_y)
				cout << "$";
			else
			if (i == player_x && j == player_y){
				cout << "x";
			}
			else
				cout << grid[i][j]->get_event();
		}
		cout << " | " << endl;
	}
}


/*** Function: runGame
 *** Input: debug mode
 *** Output: game
 *** Description: Game functions called in order
 ***/
void Game::runGame(int debug){
	int move;
	eventNearby();
	cout << "Would you like to move to a different room or shoot an arrow?" << endl;
	cout << "(1) Move to a different room" << endl;
	cout << "(2) Shoot an arrow" << endl;
	cin >> move;
	
	if (move == 1){
		playerMove();
	}
	if (move == 2){
		if (arrows != 0)
			shootArrow();
		else{
			cout << "You ran out of arrows!" << endl;
			playerMove();		
		}
	}
	cin.clear();
	if (debug == 1){
		printGrid();
	}
	checkRoom(debug);
	escape();
	if (hasgold !=0 && back2start !=0){
                cout << "You have retrieved the gold and successfully escaped!" << endl;
        }
	if (alive == 0 && (hasgold ==0 || back2start == 0)){
		runGame(debug);
	}
}


//default destructor
Game::~Game(){
}
