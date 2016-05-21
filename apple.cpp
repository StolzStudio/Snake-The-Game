
#include "apple.hpp"


void Apple::setApple(char **aMap, int aLength) {
    this->_changePos = false;
    int x = 0;
    int y = 0;
    
    while (!this->_changePos) {
        x = random() % (aLength - 1);
        y = random() % (aLength - 1);
        
        if (aMap[y][x] != CHAR_BLOCK) {
            this->_position = Point(x, y);
            this->_changePos = true;
        }
    }
    this->_isEat = false;
}
