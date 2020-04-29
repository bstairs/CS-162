CC = g++ -g 
exe_file = run
$(exe_file): driver.o list.o
	$(CC)  driver.o list.o -o $(exe_file)
driver.o: driver.cpp
	$(CC) -c driver.cpp
list.o: list.cpp
	$(CC) -c list.cpp
clean:
	rm -f *.out *.o $(exe_file)
