#include "mainwindow.h"
#include <QApplication>
#include "node.h"
#include "project.h"
#include "doublylinkedlist.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();

}
