#include "controllerproject.h"
#include "gui.h"
#include "projectwindow.h"

controllerproject::controllerproject(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ProjectWindow w;
    w.show();
    a.exec();
}
