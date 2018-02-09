#include <QtWidgets>

#include "flightwindow.h"

FlightWindow::FlightWindow()
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    infoLabel = new QLabel(tr("<b>Welcome to Mission Control</b>"));
    infoLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    infoLabel->setAlignment(Qt::AlignCenter);
    infoLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    latitudeInfo_1 = new QLabel(tr("Latitude: 0"));
    latitudeInfo_1->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    latitudeInfo_1->setFixedSize(100, 40);
    latitudeInfo_1->setAlignment(Qt::AlignCenter);

    longitudeInfo_1 = new QLabel(tr("Longitude: 0"));
    longitudeInfo_1->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    longitudeInfo_1->setFixedSize(100, 40);
    longitudeInfo_1->setAlignment(Qt::AlignCenter);

    altitudeInfo_1 = new QLabel(tr("Altitude: 0"));
    altitudeInfo_1->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    altitudeInfo_1->setFixedSize(100, 40);
    altitudeInfo_1->setAlignment(Qt::AlignCenter);

    velocityInfo_1 = new QLabel(tr("Velocity: 0"));
    velocityInfo_1->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    velocityInfo_1->setFixedSize(100, 40);
    velocityInfo_1->setAlignment(Qt::AlignCenter);

    flightInfo_1 = new QLabel(tr("Velocity: 0"));
    flightInfo_1->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    flightInfo_1->setFixedSize(100, 40);
    flightInfo_1->setAlignment(Qt::AlignCenter);

    batteryInfo_1 = new QLabel(tr("Velocity: 0"));
    batteryInfo_1->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    batteryInfo_1->setFixedSize(100, 40);
    batteryInfo_1->setAlignment(Qt::AlignCenter);

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(infoLabel, 0, 0, 1, 3);
    layout->addWidget(latitudeInfo_1, 1, 0);
    layout->addWidget(longitudeInfo_1, 2, 0);
    layout->addWidget(altitudeInfo_1, 1, 1);
    layout->addWidget(velocityInfo_1, 2, 1);
    layout->addWidget(flightInfo_1, 1, 2);
    layout->addWidget(batteryInfo_1, 2, 2);
    widget->setLayout(layout);

    createActions();
    createMenus();

    setWindowTitle(tr("Mission Control"));
    resize(800, 600);
}

void FlightWindow::newFile()
{
    infoLabel->setText(tr("Invoked <b>File|New</b>"));
}

void FlightWindow::open()
{
    infoLabel->setText(tr("Invoked <b>File|Open</b>"));
}

void FlightWindow::save()
{
    infoLabel->setText(tr("Invoked <b>File|Save</b>"));
}

void FlightWindow::about()
{
    QMessageBox::about(this, tr("About Menu"),
            tr("The <b>Menu</b> example shows how to create "
               "menu-bar menus and context menus."));
}

void FlightWindow::createActions()
{
    newAct = new QAction(tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, &QAction::triggered, this, &FlightWindow::newFile);

    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, &QAction::triggered, this, &FlightWindow::open);

    saveAct = new QAction(tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the document to disk"));
    connect(saveAct, &QAction::triggered, this, &FlightWindow::save);

    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, &QAction::triggered, this, &FlightWindow::about);
}

void FlightWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
}
