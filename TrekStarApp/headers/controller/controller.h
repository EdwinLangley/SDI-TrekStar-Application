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

private slots:
    void handleCreateProject();
    void handleClear();
    void handleLocationAdd();
    void handleLocationDel();
    void handleKeywordsAdd();
    void handleKeywordsDel();

private:
    DoublyLinkedList projList;
    MainWindow mw;
    ProjectWindow pw;
    Project* openProj;
};

#endif // CONTROLLER_H
