
#include <iostream>
#include "snake.hpp"
#include "map.hpp"

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
        Point way = map.getWay(q);
        actor.move(way, map.getElement(way, actor._positions[actor.length()]));
    }
    
    endwin();
    return 0;
}
