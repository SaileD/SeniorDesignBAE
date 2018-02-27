#ifndef FLIGHTWINDOW_H
#define FLIGHTWINDOW_H

#include <QWindow>
#include <QMainWindow>

class QAction;
class QPushButton;
class QActionGroup;
class QLabel;
class QMenu;
class QPixmap;
class QPainter;

class FlightWindow : public QMainWindow
{
    Q_OBJECT
public:
    FlightWindow();
    void paintEvent(QPaintEvent *);

private slots:

private:

    QPainter *p;
    QPixmap *image1;
    QPixmap *image2;
    QMenu *fileMenu;
    QMenu *helpMenu;
    QLabel *infoLabel1;
    QLabel *infoLabel2;
    QLabel *feed1;
    QLabel *altitudeInfo_1;
    QLabel *latitudeInfo_1;
    QLabel *longitudeInfo_1;
    QLabel *velocityInfo_1;
    QLabel *batteryInfo_1;
    QPushButton *flightInfo_1;
    QLabel *feed2;
    QLabel *altitudeInfo_2;
    QLabel *latitudeInfo_2;
    QLabel *longitudeInfo_2;
    QLabel *velocityInfo_2;
    QLabel *batteryInfo_2;
};

#endif // FLIGHTWINDOW_H
