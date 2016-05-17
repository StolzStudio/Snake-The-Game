//
//  map.hpp
//  snake
//
//  Created by Nicholas on 16.05.16.
//  Copyright © 2016 Nicholas. All rights reserved.
//

#ifndef map_hpp
#define map_hpp

#include <stdio.h>

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
    
    friend const Point operator+=(const Point& aLeft, const Point& aRight);
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
    int _width;
    int _height;
public:
    Map(): _width(LENGTH_STANDART), _height(LENGTH_STANDART) {};
    Map(int aWidth, int aHeight): _width(aWidth), _height(aHeight) {};
    ~Map() {};
    
    void drawMap();
};


#endif /* map_hpp */