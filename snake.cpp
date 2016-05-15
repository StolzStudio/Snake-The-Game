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