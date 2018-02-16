#ifndef FLIGHTWINDOW_H
#define FLIGHTWINDOW_H

#include <QWindow>
#include <QMainWindow>

class QAction;
class QActionGroup;
class QLabel;
class QMenu;

class FlightWindow : public QMainWindow
{
    Q_OBJECT
public:
    FlightWindow();

private slots:
    void newFile();
    void open();
    void save();
    void about();

private:
    void createActions();
    void createMenus();

    QMenu *fileMenu;
    QMenu *helpMenu;
    QAction *newAct;
    QAction *openAct;
    QAction *saveAct;
    QAction *aboutAct;
    QAction *startAct;
    QLabel *infoLabel;
    QLabel *altitudeInfo_1;
    QLabel *latitudeInfo_1;
    QLabel *longitudeInfo_1;
    QLabel *velocityInfo_1;
    QLabel *batteryInfo_1;
    QLabel *flightInfo_1;
};

#endif // FLIGHTWINDOW_H
