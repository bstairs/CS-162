CC = g++
exe_file = prog1
$(exe_file): prog1.o main.o
	$(CC) prog1.o main.o -o $(exe_file)
prog1.o: prog1.cpp
	$(CC) -c prog1.cpp
main.o: main.cpp
	$(CC) -c main.cpp

clean:
	rm -f *.out *.o $(exe_file)
