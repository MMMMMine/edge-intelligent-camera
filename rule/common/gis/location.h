#pragma once

class Location
{
private:
    double x, y;
    double maxX, maxY;
    double width, height;
    double middleX, middleY, yXRatio;
public:
    Location(double x, double y);
    Location(double x, double y, double maxX, double maxY);
    double getX() { return x; }
    double getMaxX() { return maxX; }
    double getY() { return y; }
    double getMaxY() { return maxY; }
    double getWidth() { return width; }
    double getHeight() { return height; }
    double getMiddleX() { return getX() + (getWidth() / 2); }
    double getMiddleY() { return getY() + (getHeight() / 2); }
    int setX(double x) {
        this->x = x;
        return 0;

    }

    int setMaxX(double maxX) {
        this->maxX = maxX;
        return 0;

    }
    int setY(double y) {
        this->y = y;
        return 0;

    }
    int setMaxY(double maxY) {
        this->maxY = maxY;
        return 0;

    }

};
Location::Location(double x, double y)
{
    this->x = x;
    this->y = y;
}

Location::Location(double x, double y, double maxX, double maxY)
{
    Location(x, y);
    this->maxX = maxX;
    this->maxY = maxY;
    this->width = maxX - x;
    this->height = maxY - y;
}