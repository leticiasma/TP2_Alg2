CC=g++
CFLAGS=-Wall -Wextra -std=c++11 -g
EXEC=./tp2

$(EXEC): main.o ProblemaMochila.o
	$(CC) $(CFLAGS) -o $(EXEC) *.o

main.o: main.cpp ProblemaMochila.o
	$(CC) $(CFLAGS) -c main.cpp -o main.o

ProblemaMochila.o: ProblemaMochila.cpp ProblemaMochila.hpp
	$(CC) $(CFLAGS) -c ProblemaMochila.cpp -o ProblemaMochila.o

.PHONY: clean

clean:
	rm -f *.o

mem:
	valgrind --leak-check=full --show-leak-kinds=all $(EXEC) -x ./testcases/dracula_C.z78 -o ./testcases/dracula_D.txt 
