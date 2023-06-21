#ifndef POINT4D_H
#define POINT4D_H

#include "Point2D.h"

class Point4D : public Point2D
{
private:
    int *z;
    int *t;

public:
    Point4D(int user_x, int user_y, int user_z, int user_t);
    Point4D& operator=(const Point2D& other);
    void display();
};

Point4D::Point4D(int user_x, int user_y, int user_z, int user_t): Point2D(user_x, user_y)
{
    z = new int(user_z);
    t = new int(user_t);
}

Point4D& Point4D::operator=(const Point2D& other){
    Point2D::operator=(other);
    int x=0;
    z=&x;
    t=&x;

    return *this;
}

void Point4D::display(){
    Point2D::display();
    std::cout<<",z: "<<*z<<",t: "<<*t;
}
#endif