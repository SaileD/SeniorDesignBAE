
#ifndef LOADINGWINDOW_H
#define LOADINGWINDOW_H

#include <QWindow>
#include <QMainWindow>
#include <flightwindow.h>
#include <QTimer>
#include <QProgressBar>
#include <camera.h>


class QAction;
class QActionGroup;
class QLabel;
class QMenu;

class LoadingWindow : public QMainWindow
{
    Q_OBJECT
public:
    LoadingWindow();
    FlightWindow *fw = new FlightWindow();

public slots:
    void turnOnClock();
    void update();

private:
    Camera *c = new Camera();
    QTimer *clock;
    QLabel *loadingLabel;
    QProgressBar *bar;
    int i;

};

#endif // LOADINGWINDOW_H


