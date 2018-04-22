#include "controller.h"
#include "gui.h"
#include "ui_mainwindow.h"
#include "project.h"
#include "doublylinkedlist.h"


controller::controller()
{

    mw.ui->cbGenre->addItem("Action");
    mw.ui->cbGenre->addItem("Horror");
    mw.ui->cbGenre->addItem("Drama");

    mw.ui->cbLanguage->addItem("English");
    mw.ui->cbLanguage->addItem("French");
    mw.ui->cbLanguage->addItem("German");

    mw.ui->lstLocations->addItem("locTest1");
    mw.ui->lstLocations->addItem("locTest2");
    mw.ui->lstLocations->addItem("locTest3");

    mw.ui->lstKeywords->addItem("keyTest1");
    mw.ui->lstKeywords->addItem("keyTest2");
    mw.ui->lstKeywords->addItem("keyTest3");


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
    for(int i = 0; i < mw.ui->lstLocations->count(); ++i){
        locations.push_back(mw.ui->lstLocations->item(i)->text().toStdString());
    }

    std::vector<std::string> keywords;
    for(int i = 0; i < mw.ui->lstKeywords->count(); ++i){
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

        openProj->setGenre("lol");

        std::cout << "Project created" << std::endl;

        std::cout << projList.findByTitle(projList.getAllFilmTitles().at(0)).getGenre() << std::endl;

     }

    pw.show();

}

void controller::handleClear(){
    std::cout << "clear" << std::endl;
}

void controller::handleLocationAdd(){
    std::cout << "Loc add" << std::endl;
}

void controller::handleLocationDel(){
    std::cout << "Loc del" << std::endl;
}

void controller::handleKeywordsAdd(){
    std::cout << "Key add" << std::endl;
}

void controller::handleKeywordsDel(){
    std::cout << "Key del" << std::endl;
}
