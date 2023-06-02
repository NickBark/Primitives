#include "paint.h"

Paint::Paint(QFrame* parent) : QFrame{parent} {
    line = new TopLine();
    circle = new TopLine();
    flag = -1;
}

void Paint::paintEvent(QPaintEvent* event) {
    QPainter p(this);
    //    drawLine(&p);
    //    drawCircle(&p);
    //    drawRectangle(&p);

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
    pp->drawLine(line->setP1().getX(), line->setP1().getY(),
                 line->setP2().getX(), line->setP2().getY());
}

void Paint::drawCircle(QPainter* pp) {

    pp->drawEllipse(circle->setP1().getX(), circle->setP1().getY(),
                    circle->setP2().getX(), circle->setP2().getY());
}

void Paint::drawRectangle(QPainter* pp) {
    pp->drawRect(100, 150, 50, 100);
    ;
}

void Paint::drawTriangle(QPainter* pp) {
    ;
    ;
}
