all: tictactoe

tictactoe: main.o
	g++ main.o -o tictactoe

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o tictactoe