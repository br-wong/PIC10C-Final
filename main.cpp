#include <QApplication>
#include <Shooter.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

#include "Mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();

    return a.exec();
}
