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

vector<SingleSidedDVD> ComboBox::getSingleDVDs() const
{
    return SingleDVDs;
}

void ComboBox::setSingleDVDs(const vector<SingleSidedDVD> &value)
{
    SingleDVDs = value;
}

vector<TwoSidedDVD> ComboBox::getDoubleDVDs() const
{
    return DoubleDVDs;
}

void ComboBox::setDoubleDVDs(const vector<TwoSidedDVD> &value)
{
    DoubleDVDs = value;
}

ComboBox::ComboBox()
{
    
}

ComboBox::ComboBox(unsigned int numberOfDVDs, vector<string> idsOfDVDs, vector<SingleSidedDVD> SingleDVDs, vector<TwoSidedDVD> DoubleDVDs)
{

}
