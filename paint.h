#ifndef PAINT_H
#define PAINT_H

#include "dependencies.h"
#include "topcircle.h"
#include "topline.h"
#include "toprectangle.h"
#include "toptriangle.h"

class Paint : public QFrame {
    Q_OBJECT
  public:
    explicit Paint(QFrame* parent = nullptr);

    int flag;

    vector<TopCircle> vCirc;
    vector<TopLine> vLine;
    vector<TopRectangle> vRect;
    vector<TopTriangle> vTri;

    //    TopLine* line;
    //    TopCircle* circle;
    //    TopRectangle* rect;
    //    TopTriangle* tri;

  protected:
    void paintEvent(QPaintEvent* event);
    void drawLine(QPainter* pp);
    void drawCircle(QPainter* pp);
    void drawRectangle(QPainter* pp);
    void drawTriangle(QPainter* pp);

  signals:
};

#endif // PAINT_H
