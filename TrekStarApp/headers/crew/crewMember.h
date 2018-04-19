#ifndef CREW_H
#define CREW_H

#include "main.h"

using namespace std;

class CrewMember
{

private:
    string name = "";
    string dateOfBirth = "";
    string idNumber = "";
    string title = "";
    string role = "";
    int yearsOfExperience = 0;

    vector<string> locationsWorkedAt;


public:
    CrewMember();
    string getName() const;
    void setName(const string &value);
    string getDateOfBirth() const;
    void setDateOfBirth(const string &value);
    string getIdNumber() const;
    void setIdNumber(const string &value);
    string getTitle() const;
    void setTitle(const string &value);
    int getYearsOfExperience() const;
    void setYearsOfExperience(int value);
    vector<string> getLocationsWorkedAt() const;
    void setLocationsWorkedAt(const vector<string> &value);
    string getRole() const;
    void setRole(const string &value);
};

#endif // CREW_H
