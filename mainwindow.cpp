#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    //Set size
    setFixedSize(800,600);

    //Create Buttons
    butt = new QPushButton("Click", this);
    butt->setGeometry(-7, 7, 100, 40);

    connect(butt, SIGNAL (clicked()), QApplication::instance(), SLOT (quit()));
}
