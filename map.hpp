
#ifndef map_hpp
#define map_hpp

#include <stdio.h>
#include <iostream>
#include <ncurses.h>
#include <vector>
using namespace std;

#define LENGTH_STANDART 20

#define CHAR_BLOCK '#'
#define CHAR_EMPTY '.'
#define CHAR_APPLE '@'



class Point {
protected:
    int _x;
    int _y;
public:
    Point(): _x(1), _y(1) {};
    Point(int aX, int aY): _x(aX), _y(aY) {};
    ~Point() {};
    
    friend const Point operator+(const Point& aLeft, const Point& aRight);
    friend bool operator==(const Point& aLeft, const Point& aRight);
    friend bool operator!=(const Point& aLeft, const Point& aRight);
    
    Point& operator=(const Point& aRight){
        _x = aRight._x;
        _y = aRight._y;
        return *this;
    }
    
    int x();
    void x(int aX);
    int y();
    void y(int aY);
};


class Map {
protected:
    int _fieldLength;
public:
    char **mapData;

    Map(int aFieldLength);
    ~Map() {};
    
    int fieldLength();
    char findElement(Point aSnakeHead, Point aUserWay);
    void drawMap();
    void drawSnake(vector<Point> aElement);
    void drawApple(Point aPosition);
    void clearMap();
};

#endif /* map_hpp */