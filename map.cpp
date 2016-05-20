
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
    this->_fieldLength = aFieldLength;
    this->mapData      = new char*[_fieldLength];
    
    for (int i = 0; i < this->_fieldLength; i++) {
        this->mapData[i] = new char[this->_fieldLength];
    }
    
    for (int i = 0; i < this->_fieldLength; i++) {
        this->mapData[i][0]                = CHAR_BLOCK;
        this->mapData[i][this->_fieldLength - 1] = CHAR_BLOCK;
        this->mapData[0][i]                = CHAR_BLOCK;
        this->mapData[this->_fieldLength - 1][i] = CHAR_BLOCK;
    }
    
    clearMap();
    
}

int Map::fieldLength() {
    return this->_fieldLength;
}

char Map::findElement(Point aSnakeHead, Point aUserWay) {
    Point charPos = aSnakeHead + aUserWay;
    return this->mapData[charPos.y()][charPos.x()];
}

void Map::drawMap() {
    for (int i = 0; i < this->_fieldLength; i++) {
        for (int j = 0; j < this->_fieldLength; j++) {
            addch(this->mapData[i][j]);
        }
        addch('\n');
    }
}

void Map::clearMap() {
    for (int i = 1; i < this->_fieldLength - 1; i ++) {
        for (int j = 1; j < this->_fieldLength - 1; j++) {
            this->mapData[i][j] = CHAR_EMPTY;
        }
    }
}

void Map::drawSnake(vector<Point> aElement) {
    for (int i = 0; i < aElement.size(); i++) {
        this->mapData[aElement[i].y()][aElement[i].x()] = CHAR_BLOCK;
    }
}

void Map::drawApple(Point aPosition) {
    this->mapData[aPosition.y()][aPosition.x()] = CHAR_APPLE;
}
