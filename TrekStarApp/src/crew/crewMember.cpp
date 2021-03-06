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

string CrewMember::getRole() const
{
    return role;
}

void CrewMember::setRole(const string &value)
{
    role = value;
}

string CrewMember::getCrewMember()
{
 string crewMember;
 crewMember.append(this->name);
 crewMember.append(SECONDLEVELDELIMSTRNG);
 crewMember.append(this->dateOfBirth);
 crewMember.append(SECONDLEVELDELIMSTRNG);
 crewMember.append(this->idNumber);
 crewMember.append(SECONDLEVELDELIMSTRNG);
 crewMember.append(this->title);
 crewMember.append(SECONDLEVELDELIMSTRNG);
 crewMember.append(this->role);
 crewMember.append(SECONDLEVELDELIMSTRNG);
 crewMember.append(to_string(this->yearsOfExperience));
 crewMember.append(SECONDLEVELDELIMSTRNG);
 crewMember.append(VectorToString(this->locationsWorkedAt));
 return crewMember;
}

CrewMember::CrewMember()
{
    
}

CrewMember::CrewMember(string name, string dateOfBirth, string idNumber, string title, string role, int yearsOfExperience, vector<string> locationsWorkedAt)
{
    this->name=name;
    this->dateOfBirth=dateOfBirth;
    this->idNumber=idNumber;
    this->title=title;
    this->role=role;
    this->yearsOfExperience=yearsOfExperience;
    this->locationsWorkedAt=locationsWorkedAt;
}
