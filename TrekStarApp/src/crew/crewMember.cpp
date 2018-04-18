#include "crewMember.h"

string CrewMember::getName() const
{
    return name;
}

void CrewMember::setName(const string &value)
{
    name = value;
}

string CrewMember::getDateOfBirth() const
{
    return dateOfBirth;
}

void CrewMember::setDateOfBirth(const string &value)
{
    dateOfBirth = value;
}

string CrewMember::getIdNumber() const
{
    return idNumber;
}

void CrewMember::setIdNumber(const string &value)
{
    idNumber = value;
}

string CrewMember::getTitle() const
{
    return title;
}

void CrewMember::setTitle(const string &value)
{
    title = value;
}

int CrewMember::getYearsOfExperience() const
{
    return yearsOfExperience;
}

void CrewMember::setYearsOfExperience(int value)
{
    yearsOfExperience = value;
}

vector<string> CrewMember::getLocationsWorkedAt() const
{
    return locationsWorkedAt;
}

void CrewMember::setLocationsWorkedAt(const vector<string> &value)
{
    locationsWorkedAt = value;
}

CrewMember::CrewMember()
{
    
}
