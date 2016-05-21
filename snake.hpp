
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
    int   _countApples;
public:
    vector<Point> _positions;
    
    Snake(int aLength, Point aPos): _isDead(false),
                                    _length(aLength),
                                    _positions(_length),
                                    _way(Point(1, 0)),
                                    _countApples(0)
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
    int   countApples();
    void  countApples(int aCount);
    void  move(Point aUserWay, char aMapElement, bool *appleIsEat);
};

#endif /* snake_hpp */
