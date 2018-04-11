#include <QtWidgets>

#include "loadingwindow.h"

LoadingWindow::LoadingWindow()
{
    i = 0;

    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    loadingLabel = new QLabel(tr("<b>Loading ...</b>"));
    loadingLabel->setAlignment(Qt::AlignCenter);
    loadingLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    bar = new QProgressBar();
    bar->setValue(0);

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(loadingLabel, 0, 0);
    layout->addWidget(bar, 1, 0);
    widget->setLayout(layout);

    setWindowTitle(tr("Loading"));
    resize(200, 100);
}

void LoadingWindow::turnOnClock(){
    clock = new QTimer(this);
    connect(clock, SIGNAL(timeout()), this, SLOT(update()));
    clock->start(200);
}

void LoadingWindow::update(){
    i++;
    bar->setValue(bar->value() + 6.67);


    if(i == 17){
        bar->setValue(100);
        loadingLabel->setText("Click Capture Image to launch Flight");
        clock->stop();
        c->show();
    }
}
