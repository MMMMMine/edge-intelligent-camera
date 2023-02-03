#pragma once
#include <math.h>

class Point
{
public:
    double x, y;
    bool Isconcave;
public:
    Point();
    ~Point();

    Point(double x, double y);
    double getX() { return x; }
    double getY() { return y; }
    Point(const Point& pt);
};

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
    Isconcave = false;
}

Point::Point(const Point& pt) { x = pt.x; y = pt.y; Isconcave = pt.Isconcave; }
Point::Point() { x = 0; y = 0; Isconcave = false; }