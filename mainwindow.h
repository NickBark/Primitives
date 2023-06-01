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
    QVBoxLayout* hbl;
    Paint* paint;
    QGridLayout* gl;
    QPushButton* pbLine;
    QPushButton* pbCircle;
    QPushButton* pbRectangle;

  private slots:
    void slotPbLine();
    void slotPbCircle();
    void slotPbRectangle();
};
#endif // MAINWINDOW_H
