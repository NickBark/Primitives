#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    Designer();
    Properties();
    Layouts();
    Connector();
}

MainWindow::~MainWindow() {}

void MainWindow::Designer() {
    qfCentral = new QFrame(this);

    vbl = new QVBoxLayout(this);

    paint = new Paint();

    hbl = new QHBoxLayout(this);

    pbLine = new QPushButton("Line", this);

    glLine = new QGridLayout(this);
    leLineX1 = new QLineEdit(this);
    leLineY1 = new QLineEdit(this);
    leLineX2 = new QLineEdit(this);
    leLineY2 = new QLineEdit(this);

    pbCircle = new QPushButton("Circle", this);

    glCircle = new QGridLayout(this);
    leCircleX = new QLineEdit(this);
    leCircleY = new QLineEdit(this);
    leCircleW = new QLineEdit(this);
    leCircleH = new QLineEdit(this);

    pbRectangle = new QPushButton("Rect", this);

    glRect = new QGridLayout(this);
    leRectX1 = new QLineEdit(this);
    leRectY1 = new QLineEdit(this);
    leRectX2 = new QLineEdit(this);
    leRectY2 = new QLineEdit(this);

    pbTri = new QPushButton("Trigon", this);

    glTri = new QGridLayout(this);
    leTriX1 = new QLineEdit(this);
    leTriY1 = new QLineEdit(this);
    leTriX2 = new QLineEdit(this);
    leTriY2 = new QLineEdit(this);
    leTriX3 = new QLineEdit(this);
    leTriY3 = new QLineEdit(this);

    pbClear = new QPushButton("Clear", this);
}

void MainWindow::Properties() {
    this->setFixedSize(740, 480);
    qfCentral->setStyleSheet("background-color: rgb(150, 150, 150)");
    paint->setFixedSize(722, 380);
    paint->setStyleSheet("background-color: rgb(255, 255, 255)");
    pbLine->setFixedSize(60, 40);
    pbCircle->setFixedSize(60, 40);
    pbRectangle->setFixedSize(60, 40);
    pbTri->setFixedSize(60, 40);
    pbClear->setFixedSize(60, 40);

    leLineX1->setPlaceholderText("X1");
    leLineY1->setPlaceholderText("Y1");
    leLineX2->setPlaceholderText("X2");
    leLineY2->setPlaceholderText("Y2");

    leCircleX->setPlaceholderText("X");
    leCircleY->setPlaceholderText("Y");
    leCircleW->setPlaceholderText("W");
    leCircleH->setPlaceholderText("H");

    leRectX1->setPlaceholderText("X1");
    leRectY1->setPlaceholderText("Y1");
    leRectX2->setPlaceholderText("X2");
    leRectY2->setPlaceholderText("Y2");

    leTriX1->setPlaceholderText("X1");
    leTriY1->setPlaceholderText("Y1");
    leTriX2->setPlaceholderText("X2");
    leTriY2->setPlaceholderText("Y2");
    leTriX3->setPlaceholderText("X3");
    leTriY3->setPlaceholderText("Y3");
}

void MainWindow::Layouts() {
    int rowSpan = 1;
    int columnSpan = 1;

    setCentralWidget(qfCentral);
    qfCentral->setLayout(vbl);
    vbl->addWidget(paint);
    vbl->addLayout(hbl);
    hbl->addWidget(pbLine, 0);
    hbl->addLayout(glLine, 1);
    glLine->addWidget(leLineX1, 0, 0, rowSpan, columnSpan);
    glLine->addWidget(leLineY1, 0, 1, rowSpan, columnSpan);
    glLine->addWidget(leLineX2, 1, 0, rowSpan, columnSpan);
    glLine->addWidget(leLineY2, 1, 1, rowSpan, columnSpan);
    hbl->addWidget(pbCircle, 2);
    hbl->addLayout(glCircle, 3);
    glCircle->addWidget(leCircleX, 0, 0, rowSpan, columnSpan);
    glCircle->addWidget(leCircleY, 0, 1, rowSpan, columnSpan);
    glCircle->addWidget(leCircleW, 1, 0, rowSpan, columnSpan);
    glCircle->addWidget(leCircleH, 1, 1, rowSpan, columnSpan);
    hbl->addWidget(pbRectangle, 4);
    hbl->addLayout(glRect, 5);
    glRect->addWidget(leRectX1, 0, 0, rowSpan, columnSpan);
    glRect->addWidget(leRectY1, 0, 1, rowSpan, columnSpan);
    glRect->addWidget(leRectX2, 1, 0, rowSpan, columnSpan);
    glRect->addWidget(leRectY2, 1, 1, rowSpan, columnSpan);
    hbl->addWidget(pbTri, 6);
    hbl->addLayout(glTri, 7);
    glTri->addWidget(leTriX1, 0, 0, rowSpan, columnSpan);
    glTri->addWidget(leTriY1, 1, 0, rowSpan, columnSpan);
    glTri->addWidget(leTriX2, 0, 1, rowSpan, columnSpan);
    glTri->addWidget(leTriY2, 1, 1, rowSpan, columnSpan);
    glTri->addWidget(leTriX3, 0, 2, rowSpan, columnSpan);
    glTri->addWidget(leTriY3, 1, 2, rowSpan, columnSpan);
    hbl->addWidget(pbClear, 8);
}

void MainWindow::Connector() {
    connect(pbLine, SIGNAL(clicked()), this, SLOT(slotPbLine()));
    connect(pbCircle, SIGNAL(clicked()), this, SLOT(slotPbCircle()));
    connect(pbRectangle, SIGNAL(clicked()), this, SLOT(slotPbRectangle()));
    connect(pbTri, SIGNAL(clicked()), this, SLOT(slotPbTriangle()));
    connect(pbClear, SIGNAL(clicked()), this, SLOT(slotPbClear()));
}

void MainWindow::slotPbLine() {
    qDebug() << "Line";
    paint->flag = LINE;
    double x = 0;
    TopLine tl;

    if (leLineX1->text().isEmpty()) {
        x = numeric_limits<double>::quiet_NaN();
    } else {
        x = leLineX1->text().toDouble();
        tl.setP1().setX(x);
    }
    if (leLineY1->text().isEmpty()) {
        x = numeric_limits<double>::quiet_NaN();
    } else {
        x = leLineY1->text().toDouble();
        tl.setP1().setY(x);
    }
    if (leLineX2->text().isEmpty()) {
        x = numeric_limits<double>::quiet_NaN();
    } else {
        x = leLineX2->text().toDouble();
        tl.setP2().setX(x);
    }
    if (leLineY2->text().isEmpty()) {
        x = numeric_limits<double>::quiet_NaN();
    } else {
        x = leLineY2->text().toDouble();
        tl.setP2().setY(x);
    }

    paint->vLine.push_back(tl);

    paint->update();
}

void MainWindow::slotPbCircle() {
    qDebug() << "Circle";
    paint->flag = CIRCLE;
    double x = 0;
    TopCircle tc;

    if (leCircleX->text().isEmpty()) {
        x = numeric_limits<double>::quiet_NaN();
    } else {
        x = leCircleX->text().toDouble();
        tc.setP1().setX(x);
        //        paint->circle->setP1().setX(x);
    }
    if (leCircleY->text().isEmpty()) {
        x = numeric_limits<double>::quiet_NaN();
    } else {
        x = leCircleY->text().toDouble();
        tc.setP1().setY(x);
        //        paint->circle->setP1().setY(x);
    }
    if (leCircleW->text().isEmpty()) {
        x = numeric_limits<double>::quiet_NaN();
    } else {
        x = leCircleW->text().toDouble();
        tc.setP2().setX(x);
        //        paint->circle->setP2().setX(x);
    }
    if (leCircleH->text().isEmpty()) {
        x = numeric_limits<double>::quiet_NaN();
    } else {
        x = leCircleH->text().toDouble();
        tc.setP2().setY(x);
        //        paint->circle->setP2().setY(x);
    }

    paint->vCirc.push_back(tc);

    paint->update();
}

void MainWindow::slotPbRectangle() {
    qDebug() << "Rect";
    paint->flag = RECT;
    double x = 0;
    TopRectangle tr;

    if (leRectX1->text().isEmpty()) {
        x = numeric_limits<double>::quiet_NaN();
    } else {
        x = leRectX1->text().toDouble();
        tr.setP1().setX(x);
    }
    if (leRectY1->text().isEmpty()) {
        x = numeric_limits<double>::quiet_NaN();
    } else {
        x = leRectY1->text().toDouble();
        tr.setP1().setY(x);
    }
    if (leRectX2->text().isEmpty()) {
        x = numeric_limits<double>::quiet_NaN();
    } else {
        x = leRectX2->text().toDouble();
        tr.setP2().setX(x);
    }
    if (leRectY2->text().isEmpty()) {
        x = numeric_limits<double>::quiet_NaN();
    } else {
        x = leRectY2->text().toDouble();
        tr.setP2().setY(x);
    }

    paint->vRect.push_back(tr);

    paint->update();
}

void MainWindow::slotPbTriangle() {
    qDebug() << "Tri";
    paint->flag = TRI;
    double x = 0;
    TopTriangle tt;

    if (leTriX1->text().isEmpty()) {
        x = numeric_limits<double>::quiet_NaN();
    } else {
        x = leTriX1->text().toDouble();
        tt.setP1().setX(x);
    }
    if (leTriY1->text().isEmpty()) {
        x = numeric_limits<double>::quiet_NaN();
    } else {
        x = leTriY1->text().toDouble();
        tt.setP1().setY(x);
    }
    if (leTriX2->text().isEmpty()) {
        x = numeric_limits<double>::quiet_NaN();
    } else {
        x = leTriX2->text().toDouble();
        tt.setP2().setX(x);
    }
    if (leTriY2->text().isEmpty()) {
        x = numeric_limits<double>::quiet_NaN();
    } else {
        x = leTriY2->text().toDouble();
        tt.setP2().setY(x);
    }
    if (leTriX3->text().isEmpty()) {
        x = numeric_limits<double>::quiet_NaN();
    } else {
        x = leTriX3->text().toDouble();
        tt.setP3().setX(x);
    }
    if (leTriY3->text().isEmpty()) {
        x = numeric_limits<double>::quiet_NaN();
    } else {
        x = leTriY3->text().toDouble();
        tt.setP3().setY(x);
    }

    paint->vTri.push_back(tt);

    paint->update();
}

void MainWindow::slotPbClear() {
    paint->vCirc.clear();
    paint->vRect.clear();
    paint->vLine.clear();
    paint->vTri.clear();

    paint->update();
}
