#include <iostream>
#include <string.h>
#include <QtWidgets>
#include <QTextStream>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QtNetwork>

#include "flightwindow.h"
#include "camera.h"

FlightWindow::FlightWindow()
{
    iter = 0;
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    feed = new QLabel();
    image1 = new QPixmap("resources/example1.jpg");
    infoLabel = new QLabel(tr("UAV Mission"));
    latitudeLabel = new QLabel(tr(""));
    longitudeLabel = new QLabel(tr(""));
    altitudeLabel = new QLabel(tr(""));
    velocityLabel = new QLabel(tr(""));
    batteryLabel = new QLabel(tr(""));
    headingLabel = new QLabel(tr(""));

    setLabels();

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(infoLabel, 0, 0);
    layout->addWidget(feed, 0, 0, 1, 3);
    layout->addWidget(latitudeLabel, 1, 0);
    layout->addWidget(longitudeLabel, 2, 0);
    layout->addWidget(altitudeLabel, 1, 1);
    layout->addWidget(velocityLabel, 2, 1);
    layout->addWidget(headingLabel, 1, 2);
    layout->addWidget(batteryLabel, 2, 2);
    widget->setLayout(layout);

    setWindowTitle(tr("Mission Control"));
    resize(800, 600);
}

void FlightWindow::setLabels()
{
    QString url;
    url = "http://127.0.0.1:56781/mavlink/";
    QNetworkAccessManager manager;
    QNetworkReply *response = manager.get(QNetworkRequest(QUrl(url)));
    QEventLoop event;
    connect(response,SIGNAL(finished()),&event,SLOT(quit()));
    event.exec();
    QString html = response->readAll(); // Source should be stored here
    int word = 0;
    word = html.toStdString().find("groundspeed");

    QString airspeed;
    airspeed = html.mid(word+13, 5);

    //TODO: Make this smarter, adjust decimal based on number of digits and +/-
    QString longitude;
    word = html.toStdString().find("lon");
    longitude = html.mid(word+5, 4);
    longitude.append(".");
    longitude.append(html.mid(word+9, 7));

    QString latitude;
    word = html.toStdString().find("lat");
    latitude = html.mid(word+5, 2);
    latitude.append(".");
    latitude.append(html.mid(word+7, 7));

    QString altitude;
    word = html.toStdString().find("alt");
    altitude = html.mid(word+5, 6);

    if(altitude.at(5) == ','){
            altitude = altitude.mid(0, 5);
    } else if(altitude.at(4) == ','){
            altitude = altitude.mid(0, 4);
    } else if(altitude.at(3) == ','){
        altitude = altitude.mid(0, 3);
    } else if(altitude.at(2) == ','){
        altitude = altitude.mid(0, 2);
    } else if(altitude.at(1) == ','){
        altitude = altitude.mid(0, 1);
    }

    QString heading;
    word = html.toStdString().find("heading");
    heading = html.mid(word+9, 4);
    if(heading.at(3) == ','){
        heading = heading.mid(0, 3);
    } else if(heading.at(2) == ','){
        heading = heading.mid(0, 2);
    } else if(heading.at(1) == ','){
        heading = heading.mid(0, 1);
    }



    infoLabel->setAlignment(Qt::AlignLeft);
    infoLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    infoLabel->setStyleSheet("QLabel { color : grey; font-size: 30px;}");

    feed->setAlignment(Qt::AlignCenter);
    feed->setFixedSize(800,600);
    feed->setPixmap(image1->scaled(feed->width(), feed->height(), Qt::KeepAspectRatio));


    latitudeLabel->setText(tr(latitude.toStdString().c_str()));
    QString temp = latitudeLabel->text();
    temp.prepend("latitude: ");
    temp.append("°");
    latitudeLabel->setText(temp);
    latitudeLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    latitudeLabel->setFixedSize(255, 50);
    latitudeLabel->setAlignment(Qt::AlignCenter);

    longitudeLabel->setText(tr(longitude.toStdString().c_str()));
    temp = longitudeLabel->text();
    temp.prepend("Longitude: ");
    temp.append("°");
    longitudeLabel->setText(temp);
    longitudeLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    longitudeLabel->setFixedSize(255, 50);
    longitudeLabel->setAlignment(Qt::AlignCenter);

    altitudeLabel->setText(tr(altitude.toStdString().c_str()));
    temp = altitudeLabel->text();
    temp.prepend("Altitude: ");
    temp.append(" m");
    altitudeLabel->setText(temp);
    altitudeLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    altitudeLabel->setFixedSize(255, 50);
    altitudeLabel->setAlignment(Qt::AlignCenter);

    velocityLabel->setText(tr(airspeed.toStdString().c_str()));
    temp = velocityLabel->text();
    temp.prepend("Velocity: ");
    temp.append(" m/s");
    velocityLabel->setText(temp);
    velocityLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    velocityLabel->setFixedSize(255, 50);
    velocityLabel->setAlignment(Qt::AlignCenter);

    batteryLabel->setText(tr("Battery: 100%"));
    batteryLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    batteryLabel->setFixedSize(255, 50);
    batteryLabel->setAlignment(Qt::AlignCenter);

    headingLabel->setText(tr(heading.toStdString().c_str()));
    temp = headingLabel->text();
    temp.prepend("Heading: ");
    temp.append("°");
    headingLabel->setText(temp);
    headingLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    headingLabel->setFixedSize(255, 50);
    headingLabel->setAlignment(Qt::AlignCenter);
}

void FlightWindow::timerEvent(QTimerEvent *event)
{
    iter++;
    setLabels();
}

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
  size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
  return written;
}

void FlightWindow::displayImage(const QString &s){
    image1 = new QPixmap(s);

    feed->setPixmap(image1->scaled(feed->width(), feed->height(), Qt::KeepAspectRatio));
}
