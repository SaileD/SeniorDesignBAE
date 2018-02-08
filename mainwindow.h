#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QAction;
class QActionGroup;
class QLabel;
class QMenu;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

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
    QLabel *infoLabel;
    QLabel *altitudeInfo_1;
    QLabel *latitudeInfo_1;
    QLabel *longitudeInfo_1;
    QLabel *velocityInfo_1;
    QLabel *batteryInfo_1;
    QLabel *flightInfo_1;
};

#endif
