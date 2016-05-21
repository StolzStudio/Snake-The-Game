
CC=g++
FILES= main.cpp map.cpp snake.cpp point.cpp apple.cpp
all:
	$(CC) $(FILES) -lncurses -o game
