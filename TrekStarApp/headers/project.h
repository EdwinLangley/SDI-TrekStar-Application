#ifndef PROJECT_H
#define PROJECT_H

#include <iostream>
#include <string>
#include <vector>

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

    vector<string> filmLoactions;


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
};

#endif // PROJECT_H
