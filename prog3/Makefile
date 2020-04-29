CC = g++
exe_file = PlayGame
$(exe_file): main.o zoo.o animal.o sealion.o tiger.o blackbear.o
	$(CC) main.o zoo.o animal.o sealion.o tiger.o blackbear.o -o $(exe_file)
main.o: main.cpp
	$(CC) -c main.cpp
zoo.o: zoo.cpp
	$(CC) -c zoo.cpp
animal.o: animal.cpp
	$(CC) -c animal.cpp
sealion.o: sealion.cpp
	$(CC) -c sealion.cpp
tiger.o: tiger.cpp
	$(CC) -c tiger.cpp
blackbear.o: blackbear.cpp
	$(CC) -c blackbear.cpp


clean:
	rm -f *.out *.o $(exe_file)
