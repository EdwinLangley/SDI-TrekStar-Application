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

    void handleClose();
    void handleCreateProject();
    void handleClear();
    void handleLocationAdd();
    void handleLocationDel();
    void handleKeywordsAdd();
    void handleKeywordsDel();
    void handleFilter();
    void handleProjectDel();
    void handleOpenProject();
    void handleStatusChange();

    void setProjectWindow();
    void handleApplyGeneralChanges();
    void handleProjectWindowLocationAdd();
    void handleProjectWindowLocationDel();
    void handleProjectWindowKeywordsAdd();
    void handleProjectWindowKeywordsDel();
    void handleProjectWindowStatusChange();
    void handleProjectWindowCrewChange();
    void handleProjectWindowCrewAdd();
    void handleProjectWindowCrewDel();
    void handleProjectWindowCrewFilter();

private:
    void showAllProjects();
    void displayCrew();
    void updateCrewLocations();
    void filterCrewByRole(std::string role);
    MainWindow mw;
    ProjectWindow pw;
    Project* openProj;
};

#endif // CONTROLLER_H
