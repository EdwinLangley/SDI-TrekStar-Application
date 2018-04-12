#include "combobox.h"

unsigned int ComboBox::getNumberOfDVDs() const
{
    return numberOfDVDs;
}

void ComboBox::setNumberOfDVDs(unsigned int value)
{
    numberOfDVDs = value;
}

vector<string> ComboBox::getIdsOfDVDs() const
{
    return idsOfDVDs;
}

void ComboBox::setIdsOfDVDs(const vector<string> &value)
{
    idsOfDVDs = value;
}

ComboBox::ComboBox()
{

}
