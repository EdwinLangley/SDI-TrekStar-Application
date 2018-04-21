#include "gui.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "controllermain.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString styleCode = readStyleSheet(":/style/general.qss") + readStyleSheet(":/style/main.qss");
    this->setStyleSheet(styleCode);

    ui->lstProject->setAttribute(Qt::WA_MacShowFocusRect, 0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

