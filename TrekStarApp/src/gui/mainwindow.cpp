#include "gui.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString styleCode = readStyleSheet(":/style/main.qss");
    this->setStyleSheet(styleCode);

}

MainWindow::~MainWindow()
{
    delete ui;
}

