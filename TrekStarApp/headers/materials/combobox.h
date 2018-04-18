#ifndef COMBOBOX_H
#define COMBOBOX_H

#include "main.h"
#include "twosideddvd.h"
#include "singlesideddvd.h"


using namespace std;


class ComboBox
{
private:
    unsigned int numberOfDVDs = 0;

    vector<string> idsOfDVDs;

    vector<SingleSidedDVD> SingleDVDs;
    vector<TwoSidedDVD> DoubleDVDs;

public:
    ComboBox();
    unsigned int getNumberOfDVDs() const;
    void setNumberOfDVDs(unsigned int value);
    vector<string> getIdsOfDVDs() const;
    void setIdsOfDVDs(const vector<string> &value);
    vector<SingleSidedDVD> getSingleDVDs() const;
    void setSingleDVDs(const vector<SingleSidedDVD> &value);
    vector<TwoSidedDVD> getDoubleDVDs() const;
    void setDoubleDVDs(const vector<TwoSidedDVD> &value);
};

#endif // COMBOBOX_H
