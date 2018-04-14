#include "gui.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Opens QSS file and stores files content in QString
    QFile windowStyleSheet(":/style/main.qss");
    windowStyleSheet.open(QFile::ReadOnly);
    QString styleCode = windowStyleSheet.readAll();
    windowStyleSheet.close();

    // Opens txt file which stores variables used in style sheet, creates list
    // of each variable and corresponding value
    QFile styleVariablesFile(":/style/styleVariables.txt");
    styleVariablesFile.open(QFile::ReadOnly);
    QString styleVariablesString = styleVariablesFile.readAll();
    QStringList styleVariables = styleVariablesString.split(QRegularExpression(";"),QString::SkipEmptyParts);
    styleVariablesFile.close();

    // Replaces each instance of variable used with the corresponding value
    for(int i = 0; i < styleVariables.size() - 1; ++i){
        styleVariables[i] = styleVariables[i].trimmed();
        QStringList buffer = styleVariables[i].split(QRegularExpression("="),QString::SkipEmptyParts);
        styleCode.replace(QString(buffer[0]), QString(buffer[1]));
    }

    this->setStyleSheet(styleCode);


}

MainWindow::~MainWindow()
{
    delete ui;
}

