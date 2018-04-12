#ifndef CREW_H
#define CREW_H

#include <string>
#include <vector>

using namespace std;

class Crew
{

private:
    string name = "";
    string dateOfBirth = "";
    string idNumber = "";
    string title = "";

    int yearsOfExperience = 0;

    vector<string> locationsWorkedAt;


public:
    Crew();
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
};

#endif // CREW_H
