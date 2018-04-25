#include "controller.h"
#include "gui.h"
#include "ui_mainwindow.h"
#include "ui_projectwindow.h"
#include "project.h"
#include "doublylinkedlist.h"


controller::controller()
{

    // Sets all options for status combo box on the main window
    mw.ui->cbStatus->addItem("Unreleased");
    mw.ui->cbStatus->addItem("Now Playing");
    mw.ui->cbStatus->addItem("Released");

    // Sets all options for the genre combo box on the main window
    mw.ui->cbGenre->addItem("Action");
    mw.ui->cbGenre->addItem("Comedy");
    mw.ui->cbGenre->addItem("Drama");
    mw.ui->cbGenre->addItem("Documentary");
    mw.ui->cbGenre->addItem("Horror");
    mw.ui->cbGenre->addItem("Thriller");

    // Sets all options for the language combo box on the main window
    mw.ui->cbLanguage->addItem("English");
    mw.ui->cbLanguage->addItem("French");
    mw.ui->cbLanguage->addItem("German");
    mw.ui->cbLanguage->addItem("Spanish");
    mw.ui->cbLanguage->addItem("Mandarin");

    // Sets all options for the filter combo box on the main window
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


    // Sets all options for status combo box on the project window
    pw.ui->cbStatus->addItem("Unreleased");
    pw.ui->cbStatus->addItem("Now Playing");
    pw.ui->cbStatus->addItem("Released");

    // Sets all options for the genre combo box on the project window
    pw.ui->cbGenre->addItem("Action");
    pw.ui->cbGenre->addItem("Comedy");
    pw.ui->cbGenre->addItem("Drama");
    pw.ui->cbGenre->addItem("Documentary");
    pw.ui->cbGenre->addItem("Horror");
    pw.ui->cbGenre->addItem("Thriller");

    // Sets all options for the language combo box on the project window
    pw.ui->cbLanguage->addItem("English");
    pw.ui->cbLanguage->addItem("French");
    pw.ui->cbLanguage->addItem("German");
    pw.ui->cbLanguage->addItem("Spanish");
    pw.ui->cbLanguage->addItem("Mandarin");


    // Sets all options for the filter combo box on the project window
    pw.ui->cbCrew->addItem("All Crew Members");
    pw.ui->cbCrew->addItem("Director");
    pw.ui->cbCrew->addItem("Actor");
    pw.ui->cbCrew->addItem("Producer");
    pw.ui->cbCrew->addItem("Writer");
    pw.ui->cbCrew->addItem("Editor");
    pw.ui->cbCrew->addItem("Production Designer");
    pw.ui->cbCrew->addItem("Set Decorator");
    pw.ui->cbCrew->addItem("Costume Designer");

    // Sets all options for the name title combo box on the project window
    pw.ui->cbNameTitle->addItem("Mr");
    pw.ui->cbNameTitle->addItem("Mrs");
    pw.ui->cbNameTitle->addItem("Miss");
    pw.ui->cbNameTitle->addItem("Dr");

    // Sets placeholder text for search bars
    mw.ui->txtFilter->setPlaceholderText("Enter search here and choose corrsponding category");
    pw.ui->txtCrew->setPlaceholderText("Enter name of crew member to search");

    // Allows multiple selection on list
    pw.ui->lstCrewLocations->setSelectionMode(QAbstractItemView::ExtendedSelection);

    // Connects button press signals on main window to functions
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

    // Connects button press signals on project window to functions
    connect(pw.ui->cmdApplyGeneralChanges, SIGNAL(clicked()),this, SLOT(handleApplyGeneralChanges()));
    connect(pw.ui->cmdClearGeneralChanges, SIGNAL(clicked()),this, SLOT(setProjectWindow()));
    connect(pw.ui->cmdLocationAdd, SIGNAL(clicked()),this, SLOT(handleProjectWindowLocationAdd()));
    connect(pw.ui->cmdLocationDel, SIGNAL(clicked()),this, SLOT(handleProjectWindowLocationDel()));
    connect(pw.ui->cmdKeywordsAdd, SIGNAL(clicked()),this, SLOT(handleProjectWindowKeywordsAdd()));
    connect(pw.ui->cmdKeywordsDel, SIGNAL(clicked()),this, SLOT(handleProjectWindowKeywordsDel()));
    connect(pw.ui->cbStatus, SIGNAL(currentIndexChanged(int)), this, SLOT(handleProjectWindowStatusChange()));
    connect(pw.ui->cbCrew, SIGNAL(currentIndexChanged(int)), this, SLOT(handleProjectWindowCrewChange()));
    connect(pw.ui->cmdCrewAdd, SIGNAL(clicked()), this, SLOT(handleProjectWindowCrewAdd()));
    connect(pw.ui->cmdCrewDel, SIGNAL(clicked()), this, SLOT(handleProjectWindowCrewDel()));
    connect(pw.ui->cmdCrewFilter, SIGNAL(clicked()), this, SLOT(handleProjectWindowCrewFilter()));

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
    std::string date = mw.ui->deRelease->date().toString(Qt::DefaultLocaleShortDate).toStdString();
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
        input.setFilmLocations(locations);
        input.setKeywords(keywords);

        projList.createnode(input);
        openProj = &projList.findByTitle(projTitle);
        setProjectWindow();
        handleProjectWindowCrewChange();
        handleProjectWindowStatusChange();
        pw.show();
        handleClear();
        showAllProjects();

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
    mw.ui->txtLocationAdd->clear();
    mw.ui->lstLocations->clear();
    mw.ui->txtKeywordsAdd->clear();
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
        mw.ui->lstProjects->clear();
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
            setProjectWindow();
            handleProjectWindowCrewChange();
            handleProjectWindowStatusChange();
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

void controller::setProjectWindow(){

    pw.ui->lblProjectName->setText(QString::fromStdString("  " + openProj->getTitle()));
    pw.ui->txtTitleProject->setText(QString::fromStdString(openProj->getTitle()));
    pw.ui->txtSummary->setText(QString::fromStdString(openProj->getSummary()));

    if(openProj->getProjectStatus() == "Unreleased"){
        pw.ui->cbStatus->setCurrentIndex(0);
    }
    else if(openProj->getProjectStatus() == "Now Playing"){
        pw.ui->cbStatus->setCurrentIndex(1);
    }

    if(openProj->getGenre() == "Action"){
        pw.ui->cbGenre->setCurrentIndex(0);
    }
    else if(openProj->getGenre() == "Comedy"){
        pw.ui->cbGenre->setCurrentIndex(1);
    }
    else if(openProj->getGenre() == "Drama"){
        pw.ui->cbGenre->setCurrentIndex(2);
    }
    else if(openProj->getGenre() == "Documentary"){
        pw.ui->cbGenre->setCurrentIndex(3);
    }
    else if(openProj->getGenre() == "Horror"){
        pw.ui->cbGenre->setCurrentIndex(4);
    }
    else if(openProj->getGenre() == "Thriller"){
        pw.ui->cbGenre->setCurrentIndex(5);
    }

    if(openProj->getLanguage() == "English"){
        pw.ui->cbLanguage->setCurrentIndex(0);
    }
    else if(openProj->getLanguage() == "French"){
        pw.ui->cbLanguage->setCurrentIndex(1);
    }
    else if(openProj->getLanguage() == "German"){
        pw.ui->cbLanguage->setCurrentIndex(2);
    }
    else if(openProj->getLanguage() == "Spanish"){
        pw.ui->cbLanguage->setCurrentIndex(3);
    }
    else if(openProj->getLanguage() == "Mandarin"){
        pw.ui->cbLanguage->setCurrentIndex(4);
    }

    pw.ui->deRelease->setDate(QDate::fromString(QString::fromStdString(openProj->getReleaseDate()), "dd/MM/yyyy"));
    pw.ui->sbRuntime->setValue(openProj->getRunTime());
    pw.ui->sbSales->setValue(openProj->getWeeklyBoxFigures());

    pw.ui->txtLocationAdd->clear();
    pw.ui->lstLocations->clear();
    for(unsigned int i = 0; i < openProj->getFilmLocations().size(); ++i){
         pw.ui->lstLocations->addItem(QString::fromStdString(openProj->getFilmLocations()[i]));
    }

    pw.ui->txtKeywordsAdd->clear();
    pw.ui->lstKeywords->clear();
    for(unsigned int j = 0; j < openProj->getKeywords().size(); ++j){
         pw.ui->lstKeywords->addItem(QString::fromStdString(openProj->getKeywords()[j]));
    }

    pw.ui->lblTitleProjects->setStyleSheet("color: #78CAD2");
    pw.ui->lblSummary->setStyleSheet("color: #78CAD2");
    pw.ui->lblLocations->setStyleSheet("color: #78CAD2");
    pw.ui->lblKeywords->setStyleSheet("color: #78CAD2");

    updateCrewLocations();

}

void controller::handleApplyGeneralChanges(){

    bool apply = true;

    // Gets data from the form
    std::string projTitle = pw.ui->txtTitleProject->text().toStdString();
    std::string summary = pw.ui->txtSummary->toPlainText().toStdString();
    std::string status = pw.ui->cbStatus->currentText().toStdString();
    std::string genre = pw.ui->cbGenre->currentText().toStdString();
    std::string language = pw.ui->cbLanguage->currentText().toStdString();
    std::string date = pw.ui->deRelease->date().toString(Qt::DefaultLocaleShortDate).toStdString();
    int runtime = pw.ui->sbRuntime->value();
    int sales = pw.ui->sbSales->value();

    std::vector<std::string> locations;
    for(int i = 0; i < pw.ui->lstLocations->count(); ++i){
        locations.push_back(pw.ui->lstLocations->item(i)->text().toStdString());
    }

    std::vector<std::string> keywords;
    for(int i = 0; i < pw.ui->lstKeywords->count(); ++i){
        keywords.push_back(pw.ui->lstKeywords->item(i)->text().toStdString());
    }

    // Checks data has been inputted and flags red if it has not
    if(projTitle == ""){
        pw.ui->lblTitleProjects->setStyleSheet("color: #D81E5B");
        apply = false;
    }else{
        pw.ui->lblTitleProjects->setStyleSheet("color: #78CAD2");
    }

    if(summary == ""){
        pw.ui->lblSummary->setStyleSheet("color: #D81E5B");
        apply = false;
    }else{
        pw.ui->lblSummary->setStyleSheet("color: #78CAD2");
    }

    if(locations.size() == 0){
        pw.ui->lblLocations->setStyleSheet("color: #D81E5B");
        apply = false;
    }else{
        pw.ui->lblLocations->setStyleSheet("color: #78CAD2");
    }

    if(keywords.size() == 0){
        pw.ui->lblKeywords->setStyleSheet("color: #D81E5B");
        apply = false;
    }else{
        pw.ui->lblKeywords->setStyleSheet("color: #78CAD2");
    }

    // If all fields have correctly inputted data a new project is created
    if(apply){

        openProj->setTitle(projTitle);
        openProj->setSummary(summary);
        openProj->setProjectStatus(status);
        openProj->setGenre(genre);
        openProj->setLanguage(language);
        openProj->setReleaseDate(date);
        openProj->setRunTime(runtime);
        openProj->setWeeklyBoxFigures(sales);
        openProj->setFilmLocations(locations);
        openProj->setKeywords(keywords);

        setProjectWindow();
        showAllProjects();

     }

}

void controller::handleProjectWindowLocationAdd(){

    QString input = pw.ui->txtLocationAdd->text();
    if(input.toStdString() != ""){
        pw.ui->lstLocations->addItem(input);
    }
    pw.ui->txtLocationAdd->clear();

}

void controller::handleProjectWindowLocationDel(){

    QList <QListWidgetItem *> selectedItems = pw.ui->lstLocations->selectedItems();
    for(int i = 0; i < selectedItems.size(); i++){
        delete pw.ui->lstLocations->takeItem(pw.ui->lstLocations->row(selectedItems[i]));
    }

}

void controller::handleProjectWindowKeywordsAdd(){

    QString input = pw.ui->txtKeywordsAdd->text();
    if(input.toStdString() != ""){
        pw.ui->lstKeywords->addItem(input);
    }
    pw.ui->txtKeywordsAdd->clear();

}

void controller::handleProjectWindowKeywordsDel(){

    QList <QListWidgetItem *> selectedItems = pw.ui->lstKeywords->selectedItems();
    for(int i = 0; i < selectedItems.size(); i++){
        delete pw.ui->lstKeywords->takeItem(pw.ui->lstKeywords->row(selectedItems[i]));
    }

}

void controller::handleProjectWindowStatusChange(){

    std::string status = pw.ui->cbStatus->currentText().toStdString();

    if(status == "Unreleased" || status == "Released"){
        pw.ui->lblSales->setStyleSheet("color: #7C8483");
        pw.ui->sbSales->setReadOnly(true);
        pw.ui->sbSales->setVisible(false);
        if(status == "Unreleased"){
            pw.ui->tabWidget->setTabEnabled(2, false);
        }
        else{
            pw.ui->tabWidget->setTabEnabled(2, true);
        }
    }
    else if (status == "Now Playing"){
        pw.ui->lblSales->setStyleSheet("color: #78CAD2");
        pw.ui->sbSales->setReadOnly(false);
        pw.ui->sbSales->setVisible(true);
        pw.ui->tabWidget->setTabEnabled(2, false);
    }

}

void controller::displayCrew(){

    pw.ui->lstCrew->clear();
    std::vector <CrewMember> crew = openProj->getCrew();

    for(unsigned int i = 0; i < crew.size(); ++i){

        std::string locationString = "";

        for(unsigned int j = 0; j < crew[i].getLocationsWorkedAt().size(); ++j){

            locationString += crew[i].getLocationsWorkedAt()[j];
            if(j != crew[i].getLocationsWorkedAt().size() - 1){
                locationString += ", ";
            }

        }

        pw.ui->lstCrew->addItem(QString::fromStdString(\
               crew[i].getTitle() + " " + crew[i].getName() + ": \n ID: " + crew[i].getIdNumber() \
               + "\n Born: " + crew[i].getDateOfBirth() + "\n Role: " + crew[i].getRole() + "\n Experience: " \
               + std::to_string(crew[i].getYearsOfExperience()) + " years"\
               + "\n Locations: " + locationString));
    }

}

void controller::updateCrewLocations(){

    pw.ui->lstCrewLocations->clear();
    for(unsigned int i = 0; i < openProj->getFilmLocations().size(); ++i){
        pw.ui->lstCrewLocations->addItem(QString::fromStdString(openProj->getFilmLocations()[i]));
    }

}

void controller::handleProjectWindowCrewChange(){

    std::string selection = pw.ui->cbCrew->currentText().toStdString();

    if(selection == "All Crew Members"){
        pw.ui->lblNameTitle->setVisible(false);
        pw.ui->cbNameTitle->setDisabled(true);
        pw.ui->cbNameTitle->setVisible(false);
        pw.ui->lblName->setVisible(false);
        pw.ui->txtName->setDisabled(true);
        pw.ui->txtName->setVisible(false);
        pw.ui->lblIDNum->setVisible(false);
        pw.ui->txtIDNum->setVisible(false);
        pw.ui->txtIDNum->setDisabled(true);
        pw.ui->cbNameTitle->setVisible(false);
        pw.ui->lblDateOfBirth->setVisible(false);
        pw.ui->deDofB->setVisible(false);
        pw.ui->deDofB->setDisabled(true);
        pw.ui->lblExperience->setVisible(false);
        pw.ui->sbExperience->setDisabled(true);
        pw.ui->sbExperience->setVisible(false);
        pw.ui->cmdCrewAdd->setDisabled(true);
        pw.ui->cmdCrewAdd->setVisible(false);
        pw.ui->lblCrewLocations->setVisible(false);
        pw.ui->lstCrewLocations->setDisabled(true);
        pw.ui->lstCrewLocations->setVisible(false);

        displayCrew();
    }else{
        pw.ui->lblNameTitle->setVisible(true);
        pw.ui->cbNameTitle->setDisabled(false);
        pw.ui->cbNameTitle->setVisible(true);
        pw.ui->lblName->setVisible(true);
        pw.ui->txtName->setDisabled(false);
        pw.ui->txtName->setVisible(true);
        pw.ui->lblIDNum->setVisible(true);
        pw.ui->txtIDNum->setVisible(true);
        pw.ui->txtIDNum->setDisabled(false);
        pw.ui->cbNameTitle->setVisible(true);
        pw.ui->lblDateOfBirth->setVisible(true);
        pw.ui->deDofB->setVisible(true);
        pw.ui->deDofB->setDisabled(false);
        pw.ui->lblExperience->setVisible(true);
        pw.ui->sbExperience->setDisabled(false);
        pw.ui->sbExperience->setVisible(true);
        pw.ui->cmdCrewAdd->setDisabled(false);
        pw.ui->cmdCrewAdd->setVisible(true);
        pw.ui->lblCrewLocations->setVisible(true);
        pw.ui->lstCrewLocations->setDisabled(false);
        pw.ui->lstCrewLocations->setVisible(true);

        if(selection == "Director"){
            filterCrewByRole("Director");
        }
        else if(selection == "Actor"){
            filterCrewByRole("Actor");
        }
        else if(selection == "Producer"){
            filterCrewByRole("Producer");
        }
        else if(selection == "Writer"){
            filterCrewByRole("Writer");
        }
        else if(selection == "Editor"){
            filterCrewByRole("Editor");
        }
        else if(selection == "Production Designer"){
            filterCrewByRole("Production Designer");
        }
        else if(selection == "Set Decorator"){
            filterCrewByRole("Set Decorator");
        }
        else if(selection == "Costume Designer"){
            filterCrewByRole("Costume Designer");
        }

    }

}

void controller::handleProjectWindowCrewAdd(){

    bool addCrew = true;

    std::string name = pw.ui->txtName->text().toStdString();
    std::string title = pw.ui->cbNameTitle->currentText().toStdString();
    std::string DofB = pw.ui->deDofB->date().toString(Qt::DefaultLocaleShortDate).toStdString();
    std::string ID = pw.ui->txtIDNum->text().toStdString();
    std::string role = pw.ui->cbCrew->currentText().toStdString();
    int experience = pw.ui->sbExperience->value();

    QList <QListWidgetItem *> selectedItems = pw.ui->lstCrewLocations->selectedItems();
    std::vector <std::string> loc;

    for(int i = 0; i < selectedItems.size(); ++i){
        loc.push_back(selectedItems[i]->text().toStdString());
    }

    if(name == ""){
        pw.ui->lblName->setStyleSheet("color: #D81E5B");
        addCrew = false;
    }else{
        pw.ui->lblName->setStyleSheet("color: #78CAD2");
    }

    if(ID == ""){
        pw.ui->lblIDNum->setStyleSheet("color: #D81E5B");
        addCrew = false;
    }else{
        pw.ui->lblIDNum->setStyleSheet("color: #78CAD2");
    }

    if(loc.size() == 0){
        pw.ui->lblCrewLocations->setStyleSheet("color: #D81E5B");
        addCrew = false;
    }else{
        pw.ui->lblIDNum->setStyleSheet("color: #78CAD2");
    }

    if(addCrew){

        std::string locationString = "";
        for(unsigned int j = 0; j < loc.size(); ++j){
            locationString += loc[j];
            if(j != loc.size() - 1){
                locationString += ", ";
            }
        }
        pw.ui->lstCrew->addItem(QString::fromStdString(\
               title + " " + name + ": \n ID: " + ID + "\n Born: " + DofB + "\n Role: "\
               + role + "\n Experience: " + std::to_string(experience) + " years" \
               + "\n Locations: " + locationString));

        CrewMember newC;

        newC.setName(name);
        newC.setTitle(title);
        newC.setIdNumber(ID);
        newC.setDateOfBirth(DofB);
        newC.setRole(role);
        newC.setYearsOfExperience(experience);
        newC.setLocationsWorkedAt(loc);

        std::vector <CrewMember> newCrew = openProj->getCrew();
        newCrew.push_back(newC);
        openProj->setCrew(newCrew);
        openProj->setCrewID(projList.getNewCrewId());

        pw.ui->txtName->clear();
        pw.ui->cbNameTitle->setCurrentIndex(0);
        pw.ui->deDofB->setDate(QDate(2000, 1, 1));
        pw.ui->txtIDNum->clear();
        pw.ui->sbExperience->setValue(0);
    }

}

void controller::handleProjectWindowCrewDel(){

    QList <QListWidgetItem *> selectedItems = pw.ui->lstCrew->selectedItems();

    for(int i = 0; i < selectedItems.size(); i++){

        std::string text = selectedItems[i]->text().toStdString();

        std::string title = text.substr(0, text.find_first_of(" "));
        std::string name = text.substr((text.find_first_of(" ") + 1), \
                                       (text.find_first_of(":") - (text.find_first_of(" ") + 1)));
        std::string id = text.substr((text.find("ID:") + 4), (text.find("\n Born:") - (text.find("ID:") + 4)));

        std::vector <CrewMember> crew = openProj->getCrew();

        for(unsigned int i = 0; i < crew.size(); ++i){
            if(crew[i].getTitle() == title && crew[i].getName() == name && crew[i].getIdNumber() == id){
                crew.erase(crew.begin() + i);
            }
        }

        openProj->setCrew(crew);
        delete pw.ui->lstCrew->takeItem(pw.ui->lstCrew->row(selectedItems[i]));
    }

}

void controller::handleProjectWindowCrewFilter(){

    std::string role = pw.ui->cbCrew->currentText().toStdString();
    std::string input = pw.ui->txtCrew->text().toStdString();

    pw.ui->lstCrew->clear();

    std::vector <CrewMember> crew = openProj->getCrew();

    for(unsigned int i = 0; i < crew.size(); ++i){
        if((crew[i].getRole() == role || role == "All Crew Members") && crew[i].getName() == input){

            std::string locationString = "";

            for(unsigned int j = 0; j < crew[i].getLocationsWorkedAt().size(); ++j){

                locationString += crew[i].getLocationsWorkedAt()[j];
                if(j != crew[i].getLocationsWorkedAt().size() - 1){
                    locationString += ", ";
                }

            }

            pw.ui->lstCrew->addItem(QString::fromStdString(\
                   crew[i].getTitle() + " " + crew[i].getName() + ": \n ID: " + crew[i].getIdNumber() \
                   + "\n Born: " + crew[i].getDateOfBirth() + "\n Role: " + crew[i].getRole() + "\n Experience: " \
                   + std::to_string(crew[i].getYearsOfExperience()) + " years"\
                   + "\n Locations: " + locationString));

        }
    }

}

void controller::filterCrewByRole(std::string role){

    pw.ui->lstCrew->clear();

    std::vector <CrewMember> crew = openProj->getCrew();

    for(unsigned int i = 0; i < crew.size(); ++i){
        if(crew[i].getRole() == role){

            std::string locationString = "";

            for(unsigned int j = 0; j < crew[i].getLocationsWorkedAt().size(); ++j){

                locationString += crew[i].getLocationsWorkedAt()[j];
                if(j != crew[i].getLocationsWorkedAt().size() - 1){
                    locationString += ", ";
                }

            }

            pw.ui->lstCrew->addItem(QString::fromStdString(\
                   crew[i].getTitle() + " " + crew[i].getName() + ": \n ID: " + crew[i].getIdNumber() \
                   + "\n Born: " + crew[i].getDateOfBirth() + "\n Role: " + crew[i].getRole() + "\n Experience: " \
                   + std::to_string(crew[i].getYearsOfExperience()) + " years"\
                   + "\n Locations: " + locationString));

        }
    }

}
