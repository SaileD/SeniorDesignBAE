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
    void displayImage(const QString &s);
    void setLabels();

protected:
    void timerEvent(QTimerEvent *event) override;

private:
    int iter;
    QMenu *fileMenu;
    QMenu *helpMenu;
    QLabel *infoLabel;
    QLabel *altitudeLabel;
    QLabel *latitudeLabel;
    QLabel *longitudeLabel;
    QLabel *velocityLabel;
    QLabel *batteryLabel;
    QLabel *feed;
    QLabel *headingLabel;
    QPixmap *image1;
    QPushButton *previewFlight;
};

#endif // FLIGHTWINDOW_H
