#ifndef CREW_H
#define CREW_H

#include "main.h"

using namespace std;

class CrewMember
{

private:
    string name = "";//0
    string dateOfBirth = "";//1
    string idNumber = "";//2
    string title = "";//3
    string role = "";//4
    int yearsOfExperience = 0;//5

    vector<string> locationsWorkedAt = {""};//6


public:
    CrewMember();
    CrewMember(string name, string dateOfBirth, string idNumber,
               string title, string role, int yearsOfExperience,
               vector<string>locationsWorkedAt);
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
    string getCrewMember();
};

#endif // CREW_H
