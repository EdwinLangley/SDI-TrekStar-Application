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

Project::Project()
{

}
