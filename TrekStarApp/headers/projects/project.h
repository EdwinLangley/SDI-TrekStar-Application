#ifndef PROJECT_H
#define PROJECT_H

#include "main.h"
#include "material.h"
#include "bluray.h"
#include "vhs.h"
#include "combobox.h"
#include "crewMember.h"

using namespace std;

class Project
{

private:
    string title = "TestTitle";
    string projectStatus = "TestStatus";
    string summary = "TestSummary";
    string genre = "TestGenre";
    string releaseDate = "01/01/1000";
    string language = "TestLanguage";
    int runTime = 0;
    int weeklyBoxFigures = 0;
    vector<string> keywords = {"Keywords"};
    vector<string> filmLocations={"Location1"};
    //Like Material IDs but only links to one singular crew entity, as each crew will be unique.
    //CrewID 0 will be an unset crew
    int crewID=0;
    vector<CrewMember> Crew;
    //ONLY TO BE SET ON LOAD FROM FILES/CREATION OF PROJECT MATERIAL. DEFAULT VALUES SET TO ENSURE
    //SECURITY WHEN WRITING INCOMPLETE PROJECT MATERIALS
    SingleSidedDVD singleDVD = SingleSidedDVD();
    TwoSidedDVD twoDVD = TwoSidedDVD();
    BluRay bluRay = BluRay();
    VHS vhs = VHS();
    ComboBox comboBox = ComboBox();
    //MAKE SURE TO ADD THE IDs OF ANY MATERIALS ASSOCIATED WITH A PROJECTS TO THIS
    //OTHERWISE CANT FIND THE MATERIALS. MAKE SURE THEY ARE UNIQUE AND NOT 0 AS 0 IS UNSET MATERIALS
    vector<string> materialIDs={"0"};

public:
    Project();
    string getTitle() const;
    void setTitle(const string &value);
    string getProjectStatus() const;
    void setProjectStatus(const string &value);
    string getSummary() const;
    void setSummary(const string &value);
    string getGenre() const;
    void setGenre(const string &value);
    string getReleaseDate() const;
    void setReleaseDate(const string &value);
    string getLanguage() const;
    void setLanguage(const string &value);
    vector<string> getFilmLocations() const;
    void setFilmLocations(const vector<string> &value);
    vector<string> getMaterials() const;
    vector<string> getAllMaterials();
    void setMaterials(const vector<string> &value);
    int getCrewID() const;
    void setCrewID(const int &value);
    vector<CrewMember> getCrew() const;
    void setCrew(const vector<CrewMember> &value);
    SingleSidedDVD getSingleDVD() const;
    void setSingleDVD(const SingleSidedDVD &value);
    TwoSidedDVD getTwoDVD() const;
    void setTwoDVD(const TwoSidedDVD &value);
    BluRay getBluRay() const;
    void setBluRay(const BluRay &value);
    VHS getVhs() const;
    void setVhs(const VHS &value);
    ComboBox getComboBox() const;
    void setComboBox(const ComboBox &value);
    void setMaterialIDs(const vector<string> &value);
    vector<string> getMaterialIDs() const;
    int getWeeklyBoxFigures() const;
    void setWeeklyBoxFigures(int value);
    vector<string> getKeywords() const;
    void setKeywords(const vector<string> &value);
    int getRunTime() const;
    void setRunTime(int value);

    bool operator ==(const Project& project){
        if(
                this->title==project.title&&
                this->projectStatus==project.projectStatus&&
                this->summary==project.summary&&
                this->genre==project.projectStatus&&
                this->releaseDate==project.releaseDate&&
                this->language==project.language&&
                this->runTime==project.runTime&&
                this->weeklyBoxFigures==project.weeklyBoxFigures&&
                this->keywords==project.keywords&&
                this->filmLocations==project.filmLocations&&
                this->singleDVD==project.singleDVD&&
                this->twoDVD==project.twoDVD&&
                this->bluRay==project.bluRay&&
                this->vhs==project.vhs&&
                this->comboBox==project.comboBox&&
                this->materialIDs==project.materialIDs)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator !=(const Project& project){
        if(
                this->title!=project.title||
                this->projectStatus!=project.projectStatus||
                this->summary!=project.summary||
                this->genre!=project.projectStatus||
                this->releaseDate!=project.releaseDate||
                this->language!=project.language||
                this->runTime!=project.runTime||
                this->weeklyBoxFigures!=project.weeklyBoxFigures||
                this->keywords!=project.keywords||
                this->filmLocations!=project.filmLocations||
                this->singleDVD!=project.singleDVD||
                this->twoDVD!=project.twoDVD||
                this->bluRay!=project.bluRay||
                this->vhs!=project.vhs||
                this->comboBox!=project.comboBox||
                this->materialIDs!=project.materialIDs)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

#endif // PROJECT_H
