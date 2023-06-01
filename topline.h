#ifndef TOPLINE_H
#define TOPLINE_H

#include "point.h"

class TopLine {
  public:
    TopLine();

    void setLine(Point p1, Point p2);

    Point& setP1() { return p1; }
    Point& setP2() { return p2; }

  private:
    Point p1;
    Point p2;
};

#endif // TOPLINE_H
