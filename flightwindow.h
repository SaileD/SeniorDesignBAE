#ifndef FLIGHTWINDOW_H
#define FLIGHTWINDOW_H

#include <QWindow>
#include <QMainWindow>

class QAction;
class QPushButton;
class QActionGroup;
class QLabel;
class QMenu;

class FlightWindow : public QMainWindow
{
    Q_OBJECT
public:
    FlightWindow();

private slots:

private:

    QMenu *fileMenu;
    QMenu *helpMenu;
    QLabel *infoLabel;
    QLabel *altitudeInfo_1;
    QLabel *latitudeInfo_1;
    QLabel *longitudeInfo_1;
    QLabel *velocityInfo_1;
    QLabel *batteryInfo_1;
    QLabel *feed1;
    QPixmap *image1;
    QPushButton *flightInfo_1;
};

#endif // FLIGHTWINDOW_H
