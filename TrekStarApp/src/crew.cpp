#include "crew.h"

string Crew::getName() const
{
    return name;
}

void Crew::setName(const string &value)
{
    name = value;
}

string Crew::getDateOfBirth() const
{
    return dateOfBirth;
}

void Crew::setDateOfBirth(const string &value)
{
    dateOfBirth = value;
}

string Crew::getIdNumber() const
{
    return idNumber;
}

void Crew::setIdNumber(const string &value)
{
    idNumber = value;
}

string Crew::getTitle() const
{
    return title;
}

void Crew::setTitle(const string &value)
{
    title = value;
}

int Crew::getYearsOfExperience() const
{
    return yearsOfExperience;
}

void Crew::setYearsOfExperience(int value)
{
    yearsOfExperience = value;
}

vector<string> Crew::getLocationsWorkedAt() const
{
    return locationsWorkedAt;
}

void Crew::setLocationsWorkedAt(const vector<string> &value)
{
    locationsWorkedAt = value;
}

Crew::Crew()
{
    
}
