#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "gui.h"
#include "mainwindow.h"

class controllermain : public QObject
{
    Q_OBJECT

public:
    controllermain();

private slots:
    void handleCreateProject();

private:
    MainWindow mw;
};

#endif // CONTROLLER_H
