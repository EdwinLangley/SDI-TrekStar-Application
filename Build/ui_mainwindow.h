/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *startTab;
    QPushButton *pushButton;
    QLabel *startTitle;
    QWidget *newProjectTab;
    QLabel *newProjectTitle;
    QLineEdit *titleLineEdit;
    QPlainTextEdit *plainTextEdit;
    QLineEdit *lineEdit;
    QDateTimeEdit *dateTimeEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEditFilmLoc;
    QPushButton *addFilmLocationButton;
    QLineEdit *lineEditKeywords;
    QPushButton *addKeywordButton;
    QLabel *label_5;
    QLabel *label_6;
    QListWidget *listWidgetFilmLocations;
    QListWidget *listWidgetKeywords;
    QWidget *existingProjects;
    QLabel *existingProjectTitle;
    QWidget *removeProjects;
    QLabel *removeProjectsTitle;
    QWidget *closeApp;
    QLabel *closeDownApplicationTitle;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(831, 530);
        QIcon icon;
        icon.addFile(QStringLiteral("icon2.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1111, 541));
        tabWidget->setTabPosition(QTabWidget::North);
        startTab = new QWidget();
        startTab->setObjectName(QStringLiteral("startTab"));
        pushButton = new QPushButton(startTab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(260, 200, 331, 101));
        QIcon icon1;
        icon1.addFile(QStringLiteral("res/Open-file-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        startTitle = new QLabel(startTab);
        startTitle->setObjectName(QStringLiteral("startTitle"));
        startTitle->setGeometry(QRect(0, 0, 831, 81));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        startTitle->setFont(font);
        tabWidget->addTab(startTab, QString());
        newProjectTab = new QWidget();
        newProjectTab->setObjectName(QStringLiteral("newProjectTab"));
        newProjectTitle = new QLabel(newProjectTab);
        newProjectTitle->setObjectName(QStringLiteral("newProjectTitle"));
        newProjectTitle->setGeometry(QRect(0, 0, 831, 81));
        newProjectTitle->setFont(font);
        titleLineEdit = new QLineEdit(newProjectTab);
        titleLineEdit->setObjectName(QStringLiteral("titleLineEdit"));
        titleLineEdit->setGeometry(QRect(120, 110, 221, 20));
        plainTextEdit = new QPlainTextEdit(newProjectTab);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(120, 300, 221, 111));
        lineEdit = new QLineEdit(newProjectTab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(120, 170, 221, 20));
        dateTimeEdit = new QDateTimeEdit(newProjectTab);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(120, 230, 221, 22));
        label = new QLabel(newProjectTab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 140, 221, 20));
        label_2 = new QLabel(newProjectTab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 80, 221, 20));
        label_3 = new QLabel(newProjectTab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 270, 81, 20));
        label_4 = new QLabel(newProjectTab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(120, 200, 81, 20));
        lineEditFilmLoc = new QLineEdit(newProjectTab);
        lineEditFilmLoc->setObjectName(QStringLiteral("lineEditFilmLoc"));
        lineEditFilmLoc->setGeometry(QRect(460, 210, 181, 20));
        addFilmLocationButton = new QPushButton(newProjectTab);
        addFilmLocationButton->setObjectName(QStringLiteral("addFilmLocationButton"));
        addFilmLocationButton->setGeometry(QRect(650, 210, 71, 23));
        lineEditKeywords = new QLineEdit(newProjectTab);
        lineEditKeywords->setObjectName(QStringLiteral("lineEditKeywords"));
        lineEditKeywords->setGeometry(QRect(460, 380, 181, 20));
        addKeywordButton = new QPushButton(newProjectTab);
        addKeywordButton->setObjectName(QStringLiteral("addKeywordButton"));
        addKeywordButton->setGeometry(QRect(650, 380, 71, 23));
        label_5 = new QLabel(newProjectTab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(460, 80, 101, 16));
        label_6 = new QLabel(newProjectTab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(460, 250, 101, 16));
        listWidgetFilmLocations = new QListWidget(newProjectTab);
        listWidgetFilmLocations->setObjectName(QStringLiteral("listWidgetFilmLocations"));
        listWidgetFilmLocations->setGeometry(QRect(460, 110, 256, 91));
        listWidgetKeywords = new QListWidget(newProjectTab);
        listWidgetKeywords->setObjectName(QStringLiteral("listWidgetKeywords"));
        listWidgetKeywords->setGeometry(QRect(460, 280, 256, 91));
        tabWidget->addTab(newProjectTab, QString());
        existingProjects = new QWidget();
        existingProjects->setObjectName(QStringLiteral("existingProjects"));
        existingProjectTitle = new QLabel(existingProjects);
        existingProjectTitle->setObjectName(QStringLiteral("existingProjectTitle"));
        existingProjectTitle->setGeometry(QRect(0, 0, 831, 81));
        existingProjectTitle->setFont(font);
        tabWidget->addTab(existingProjects, QString());
        removeProjects = new QWidget();
        removeProjects->setObjectName(QStringLiteral("removeProjects"));
        removeProjectsTitle = new QLabel(removeProjects);
        removeProjectsTitle->setObjectName(QStringLiteral("removeProjectsTitle"));
        removeProjectsTitle->setGeometry(QRect(0, 0, 831, 81));
        removeProjectsTitle->setFont(font);
        tabWidget->addTab(removeProjects, QString());
        closeApp = new QWidget();
        closeApp->setObjectName(QStringLiteral("closeApp"));
        closeDownApplicationTitle = new QLabel(closeApp);
        closeDownApplicationTitle->setObjectName(QStringLiteral("closeDownApplicationTitle"));
        closeDownApplicationTitle->setGeometry(QRect(0, 0, 831, 81));
        closeDownApplicationTitle->setFont(font);
        tabWidget->addTab(closeApp, QString());
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "TrekStar", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Click to open Project", Q_NULLPTR));
        startTitle->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">OPEN PROJECT</p></body></html>", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(startTab), QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        newProjectTitle->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">NEW PROJECT</p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Genre", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Title", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Summary", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Release Date", Q_NULLPTR));
        addFilmLocationButton->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        addKeywordButton->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Filming Locations", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Keywords", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(newProjectTab), QApplication::translate("MainWindow", "New Project", Q_NULLPTR));
        existingProjectTitle->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">EXISTING PROJECTS</p></body></html>", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(existingProjects), QApplication::translate("MainWindow", "Existing Project", Q_NULLPTR));
        removeProjectsTitle->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">REMOVE PROJECTS</p></body></html>", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(removeProjects), QApplication::translate("MainWindow", "Remove Project", Q_NULLPTR));
        closeDownApplicationTitle->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">CLOSE DOWN APPLICATION</p></body></html>", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(closeApp), QApplication::translate("MainWindow", "Close Application (Save)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
