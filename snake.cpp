
#include "snake.hpp"


int Snake::length() {
    return this->_length;
}

bool Snake::isDead() {
    return this->_isDead;
}

Point Snake::way() {
    return this->_way;
}

void Snake::way(Point aUserWay) {
    this->_way = aUserWay;
}

int Snake::countApples() {
    return this->_countApples;
}

void Snake::countApples(int aCount) {
    this->_countApples = aCount;
}

void Snake::move(Point aUserWay, char aMapElement, bool *appleIsEat) {
    for (int i = 0; i < _length - 1; i++) {
        this->_positions[i] = this->_positions[i+1];
    }
    
    switch (aMapElement) {
        case CHAR_EMPTY: {
                            this->_positions[_length - 1] = this->_positions[_length - 1] + aUserWay;
                            break;
                         }
        case CHAR_BLOCK: {
                            this->_isDead = true;
                            break;
                         }
        case CHAR_APPLE: {
                            this->_positions.insert(this->_positions.end(), this->_positions[_length - 1] + aUserWay);
                            *appleIsEat = true;
                            this->_countApples++;
                            this->_length++;
                            break;
                         }
    }
    
}
