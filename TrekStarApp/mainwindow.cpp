#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QImage loadProjectImage;
//    QLabel *projectImageLabel;
//    projectImageLabel = new QLabel(this);
//    projectImageLabel->setPixmap(QPixmap(QString::fromUtf8("D:/Users/Edwin/Documents/SDIPROJECT/TrekStarApp/res/Open-file-icon.png")));
//    projectImageLabel->show();
//    projectImageLabel->setGeometry(340,180,128,128);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open File"),"C://","All files (*.*)");

    QMessageBox::information(this,tr("File Name"),fileName);
}



void MainWindow::on_addFilmLocationButton_clicked()
{
    ui->listWidgetFilmLocations->addItem(ui->lineEditFilmLoc->text());
    ui->lineEditFilmLoc->setText("");

}

void MainWindow::on_addKeywordButton_clicked()
{
    ui->listWidgetKeywords->addItem(ui->lineEditKeywords->text());
    ui->lineEditKeywords->setText("");
}
