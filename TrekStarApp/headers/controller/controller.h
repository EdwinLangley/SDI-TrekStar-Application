#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "gui.h"
#include "mainwindow.h"
#include "projectwindow.h"
#include "doublylinkedlist.h"

class controller : public QObject
{
    Q_OBJECT

public:
    controller();
    //Global linked list, calls constructor and loads all projects
    DoublyLinkedList projList;

private slots:
    void handleCreateProject();
    void handleClear();
    void handleLocationAdd();
    void handleLocationDel();
    void handleKeywordsAdd();
    void handleKeywordsDel();

private:
    MainWindow mw;
    ProjectWindow pw;
    Project* openProj;
};

#endif // CONTROLLER_H
