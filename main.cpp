
#include <iostream>
#include <unistd.h>
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
    timeout(0);
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
        printw("Your score: %d\n", actor.countApples());
        
        q = getch();
        
        Point userWay    = getWayPoint(q);
        char  mapElement = map.findElement(actor._positions[actor.length() - 1], userWay);
        
        actor.move(userWay, mapElement, &apple._isEat);
        usleep(80000);
    }
    
    erase();
    timeout(80000);
    printw("YOU LOOSE!\nYour score: %d\n\n\n", actor.countApples());
    getch();

    endwin();
    
    return 0;
}
