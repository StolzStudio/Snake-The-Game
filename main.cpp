
#include <iostream>
#include "snake.hpp"
#include "map.hpp"

Snake actor = *new Snake(3, Point(5, 5));
Map   map   = *new Map(20);
Apple apple = *new Apple();

Point checkWayReverseValid(Point aUserWay) {
    Point reverseWay = Point(-aUserWay.x(), -aUserWay.y());
    
    if (reverseWay != actor.way()) {
        actor.way(aUserWay);
        return aUserWay;
    } else {
        return actor.way();
    }
}

Point getWayPoint(int aKey) {
    switch (aKey) {
        case 'w': return checkWayReverseValid(Point( 0, -1));
        case 'a': return checkWayReverseValid(Point(-1,  0));
        case 's': return checkWayReverseValid(Point( 0,  1));
        case 'd': return checkWayReverseValid(Point( 1,  0));
        default:  return actor.way();
    }
}

int main(int argc, const char * argv[]) {
    int q = -1;
    
    initscr();
    noecho();
    
    erase();
    
    while (!actor.isDead()) {
        q = -1;
        
        erase();
        
        map.clearMap();
        map.drawSnake(actor._positions);

        if (apple._isEat) {
            apple.setApple(map.mapData, map.fieldLength());
        }
        
        map.drawApple(apple._position);
        map.drawMap();
        
        q = getch();
        
        Point userWay    = getWayPoint(q);
        char  mapElement = map.findElement(actor._positions[actor.length() - 1], userWay);
        
        actor.move(userWay, mapElement, &apple._isEat);
    }
    
    endwin();
    
    return 0;
}
