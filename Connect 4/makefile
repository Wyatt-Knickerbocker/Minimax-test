all: connect4

connect4: main.o MiniMax.o Board.o
	g++ main.o MiniMax.o Board.o -o connect4

main.o: main.cpp
	g++ -c main.cpp

MiniMax.o: ./src/MiniMax.cpp
	g++ -c ./src/MiniMax.cpp

Board.o: ./src/Board.cpp
	g++ -c ./src/Board.cpp
