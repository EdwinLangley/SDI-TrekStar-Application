#ifndef PROJECT_H
#define PROJECT_H

#include "main.h"

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

    vector<string> filmLocations;
    vector<string> materials;


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
};

#endif // PROJECT_H
