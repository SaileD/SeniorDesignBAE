#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWindow>
#include <flightwindow.h>

class QAction;
class QActionGroup;
class QLabel;
class QMenu;
class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private slots:
    void about();
    void on_Start();

private:
    void createActions();
    void createMenus();

    QMenu *fileMenu;
    QMenu *helpMenu;
    QAction *aboutAct;
    QAction *startAct;
    QLabel *infoLabel;
    QPushButton *startNew;
    QPushButton *quit;
    FlightWindow *fw = new FlightWindow();
};

#endif
