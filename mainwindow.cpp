#include <QtWidgets>

#include "mainwindow.h"

MainWindow::MainWindow()
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    infoLabel = new QLabel(tr("<b>Welcome to Mission Control</b>"));
    infoLabel->setAlignment(Qt::AlignCenter);
    infoLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    infoLabel->setStyleSheet("QLabel { color : white; font-size: 36px;}");

    image = new QPixmap("resources/Main.png");

    imageLabel = new QLabel();
    imageLabel->setPixmap(image->scaled(infoLabel->width(), infoLabel->height(), Qt::KeepAspectRatio));
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    startNew = new QPushButton(tr("Start Flight"));
    startNew->setFixedSize(400, 200);

    quit = new QPushButton(tr("Quit"));
    quit->setFixedSize(400,200);

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(imageLabel, 0, 0, 1, 2);
    layout->addWidget(infoLabel, 0, 0, 1, 2);
    layout->addWidget(startNew, 1,0);
    layout->addWidget(quit, 1,1);
    widget->setLayout(layout);

    createActions();
    createMenus();

    setWindowTitle(tr("Mission Control"));
    resize(800, 600);
}

void MainWindow::on_Start(){
    lw->show();
    this->hide();
    lw->turnOnClock();
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About Menu"),
            tr("The <b>Menu</b> example shows how to create "
               "menu-bar menus and context menus."));
}

void MainWindow::createActions()
{
    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, &QAction::triggered, this, &MainWindow::about);

    startAct = new QAction(tr("&Start"), this);
    startAct->setStatusTip(tr("Start a new flight"));
    connect(startAct, &QAction::triggered, this, &MainWindow::on_Start);

    connect(quit, SIGNAL (clicked()), QApplication::instance(), SLOT (quit()));

    connect(startNew, SIGNAL (clicked()), this, SLOT (on_Start()));
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(startAct);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
}
