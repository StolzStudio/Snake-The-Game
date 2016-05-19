
#include "snake.hpp"
#include <random>

int Snake::length() {
    return this->_length;
}

bool Snake::isDead() {
    return this->_isDead;
}

void Snake::move(Point aKey, char mapElement) {
    for (int i = 0; i < _length - 1; i++) {
        _positions[i] = _positions[i+1];
    }
    switch (mapElement) {
        case CHAR_EMPTY: { _positions[_length] += aKey; }
        case CHAR_BLOCK: { _isDead = true; }
        case CHAR_APPLE: { _positions.insert(_positions.end(), _positions[_length] + aKey); }
    }
    
}

void Apple::setApple(char **aMap, int aLength) {
    int y = random() % (aLength - 1);
    int x = random() % (aLength - 1);
    if (aMap[y][x] != CHAR_BLOCK) {
        this->_position = Point(x, y);
    }
    this->_isEat = false;
}

bool Apple::isEat() {
    return this->_isEat;
}