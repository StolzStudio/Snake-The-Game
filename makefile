
CC=g++
FILES= main.cpp map.cpp snake.cpp
all:
	$(CC) $(FILES) -lncurses -o game
