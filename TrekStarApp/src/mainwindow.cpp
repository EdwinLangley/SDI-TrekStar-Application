
#include "gui.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile windowStyleSheet(":/style/main.qss");
    windowStyleSheet.open(QFile::ReadOnly);
    this->setStyleSheet(windowStyleSheet.readAll());
    windowStyleSheet.close();

}

MainWindow::~MainWindow()
{
    delete ui;
}

