
#ifndef snake_hpp
#define snake_hpp

#include <stdio.h>
#include <vector>
#include "map.hpp"

using namespace std;

class Snake {
protected:
    int _length;
    bool _isDead;
public:
    vector<Point> _positions;
    
    Snake(int aLength, Point aPos): _isDead(false), _length(aLength), _positions(_length) {
        for (int i = 0; i < _length; i++) {
            _positions[i] = Point((aPos.x() - _length + 1) + i, aPos.y());
        }
    };
    
    ~Snake() {};
    
    int length();
    bool isDead();
    void move(Point aKey, char aMapElement);
};

class Apple {
protected:
    bool _isEat;
public:
    Point _position;
    
    Apple(): _isEat(true) {};
    ~Apple() {};
    
    void setApple(char **aMap, int aLength);
    bool isEat();
};
#endif /* snake_hpp */
