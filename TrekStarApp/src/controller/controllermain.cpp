#include "controllermain.h"
#include "gui.h"
#include "mainwindow.h"
#include "controllerproject.h"

controllermain::controllermain(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    controllerproject c(argc, argv);

    a.exec();
}
