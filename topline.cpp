#include "topline.h"

TopLine::TopLine() {}

void TopLine::setLine(Point p1, Point p2) {
    this->p1.setX(p1.getX());
    this->p1.setY(p1.getY());
    this->p2.setX(p2.getX());
    this->p2.setY(p2.getY());
}
