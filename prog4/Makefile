CC = g++
exe_file = PlayGame
$(exe_file): main.o event.o wumpus.o bats.o pit.o gold.o room.o game.o
	$(CC) main.o event.o wumpus.o bats.o pit.o gold.o room.o game.o -o $(exe_file)
main.o: main.cpp
	$(CC) -c main.cpp
event.o: event.cpp
	$(CC) -c event.cpp
wumpus.o: wumpus.cpp
	$(CC) -c wumpus.cpp
bats.o: bats.cpp
	$(CC) -c bats.cpp
pit.o: pit.cpp
	$(CC) -c pit.cpp
gold.o: gold.cpp
	$(CC) -c gold.cpp
room.o: room.cpp
	$(CC) -c room.cpp
game.o: game.cpp
	$(CC) -c game.cpp
clean:
	rm -f *.out *.o $(exe_file)
