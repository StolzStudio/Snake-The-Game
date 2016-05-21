
#ifndef point_hpp
#define point_hpp

#include <stdio.h>


class Point {
protected:
    int _x;
    int _y;
public:
    Point(): _x(1),
    _y(1)
    {};
    
    Point(int aX, int aY): _x(aX),
    _y(aY)
    {};
    
    ~Point() {};
    
    friend const Point operator+ (const Point& aLeft, const Point& aRight);
    friend bool        operator==(const Point& aLeft, const Point& aRight);
    friend bool        operator!=(const Point& aLeft, const Point& aRight);
    
    Point& operator=(const Point& aRight) {
        this->_x = aRight._x;
        this->_y = aRight._y;
        return *this;
    }
    
    int  x();
    void x(int aX);
    int  y();
    void y(int aY);
};


#endif /* point_hpp */
