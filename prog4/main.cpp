/*
***** File: main.cpp
***** Author: Katelyn Nguyen
***** Date: 03/01/2020
***** Description: driver file for Hunt the Wumpus game
*/

#include "game.hpp"

//Main function
int main(int argc, char **argv){
        int choice, debug;
        if(argc != 3){
                cout << "Error, invalid command line" << endl;
                cout << "Restart program" << endl;
                return 1;
        }

        int size = atoi(argv[1]);
        int showGrid = atoi(argv[2]);

        if (showGrid == 1){
                Game game(size);
                game.setPlayer();
                game.setRandomEvents();
                game.printGrid();
                game.runGame(1);
        }

        if (showGrid == 0){
                Game game(size);
                game.setPlayer();
                game.setRandomEvents();
                game.runGame(0);
        }
        cout << "Would you like to play again?" << endl;
        cout << "(1) Yes - same board" << endl;
        cout << "(2) Yes - new board" << endl;
        cout << "(3) No" << endl;

        cin >> choice;

        if (choice == 1){
                if (showGrid == 1){
                        Game game(size);
                        game.setPlayer();
                        game.setRandomEvents();
                        game.printGrid();
                        game.runGame(1);
        }

                if (showGrid == 0){
                        Game game(size);
                        game.setPlayer();
                        game.setRandomEvents();
                        game.runGame(0);
        }
        }
        if (choice == 2){
                int size;
                cout << "What size grid?" << endl;
                cin >> size;
                Game game2(size);
                cout << "Would you like to play in debug mode?" << endl;
                cout << "(1) Yes" << endl;
                cout << "(0) No" << endl;
                cin >> debug;

                if (debug == 1){
                        game2.setPlayer();
                        game2.setRandomEvents();
                        game2.printGrid();
                        game2.runGame(1);
                }
                if (debug == 0){
                        game2.setPlayer();
                        game2.setRandomEvents();
                        game2.runGame(0);
                }

        }


}






