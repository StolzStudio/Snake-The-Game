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

int Point::y() {
    return this->_y;
}

bool operator==(const Point& aLeft, const Point& aRight) {
    return ((aLeft._x == aRight._x)&&(aLeft._y == aRight._y));
}

bool operator!=(const Point& aLeft, const Point& aRight) {
    return !((aLeft._x == aRight._x)&&(aLeft._y == aRight._y));
}

