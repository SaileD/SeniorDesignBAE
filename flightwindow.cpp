#include <QtWidgets>

#include "flightwindow.h"

FlightWindow::FlightWindow()
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    image1 = new QPixmap("resources/example1.jpg");
    image2 = new QPixmap("resources/example2.jpg");

    feed1 = new QLabel(tr("<b>Welcome to Mission Control</b>"));
    feed1->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    feed1->setAlignment(Qt::AlignCenter);
    feed1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    feed1->setPixmap(image1->scaled(feed1->width(), feed1->height(), Qt::KeepAspectRatio));

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

    feed2 = new QLabel(tr("<b>Welcome to Mission Control</b>"));
    feed2->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    feed2->setAlignment(Qt::AlignCenter);
    feed2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    feed2->setPixmap(image2->scaled(feed2->width(), feed2->height(), Qt::KeepAspectRatio));

    latitudeInfo_2 = new QLabel(tr("Latitude: 0"));
    latitudeInfo_2->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    latitudeInfo_2->setFixedSize(100, 40);
    latitudeInfo_2->setAlignment(Qt::AlignCenter);

    longitudeInfo_2 = new QLabel(tr("Longitude: 0"));
    longitudeInfo_2->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    longitudeInfo_2->setFixedSize(100, 40);
    longitudeInfo_2->setAlignment(Qt::AlignCenter);

    altitudeInfo_2 = new QLabel(tr("Altitude: 0"));
    altitudeInfo_2->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    altitudeInfo_2->setFixedSize(100, 40);
    altitudeInfo_2->setAlignment(Qt::AlignCenter);

    velocityInfo_2 = new QLabel(tr("Velocity: 0"));
    velocityInfo_2->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    velocityInfo_2->setFixedSize(100, 40);
    velocityInfo_2->setAlignment(Qt::AlignCenter);

    batteryInfo_2 = new QLabel(tr("Battery: 100%"));
    batteryInfo_2->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    batteryInfo_2->setFixedSize(100, 40);
    batteryInfo_2->setAlignment(Qt::AlignCenter);

    flightInfo_1 = new QPushButton(tr("Reload"));
    flightInfo_1->setFixedSize(112, 52);

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(feed1, 0, 0, 1, 3);
    layout->addWidget(latitudeInfo_1, 1, 0);
    layout->addWidget(longitudeInfo_1, 2, 0);
    layout->addWidget(altitudeInfo_1, 1, 1);
    layout->addWidget(velocityInfo_1, 2, 1);
    layout->addWidget(batteryInfo_1, 2, 2);

    layout->addWidget(feed2, 0, 3, 1, 3);
    layout->addWidget(latitudeInfo_2, 1, 3);
    layout->addWidget(longitudeInfo_2, 2, 3);
    layout->addWidget(altitudeInfo_2, 1, 4);
    layout->addWidget(velocityInfo_2, 2, 4);
    layout->addWidget(batteryInfo_2, 2, 5);
    layout->addWidget(flightInfo_1, 1, 5);
    widget->setLayout(layout);

    setWindowTitle(tr("Mission Control"));
    resize(800, 600);
}
