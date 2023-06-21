#include <iostream>
#include<cmath>
using namespace std;

/*1.jude rectangle && calarea
  2.draw vec
  3.move vec
*/

class quadrangle
{
public:
    class vertex
    {
    public:
        int x;
        int y;
        vertex(int i = 0, int j = 0) : x(i), y(j) {}
    };
    // constructor
    quadrangle(const vertex &v1, const vertex &v2, const vertex &v3, const vertex &v4);
    quadrangle(const vertex &lowerleft, const vertex &upperright);
    // function-outside
    void draw();
    void move(const vertex &v1);

private:
    string name;
    vertex vec[4];
    bool isrectangle;
    int area;
    // function-inner
    bool judgeRectangle() const;
    int calarea() const; // calculate the area
    double distance(const vertex &o,const vertex &v1) const;//calculate move distance
};

quadrangle::quadrangle(const vertex &v1, const vertex &v2, const vertex &v3, const vertex &v4)
{
    vec[0] = v1;
    vec[1] = v2;
    vec[2] = v3;
    vec[3] = v4;
    isrectangle = judgeRectangle();
}

quadrangle::quadrangle(const vertex &lowerleft, const vertex &upperright)
{
    vec[0] = lowerleft;
    vec[1] = vertex(upperright.x, lowerleft.y);
    vec[2] = upperright;
    vec[3] = vertex(lowerleft.x, upperright.y);
    isrectangle = 1;
}

bool quadrangle::judgeRectangle() const
{
    bool dx = 0, dy = 0;
    for (int i = 1; i < 4; i++)
    {
        if ((vec[0].x - vec[i].x) == 0 && (vec[0].y - vec[i].y) != 0)
        {
            dx = 1;
        }
        else if ((vec[0].x - vec[i].x) != 0 && (vec[0].y - vec[i].y) == 0)
        {
            dy = 1;
        }
    }

    return (dx * dy);
}

int quadrangle::calarea() const
{
    int xedge = 10, yedge = 10;
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if (vec[i].x == vec[j].x)
            {
                yedge = vec[i].y - vec[j].y;
                if (yedge < 0)
                {
                    yedge *= -1;
                }
            }

            if (vec[i].y == vec[j].y)
            {
                xedge = vec[i].x - vec[j].x;
                if (xedge < 0)
                {
                    xedge *= -1;
                }
            }
        }
    }

    return (xedge * yedge);
}

double quadrangle::distance(const vertex &o,const vertex &v1) const{
    int x=o.x-v1.x;
    int y=o.y-v1.y;
    x<0?(x*-1):x;
    y<0?(y*-1):y;

    return (sqrt(x*x+y*y));
}

void quadrangle::draw()
{
    for (int i = 0; i < 4; i++)
    {
        cout << "v"<<(i+1)<<": (" << vec[i].x << "," << vec[i].y << ") ";
    }

    if (isrectangle)
    {
        cout << "area: " << calarea() << endl;
    }
    else
    {
        cout << endl;
    }
}

void quadrangle::move(const vertex &v1){
    int dx=v1.x-vec[0].x;
    int dy=v1.y-vec[0].y;
    cout<<"Distance: "<<distance(vec[0],v1)<<endl;
    //move posion
    for(int i=1;i<4;i++){
        vec[i].x+=dx;
        vec[i].y+=dy;
    }
    vec[0]=v1;
}
