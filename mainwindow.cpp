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
}

void MainWindow::Properties() {
    this->setFixedSize(640, 480);
    qfCentral->setStyleSheet("background-color: rgb(150, 150, 150)");
    paint->setFixedSize(620, 380);
    paint->setStyleSheet("background-color: rgb(255, 255, 255)");
    pbLine->setFixedSize(60, 40);
    pbCircle->setFixedSize(60, 40);
    pbRectangle->setFixedSize(60, 40);

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
}

void MainWindow::Connector() {
    connect(pbLine, SIGNAL(clicked()), this, SLOT(slotPbLine()));
    connect(pbCircle, SIGNAL(clicked()), this, SLOT(slotPbCircle()));
    connect(pbRectangle, SIGNAL(clicked()), this, SLOT(slotPbRectangle()));
}

void MainWindow::slotPbLine() {
    qDebug() << "Line";
    paint->flag = LINE;
    double x = 0;

    if (leLineX1->text().isEmpty()) {
        x = numeric_limits<double>::quiet_NaN();
    } else {
        x = leLineX1->text().toDouble();
        paint->line->setP1().setX(x);
    }
    if (leLineY1->text().isEmpty()) {
        x = numeric_limits<double>::quiet_NaN();
    } else {
        x = leLineY1->text().toDouble();
        paint->line->setP1().setY(x);
    }
    if (leLineX2->text().isEmpty()) {
        x = numeric_limits<double>::quiet_NaN();
    } else {
        x = leLineX2->text().toDouble();
        paint->line->setP2().setX(x);
    }
    if (leLineY2->text().isEmpty()) {
        x = numeric_limits<double>::quiet_NaN();
    } else {
        x = leLineY2->text().toDouble();
        paint->line->setP2().setY(x);
    }

    paint->update();
}

void MainWindow::slotPbCircle() {
    qDebug() << "Circle";
    paint->flag = CIRCLE;
    double x = 0;

    if (leCircleX->text().isEmpty()) {
        x = numeric_limits<double>::quiet_NaN();
    } else {
        x = leCircleX->text().toDouble();
        paint->circle->setP1().setX(x);
    }
    if (leCircleY->text().isEmpty()) {
        x = numeric_limits<double>::quiet_NaN();
    } else {
        x = leCircleY->text().toDouble();
        paint->circle->setP1().setY(x);
    }
    if (leCircleW->text().isEmpty()) {
        x = numeric_limits<double>::quiet_NaN();
    } else {
        x = leCircleW->text().toDouble();
        paint->circle->setP2().setX(x);
    }
    if (leCircleH->text().isEmpty()) {
        x = numeric_limits<double>::quiet_NaN();
    } else {
        x = leCircleH->text().toDouble();
        paint->circle->setP2().setY(x);
    }

    paint->update();
}

void MainWindow::slotPbRectangle() {
    qDebug() << "Rect";
    paint->flag = RECT;
    paint->update();
}
