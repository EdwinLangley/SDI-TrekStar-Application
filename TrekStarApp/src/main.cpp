#include "gui.h"
#include "mainwindow.h"
#include "node.h"
#include "project.h"
#include "doublylinkedlist.h"

using namespace std;

int main(int argc, char *argv[])
{

    // Calls function which stores qss variables in a global list variable
    readVariables();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();

}
