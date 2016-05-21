
#ifndef map_hpp
#define map_hpp

#include <stdio.h>
#include <iostream>
#include <ncurses.h>
#include <vector>
#include "point.hpp"
using namespace std;

#define LENGTH_STANDART 20

#define CHAR_BLOCK '#'
#define CHAR_EMPTY ' '
#define CHAR_APPLE '@'


class Map {
protected:
    int _fieldLength;
public:
    char **mapData;

    Map(int aFieldLength);
    ~Map() {};
    
    int  fieldLength();
    char findElement(Point aSnakeHead, Point aUserWay);
    void drawMap();
    void drawSnake(vector<Point> aElement);
    void drawApple(Point aPosition);
    void clearMap();
};

#endif /* map_hpp */