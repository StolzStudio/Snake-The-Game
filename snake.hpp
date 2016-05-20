
#ifndef snake_hpp
#define snake_hpp

#include <stdio.h>
#include <vector>
#include "map.hpp"

using namespace std;

class Snake {
protected:
    int  _length;
    bool _isDead;
    Point _way;
public:
    vector<Point> _positions;
    
    Snake(int aLength, Point aPos): _isDead(false),
                                    _length(aLength),
                                    _positions(_length),
                                    _way(Point(1, 0))
    {
        for (int i = 0; i < _length; i++) {
            _positions[i] = Point((aPos.x() - _length + 1) + i, aPos.y());
        }
    };
    
    ~Snake() {};
    
    int   length();
    bool  isDead();
    Point way();
    void  way(Point aUserWay);
    void  move(Point aUserWay, char aMapElement, bool *appleIsEat);
};

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

#endif /* snake_hpp */
