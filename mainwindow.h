#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dependencies.h"
#include "paint.h"
#include "topline.h"
#include <QMainWindow>

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    void Designer();
    void Properties();
    void Layouts();
    void Connector();

    QFrame* qfCentral;
    QVBoxLayout* vbl;
    Paint* paint;
    QHBoxLayout* hbl;
    QPushButton* pbLine;
    QGridLayout* glLine;
    QLineEdit* leLineX1;
    QLineEdit* leLineY1;
    QLineEdit* leLineX2;
    QLineEdit* leLineY2;
    QPushButton* pbCircle;
    QGridLayout* glCircle;
    QLineEdit* leCircleX;
    QLineEdit* leCircleY;
    QLineEdit* leCircleW;
    QLineEdit* leCircleH;
    QPushButton* pbRectangle;
    QGridLayout* glRect;
    QLineEdit* leRectX1;
    QLineEdit* leRectY1;
    QLineEdit* leRectX2;
    QLineEdit* leRectY2;
    QPushButton* pbTri;
    QGridLayout* glTri;
    QLineEdit* leTriX1;
    QLineEdit* leTriY1;
    QLineEdit* leTriX2;
    QLineEdit* leTriY2;
    QLineEdit* leTriX3;
    QLineEdit* leTriY3;
    QPushButton* pbClear;

  private slots:
    void slotPbLine();
    void slotPbCircle();
    void slotPbRectangle();
    void slotPbTriangle();
    void slotPbClear();
};
#endif // MAINWINDOW_H
