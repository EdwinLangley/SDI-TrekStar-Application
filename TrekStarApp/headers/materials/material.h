#ifndef MATERIAL_H
#define MATERIAL_H

#include "main.h"
#include "frameaspect.h"
#include "packaging.h"

using namespace std;

class Material
{

private:
   string idNumber = "";
   string title = "";
   string vFormat = "";
   string aFormat = "";
   string language = "";
   FrameAspect frame;
   Packaging package;


   int runTime = 0;

   float price = 0;

   vector<string> subTitleLanguages;


public:
    Material();
    Material(string idNumber,string title,string vFormat,string aFormat,string language,int runTime,float price,vector<string> subTitleLanguages);
    string getIdNumber() const;
    void setIdNumber(const string &value);
    string getTitle() const;
    void setTitle(const string &value);
    string getVFormat() const;
    void setVFormat(const string &value);
    string getAFormat() const;
    void setAFormat(const string &value);
    string getLanguage() const;
    void setLanguage(const string &value);
    int getRunTime() const;
    void setRunTime(int value);
    float getPrice() const;
    void setPrice(float value);
    vector<string> getSubTitleLanguages() const;
    void setSubTitleLanguages(const vector<string> &value);
    string getMaterials();
    FrameAspect getFrame() const;
    void setFrame(const FrameAspect &value);
    Packaging getPackage() const;
    void setPackage(const Packaging &value);
};

#endif // MATERIAL_H
