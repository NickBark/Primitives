#include "mainwindow.h"
#include "point.h"
#include <QApplication>

int main(int argc, char* argv[]) {
    //    TopLine line;

    //    line.setLine(Point(2, 3), Point(4, 5));

    //    cout << line.setP1().getX() << endl;
    //    p.setX(21);
    //    p.setY(22);
    //    cout << p.getX() << endl;
    //    cout << p.getY() << endl;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    return 0;
}
