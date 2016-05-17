//
//  map.cpp
//  snake
//
//  Created by Nicholas on 16.05.16.
//  Copyright © 2016 Nicholas. All rights reserved.
//

#include "map.hpp"

int Point::x() {
    return this->_x;
}

void Point::x(int aX) {
    this->_x = aX;
}

int Point::y() {
    return this->_y;
}

void Point::y(int aY) {
    this->_y = aY;
}

const Point operator+=(const Point& aLeft, const Point& aRight) {
    return Point(aLeft._x + aRight._x, aLeft._y + aRight._y);
}

const Point operator+(const Point& aLeft, const Point& aRight) {
    return Point(aLeft._x + aRight._x, aLeft._y + aRight._y);
}

bool operator==(const Point& aLeft, const Point& aRight) {
    return ((aLeft._x == aRight._x)&&(aLeft._y == aRight._y));
}

bool operator!=(const Point& aLeft, const Point& aRight) {
    return !((aLeft._x == aRight._x)&&(aLeft._y == aRight._y));
}

