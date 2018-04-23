#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gui.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow *ui;
    QPushButton *x;
};

#endif // MAINWINDOW_H
