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

    hbl = new QVBoxLayout(this);

    paint = new Paint();

    gl = new QGridLayout(this);

    pbLine = new QPushButton("Line", this);
    pbCircle = new QPushButton("Circle", this);
    pbRectangle = new QPushButton("Rect", this);
}

void MainWindow::Properties() {
    this->setFixedSize(640, 480);
    qfCentral->setStyleSheet("background-color: rgb(150, 150, 150)");
    paint->setFixedSize(620, 380);
    paint->setStyleSheet("background-color: rgb(255, 255, 255)");
    pbLine->setFixedSize(60, 40);
    pbCircle->setFixedSize(60, 40);
    pbRectangle->setFixedSize(60, 40);
}

void MainWindow::Layouts() {
    int rowSpan = 1;
    int columnSpan = 1;

    setCentralWidget(qfCentral);
    qfCentral->setLayout(hbl);
    hbl->addWidget(paint);
    hbl->addLayout(gl);
    gl->addWidget(pbLine, 0, 1, rowSpan, columnSpan);
    gl->addWidget(pbCircle, 0, 2, rowSpan, columnSpan);
    gl->addWidget(pbRectangle, 0, 3, rowSpan, columnSpan);
}

void MainWindow::Connector() {
    connect(pbLine, SIGNAL(clicked()), this, SLOT(slotPbLine()));
    connect(pbCircle, SIGNAL(clicked()), this, SLOT(slotPbCircle()));
    connect(pbRectangle, SIGNAL(clicked()), this, SLOT(slotPbRectangle()));
}

void MainWindow::slotPbLine() {
    qDebug() << "Line";
    paint->flag = LINE;
    paint->update();
}

void MainWindow::slotPbCircle() {
    qDebug() << "Circle";
    paint->flag = CIRCLE;
    paint->update();
}

void MainWindow::slotPbRectangle() {
    qDebug() << "Rect";
    paint->flag = RECT;
    paint->update();
}
