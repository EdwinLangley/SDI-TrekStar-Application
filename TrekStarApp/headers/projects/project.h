#ifndef PROJECT_H
#define PROJECT_H

#include "main.h"
#include "twosideddvd.h"
#include "singlesideddvd.h"
#include "bluray.h"
#include "vhs.h"
#include "combobox.h"

using namespace std;

class Project
{

private:
    string title = "";
    string projectStatus = "";
    string summary = "";
    string genre = "";
    string releaseDate = "";
    string language = "";
    //Like Material IDs but only links to one singular crew entity, as each crew will be unique.
    //CrewID 0 will be an unset crew
    string crewID;
    vector<string> filmLocations;
   ;
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
};

#endif // PROJECT_H
