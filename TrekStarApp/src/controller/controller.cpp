#include "controller.h"
#include "gui.h"
#include "ui_mainwindow.h"
#include "project.h"
#include "doublylinkedlist.h"


controller::controller()
{

    mw.ui->cbGenre->addItem("Action");
    mw.ui->cbGenre->addItem("Comedy");
    mw.ui->cbGenre->addItem("Drama");
    mw.ui->cbGenre->addItem("Documentary");
    mw.ui->cbGenre->addItem("Horror");
    mw.ui->cbGenre->addItem("Thriller");

    mw.ui->cbLanguage->addItem("English");
    mw.ui->cbLanguage->addItem("French");
    mw.ui->cbLanguage->addItem("German");
    mw.ui->cbLanguage->addItem("Spanish");
    mw.ui->cbLanguage->addItem("Mandarin");

    connect(mw.ui->cmdCreate, SIGNAL (clicked()), this, SLOT (handleCreateProject()));
    connect(mw.ui->cmdClear, SIGNAL (clicked()), this, SLOT (handleClear()));
    connect(mw.ui->cmdLocationAdd, SIGNAL (clicked()), this, SLOT (handleLocationAdd()));
    connect(mw.ui->cmdLocationDel, SIGNAL (clicked()), this, SLOT (handleLocationDel()));
    connect(mw.ui->cmdKeywordsAdd, SIGNAL (clicked()), this, SLOT (handleKeywordsAdd()));
    connect(mw.ui->cmdKeywordsDel, SIGNAL (clicked()), this, SLOT (handleKeywordsDel()));

    mw.show();

}

void controller::handleCreateProject(){

    bool create = true;

    // Gets data from the form
    std::string projTitle = mw.ui->txtTitleProject->text().toStdString();
    std::string summary = mw.ui->txtSummary->toPlainText().toStdString();
    std::string genre = mw.ui->cbGenre->currentText().toStdString();
    std::string language = mw.ui->cbLanguage->currentText().toStdString();
    std::string date = mw.ui->deRelease->date().toString().toStdString();
    int runtime = mw.ui->sbRuntime->value();
    int sales = mw.ui->sbSales->value();

    std::vector<std::string> locations;
    for(unsigned int i = 0; i < mw.ui->lstLocations->count(); ++i){
        locations.push_back(mw.ui->lstLocations->item(i)->text().toStdString());
    }

    std::vector<std::string> keywords;
    for(unsigned int i = 0; i < mw.ui->lstKeywords->count(); ++i){
        keywords.push_back(mw.ui->lstKeywords->item(i)->text().toStdString());
    }

    if(projTitle == ""){
        mw.ui->lblTitleProjects->setStyleSheet("color: #D81E5B");
        create = false;
    }else{
        mw.ui->lblTitleProjects->setStyleSheet("color: #78CAD2");
    }

    if(summary == ""){
        mw.ui->lblSummary->setStyleSheet("color: #D81E5B");
        create = false;
    }else{
        mw.ui->lblSummary->setStyleSheet("color: #78CAD2");
    }

    if(locations.size() == 0){
        mw.ui->lblLocations->setStyleSheet("color: #D81E5B");
        create = false;
    }else{
        mw.ui->lblLocations->setStyleSheet("color: #78CAD2");
    }

    if(keywords.size() == 0){
        mw.ui->lblKeywords->setStyleSheet("color: #D81E5B");
        create = false;
    }else{
        mw.ui->lblKeywords->setStyleSheet("color: #78CAD2");
    }

    // If all fields have correctly inputted data a new project is created
    if(create){

        Project input;

        input.setTitle(projTitle);
        input.setSummary(summary);
        input.setGenre(genre);
        input.setLanguage(language);
        input.setReleaseDate(date);
        input.setRunTime(runtime);
        input.setWeeklyBoxFigures(sales);

        projList.createnode(input);
        openProj = &projList.findByTitle(projTitle);
        pw.show();

        handleClear();

     }

}

// Clears form
void controller::handleClear(){

    mw.ui->txtTitleProject->clear();
    mw.ui->txtSummary->clear();
    mw.ui->cbGenre->setCurrentIndex(0);
    mw.ui->cbLanguage->setCurrentIndex(0);
    mw.ui->deRelease->setDate(QDate(2000, 1, 1));
    mw.ui->sbRuntime->setValue(0);
    mw.ui->sbSales->setValue(0);
    mw.ui->lstLocations->clear();
    mw.ui->lstKeywords->clear();

    mw.ui->lblTitleProjects->setStyleSheet("color: #78CAD2");
    mw.ui->lblSummary->setStyleSheet("color: #78CAD2");
    mw.ui->lblLocations->setStyleSheet("color: #78CAD2");
    mw.ui->lblKeywords->setStyleSheet("color: #78CAD2");
}

// Adds the input from the text box to the location list
void controller::handleLocationAdd(){

    QString input = mw.ui->txtLocationAdd->text();
    if(input.toStdString() != ""){
        mw.ui->lstLocations->addItem(input);
    }
    mw.ui->txtLocationAdd->clear();
}

// Deletes selected items from the location list
void controller::handleLocationDel(){

    QList <QListWidgetItem *> selectedItems = mw.ui->lstLocations->selectedItems();
    for(unsigned int i = 0; i < selectedItems.size(); i++){
        std::cout << i << std::endl;
        delete mw.ui->lstLocations->takeItem(mw.ui->lstLocations->row(selectedItems[i]));
    }

}

// Adds the input from the text box to the keywords list
void controller::handleKeywordsAdd(){

    QString input = mw.ui->txtKeywordsAdd->text();
    if(input.toStdString() != ""){
        mw.ui->lstKeywords->addItem(input);
    }
    mw.ui->txtKeywordsAdd->clear();

}

// Deletes selected items from the keywords list
void controller::handleKeywordsDel(){

    QList <QListWidgetItem *> selectedItems = mw.ui->lstKeywords->selectedItems();
    for(unsigned int i = 0; i < selectedItems.size(); i++){
        std::cout << i << std::endl;
        delete mw.ui->lstKeywords->takeItem(mw.ui->lstKeywords->row(selectedItems[i]));
    }

}
