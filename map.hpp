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

#endif /* map_hpp */

class Point {
protected:
    int _x;
    int _y;
public:
    Point(): _x(1), _y(1) {};
    Point(int aX, int aY): _x(aX), _y(aY) {};
    ~Point() {};
    
    friend bool operator==(const Point& aLeft, const Point& aRight);
    friend bool operator!=(const Point& aLeft, const Point& aRight);
    
    int x();
    int y();
};


class Map {
protected:
    int _width;
    int _height;
public:
    Map(): _width(LENGTH_STANDART), _height(LENGTH_STANDART) {};
    Map(int aWidth, int aHeight): _width(aWidth), _height(aHeight) {};
    ~Map() {};
    
};