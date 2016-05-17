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
#include <vector>
#include "map.hpp"

using namespace std;
#endif /* snake_hpp */

class Snake {
protected:
    int _length;
    bool _isDead;
    vector<Point> _positions;
public:
    Snake(int aLength, Point aPos): _length(aLength), _positions(_length) {
        for (int i = 0; i < _length; i++) {
            _positions[i] = Point((aPos.x() - _length + 1) + i, aPos.y());
        }
    };
    
    ~Snake() {};
    
    int length();
    bool isDead();
    void move(Point aKey, char aMapElement);
};