#ifndef POINT2D_H
#define POINT2D_H

class Point2D
{
private:
    int *x;
    int *y;

public:
    Point2D(int user_x, int user_y):x(new int(user_x)),y(new int(user_y)){}
    Point2D& operator=(const Point2D& other);
    void display();
};

Point2D& Point2D::operator=(const Point2D& other){
    x=other.x;
    y=other.y;

    return *this;
}

void Point2D::display()
{
    std::cout << "x: " << *x << ",y: " << *y;
}

#endif