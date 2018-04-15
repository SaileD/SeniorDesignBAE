#include <QApplication>
#include <QtMultimedia/QCameraInfo>
#include <QtMultimedia/QCamera>
#include <QtMultimedia/QVideoEncoderSettings>
#include <QtMultimedia/QMediaRecorder>
#include <QtMultimediaWidgets/QCameraViewFinder>
#include <QDateTime>
#include <QUrl>
#include <iostream>
#include <QNetworkAccessManager>
#include <QNetworkReply>

using namespace std;

#include "mainwindow.h"
#include "camera.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    MainWindow window;
    window.show();

    return app.exec();


}
