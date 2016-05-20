
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

Map::Map(int aFieldLength) {
    _fieldLength  = aFieldLength;
    mapData = new char*[_fieldLength];
    for (int i = 0; i < _fieldLength; i++) {
        mapData[i] = new char[_fieldLength];
    }
    for (int i = 0; i < _fieldLength; i++) {
        mapData[i][0] = CHAR_BLOCK;
        mapData[i][_fieldLength - 1] = CHAR_BLOCK;
        mapData[0][i] = CHAR_BLOCK;
        mapData[_fieldLength - 1][i] = CHAR_BLOCK;
    }
    for (int i = 1; i < _fieldLength - 1; i ++) {
        for (int j = 1; j < _fieldLength - 1; j++) {
            mapData[i][j] = CHAR_EMPTY;
        }
    }
    
}

int Map::fieldLength() {
    return this->_fieldLength;
}

void Map::drawMap() {
    for (int i = 0; i < _fieldLength; i++) {
        for (int j = 0; j < _fieldLength; j++) {
            addch(mapData[i][j]);
        }
        addch('\n');
    }
}

void Map::clearMap() {
    for (int i = 1; i < _fieldLength - 1; i ++) {
        for (int j = 1; j < _fieldLength - 1; j++) {
            mapData[i][j] = CHAR_EMPTY;
        }
    }
}

void Map::drawSnake(vector<Point> aElement) {
    for (int i = 0; i < aElement.size(); i++) {
        mapData[aElement[i].y()][aElement[i].x()] = CHAR_BLOCK;
    }
}

void Map::drawApple(Point aPosition) {
    mapData[aPosition.y()][aPosition.x()] = CHAR_APPLE;
}
