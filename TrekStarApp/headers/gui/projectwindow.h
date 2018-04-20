#ifndef PROJECTWINDOW_H
#define PROJECTWINDOW_H

#include <QWidget>

namespace Ui {
class ProjectWindow;
}

class ProjectWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectWindow(QWidget *parent = 0);
    ~ProjectWindow();

private:
    Ui::ProjectWindow *ui;
};

#endif // PROJECTWINDOW_H
