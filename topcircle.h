#ifndef TOPCIRCLE_H
#define TOPCIRCLE_H

#include "point.h"

class TopCircle {
  public:
    TopCircle();

    Point& setP1() { return p1; }
    Point& setP2() { return p2; }

  private:
    Point p1;
    Point p2; // ширина и высота
};

#endif // TOPCIRCLE_H
