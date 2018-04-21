#include "project.h"

string Project::getTitle() const
{
    return title;
}

void Project::setTitle(const string &value)
{
    title = value;
}

string Project::getProjectStatus() const
{
    return projectStatus;
}

void Project::setProjectStatus(const string &value)
{
    projectStatus = value;
}

string Project::getSummary() const
{
    return summary;
}

void Project::setSummary(const string &value)
{
    summary = value;
}

string Project::getGenre() const
{
    return genre;
}

void Project::setGenre(const string &value)
{
    genre = value;
}

string Project::getReleaseDate() const
{
    return releaseDate;
}

void Project::setReleaseDate(const string &value)
{
    releaseDate = value;
}

string Project::getLanguage() const
{
    return language;
}

void Project::setLanguage(const string &value)
{
    language = value;
}

vector<string> Project::getFilmLocations() const

{
    return filmLocations;
}

void Project::setFilmLocations(const vector<string> &value)
{
    filmLocations = value;
}

vector<string> Project::getMaterials() const
{
    return materialIDs;
}

void Project::setMaterials(const vector<string> &value)
{
    materialIDs = value;
}

string Project::getCrewID() const
{
    return crewID;
}

void Project::setCrewID(const string &value)
{
    crewID = value;
}

vector<CrewMember> Project::getCrew() const
{
    return Crew;
}

void Project::setCrew(const vector<CrewMember> &value)
{
    Crew = value;
}

SingleSidedDVD Project::getSingleDVD() const
{
    return singleDVD;
}

void Project::setSingleDVD(const SingleSidedDVD &value)
{
    singleDVD = value;
}

TwoSidedDVD Project::getTwoDVD() const
{
    return twoDVD;
}

void Project::setTwoDVD(const TwoSidedDVD &value)
{
    twoDVD = value;
}

BluRay Project::getBluRay() const
{
    return bluRay;
}

void Project::setBluRay(const BluRay &value)
{
    bluRay = value;
}

VHS Project::getVhs() const
{
    return vhs;
}

void Project::setVhs(const VHS &value)
{
    vhs = value;
}

ComboBox Project::getComboBox() const
{
    return comboBox;
}

void Project::setComboBox(const ComboBox &value)
{
    comboBox = value;
}

vector<string> Project::getMaterialIDs() const
{
    return materialIDs;
}

void Project::setMaterialIDs(const vector<string> &value)
{
    materialIDs = value;
}

int Project::getWeeklyBoxFigures() const
{
    return weeklyBoxFigures;
}

void Project::setWeeklyBoxFigures(int value)
{
    weeklyBoxFigures = value;
}

vector<string> Project::getKeywords() const
{
    return keywords;
}

void Project::setKeywords(const vector<string> &value)
{
    keywords = value;
}

Project::Project()
{
    
}
