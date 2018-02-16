
#ifndef LOADINGWINDOW_H
#define LOADINGWINDOW_H

#include <QWindow>
#include <QMainWindow>
#include <flightwindow.h>
#include <QTimer>
#include <QProgressBar>

class QAction;
class QActionGroup;
class QLabel;
class QMenu;

class LoadingWindow : public QMainWindow
{
    Q_OBJECT
public:
    LoadingWindow();

public slots:
    void turnOnClock();
    void update();

private:
    QTimer *clock;
    QLabel *loadingLabel;
    FlightWindow *fw = new FlightWindow();
    QProgressBar *bar;
    int i;

};

#endif // LOADINGWINDOW_H


