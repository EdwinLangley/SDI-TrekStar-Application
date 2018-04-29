#ifndef COMBOBOX_H
#define COMBOBOX_H

#include "main.h"
#include "twosideddvd.h"
#include "singlesideddvd.h"
#include "packaging.h"


using namespace std;


class ComboBox
{
private:
    string idNumber = "0";
    string title = "";
    Packaging packaging;
    float price = 0;

    unsigned int numberOfDVDs = 0;
    vector<string> idsOfDVDs = {"0"};
    vector<SingleSidedDVD> SingleDVDs;
    vector<TwoSidedDVD> DoubleDVDs;

public:
    ComboBox();
    ComboBox(unsigned int numberOfDVDs, vector<string> idsOfDVDs,
             vector<SingleSidedDVD> SingleDVDs, vector<TwoSidedDVD> DoubleDVDs,
             string idNumber, string title, Packaging packaging, float price);
    unsigned int getNumberOfDVDs() const;
    void setNumberOfDVDs(unsigned int value);
    vector<string> getIdsOfDVDs() const;
    void setIdsOfDVDs(const vector<string> &value);
    vector<SingleSidedDVD> getSingleDVDs() const;
    void setSingleDVDs(const vector<SingleSidedDVD> &value);
    vector<TwoSidedDVD> getDoubleDVDs() const;
    void setDoubleDVDs(const vector<TwoSidedDVD> &value);

    bool operator ==(const ComboBox& comboBox){
        if(
                this->numberOfDVDs==comboBox.numberOfDVDs&&
                this->idsOfDVDs==comboBox.idsOfDVDs)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator !=(const ComboBox& comboBox){
        if(
                this->numberOfDVDs!=comboBox.numberOfDVDs||
                this->idsOfDVDs!=comboBox.idsOfDVDs)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    string getIdNumber() const;
    void setIdNumber(const string &value);
    string getTitle() const;
    void setTitle(const string &value);
    Packaging getPackaging() const;
    void setPackaging(const Packaging &value);
    float getPrice() const;
    void setPrice(float value);
    string getDetails();
};

#endif // COMBOBOX_H
