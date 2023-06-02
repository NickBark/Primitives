#ifndef PAINT_H
#define PAINT_H

#include "dependencies.h"
#include "topline.h"
#include <QFrame>

class Paint : public QFrame {
    Q_OBJECT
  public:
    explicit Paint(QFrame* parent = nullptr);

    int flag;

    // Line
    TopLine* line;
    TopLine* circle;

  protected:
    void paintEvent(QPaintEvent* event);
    void drawLine(QPainter* pp);
    void drawCircle(QPainter* pp);
    void drawRectangle(QPainter* pp);
    void drawTriangle(QPainter* pp);

  signals:
};

#endif // PAINT_H
