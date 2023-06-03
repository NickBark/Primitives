#ifndef TOPTRIANGLE_H
#define TOPTRIANGLE_H

#include "point.h"

class TopTriangle {
  public:
    TopTriangle();

    Point& setP1() { return p1; }
    Point& setP2() { return p2; }
    Point& setP3() { return p3; }

  private:
    Point p1;
    Point p2;
    Point p3;
};

#endif // TOPTRIANGLE_H
