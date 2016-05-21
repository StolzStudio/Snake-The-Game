
#ifndef apple_hpp
#define apple_hpp

#include <stdio.h>
#include <random>
#include "map.hpp"

class Apple {
private:
    bool _changePos;
public:
    Point _position;
    bool  _isEat;
    
    Apple(): _isEat(true) {};
    ~Apple() {};
    
    void setApple(char **aMap, int aLength);
    
};

#endif /* apple_hpp */
