#include "controller.h"
#include "gui.h"
#include "ui_mainwindow.h"
#include "project.h"
#include "doublylinkedlist.h"


controller::controller()
{

    // Sets all options for status combo box
    mw.ui->cbStatus->addItem("Unreleased");
    mw.ui->cbStatus->addItem("Now Playing");
    mw.ui->cbStatus->addItem("Released");

    // Sets all options for the genre combo box
    mw.ui->cbGenre->addItem("Action");
    mw.ui->cbGenre->addItem("Comedy");
    mw.ui->cbGenre->addItem("Drama");
    mw.ui->cbGenre->addItem("Documentary");
    mw.ui->cbGenre->addItem("Horror");
    mw.ui->cbGenre->addItem("Thriller");

    // Sets all options for the language combo box
    mw.ui->cbLanguage->addItem("English");
    mw.ui->cbLanguage->addItem("French");
    mw.ui->cbLanguage->addItem("German");
    mw.ui->cbLanguage->addItem("Spanish");
    mw.ui->cbLanguage->addItem("Mandarin");

    // Sets all options for the filter combo box
    mw.ui->cbFilter->addItem("No Filter");
    mw.ui->cbFilter->addItem("Title");
    mw.ui->cbFilter->addItem("Genre");
    mw.ui->cbFilter->addItem("Keywords");
    mw.ui->cbFilter->addItem("Newest to Oldest");
    mw.ui->cbFilter->addItem("Oldest to Newest");
    mw.ui->cbFilter->addItem("Director");
    mw.ui->cbFilter->addItem("Actor");
    mw.ui->cbFilter->addItem("Producer");
    mw.ui->cbFilter->addItem("Writer");
    mw.ui->cbFilter->addItem("Editor");
    mw.ui->cbFilter->addItem("Production Designer");
    mw.ui->cbFilter->addItem("Set Decorator");
    mw.ui->cbFilter->addItem("Costume Designer");

    // Connects button press signal to functions
    //connect(mw.x, SIGNAL(aboutToQuit()), this, SLOT(handleClose()));
    connect(mw.ui->cmdCreate, SIGNAL (clicked()), this, SLOT (handleCreateProject()));
    connect(mw.ui->cmdClear, SIGNAL (clicked()), this, SLOT (handleClear()));
    connect(mw.ui->cmdLocationAdd, SIGNAL (clicked()), this, SLOT (handleLocationAdd()));
    connect(mw.ui->cmdLocationDel, SIGNAL (clicked()), this, SLOT (handleLocationDel()));
    connect(mw.ui->cmdKeywordsAdd, SIGNAL (clicked()), this, SLOT (handleKeywordsAdd()));
    connect(mw.ui->cmdKeywordsDel, SIGNAL (clicked()), this, SLOT (handleKeywordsDel()));
    connect(mw.ui->cmdFilter, SIGNAL (clicked()), this, SLOT (handleFilter()));
    connect(mw.ui->cmdProjectDel, SIGNAL (clicked()), this, SLOT (handleProjectDel()));
    connect(mw.ui->cmdOpenProject, SIGNAL (clicked()), this, SLOT (handleOpenProject()));
    connect(mw.ui->cbStatus, SIGNAL(currentIndexChanged(int)), this, SLOT(handleStatusChange()));

    // Displays list of all projects
    showAllProjects();

    // Locks any input options based on status selection
    handleStatusChange();

    // Displays the main window
    mw.show();

}

void controller::handleClose(){
    std::cout << "lol" << std::endl;
}

void controller::handleCreateProject(){

    bool create = true;

    // Gets data from the form
    std::string projTitle = mw.ui->txtTitleProject->text().toStdString();
    std::string summary = mw.ui->txtSummary->toPlainText().toStdString();
    std::string status = mw.ui->cbStatus->currentText().toStdString();
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

    // Checks data has been inputted and flags red if it has not
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
        input.setProjectStatus(status);
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
    mw.ui->cbStatus->setCurrentIndex(0);
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

    //Keep this comment, its how we are calling the destructor and I wont remember it :(
    //DoublyLinkedList *projList2 = &projList;
    //delete projList2;

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
    for(int i = 0; i < selectedItems.size(); i++){
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
    for(int i = 0; i < selectedItems.size(); i++){
        delete mw.ui->lstKeywords->takeItem(mw.ui->lstKeywords->row(selectedItems[i]));
    }

}

// Filters project list
void controller::handleFilter(){

    try{
        mw.ui->lstProjects->clear();

        std::string filterCategory = mw.ui->cbFilter->currentText().toStdString();
        std::string input = mw.ui->txtFilter->text().toStdString();
        std::vector<std::string> returnedValues;

        if(filterCategory == "No Filter"){
            showAllProjects();
        }
        else if(filterCategory == "Newest to Oldest"){
            returnedValues = projList.sortByNewest();
        }
        else if(filterCategory == "Oldest to Newest"){
            returnedValues = projList.sortByOldest();
        }
        else if (input != ""){

                if(filterCategory == "Title"){
                    returnedValues = projList.findByKeyword(input);
                }
                else if(filterCategory == "Genre"){
                    returnedValues = projList.findByGenre(input);
                }
                else if(filterCategory == "Keywords"){
                    returnedValues = projList.findByKeyword(input);
                }
                else{
                    returnedValues = projList.findByRoleAndName(filterCategory, input);
                }
        }

        for(unsigned int i = 0; i < returnedValues.size(); ++i){
            mw.ui->lstProjects->addItem(QString::fromStdString(returnedValues[i]));
        }
    }
    catch(std::out_of_range e1){
        std::cout << e1.what() << std::endl;
    }
    catch(std::invalid_argument e2){
        std::cout << e2.what() << std::endl;
    }
    catch(std::bad_alloc e3){
        std::cout << e3.what() << std::endl;
    }
    catch(...){}

}

// Outputs all projects to project list
void controller::showAllProjects(){
    try{
        std::vector<std::string> allProjects = projList.getAllFilmTitles();
        for(unsigned int i = 0; i < allProjects.size(); ++i){
            mw.ui->lstProjects->addItem(QString::fromStdString(allProjects[i]));
        }
    }
    catch(out_of_range e1){
        std::cout << e1.what() << std::endl;
    }
    catch(std::invalid_argument e2){
        std::cout << e2.what() << std::endl;
    }
    catch(std::bad_alloc e3){
        std::cout << e3.what() << std::endl;
    }
    catch(...){}

}

// Removes project from linked list and list widget
void controller::handleProjectDel(){

    try {

        QList <QListWidgetItem *> selectedItems = mw.ui->lstProjects->selectedItems();
        std::string projectTitle;
        for(int i = 0; i < selectedItems.size(); i++){
            projectTitle = selectedItems[i]->text().toStdString();
            projList.delete_by_title(projectTitle);
            delete mw.ui->lstProjects->takeItem(mw.ui->lstProjects->row(selectedItems[i]));

        }

    }
    catch (out_of_range e1){
        std::cout << e1.what() << std::endl;
    }
    catch(std::invalid_argument e2){
        std::cout << e2.what() << std::endl;
    }
    catch(std::bad_alloc e3){
        std::cout << e3.what() << std::endl;
    }
    catch(...){}


}

// Opens selected project from the list
void controller::handleOpenProject(){

    try{
        QList <QListWidgetItem *> selectedItems = mw.ui->lstProjects->selectedItems();
        std::string projectTitle = selectedItems[0]->text().toStdString();
        if(projectTitle != ""){
            openProj = &projList.findByTitle(projectTitle);
            pw.show();
        }
    }
    catch(out_of_range e1){
        std::cout << e1.what() << std::endl;
    }
    catch(std::invalid_argument e2){
        std::cout << e2.what() << std::endl;
    }
    catch(std::bad_alloc e3){
        std::cout << e3.what() << std::endl;
    }
    catch(...){}

}

// Changes input options based on status combo box selection
void controller::handleStatusChange(){
    // released = sales,
    // unreleased = sales, materials,
    // now playing = materials,

    std::string status = mw.ui->cbStatus->currentText().toStdString();

    if(status == "Unreleased"){
        mw.ui->lblSales->setStyleSheet("color: #7C8483");
        mw.ui->sbSales->setReadOnly(true);
        mw.ui->sbSales->setVisible(false);
    }
    else if (status == "Now Playing"){
        mw.ui->lblSales->setStyleSheet("color: #78CAD2");
        mw.ui->sbSales->setReadOnly(false);
        mw.ui->sbSales->setVisible(true);
    }
    else if (status == "Released"){
        mw.ui->lblSales->setStyleSheet("color: #7C8483");
        mw.ui->sbSales->setReadOnly(true);
        mw.ui->sbSales->setVisible(false);
    }

}


