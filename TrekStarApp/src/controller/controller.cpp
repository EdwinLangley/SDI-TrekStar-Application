#include "controller.h"
#include "gui.h"
#include "ui_mainwindow.h"
#include "ui_projectwindow.h"
#include "project.h"
#include "doublylinkedlist.h"

#include <QInputDialog>


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

    // Sets all options for the materials type combo box on the project window
    pw.ui->cbMaterialType->addItem("DVD Single Sided");
    pw.ui->cbMaterialType->addItem("DVD Double Sided");
    pw.ui->cbMaterialType->addItem("Blu Ray");
    pw.ui->cbMaterialType->addItem("VHS");
    pw.ui->cbMaterialType->addItem("Combo Box");

    // Sets all options for the video format combo box on the project window
    pw.ui->cbVFormat->addItem("mp4");
    pw.ui->cbVFormat->addItem("flv");
    pw.ui->cbVFormat->addItem("avi");
    pw.ui->cbVFormat->addItem("mov");
    pw.ui->cbVFormat->addItem("wmv");
    pw.ui->cbVFormat->addItem("other");

    // Sets all options for the audio format combo box on the project window
    pw.ui->cbAFormat->addItem("Dolby");
    pw.ui->cbAFormat->addItem("Dolby digital");
    pw.ui->cbAFormat->addItem("MPEG-1");
    pw.ui->cbAFormat->addItem("PCM");
    pw.ui->cbAFormat->addItem("DTS");

    // Sets all options for the materials language combo box on the project window
    pw.ui->cbMaterialLanguage->addItem("English");
    pw.ui->cbMaterialLanguage->addItem("French");
    pw.ui->cbMaterialLanguage->addItem("German");
    pw.ui->cbMaterialLanguage->addItem("Spanish");
    pw.ui->cbMaterialLanguage->addItem("Mandarin");
    pw.ui->cbMaterialLanguage->addItem("Other");

    // Sets all options for the materials subtitle combo box on the project window
    pw.ui->cbSubLang->addItem("English");
    pw.ui->cbSubLang->addItem("French");
    pw.ui->cbSubLang->addItem("German");
    pw.ui->cbSubLang->addItem("Spanish");
    pw.ui->cbSubLang->addItem("Mandarin");
    pw.ui->cbSubLang->addItem("Other");

    // Sets all options for the materials extra language tracks combo box on the project window
    pw.ui->cbExtraLanguageTracks->addItem("English");
    pw.ui->cbExtraLanguageTracks->addItem("French");
    pw.ui->cbExtraLanguageTracks->addItem("German");
    pw.ui->cbExtraLanguageTracks->addItem("Spanish");
    pw.ui->cbExtraLanguageTracks->addItem("Mandarin");
    pw.ui->cbExtraLanguageTracks->addItem("Other");

    // Sets all options for the materials extra subtitle tracks combo box on the project window
    pw.ui->cbExtraSubtitleTracks->addItem("English");
    pw.ui->cbExtraSubtitleTracks->addItem("French");
    pw.ui->cbExtraSubtitleTracks->addItem("German");
    pw.ui->cbExtraSubtitleTracks->addItem("Spanish");
    pw.ui->cbExtraSubtitleTracks->addItem("Mandarin");
    pw.ui->cbExtraSubtitleTracks->addItem("Other");

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
    connect(mw.ui->cmdApplySettings, SIGNAL(clicked()), this, SLOT(handleSettingsApply()));

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
    connect(pw.ui->cbMaterialType, SIGNAL(currentIndexChanged(int)), this, SLOT(handleProjectWindowMaterialChange()));
    connect(pw.ui->cmdMaterialClear, SIGNAL(clicked()), this, SLOT(handleProjectWindowMaterialChange()));
    connect(pw.ui->cmdMaterialDel, SIGNAL(clicked()), this, SLOT(handleProjectWindowMaterialDelete()));
    connect(pw.ui->cmdMaterialCreate, SIGNAL(clicked()), this, SLOT(handleProjectWindowMaterialCreate()));
    connect(pw.ui->cmdSubLangAdd, SIGNAL(clicked()), this, SLOT(handleProjectWindowSubLangAdd()));
    connect(pw.ui->cmdSubLangDel, SIGNAL(clicked()), this, SLOT(handleProjectWindowSubLangDel()));
    connect(pw.ui->cmdExtraLanguageTracksAdd, SIGNAL(clicked()), this, SLOT(handleProjectWindowExtraLangAdd()));
    connect(pw.ui->cmdExtraLanguageTracksDel, SIGNAL(clicked()), this, SLOT(handleProjectWindowExtraLangDel()));
    connect(pw.ui->cmdExtraSubtitleTracksAdd, SIGNAL(clicked()), this, SLOT(handleProjectWindowExtraSubLangAdd()));
    connect(pw.ui->cmdExtraSubtitleTracksDel, SIGNAL(clicked()), this, SLOT(handleProjectWindowExtraSubLangDel()));
    connect(pw.ui->cmdBonusFeaturesAdd, SIGNAL(clicked()), this, SLOT(handleProjectWindowBonusAdd()));
    connect(pw.ui->cmdBonusFeaturesDel, SIGNAL(clicked()), this, SLOT(handleProjectWindowBonusDel()));
    connect(pw.ui->sbComboSingleDVD, SIGNAL(valueChanged(int)), this, SLOT(updateComboRuntime()));
    connect(pw.ui->sbComboDoubleDVD, SIGNAL(valueChanged(int)), this, SLOT(updateComboRuntime()));
    connect(pw.ui->sbComboSingleDVD, SIGNAL(valueChanged(int)), this, SLOT(updateMinimumPackage()));
    connect(pw.ui->sbComboDoubleDVD, SIGNAL(valueChanged(int)), this, SLOT(updateMinimumPackage()));

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
        handleProjectWindowMaterialChange();
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
            handleProjectWindowMaterialChange();
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
    }else if(openProj->getProjectStatus() == "Released"){
        pw.ui->cbStatus->setCurrentIndex(2);
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

void controller::handleProjectWindowMaterialChange(){

    pw.ui->sbPackagingHeight->setMinimum(0);
    pw.ui->sbPackagingWidth->setMinimum(0);
    pw.ui->sbPackagingDepth->setMinimum(0);

    pw.ui->txtMaterialTitle->clear();
    pw.ui->txtMaterialIDNum->clear();
    pw.ui->cbVFormat->setCurrentIndex(0);
    pw.ui->cbAFormat->setCurrentIndex(0);
    pw.ui->cbMaterialLanguage->setCurrentIndex(0);
    pw.ui->sbMaterialRuntime->setValue(0);
    pw.ui->sbMaterialPrice->setValue(0);
    pw.ui->lstSubLang->clear();
    pw.ui->txtFirstSideContent->clear();
    pw.ui->txtSecondSideContent->clear();
    pw.ui->sbFrameHorizontal->setValue(0);
    pw.ui->sbFrameVertical->setValue(0);
    pw.ui->txtFrameDescription->clear();
    pw.ui->cbPackagingMaterial->clear();
    pw.ui->sbPackagingHeight->setValue(0);
    pw.ui->sbPackagingWidth->setValue(0);
    pw.ui->sbPackagingDepth->setValue(0);
    pw.ui->lstBonusFeatures->clear();
    pw.ui->lstExtraLanguageTracks->clear();
    pw.ui->lstExtraSubtitleTracks->clear();
    pw.ui->sbComboSingleDVD->setValue(0);
    pw.ui->sbComboDoubleDVD->setValue(0);

    pw.ui->sbMaterialRuntime->setDisabled(false);

    pw.ui->lblVFormat->setVisible(true);
    pw.ui->cbVFormat->setDisabled(false);
    pw.ui->cbVFormat->setVisible(true);

    pw.ui->lblAFormat->setVisible(true);
    pw.ui->cbAFormat->setDisabled(false);
    pw.ui->cbAFormat->setVisible(true);

    pw.ui->lblMaterialLanguage->setVisible(true);
    pw.ui->cbMaterialLanguage->setDisabled(false);
    pw.ui->cbMaterialLanguage->setVisible(true);

    pw.ui->lblMaterialRuntime->setDisabled(false);

    pw.ui->lblMaterialSubLang->setVisible(true);
    pw.ui->cbSubLang->setDisabled(false);
    pw.ui->cbSubLang->setVisible(true);
    pw.ui->cmdSubLangAdd->setDisabled(false);
    pw.ui->cmdSubLangAdd->setVisible(true);
    pw.ui->cmdSubLangDel->setDisabled(false);
    pw.ui->cmdSubLangDel->setVisible(true);
    pw.ui->lstSubLang->setVisible(true);

    pw.ui->lblMaterialFrameAspect->setVisible(true);
    pw.ui->lblMaterialFrameDescription->setVisible(true);
    pw.ui->txtFrameDescription->setDisabled(false);
    pw.ui->txtFrameDescription->setVisible(true);
    pw.ui->lblMaterialFrameHorizontal->setVisible(true);
    pw.ui->sbFrameHorizontal->setDisabled(false);
    pw.ui->sbFrameHorizontal->setVisible(true);
    pw.ui->lblMaterialFrameVertical->setVisible(true);
    pw.ui->sbFrameVertical->setDisabled(false);
    pw.ui->sbFrameVertical->setVisible(true);

    pw.ui->lblComboSingleDVD->setVisible(false);
    pw.ui->sbComboSingleDVD->setDisabled(true);
    pw.ui->sbComboSingleDVD->setVisible(false);

    pw.ui->lblComboDoubleDVD->setVisible(false);
    pw.ui->sbComboDoubleDVD->setDisabled(true);
    pw.ui->sbComboDoubleDVD->setVisible(false);

    pw.ui->cbPackagingMaterial->addItem("Plastic");

    pw.ui->lblMaterialAnswer->setText("Not Created");
    pw.ui->lblMaterialAnswer->setStyleSheet("color: #D81E5B");
    pw.ui->cmdMaterialDel->setVisible(false);
    pw.ui->cmdMaterialClear->setText("Clear");
    pw.ui->cmdMaterialCreate->setText("Create");

    std::string material = pw.ui->cbMaterialType->currentText().toStdString();

    if(material == "DVD Single Sided"){

        if(openProj->getSingleDVD().getTitle() != ""){

            pw.ui->lblMaterialAnswer->setText("Created");
            pw.ui->lblMaterialAnswer->setStyleSheet("color: #78CAD2");
            pw.ui->cmdMaterialDel->setVisible(true);
            pw.ui->cmdMaterialClear->setText("Clear Changes");
            pw.ui->cmdMaterialCreate->setText("Apply Changes");

            pw.ui->txtMaterialTitle->setText(QString::fromStdString(openProj->getSingleDVD().getTitle()));
            pw.ui->txtMaterialIDNum->setText(QString::fromStdString(openProj->getSingleDVD().getIdNumber()));
            pw.ui->sbMaterialRuntime->setValue(openProj->getSingleDVD().getRunTime());
            pw.ui->sbMaterialPrice->setValue(openProj->getSingleDVD().getPrice());

            if(openProj->getSingleDVD().getVFormat() == "mp4"){
                pw.ui->cbVFormat->setCurrentIndex(0);
            }
            else if(openProj->getSingleDVD().getVFormat() == "flv"){
                pw.ui->cbVFormat->setCurrentIndex(1);
            }
            else if(openProj->getSingleDVD().getVFormat() == "avi"){
                pw.ui->cbVFormat->setCurrentIndex(2);
            }
            else if(openProj->getSingleDVD().getVFormat() == "mov"){
                pw.ui->cbVFormat->setCurrentIndex(3);
            }
            else if(openProj->getSingleDVD().getVFormat() == "wmv"){
                pw.ui->cbVFormat->setCurrentIndex(4);
            }
            else if(openProj->getSingleDVD().getVFormat() == "other"){
                pw.ui->cbVFormat->setCurrentIndex(5);
            }

            if(openProj->getSingleDVD().getAFormat() == "Dolby"){
                pw.ui->cbAFormat->setCurrentIndex(0);
            }
            else if(openProj->getSingleDVD().getAFormat() == "Dolby digital"){
                pw.ui->cbAFormat->setCurrentIndex(1);
            }
            else if(openProj->getSingleDVD().getAFormat() == "MPEG-1"){
                pw.ui->cbAFormat->setCurrentIndex(2);
            }
            else if(openProj->getSingleDVD().getAFormat() == "PCM"){
                pw.ui->cbAFormat->setCurrentIndex(3);
            }
            else if(openProj->getSingleDVD().getAFormat() == "DTS"){
                pw.ui->cbAFormat->setCurrentIndex(4);
            }

            if(openProj->getSingleDVD().getLanguage() == "English"){
                pw.ui->cbMaterialLanguage->setCurrentIndex(0);
            }
            else if(openProj->getSingleDVD().getLanguage() == "French"){
                pw.ui->cbMaterialLanguage->setCurrentIndex(1);
            }
            else if(openProj->getSingleDVD().getLanguage() == "German"){
                pw.ui->cbMaterialLanguage->setCurrentIndex(2);
            }
            else if(openProj->getSingleDVD().getLanguage() == "Spanish"){
                pw.ui->cbMaterialLanguage->setCurrentIndex(3);
            }
            else if(openProj->getSingleDVD().getLanguage() == "Mandarin"){
                pw.ui->cbMaterialLanguage->setCurrentIndex(4);
            }
            else if(openProj->getSingleDVD().getLanguage() == "Other"){
                pw.ui->cbMaterialLanguage->setCurrentIndex(5);
            }

            pw.ui->sbFrameHorizontal->setValue(openProj->getSingleDVD().getFrame().getHorizontalRatio());
            pw.ui->sbFrameVertical->setValue(openProj->getSingleDVD().getFrame().getVerticalRatio());
            pw.ui->txtFrameDescription->setText(QString::fromStdString(openProj->getSingleDVD().getFrame().getRatioDescription()));

            pw.ui->cbPackagingMaterial->setCurrentIndex(0);
            pw.ui->sbPackagingHeight->setValue(openProj->getSingleDVD().getPackage().getHeight());
            pw.ui->sbPackagingWidth->setValue(openProj->getSingleDVD().getPackage().getWidth());
            pw.ui->sbPackagingDepth->setValue(openProj->getSingleDVD().getPackage().getDepth());

            pw.ui->txtFirstSideContent->setText(QString::fromStdString(openProj->getSingleDVD().getFirstSideContent()));

            for(unsigned int i = 0; i < openProj->getSingleDVD().getSubTitleLanguages().size(); ++i){
                pw.ui->lstSubLang->addItem(QString::fromStdString(openProj->getSingleDVD().getSubTitleLanguages()[i]));
            }

            for(unsigned int j = 0; j < openProj->getSingleDVD().getExtraLanguageTracks().size(); ++j){
                pw.ui->lstExtraLanguageTracks->addItem(QString::fromStdString(openProj->getSingleDVD().getExtraLanguageTracks()[j]));
            }

            for(unsigned int k = 0; k < openProj->getSingleDVD().getExtraSubtitleTracks().size(); ++k){
                pw.ui->lstExtraSubtitleTracks->addItem(QString::fromStdString(openProj->getSingleDVD().getExtraSubtitleTracks()[k]));
            }

            for(unsigned int l = 0; l < openProj->getSingleDVD().getBonusFeatures().size(); ++l){
                pw.ui->lstBonusFeatures->addItem(QString::fromStdString(openProj->getSingleDVD().getBonusFeatures()[l]));
            }

        }

        pw.ui->lblFirstSideContent->setVisible(true);
        pw.ui->txtFirstSideContent->setDisabled(false);
        pw.ui->txtFirstSideContent->setVisible(true);

        pw.ui->lblSecondSideContent->setVisible(false);
        pw.ui->txtSecondSideContent->setDisabled(true);
        pw.ui->txtSecondSideContent->setVisible(false);

        pw.ui->lblExtraLanguageTracks->setVisible(true);
        pw.ui->cbExtraLanguageTracks->setVisible(true);
        pw.ui->cmdExtraLanguageTracksAdd->setDisabled(false);
        pw.ui->cmdExtraLanguageTracksAdd->setVisible(true);
        pw.ui->cmdExtraLanguageTracksDel->setDisabled(false);
        pw.ui->cmdExtraLanguageTracksDel->setVisible(true);
        pw.ui->lstExtraLanguageTracks->setVisible(true);

        pw.ui->lblExtraSubtitleTracks->setVisible(true);
        pw.ui->cbExtraSubtitleTracks->setVisible(true);
        pw.ui->cmdExtraSubtitleTracksAdd->setDisabled(false);
        pw.ui->cmdExtraSubtitleTracksAdd->setVisible(true);
        pw.ui->cmdExtraSubtitleTracksDel->setDisabled(false);
        pw.ui->cmdExtraSubtitleTracksDel->setVisible(true);
        pw.ui->lstExtraSubtitleTracks->setVisible(true);

        pw.ui->lblBonusFeatures->setVisible(true);
        pw.ui->txtBonusFeatures->setVisible(true);
        pw.ui->cmdBonusFeaturesAdd->setDisabled(false);
        pw.ui->cmdBonusFeaturesAdd->setVisible(true);
        pw.ui->cmdBonusFeaturesDel->setDisabled(false);
        pw.ui->cmdBonusFeaturesDel->setVisible(true);
        pw.ui->lstBonusFeatures->setVisible(true);

    }
    else if(material == "DVD Double Sided"){

        if(openProj->getTwoDVD().getTitle() != ""){

            pw.ui->lblMaterialAnswer->setText("Created");
            pw.ui->lblMaterialAnswer->setStyleSheet("color: #78CAD2");
            pw.ui->cmdMaterialDel->setVisible(true);
            pw.ui->cmdMaterialClear->setText("Clear Changes");
            pw.ui->cmdMaterialCreate->setText("Apply Changes");

            pw.ui->txtMaterialTitle->setText(QString::fromStdString(openProj->getTwoDVD().getTitle()));
            pw.ui->txtMaterialIDNum->setText(QString::fromStdString(openProj->getTwoDVD().getIdNumber()));
            pw.ui->sbMaterialRuntime->setValue(openProj->getTwoDVD().getRunTime());
            pw.ui->sbMaterialPrice->setValue(openProj->getTwoDVD().getPrice());

            if(openProj->getTwoDVD().getVFormat() == "mp4"){
                pw.ui->cbVFormat->setCurrentIndex(0);
            }
            else if(openProj->getTwoDVD().getVFormat() == "flv"){
                pw.ui->cbVFormat->setCurrentIndex(1);
            }
            else if(openProj->getTwoDVD().getVFormat() == "avi"){
                pw.ui->cbVFormat->setCurrentIndex(2);
            }
            else if(openProj->getTwoDVD().getVFormat() == "mov"){
                pw.ui->cbVFormat->setCurrentIndex(3);
            }
            else if(openProj->getTwoDVD().getVFormat() == "wmv"){
                pw.ui->cbVFormat->setCurrentIndex(4);
            }
            else if(openProj->getTwoDVD().getVFormat() == "other"){
                pw.ui->cbVFormat->setCurrentIndex(5);
            }

            if(openProj->getTwoDVD().getAFormat() == "Dolby"){
                pw.ui->cbAFormat->setCurrentIndex(0);
            }
            else if(openProj->getTwoDVD().getAFormat() == "Dolby digital"){
                pw.ui->cbAFormat->setCurrentIndex(1);
            }
            else if(openProj->getTwoDVD().getAFormat() == "MPEG-1"){
                pw.ui->cbAFormat->setCurrentIndex(2);
            }
            else if(openProj->getTwoDVD().getAFormat() == "PCM"){
                pw.ui->cbAFormat->setCurrentIndex(3);
            }
            else if(openProj->getTwoDVD().getAFormat() == "DTS"){
                pw.ui->cbAFormat->setCurrentIndex(4);
            }

            if(openProj->getTwoDVD().getLanguage() == "English"){
                pw.ui->cbMaterialLanguage->setCurrentIndex(0);
            }
            else if(openProj->getTwoDVD().getLanguage() == "French"){
                pw.ui->cbMaterialLanguage->setCurrentIndex(1);
            }
            else if(openProj->getTwoDVD().getLanguage() == "German"){
                pw.ui->cbMaterialLanguage->setCurrentIndex(2);
            }
            else if(openProj->getTwoDVD().getLanguage() == "Spanish"){
                pw.ui->cbMaterialLanguage->setCurrentIndex(3);
            }
            else if(openProj->getTwoDVD().getLanguage() == "Mandarin"){
                pw.ui->cbMaterialLanguage->setCurrentIndex(4);
            }
            else if(openProj->getTwoDVD().getLanguage() == "Other"){
                pw.ui->cbMaterialLanguage->setCurrentIndex(5);
            }

            pw.ui->sbFrameHorizontal->setValue(openProj->getTwoDVD().getFrame().getHorizontalRatio());
            pw.ui->sbFrameVertical->setValue(openProj->getTwoDVD().getFrame().getVerticalRatio());
            pw.ui->txtFrameDescription->setText(QString::fromStdString(openProj->getTwoDVD().getFrame().getRatioDescription()));

            pw.ui->cbPackagingMaterial->setCurrentIndex(0);
            pw.ui->sbPackagingHeight->setValue(openProj->getTwoDVD().getPackage().getHeight());
            pw.ui->sbPackagingWidth->setValue(openProj->getTwoDVD().getPackage().getWidth());
            pw.ui->sbPackagingDepth->setValue(openProj->getTwoDVD().getPackage().getDepth());

            pw.ui->txtFirstSideContent->setText(QString::fromStdString(openProj->getTwoDVD().getFirstSideContent()));
            pw.ui->txtSecondSideContent->setText(QString::fromStdString(openProj->getTwoDVD().getSecondSideContent()));


            for(unsigned int i = 0; i < openProj->getTwoDVD().getSubTitleLanguages().size(); ++i){
                pw.ui->lstSubLang->addItem(QString::fromStdString(openProj->getTwoDVD().getSubTitleLanguages()[i]));
            }

            for(unsigned int j = 0; j < openProj->getTwoDVD().getExtraLanguageTracks().size(); ++j){
                pw.ui->lstExtraLanguageTracks->addItem(QString::fromStdString(openProj->getTwoDVD().getExtraLanguageTracks()[j]));
            }

            for(unsigned int k = 0; k < openProj->getTwoDVD().getExtraSubtitleTracks().size(); ++k){
                pw.ui->lstExtraSubtitleTracks->addItem(QString::fromStdString(openProj->getTwoDVD().getExtraSubtitleTracks()[k]));
            }

            for(unsigned int l = 0; l < openProj->getTwoDVD().getBonusFeatures().size(); ++l){
                pw.ui->lstBonusFeatures->addItem(QString::fromStdString(openProj->getTwoDVD().getBonusFeatures()[l]));
            }

        }

        pw.ui->lblFirstSideContent->setVisible(true);
        pw.ui->txtFirstSideContent->setDisabled(false);
        pw.ui->txtFirstSideContent->setVisible(true);

        pw.ui->lblSecondSideContent->setVisible(true);
        pw.ui->txtSecondSideContent->setDisabled(false);
        pw.ui->txtSecondSideContent->setVisible(true);

        pw.ui->lblExtraLanguageTracks->setVisible(true);
        pw.ui->cbExtraLanguageTracks->setVisible(true);
        pw.ui->cmdExtraLanguageTracksAdd->setDisabled(false);
        pw.ui->cmdExtraLanguageTracksAdd->setVisible(true);
        pw.ui->cmdExtraLanguageTracksDel->setDisabled(false);
        pw.ui->cmdExtraLanguageTracksDel->setVisible(true);
        pw.ui->lstExtraLanguageTracks->setVisible(true);

        pw.ui->lblExtraSubtitleTracks->setVisible(true);
        pw.ui->cbExtraSubtitleTracks->setVisible(true);
        pw.ui->cmdExtraSubtitleTracksAdd->setDisabled(false);
        pw.ui->cmdExtraSubtitleTracksAdd->setVisible(true);
        pw.ui->cmdExtraSubtitleTracksDel->setDisabled(false);
        pw.ui->cmdExtraSubtitleTracksDel->setVisible(true);
        pw.ui->lstExtraSubtitleTracks->setVisible(true);

        pw.ui->lblBonusFeatures->setVisible(true);
        pw.ui->txtBonusFeatures->setVisible(true);
        pw.ui->cmdBonusFeaturesAdd->setDisabled(false);
        pw.ui->cmdBonusFeaturesAdd->setVisible(true);
        pw.ui->cmdBonusFeaturesDel->setDisabled(false);
        pw.ui->cmdBonusFeaturesDel->setVisible(true);
        pw.ui->lstBonusFeatures->setVisible(true);

    }
    else if(material == "Blu Ray"){

        if(openProj->getBluRay().getTitle() != ""){

            pw.ui->lblMaterialAnswer->setText("Created");
            pw.ui->lblMaterialAnswer->setStyleSheet("color: #78CAD2");
            pw.ui->cmdMaterialDel->setVisible(true);
            pw.ui->cmdMaterialClear->setText("Clear Changes");
            pw.ui->cmdMaterialCreate->setText("Apply Changes");

            pw.ui->txtMaterialTitle->setText(QString::fromStdString(openProj->getBluRay().getTitle()));
            pw.ui->txtMaterialIDNum->setText(QString::fromStdString(openProj->getBluRay().getIdNumber()));
            pw.ui->sbMaterialRuntime->setValue(openProj->getBluRay().getRunTime());
            pw.ui->sbMaterialPrice->setValue(openProj->getBluRay().getPrice());

            if(openProj->getBluRay().getVFormat() == "mp4"){
                pw.ui->cbVFormat->setCurrentIndex(0);
            }
            else if(openProj->getBluRay().getVFormat() == "flv"){
                pw.ui->cbVFormat->setCurrentIndex(1);
            }
            else if(openProj->getBluRay().getVFormat() == "avi"){
                pw.ui->cbVFormat->setCurrentIndex(2);
            }
            else if(openProj->getBluRay().getVFormat() == "mov"){
                pw.ui->cbVFormat->setCurrentIndex(3);
            }
            else if(openProj->getBluRay().getVFormat() == "wmv"){
                pw.ui->cbVFormat->setCurrentIndex(4);
            }
            else if(openProj->getBluRay().getVFormat() == "other"){
                pw.ui->cbVFormat->setCurrentIndex(5);
            }

            if(openProj->getBluRay().getAFormat() == "Dolby"){
                pw.ui->cbAFormat->setCurrentIndex(0);
            }
            else if(openProj->getBluRay().getAFormat() == "Dolby digital"){
                pw.ui->cbAFormat->setCurrentIndex(1);
            }
            else if(openProj->getBluRay().getAFormat() == "MPEG-1"){
                pw.ui->cbAFormat->setCurrentIndex(2);
            }
            else if(openProj->getBluRay().getAFormat() == "PCM"){
                pw.ui->cbAFormat->setCurrentIndex(3);
            }
            else if(openProj->getBluRay().getAFormat() == "DTS"){
                pw.ui->cbAFormat->setCurrentIndex(4);
            }

            if(openProj->getBluRay().getLanguage() == "English"){
                pw.ui->cbMaterialLanguage->setCurrentIndex(0);
            }
            else if(openProj->getBluRay().getLanguage() == "French"){
                pw.ui->cbMaterialLanguage->setCurrentIndex(1);
            }
            else if(openProj->getBluRay().getLanguage() == "German"){
                pw.ui->cbMaterialLanguage->setCurrentIndex(2);
            }
            else if(openProj->getBluRay().getLanguage() == "Spanish"){
                pw.ui->cbMaterialLanguage->setCurrentIndex(3);
            }
            else if(openProj->getBluRay().getLanguage() == "Mandarin"){
                pw.ui->cbMaterialLanguage->setCurrentIndex(4);
            }
            else if(openProj->getBluRay().getLanguage() == "Other"){
                pw.ui->cbMaterialLanguage->setCurrentIndex(5);
            }

            pw.ui->sbFrameHorizontal->setValue(openProj->getBluRay().getFrame().getHorizontalRatio());
            pw.ui->sbFrameVertical->setValue(openProj->getBluRay().getFrame().getVerticalRatio());
            pw.ui->txtFrameDescription->setText(QString::fromStdString(openProj->getBluRay().getFrame().getRatioDescription()));

            pw.ui->cbPackagingMaterial->setCurrentIndex(0);
            pw.ui->sbPackagingHeight->setValue(openProj->getBluRay().getPackage().getHeight());
            pw.ui->sbPackagingWidth->setValue(openProj->getBluRay().getPackage().getWidth());
            pw.ui->sbPackagingDepth->setValue(openProj->getBluRay().getPackage().getDepth());

            for(unsigned int i = 0; i < openProj->getBluRay().getSubTitleLanguages().size(); ++i){
                pw.ui->lstSubLang->addItem(QString::fromStdString(openProj->getBluRay().getSubTitleLanguages()[i]));
            }

            for(unsigned int j = 0; j < openProj->getBluRay().getExtraLanguageTracks().size(); ++j){
                pw.ui->lstExtraLanguageTracks->addItem(QString::fromStdString(openProj->getBluRay().getExtraLanguageTracks()[j]));
            }

            for(unsigned int k = 0; k < openProj->getBluRay().getExtraSubtitleTracks().size(); ++k){
                pw.ui->lstExtraSubtitleTracks->addItem(QString::fromStdString(openProj->getBluRay().getExtraSubtitleTracks()[k]));
            }

            for(unsigned int l = 0; l < openProj->getBluRay().getBonusTracks().size(); ++l){
                pw.ui->lstBonusFeatures->addItem(QString::fromStdString(openProj->getBluRay().getBonusTracks()[l]));
            }

        }

        pw.ui->lblFirstSideContent->setVisible(false);
        pw.ui->txtFirstSideContent->setDisabled(true);
        pw.ui->txtFirstSideContent->setVisible(false);

        pw.ui->lblSecondSideContent->setVisible(false);
        pw.ui->txtSecondSideContent->setDisabled(true);
        pw.ui->txtSecondSideContent->setVisible(false);

        pw.ui->lblExtraLanguageTracks->setVisible(true);
        pw.ui->cbExtraLanguageTracks->setVisible(true);
        pw.ui->cmdExtraLanguageTracksAdd->setDisabled(false);
        pw.ui->cmdExtraLanguageTracksAdd->setVisible(true);
        pw.ui->cmdExtraLanguageTracksDel->setDisabled(false);
        pw.ui->cmdExtraLanguageTracksDel->setVisible(true);
        pw.ui->lstExtraLanguageTracks->setVisible(true);

        pw.ui->lblExtraSubtitleTracks->setVisible(true);
        pw.ui->cbExtraSubtitleTracks->setVisible(true);
        pw.ui->cmdExtraSubtitleTracksAdd->setDisabled(false);
        pw.ui->cmdExtraSubtitleTracksAdd->setVisible(true);
        pw.ui->cmdExtraSubtitleTracksDel->setDisabled(false);
        pw.ui->cmdExtraSubtitleTracksDel->setVisible(true);
        pw.ui->lstExtraSubtitleTracks->setVisible(true);

        pw.ui->lblBonusFeatures->setVisible(true);
        pw.ui->txtBonusFeatures->setVisible(true);
        pw.ui->cmdBonusFeaturesAdd->setDisabled(false);
        pw.ui->cmdBonusFeaturesAdd->setVisible(true);
        pw.ui->cmdBonusFeaturesDel->setDisabled(false);
        pw.ui->cmdBonusFeaturesDel->setVisible(true);
        pw.ui->lstBonusFeatures->setVisible(true);

    }
    else if(material == "VHS"){

        pw.ui->cbPackagingMaterial->addItem("Cardboard");

        if(openProj->getVhs().getTitle() != ""){

            pw.ui->lblMaterialAnswer->setText("Created");
            pw.ui->lblMaterialAnswer->setStyleSheet("color: #78CAD2");
            pw.ui->cmdMaterialDel->setVisible(true);
            pw.ui->cmdMaterialClear->setText("Clear Changes");
            pw.ui->cmdMaterialCreate->setText("Apply Changes");

            pw.ui->txtMaterialTitle->setText(QString::fromStdString(openProj->getVhs().getTitle()));
            pw.ui->txtMaterialIDNum->setText(QString::fromStdString(openProj->getVhs().getIdNumber()));
            pw.ui->sbMaterialRuntime->setValue(openProj->getVhs().getRunTime());
            pw.ui->sbMaterialPrice->setValue(openProj->getVhs().getPrice());

            if(openProj->getVhs().getVFormat() == "mp4"){
                pw.ui->cbVFormat->setCurrentIndex(0);
            }
            else if(openProj->getVhs().getVFormat() == "flv"){
                pw.ui->cbVFormat->setCurrentIndex(1);
            }
            else if(openProj->getVhs().getVFormat() == "avi"){
                pw.ui->cbVFormat->setCurrentIndex(2);
            }
            else if(openProj->getVhs().getVFormat() == "mov"){
                pw.ui->cbVFormat->setCurrentIndex(3);
            }
            else if(openProj->getVhs().getVFormat() == "wmv"){
                pw.ui->cbVFormat->setCurrentIndex(4);
            }
            else if(openProj->getVhs().getVFormat() == "other"){
                pw.ui->cbVFormat->setCurrentIndex(5);
            }

            if(openProj->getVhs().getAFormat() == "Dolby"){
                pw.ui->cbAFormat->setCurrentIndex(0);
            }
            else if(openProj->getVhs().getAFormat() == "Dolby digital"){
                pw.ui->cbAFormat->setCurrentIndex(1);
            }
            else if(openProj->getVhs().getAFormat() == "MPEG-1"){
                pw.ui->cbAFormat->setCurrentIndex(2);
            }
            else if(openProj->getVhs().getAFormat() == "PCM"){
                pw.ui->cbAFormat->setCurrentIndex(3);
            }
            else if(openProj->getVhs().getAFormat() == "DTS"){
                pw.ui->cbAFormat->setCurrentIndex(4);
            }

            if(openProj->getVhs().getLanguage() == "English"){
                pw.ui->cbMaterialLanguage->setCurrentIndex(0);
            }
            else if(openProj->getVhs().getLanguage() == "French"){
                pw.ui->cbMaterialLanguage->setCurrentIndex(1);
            }
            else if(openProj->getVhs().getLanguage() == "German"){
                pw.ui->cbMaterialLanguage->setCurrentIndex(2);
            }
            else if(openProj->getVhs().getLanguage() == "Spanish"){
                pw.ui->cbMaterialLanguage->setCurrentIndex(3);
            }
            else if(openProj->getVhs().getLanguage() == "Mandarin"){
                pw.ui->cbMaterialLanguage->setCurrentIndex(4);
            }
            else if(openProj->getVhs().getLanguage() == "Other"){
                pw.ui->cbMaterialLanguage->setCurrentIndex(5);
            }

            pw.ui->sbFrameHorizontal->setValue(openProj->getVhs().getFrame().getHorizontalRatio());
            pw.ui->sbFrameVertical->setValue(openProj->getVhs().getFrame().getVerticalRatio());
            pw.ui->txtFrameDescription->setText(QString::fromStdString(openProj->getVhs().getFrame().getRatioDescription()));

            if(openProj->getVhs().getPackage().getMaterial() == "Plastic"){
                pw.ui->cbPackagingMaterial->setCurrentIndex(0);
            }else if(openProj->getVhs().getPackage().getMaterial() == "Cardboard"){
                pw.ui->cbPackagingMaterial->setCurrentIndex(1);
            }

            pw.ui->sbPackagingHeight->setValue(openProj->getVhs().getPackage().getHeight());
            pw.ui->sbPackagingWidth->setValue(openProj->getVhs().getPackage().getWidth());
            pw.ui->sbPackagingDepth->setValue(openProj->getVhs().getPackage().getDepth());

            for(unsigned int i = 0; i < openProj->getVhs().getSubTitleLanguages().size(); ++i){
                pw.ui->lstSubLang->addItem(QString::fromStdString(openProj->getVhs().getSubTitleLanguages()[i]));
            }

        }

        pw.ui->lblFirstSideContent->setVisible(false);
        pw.ui->txtFirstSideContent->setDisabled(true);
        pw.ui->txtFirstSideContent->setVisible(false);

        pw.ui->lblSecondSideContent->setVisible(false);
        pw.ui->txtSecondSideContent->setDisabled(true);
        pw.ui->txtSecondSideContent->setVisible(false);

        pw.ui->lblExtraLanguageTracks->setVisible(false);
        pw.ui->cbExtraLanguageTracks->setVisible(false);
        pw.ui->cmdExtraLanguageTracksAdd->setDisabled(true);
        pw.ui->cmdExtraLanguageTracksAdd->setVisible(false);
        pw.ui->cmdExtraLanguageTracksDel->setDisabled(true);
        pw.ui->cmdExtraLanguageTracksDel->setVisible(false);
        pw.ui->lstExtraLanguageTracks->setVisible(false);

        pw.ui->lblExtraSubtitleTracks->setVisible(false);
        pw.ui->cbExtraSubtitleTracks->setVisible(false);
        pw.ui->cmdExtraSubtitleTracksAdd->setDisabled(true);
        pw.ui->cmdExtraSubtitleTracksAdd->setVisible(false);
        pw.ui->cmdExtraSubtitleTracksDel->setDisabled(true);
        pw.ui->cmdExtraSubtitleTracksDel->setVisible(false);
        pw.ui->lstExtraSubtitleTracks->setVisible(false);

        pw.ui->lblBonusFeatures->setVisible(false);
        pw.ui->txtBonusFeatures->setVisible(false);
        pw.ui->cmdBonusFeaturesAdd->setDisabled(true);
        pw.ui->cmdBonusFeaturesAdd->setVisible(false);
        pw.ui->cmdBonusFeaturesDel->setDisabled(true);
        pw.ui->cmdBonusFeaturesDel->setVisible(false);
        pw.ui->lstBonusFeatures->setVisible(false);

    }
    else if(material == "Combo Box"){

        pw.ui->cbPackagingMaterial->clear();
        pw.ui->cbPackagingMaterial->addItem("Cardboard");

        pw.ui->sbMaterialRuntime->setDisabled(true);

        if(openProj->getComboBox().getTitle() != ""){

            pw.ui->lblMaterialAnswer->setText("Created");
            pw.ui->lblMaterialAnswer->setStyleSheet("color: #78CAD2");
            pw.ui->cmdMaterialDel->setVisible(true);
            pw.ui->cmdMaterialClear->setText("Clear Changes");
            pw.ui->cmdMaterialCreate->setText("Apply Changes");

            pw.ui->txtMaterialTitle->setText(QString::fromStdString(openProj->getComboBox().getTitle()));
            pw.ui->sbMaterialPrice->setValue(openProj->getComboBox().getPrice());
            pw.ui->sbComboSingleDVD->setValue(openProj->getComboBox().getNumberOfDVDs());
            //pw.ui->sbComboDoubleDVD->setValue(QString::fromStdString(openProj->getComboBox().get));
            pw.ui->sbPackagingHeight->setValue(openProj->getComboBox().getPackaging().getHeight());
            pw.ui->sbPackagingWidth->setValue(openProj->getComboBox().getPackaging().getWidth());
            pw.ui->sbPackagingDepth->setValue(openProj->getComboBox().getPackaging().getDepth());

            updateComboRuntime();

        }

        pw.ui->lblComboSingleDVD->setVisible(true);
        pw.ui->sbComboSingleDVD->setDisabled(false);
        pw.ui->sbComboSingleDVD->setVisible(true);

        pw.ui->lblComboDoubleDVD->setVisible(true);
        pw.ui->sbComboDoubleDVD->setDisabled(false);
        pw.ui->sbComboDoubleDVD->setVisible(true);

        pw.ui->lblVFormat->setVisible(false);
        pw.ui->cbVFormat->setDisabled(true);
        pw.ui->cbVFormat->setVisible(false);

        pw.ui->lblAFormat->setVisible(false);
        pw.ui->cbAFormat->setDisabled(true);
        pw.ui->cbAFormat->setVisible(false);

        pw.ui->lblMaterialLanguage->setVisible(false);
        pw.ui->cbMaterialLanguage->setDisabled(true);
        pw.ui->cbMaterialLanguage->setVisible(false);

        pw.ui->lblMaterialRuntime->setDisabled(true);

        pw.ui->lblMaterialSubLang->setVisible(false);
        pw.ui->cbSubLang->setDisabled(true);
        pw.ui->cbSubLang->setVisible(false);
        pw.ui->cmdSubLangAdd->setDisabled(true);
        pw.ui->cmdSubLangAdd->setVisible(false);
        pw.ui->cmdSubLangDel->setDisabled(true);
        pw.ui->cmdSubLangDel->setVisible(false);
        pw.ui->lstSubLang->setVisible(false);

        pw.ui->lblMaterialFrameAspect->setVisible(false);
        pw.ui->lblMaterialFrameDescription->setVisible(false);
        pw.ui->txtFrameDescription->setDisabled(true);
        pw.ui->txtFrameDescription->setVisible(false);
        pw.ui->lblMaterialFrameHorizontal->setVisible(false);
        pw.ui->sbFrameHorizontal->setDisabled(true);
        pw.ui->sbFrameHorizontal->setVisible(false);
        pw.ui->lblMaterialFrameVertical->setVisible(false);
        pw.ui->sbFrameVertical->setDisabled(true);
        pw.ui->sbFrameVertical->setVisible(false);

        pw.ui->lblFirstSideContent->setVisible(false);
        pw.ui->txtFirstSideContent->setDisabled(true);
        pw.ui->txtFirstSideContent->setVisible(false);

        pw.ui->lblSecondSideContent->setVisible(false);
        pw.ui->txtSecondSideContent->setDisabled(true);
        pw.ui->txtSecondSideContent->setVisible(false);

        pw.ui->lblExtraLanguageTracks->setVisible(false);
        pw.ui->cbExtraLanguageTracks->setVisible(false);
        pw.ui->cmdExtraLanguageTracksAdd->setDisabled(true);
        pw.ui->cmdExtraLanguageTracksAdd->setVisible(false);
        pw.ui->cmdExtraLanguageTracksDel->setDisabled(true);
        pw.ui->cmdExtraLanguageTracksDel->setVisible(false);
        pw.ui->lstExtraLanguageTracks->setVisible(false);

        pw.ui->lblExtraSubtitleTracks->setVisible(false);
        pw.ui->cbExtraSubtitleTracks->setVisible(false);
        pw.ui->cmdExtraSubtitleTracksAdd->setDisabled(true);
        pw.ui->cmdExtraSubtitleTracksAdd->setVisible(false);
        pw.ui->cmdExtraSubtitleTracksDel->setDisabled(true);
        pw.ui->cmdExtraSubtitleTracksDel->setVisible(false);
        pw.ui->lstExtraSubtitleTracks->setVisible(false);

        pw.ui->lblBonusFeatures->setVisible(false);
        pw.ui->txtBonusFeatures->setVisible(false);
        pw.ui->cmdBonusFeaturesAdd->setDisabled(true);
        pw.ui->cmdBonusFeaturesAdd->setVisible(false);
        pw.ui->cmdBonusFeaturesDel->setDisabled(true);
        pw.ui->cmdBonusFeaturesDel->setVisible(false);
        pw.ui->lstBonusFeatures->setVisible(false);

    }

    pw.ui->lblMaterialIDNum->setStyleSheet("color: #78CAD2");
    pw.ui->lblMaterialTitle->setStyleSheet("color: #78CAD2");
    pw.ui->lblBonusFeatures->setStyleSheet("color: #78CAD2");
    pw.ui->lblMaterialSubLang->setStyleSheet("color: #78CAD2");
    pw.ui->lblFirstSideContent->setStyleSheet("color: #78CAD2");
    pw.ui->lblSecondSideContent->setStyleSheet("color: #78CAD2");
    pw.ui->lblExtraLanguageTracks->setStyleSheet("color: #78CAD2");
    pw.ui->lblExtraSubtitleTracks->setStyleSheet("color: #78CAD2");
    pw.ui->lblBonusFeatures->setStyleSheet("color: #78CAD2");
    pw.ui->lblMaterialFrameAspect->setStyleSheet("color: #78CAD2");
    pw.ui->lblMaterialFrameDescription->setStyleSheet("color: #78CAD2");
    pw.ui->lblMaterialPackage->setStyleSheet("color: #78CAD2");
    pw.ui->lblMaterialPackageMaterial->setStyleSheet("color: #78CAD2");

}

void controller::handleProjectWindowMaterialDelete(){

    std::string material = pw.ui->cbMaterialType->currentText().toStdString();

    if(material == "DVD Single Sided"){
        openProj->setSingleDVD(SingleSidedDVD());
    }else if(material == "DVD Double Sided"){
        openProj->setTwoDVD(TwoSidedDVD());
    }else if(material == "Blu Ray"){
        openProj->setBluRay(BluRay());
    }else if(material == "VHS"){
        openProj->setVhs(VHS());
    }else if(material == "Combo Box"){
        openProj->setComboBox(ComboBox());
    }

    handleProjectWindowMaterialChange();
    handleCreateProject();
    handleFilter();

}

void controller::handleProjectWindowMaterialCreate(){

    bool submit = true;
    std::string materialType = pw.ui->cbMaterialType->currentText().toStdString();

    std::string firstSideContent;
    std::string secondSideContent;
    std::string vformat;
    std::string aformat;
    std::string language;
    int frameHorizontal;
    int frameVertical;
    int runtime;
    int comboNumberSingleDVD;
    int comboNumberDoubleDVD;
    std::string frameDesc;
    std::vector<std::string> subLang;
    std::vector<std::string> extraLanguageTracks;
    std::vector<std::string> extraSubtitleTracks;
    std::vector<std::string> bonusFeatures;   

    // Getting data from window
    std::string title = pw.ui->txtMaterialTitle->text().toStdString();
    std::string id = to_string(projList.getNewMaterialId());
    int price = pw.ui->sbMaterialPrice->value();
    std::string packagingMaterial = pw.ui->cbPackagingMaterial->currentText().toStdString();
    int packagingHeight = pw.ui->sbPackagingHeight->value();
    int packagingWidth = pw.ui->sbPackagingWidth->value();
    int packagingDepth = pw.ui->sbPackagingDepth->value();

    if(materialType != "Combo Box"){

        runtime = pw.ui->sbMaterialRuntime->value();
        vformat = pw.ui->cbVFormat->currentText().toStdString();
        aformat = pw.ui->cbAFormat->currentText().toStdString();
        language = pw.ui->cbMaterialLanguage->currentText().toStdString();
        frameHorizontal = pw.ui->sbFrameHorizontal->value();
        frameVertical = pw.ui->sbFrameVertical->value();
        frameDesc = pw.ui->txtFrameDescription->text().toStdString();

        for(int i = 0; i < pw.ui->lstSubLang->count(); ++i){
            subLang.push_back(pw.ui->lstSubLang->item(i)->text().toStdString());
        }

        if(materialType != "VHS"){

            for(int i = 0; i < pw.ui->lstExtraLanguageTracks->count(); ++i){
                extraLanguageTracks.push_back(pw.ui->lstExtraLanguageTracks->item(i)->text().toStdString());
            }

            for(int i = 0; i < pw.ui->lstExtraSubtitleTracks->count(); ++i){
                extraSubtitleTracks.push_back(pw.ui->lstExtraSubtitleTracks->item(i)->text().toStdString());
            }

            for(int i = 0; i < pw.ui->lstBonusFeatures->count(); ++i){
                bonusFeatures.push_back(pw.ui->lstBonusFeatures->item(i)->text().toStdString());
            }

            if(materialType != "Blu Ray"){
                firstSideContent = pw.ui->txtFirstSideContent->text().toStdString();
                if(materialType == "DVD Double Sided"){
                    secondSideContent = pw.ui->txtSecondSideContent->text().toStdString();
                }
            }
        }
    }else{

        comboNumberSingleDVD = pw.ui->sbComboSingleDVD->value();
        comboNumberDoubleDVD = pw.ui->sbComboDoubleDVD->value();

    }

    // Error checking
    if(title == ""){
        submit = false;
        pw.ui->lblMaterialTitle->setStyleSheet("color: #D81E5B");
    }else{
        pw.ui->lblMaterialTitle->setStyleSheet("color: #78CAD2");
    }

    if(id == ""){
        submit = false;
        pw.ui->lblMaterialIDNum->setStyleSheet("color: #D81E5B");
    }else{
        pw.ui->lblMaterialIDNum->setStyleSheet("color: #78CAD2");
    }

    if(price == 0){
        submit = false;
        pw.ui->lblMaterialPrice->setStyleSheet("color: #D81E5B");
    }else{
        pw.ui->lblMaterialPrice->setStyleSheet("color: #78CAD2");
    }

    if(packagingMaterial == ""){
        submit = false;
        pw.ui->lblMaterialPackageMaterial->setStyleSheet("color: #D81E5B");
    }else{
        pw.ui->lblMaterialPackageMaterial->setStyleSheet("color: #78CAD2");
    }

    if(packagingHeight == 0){
        submit = false;
        pw.ui->lblMaterialPackageHeight->setStyleSheet("color: #D81E5B");
    }else{
        pw.ui->lblMaterialPackageHeight->setStyleSheet("color: #78CAD2");
    }

    if(packagingWidth == 0){
        submit = false;
        pw.ui->lblMaterialPackageWidth->setStyleSheet("color: #D81E5B");
    }else{
        pw.ui->lblMaterialPackageWidth->setStyleSheet("color: #78CAD2");
    }

    if(packagingDepth == 0){
        submit = false;
        pw.ui->lblMaterialPackageDepth->setStyleSheet("color: #D81E5B");
    }else{
        pw.ui->lblMaterialPackageDepth->setStyleSheet("color: #78CAD2");
    }

    if(materialType != "Combo Box"){

        if(runtime == 0){
            submit = false;
            pw.ui->lblMaterialRuntime->setStyleSheet("color: #D81E5B");
        }else{
            pw.ui->lblMaterialRuntime->setStyleSheet("color: #78CAD2");
        }

        if(frameDesc == ""){
            submit = false;
            pw.ui->lblMaterialFrameDescription->setStyleSheet("color: #D81E5B");
        }else{
            pw.ui->lblMaterialFrameDescription->setStyleSheet("color: #78CAD2");
        }

        if(subLang.size() == 0){
            submit = false;
            pw.ui->lblMaterialSubLang->setStyleSheet("color: #D81E5B");
        }else{
            pw.ui->lblMaterialSubLang->setStyleSheet("color: #78CAD2");
        }

        if(frameHorizontal == 0){
            submit = false;
            pw.ui->lblMaterialFrameHorizontal->setStyleSheet("color: #D81E5B");
        }else{
            pw.ui->lblMaterialFrameHorizontal->setStyleSheet("color: #78CAD2");
        }

        if(frameVertical == 0){
            submit = false;
            pw.ui->lblMaterialFrameVertical->setStyleSheet("color: #D81E5B");
        }else{
            pw.ui->lblMaterialFrameVertical->setStyleSheet("color: #78CAD2");
        }

        if(materialType != "VHS"){

            if(extraLanguageTracks.size() == 0){
                submit = false;
                pw.ui->lblExtraLanguageTracks->setStyleSheet("color: #D81E5B");
            }else{
                pw.ui->lblExtraLanguageTracks->setStyleSheet("color: #78CAD2");
            }

            if(extraSubtitleTracks.size() == 0){
                submit = false;
                pw.ui->lblExtraSubtitleTracks->setStyleSheet("color: #D81E5B");
            }else{
                pw.ui->lblExtraSubtitleTracks->setStyleSheet("color: #78CAD2");
            }

            if(bonusFeatures.size() == 0){
                submit = false;
                pw.ui->lblBonusFeatures->setStyleSheet("color: #D81E5B");
            }else{
                pw.ui->lblBonusFeatures->setStyleSheet("color: #78CAD2");
            }

            if(materialType != "Blu Ray"){

                if(firstSideContent == ""){
                    submit = false;
                    pw.ui->lblFirstSideContent->setStyleSheet("color: #D81E5B");
                }else{
                    pw.ui->lblFirstSideContent->setStyleSheet("color: #78CAD2");
                }

                if(materialType == "DVD Double Sided"){

                    if(secondSideContent == ""){
                        submit = false;
                        pw.ui->lblSecondSideContent->setStyleSheet("color: #D81E5B");
                    }else{
                        pw.ui->lblSecondSideContent->setStyleSheet("color: #78CAD2");
                    }
                }
            }
        }
    }else{

        if(comboNumberSingleDVD == 0){
            submit = false;
            pw.ui->lblComboSingleDVD->setStyleSheet("color: #D81E5B");
        }else{
            pw.ui->lblComboSingleDVD->setStyleSheet("color: #78CAD2");
        }

        if(comboNumberDoubleDVD == 0){
            submit = false;
            pw.ui->lblComboDoubleDVD->setStyleSheet("color: #D81E5B");
        }else{
            pw.ui->lblComboDoubleDVD->setStyleSheet("color: #78CAD2");
        }

    }

    if(submit == true){

        Packaging package;
        package.setMaterial(packagingMaterial);
        package.setHeight(packagingHeight);
        package.setWidth(packagingWidth);
        package.setDepth(packagingDepth);

        FrameAspect frame;
        if(materialType != "Combo Box"){
            frame.setRatioDescription(frameDesc);
            frame.setHorizontalRatio(frameHorizontal);
            frame.setVerticalRatio(frameVertical);
        }

        if(materialType == "DVD Single Sided"){

            SingleSidedDVD newMaterial;

            newMaterial.setIdNumber(id);
            newMaterial.setTitle(title);
            newMaterial.setVFormat(vformat);
            newMaterial.setAFormat(aformat);
            newMaterial.setLanguage(language);
            newMaterial.setPrice(price);
            newMaterial.setRunTime(runtime);
            newMaterial.setSubTitleLanguages(subLang);
            newMaterial.setFrame(frame);
            newMaterial.setPackage(package);
            newMaterial.setFirstSideContent(firstSideContent);
            newMaterial.setExtraLanguageTracks(extraLanguageTracks);
            newMaterial.setExtraSubtitleTracks(extraSubtitleTracks);
            newMaterial.setBonusFeatures(bonusFeatures);

            openProj->setSingleDVD(newMaterial);

        }else if(materialType == "DVD Double Sided"){

            TwoSidedDVD newMaterial;

            newMaterial.setIdNumber(id);
            newMaterial.setTitle(title);
            newMaterial.setVFormat(vformat);
            newMaterial.setAFormat(aformat);
            newMaterial.setLanguage(language);
            newMaterial.setPrice(price);
            newMaterial.setRunTime(runtime);
            newMaterial.setSubTitleLanguages(subLang);
            newMaterial.setFrame(frame);
            newMaterial.setPackage(package);
            newMaterial.setFirstSideContent(firstSideContent);
            newMaterial.setSecondSideContent(secondSideContent);
            newMaterial.setExtraLanguageTracks(extraLanguageTracks);
            newMaterial.setExtraSubtitleTracks(extraSubtitleTracks);
            newMaterial.setBonusFeatures(bonusFeatures);

            openProj->setTwoDVD(newMaterial);

        }else if(materialType == "Blu Ray"){

            BluRay newMaterial;

            newMaterial.setIdNumber(id);
            newMaterial.setTitle(title);
            newMaterial.setVFormat(vformat);
            newMaterial.setAFormat(aformat);
            newMaterial.setLanguage(language);
            newMaterial.setPrice(price);
            newMaterial.setRunTime(runtime);
            newMaterial.setSubTitleLanguages(subLang);
            newMaterial.setFrame(frame);
            newMaterial.setPackage(package);
            newMaterial.setExtraLanguageTracks(extraLanguageTracks);
            newMaterial.setExtraSubtitleTracks(extraSubtitleTracks);
            newMaterial.setBonusTracks(bonusFeatures);

            openProj->setBluRay(newMaterial);

        }else if(materialType == "VHS"){

            VHS newMaterial;

            newMaterial.setIdNumber(id);
            newMaterial.setTitle(title);
            newMaterial.setVFormat(vformat);
            newMaterial.setAFormat(aformat);
            newMaterial.setLanguage(language);
            newMaterial.setPrice(price);
            newMaterial.setRunTime(runtime);
            newMaterial.setSubTitleLanguages(subLang);
            newMaterial.setFrame(frame);
            newMaterial.setPackage(package);

            openProj->setVhs(newMaterial);

        }else if(materialType == "Combo Box"){

            ComboBox newMaterial;

            newMaterial.setIdNumber(id);
            newMaterial.setTitle(title);
            newMaterial.setPrice(price);
            newMaterial.setPackaging(package);
            newMaterial.setNumberOfDVDs(comboNumberSingleDVD);
            //newMaterial.setNumberOfDVDs(comboNumberSingleDVD);

            openProj->setComboBox(newMaterial);

        }

        handleProjectWindowMaterialChange();
        handleCreateProject();
        handleFilter();

    }

}

void controller::handleProjectWindowSubLangAdd(){

    QString input = pw.ui->cbSubLang->currentText();
    bool addOption = true;

    std::vector<std::string> languages;
    for(int i = 0; i < pw.ui->lstSubLang->count(); ++i){
        languages.push_back(pw.ui->lstSubLang->item(i)->text().toStdString());
    }

    for(unsigned int j = 0; j < languages.size(); ++j){
        if(input.toStdString() == languages[j]){
            addOption = false;
        }
    }

    if(addOption){
        pw.ui->lstSubLang->addItem(input);
    }

    pw.ui->cbSubLang->setCurrentIndex(0);

}

void controller::handleProjectWindowSubLangDel(){

    QList <QListWidgetItem *> selectedItems = pw.ui->lstSubLang->selectedItems();
    for(int i = 0; i < selectedItems.size(); i++){
        delete pw.ui->lstSubLang->takeItem(pw.ui->lstSubLang->row(selectedItems[i]));
    }

}

void controller::handleProjectWindowExtraLangAdd(){

    QString input = pw.ui->cbExtraLanguageTracks->currentText();
    bool addOption = true;

    std::vector<std::string> languages;
    for(int i = 0; i < pw.ui->lstExtraLanguageTracks->count(); ++i){
        languages.push_back(pw.ui->lstExtraLanguageTracks->item(i)->text().toStdString());
    }

    for(unsigned int j = 0; j < languages.size(); ++j){
        if(input.toStdString() == languages[j]){
            addOption = false;
        }
    }

    if(addOption){
        pw.ui->lstExtraLanguageTracks->addItem(input);
    }

    pw.ui->cbExtraLanguageTracks->setCurrentIndex(0);

}

void controller::handleProjectWindowExtraLangDel(){

    QList <QListWidgetItem *> selectedItems = pw.ui->lstExtraLanguageTracks->selectedItems();
    for(int i = 0; i < selectedItems.size(); i++){
        delete pw.ui->lstExtraLanguageTracks->takeItem(pw.ui->lstExtraLanguageTracks->row(selectedItems[i]));
    }

}

void controller::handleProjectWindowExtraSubLangAdd(){

    QString input = pw.ui->cbExtraSubtitleTracks->currentText();
    bool addOption = true;

    std::vector<std::string> languages;
    for(int i = 0; i < pw.ui->lstExtraSubtitleTracks->count(); ++i){
        languages.push_back(pw.ui->lstExtraSubtitleTracks->item(i)->text().toStdString());
    }

    for(unsigned int j = 0; j < languages.size(); ++j){
        if(input.toStdString() == languages[j]){
            addOption = false;
        }
    }

    if(addOption){
        pw.ui->lstExtraSubtitleTracks->addItem(input);
    }

    pw.ui->cbExtraSubtitleTracks->setCurrentIndex(0);

}

void controller::handleProjectWindowExtraSubLangDel(){

    QList <QListWidgetItem *> selectedItems = pw.ui->lstExtraSubtitleTracks->selectedItems();
    for(int i = 0; i < selectedItems.size(); i++){
        delete pw.ui->lstExtraSubtitleTracks->takeItem(pw.ui->lstExtraSubtitleTracks->row(selectedItems[i]));
    }

}

void controller::handleProjectWindowBonusAdd(){

    QString input = pw.ui->txtBonusFeatures->text();
    if(input.toStdString() != ""){
        pw.ui->lstBonusFeatures->addItem(input);
    }
    pw.ui->txtBonusFeatures->clear();

}

void controller::handleProjectWindowBonusDel(){

    QList <QListWidgetItem *> selectedItems = pw.ui->lstBonusFeatures->selectedItems();
    for(int i = 0; i < selectedItems.size(); i++){
        delete pw.ui->lstBonusFeatures->takeItem(pw.ui->lstBonusFeatures->row(selectedItems[i]));
    }

}

void controller::handleSettingsApply(){

    QString input = mw.ui->txtEarningsLimit->text();
    if(input.toStdString() != ""){
        projList.File.ReportEarningsLimit=(input.toInt());
    }

}

void controller::updateComboRuntime(){

    int numOfSingle = pw.ui->sbComboSingleDVD->value();
    int numOfDouble = pw.ui->sbComboDoubleDVD->value();
    int runtimeSingle = openProj->getSingleDVD().getRunTime();
    int runtimeDouble = openProj->getTwoDVD().getRunTime();

    pw.ui->sbMaterialRuntime->setValue((numOfSingle * runtimeSingle) + (numOfDouble * runtimeDouble));

}

void controller::updateMinimumPackage(){

    unsigned int minHeight = 0;
    unsigned int minWidth = 0;
    unsigned int minDepth = 0;

    pw.ui->sbPackagingHeight->setMinimum(0);
    pw.ui->sbPackagingWidth->setMinimum(0);
    pw.ui->sbPackagingDepth->setMinimum(0);

    pw.ui->sbPackagingHeight->setValue(0);
    pw.ui->sbPackagingWidth->setValue(0);
    pw.ui->sbPackagingDepth->setValue(0);

    if(pw.ui->sbComboSingleDVD->value() != 0){

        minHeight = openProj->getSingleDVD().getPackage().getHeight();
        minWidth = openProj->getSingleDVD().getPackage().getWidth();
        minDepth = openProj->getSingleDVD().getPackage().getDepth();

    }

    if(pw.ui->sbComboDoubleDVD->value() != 0){

        if(minHeight < openProj->getTwoDVD().getPackage().getHeight()){
            minHeight = openProj->getTwoDVD().getPackage().getHeight();
        }

        if(minWidth < openProj->getTwoDVD().getPackage().getWidth()){
            minWidth = openProj->getTwoDVD().getPackage().getWidth();
        }

        if(minDepth < openProj->getTwoDVD().getPackage().getDepth()){
            minDepth = openProj->getTwoDVD().getPackage().getDepth();
        }

    }

    pw.ui->sbPackagingHeight->setMinimum(minHeight);
    pw.ui->sbPackagingWidth->setMinimum(minWidth);
    pw.ui->sbPackagingDepth->setMinimum(minDepth);

}
