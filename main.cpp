#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
    /*QApplication a(argc, argv);
    QGraphicsScene scene;
    QGraphicsView view(&scene);
    QGraphicsPixmapItem item(QPixmap("c:\\test.jpg"));
    scene.addItem(&item);
    view.show();
    return a.exec();*/
}
