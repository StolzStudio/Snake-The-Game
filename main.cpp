//
//  main.cpp
//  snake
//
//  Created by Nicholas on 16.05.16.
//  Copyright © 2016 Nicholas. All rights reserved.
//

#include <iostream>
#include "snake.hpp"
#include "map.hpp"

int main(int argc, const char * argv[]) {
    Snake actor = *new Snake(3, Point(5, 5));
    Map map = *new Map(20);
    Apple apple = *new Apple();
//    while (!actor.isDead()) {
        map.clearMap();
        map.drawSnake(actor._positions);
        if (apple.isEat()) {
            apple.setApple(map.mapData, map.fieldLength());
        }
        map.drawApple(apple._position);
        map.drawMap(cout);
//    }
    
    return 0;
}
