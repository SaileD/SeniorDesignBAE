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

    batteryInfo_1 = new QLabel(tr("Battery: 100%"));
    batteryInfo_1->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    batteryInfo_1->setFixedSize(100, 40);
    batteryInfo_1->setAlignment(Qt::AlignCenter);

    flightInfo_1 = new QPushButton(tr("Reload"));
    flightInfo_1->setFixedSize(112, 52);

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(infoLabel, 0, 0, 1, 3);
    layout->addWidget(latitudeInfo_1, 1, 0);
    layout->addWidget(longitudeInfo_1, 2, 0);
    layout->addWidget(altitudeInfo_1, 1, 1);
    layout->addWidget(velocityInfo_1, 2, 1);
    layout->addWidget(flightInfo_1, 1, 2);
    layout->addWidget(batteryInfo_1, 2, 2);
    widget->setLayout(layout);

    setWindowTitle(tr("Mission Control"));
    resize(800, 600);
}
