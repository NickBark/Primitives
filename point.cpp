#include "point.h"

double Point::getX() const { return x; }

double Point::getY() const { return y; }

void Point::setX(double x) { this->x = x; }

void Point::setY(double y) { this->y = y; }

void Point::setPoint(Point& p, double x, double y) {
    p.setX(x);
    p.setY(y);
}
