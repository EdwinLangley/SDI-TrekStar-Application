#ifndef PROJECT_H
#define PROJECT_H

#include "main.h"
#include "material.h"
#include "twosideddvd.h"
#include "singlesideddvd.h"
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
    string releaseDate = "TestReleaseData";
    string language = "TestLanguage";
    vector<string> filmLocations={"Location1","Location2","location3"};
    //Like Material IDs but only links to one singular crew entity, as each crew will be unique.
    //CrewID 0 will be an unset crew
    string crewID="0";
    vector<CrewMember> Crew;

public:
    //ONLY TO BE SET ON LOAD FROM FILES/CREATION OF PROJECT MATERIAL
    SingleSidedDVD singleDVD;
    TwoSidedDVD twoDVD;
    BluRay bluRay;
    VHS vhs;
    ComboBox comboBox;
    //MAKE SURE TO ADD THE IDs OF ANY MATERIALS ASSOCIATED WITH A PROJECTS TO THIS
    //OTHERWISE CANT FIND THE MATERIALS. MAKE SURE THEY ARE UNIQUE AND NOT 0 AS 0 IS UNSET MATERIALS
    vector<string> materialIDs;

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
    void setMaterials(const vector<string> &value);
    string getCrewID() const;
    void setCrewID(const string &value);
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
    vector<string> getMaterialIDs() const;
    void setMaterialIDs(const vector<string> &value);
};

#endif // PROJECT_H
