#include "gui.h"
#include "projectwindow.h"
#include "ui_projectwindow.h"

ProjectWindow::ProjectWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProjectWindow)
{

    QString styleCode = readStyleSheet(":/style/general.qss") + readStyleSheet(":/style/project.qss");
    this->setStyleSheet(styleCode);

    ui->setupUi(this);
}

ProjectWindow::~ProjectWindow()
{
    delete ui;
}
