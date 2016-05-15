//
//  snake.hpp
//  snake
//
//  Created by Nicholas on 16.05.16.
//  Copyright © 2016 Nicholas. All rights reserved.
//

#ifndef snake_hpp
#define snake_hpp

#include <stdio.h>
#include "map.hpp"

#endif /* snake_hpp */

class Snake {
protected:
    int _length;
    bool _isDead;
    Point _position;
public:
    Snake(int aLength, Point aPos): _length(aLength), _position(aPos) {};
    ~Snake() {};
    
    int length();
    bool isDead();
    void move();
};