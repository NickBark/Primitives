#include "paint.h"

Paint::Paint(QFrame* parent) : QFrame{parent} { flag = -1; }

void Paint::paintEvent(QPaintEvent* event) {
    QPainter p(this);
    if (flag == LINE) {
        drawLine(&p);
        flag = -1;
    } else if (flag == CIRCLE) {
        drawCircle(&p);
        flag = -1;
    } else if (flag == RECT) {
        drawRectangle(&p);
        flag = -1;
    }
}

void Paint::drawLine(QPainter* pp) {
    TopLine line;
    line.setLine(Point(50, 50), Point(100, 100));
    pp->drawLine(line.setP1().getX(), line.setP1().getY(), line.setP2().getX(),
                 line.setP2().getY());
}

void Paint::drawCircle(QPainter* pp) {
    pp->drawEllipse(100, 100, 50, 50);
    ;
}

void Paint::drawRectangle(QPainter* pp) { pp->drawRect(100, 150, 50, 100); }
