#include <QtWidgets>

#include "flightwindow.h"
#include "camera.h"

FlightWindow::FlightWindow()
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    image1 = new QPixmap("resources/example1.jpg");

    infoLabel = new QLabel(tr("UAV Capture:"));
    infoLabel->setAlignment(Qt::AlignLeft);
    infoLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    infoLabel->setStyleSheet("QLabel { color : grey; font-size: 36px;}");

    feed1 = new QLabel();
    feed1->setAlignment(Qt::AlignCenter);
    feed1->setFixedSize(800,600);
    feed1->setPixmap(image1->scaled(feed1->width(), feed1->height(), Qt::KeepAspectRatio));

    latitudeInfo_1 = new QLabel(tr("Latitude: 0"));
    latitudeInfo_1->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    latitudeInfo_1->setFixedSize(255, 50);
    latitudeInfo_1->setAlignment(Qt::AlignCenter);

    longitudeInfo_1 = new QLabel(tr("Longitude: 0"));
    longitudeInfo_1->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    longitudeInfo_1->setFixedSize(255, 50);
    longitudeInfo_1->setAlignment(Qt::AlignCenter);

    altitudeInfo_1 = new QLabel(tr("Altitude: 0"));
    altitudeInfo_1->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    altitudeInfo_1->setFixedSize(255, 50);
    altitudeInfo_1->setAlignment(Qt::AlignCenter);

    velocityInfo_1 = new QLabel(tr("Velocity: 0"));
    velocityInfo_1->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    velocityInfo_1->setFixedSize(255, 50);
    velocityInfo_1->setAlignment(Qt::AlignCenter);

    batteryInfo_1 = new QLabel(tr("Battery: 100%"));
    batteryInfo_1->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    batteryInfo_1->setFixedSize(255, 50);
    batteryInfo_1->setAlignment(Qt::AlignCenter);

    previewFlight = new QPushButton(tr("Open UAV Feed"));
    previewFlight->setFixedSize(257, 52);

    createActions();

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(infoLabel, 0, 0);
    layout->addWidget(feed1, 0, 0, 1, 3);
    layout->addWidget(latitudeInfo_1, 1, 0);
    layout->addWidget(longitudeInfo_1, 2, 0);
    layout->addWidget(altitudeInfo_1, 1, 1);
    layout->addWidget(velocityInfo_1, 2, 1);
    layout->addWidget(previewFlight, 1, 2);
    layout->addWidget(batteryInfo_1, 2, 2);
    widget->setLayout(layout);

    setWindowTitle(tr("Mission Control"));
    resize(800, 600);
}

void FlightWindow::on_Preview(){
    c->show();
}

void FlightWindow::createActions()
{
    connect(previewFlight, SIGNAL(clicked()), this, SLOT(on_Preview()));
}
