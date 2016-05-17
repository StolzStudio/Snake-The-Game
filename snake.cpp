//
//  snake.cpp
//  snake
//
//  Created by Nicholas on 16.05.16.
//  Copyright © 2016 Nicholas. All rights reserved.
//

#include "snake.hpp"

int Snake::length() {
    return this->_length;
}

bool Snake::isDead() {
    return this->_isDead;
}

void Snake::move(Point aKey, char aMapElement) {
    for (int i = 0; i < _length - 1; i++) {
        _positions[i] = _positions[i+1];
    }
    switch (aMapElement) {
        case CHAR_EMPTY: { _positions[_length] += aKey; }
        case CHAR_BLOCK: { _isDead = true; }
        case CHAR_APPLE: { _positions.insert(_positions.end(), _positions[_length] + aKey); }
    }
    
}