#include "paint.h"

Paint::Paint(QFrame* parent) : QFrame{parent} { flag = -1; }

void Paint::paintEvent(QPaintEvent* event) {
    QPainter p(this);

    drawLine(&p);
    drawCircle(&p);
    drawRectangle(&p);
    drawTriangle(&p);

    //    if (flag == LINE) {
    //        qDebug() << "draw Line";
    //        drawLine(&p);
    //        flag = -1;
    //    } else if (flag == CIRCLE) {
    //        qDebug() << "draw Circle";
    //        drawCircle(&p);
    //        flag = -1;
    //    } else if (flag == RECT) {
    //        qDebug() << "draw Rect";
    //        drawRectangle(&p);
    //        flag = -1;
    //    } else if (flag == TRI) {
    //        qDebug() << "draw Triangle";
    //        drawTriangle(&p);
    //        flag = -1;
    //    }
}

void Paint::drawLine(QPainter* pp) {
    for (size_t i = 0; i < vLine.size(); i++) {
        pp->drawLine(vLine.at(i).setP1().getX(), vLine.at(i).setP1().getY(),
                     vLine.at(i).setP2().getX(), vLine.at(i).setP2().getY());
    }
}

void Paint::drawCircle(QPainter* pp) {
    for (size_t i = 0; i < vCirc.size(); i++) {
        pp->drawEllipse(vCirc.at(i).setP1().getX(), vCirc.at(i).setP1().getY(),
                        vCirc.at(i).setP2().getX(), vCirc.at(i).setP2().getY());
    }
}

void Paint::drawRectangle(QPainter* pp) {
    for (size_t i = 0; i < vRect.size(); i++) {
        pp->drawRect(vRect.at(i).setP1().getX(), vRect.at(i).setP1().getY(),
                     vRect.at(i).setP2().getX(), vRect.at(i).setP2().getY());
    }
}

void Paint::drawTriangle(QPainter* pp) {
    for (size_t i = 0; i < vTri.size(); i++) {
        pp->drawLine(vTri.at(i).setP1().getX(), vTri.at(i).setP1().getY(),
                     vTri.at(i).setP2().getX(), vTri.at(i).setP2().getY());
        pp->drawLine(vTri.at(i).setP2().getX(), vTri.at(i).setP2().getY(),
                     vTri.at(i).setP3().getX(), vTri.at(i).setP3().getY());
        pp->drawLine(vTri.at(i).setP3().getX(), vTri.at(i).setP3().getY(),
                     vTri.at(i).setP1().getX(), vTri.at(i).setP1().getY());
    }
}
