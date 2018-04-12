#ifndef COMBOBOX_H
#define COMBOBOX_H

#include "twosideddvd.h"
#include "singlesideddvd.h"

#include <string>

#include <vector>

using namespace std;


class ComboBox
{
private:
    unsigned int numberOfDVDs = 0;

    vector<string> idsOfDVDs;

public:
    ComboBox();
    unsigned int getNumberOfDVDs() const;
    void setNumberOfDVDs(unsigned int value);
    vector<string> getIdsOfDVDs() const;
    void setIdsOfDVDs(const vector<string> &value);
};

#endif // COMBOBOX_H
