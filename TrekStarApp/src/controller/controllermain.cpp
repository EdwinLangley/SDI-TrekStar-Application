#include "controllermain.h"
#include "gui.h"
#include "controllerproject.h"
#include "ui_mainwindow.h"


controllermain::controllermain()
{
    //controllerproject cp;

    connect(mw.ui->cmdCreate, SIGNAL (clicked()), this, SLOT (handleCreateProject()));
    mw.show();

}

void controllermain::handleCreateProject(){

    QString projTitle = mw.ui->txtTitleProject->text();
    //mw.ui->txtSummary->
    QVariant genre = mw.ui->cbGenre->currentData();
    QVariant language = mw.ui->cbLanguage->currentData();
    QDate date = mw.ui->deRelease->date();
    float runtime = mw.ui->dsbRuntime->value();
    float sales = mw.ui->sbSales->value();
    QSize locationSize = mw.ui->lstLocation->size();
    QSize keywordsSize = mw.ui->lstKeywords->size();
    /*
    for(unsigned int i = 0; i < ; ++i){

    }
    */



}
