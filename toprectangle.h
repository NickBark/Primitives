#ifndef TOPRECTANGLE_H
#define TOPRECTANGLE_H

#include "point.h"

class TopRectangle {
  public:
    TopRectangle();

    Point& setP1() { return p1; }
    Point& setP2() { return p2; }

  private:
    Point p1;
    Point p2;
};

#endif // TOPRECTANGLE_H
