CC=g++
CFLAGS=-Wall -Wextra -std=c++11 -g
EXEC=./tp2

$(EXEC): main.o ProblemaMochila.o Auxiliares.o
	$(CC) $(CFLAGS) -o $(EXEC) *.o

main.o: main.cpp ProblemaMochila.o Auxiliares.o
	$(CC) $(CFLAGS) -c main.cpp -o main.o

ProblemaMochila.o: ProblemaMochila.cpp ProblemaMochila.hpp Auxiliares.hpp
	$(CC) $(CFLAGS) -c ProblemaMochila.cpp -o ProblemaMochila.o

Auxiliares.o: Auxiliares.cpp Auxiliares.hpp
	$(CC) $(CFLAGS) -c Auxiliares.cpp -o Auxiliares.hpp

.PHONY: clean

clean:
	rm -f *.o

mem:
	valgrind --leak-check=full --show-leak-kinds=all $(EXEC) -x ./testcases/dracula_C.z78 -o ./testcases/dracula_D.txt 
