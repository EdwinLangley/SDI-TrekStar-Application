#ifndef GUI_H
#define GUI_H

#include <QApplication>
#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include "main.h"

// Declares list which stores variable names used in qss style sheets
// and the corresponding values
extern QStringList styleVariables;

// Function which reads text file containing qss style sheet variables
// and stores them
void readVariables();

// Function which takes filepath to qss file and stores the contents in
// a QString
QString readStyleSheet(QString filePath);

#endif // GUI_H
