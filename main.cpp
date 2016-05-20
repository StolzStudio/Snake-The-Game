
#include <iostream>
#include "snake.hpp"
#include "map.hpp"


Point getWayPoint(int aKey) {
    switch (aKey) {
        case 'w': return Point(0, -1);
        case 'a': return Point(-1, 0);
        case 's': return Point(0, 1);
        case 'd': return Point(1, 0);
        default: return Point(0, 0);
    }
}

int main(int argc, const char * argv[]) {
    int q = -1;
    Snake actor = *new Snake(3, Point(5, 5));
    Map map = *new Map(20);
    Apple apple = *new Apple();
    
    initscr();
    noecho();
    
    erase();
    
    map.clearMap();
    map.drawSnake(actor._positions);
    
    while (!actor.isDead()) {
        q = -1;
        erase();
        
        map.clearMap();
        map.drawSnake(actor._positions);

        if (apple.isEat()) {
            apple.setApple(map.mapData, map.fieldLength());
        }
        map.drawApple(apple._position);
        map.drawMap();
        q = getch();
        actor.move(getWayPoint(q));
        cout << actor._positions[actor.length()].x() << "|" << actor._positions[actor.length()].y();
    }
    
    endwin();
    return 0;
}
