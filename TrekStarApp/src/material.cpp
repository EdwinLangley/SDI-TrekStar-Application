#include "material.h"



string Material::getIdNumber() const
{
    return idNumber;
}

void Material::setIdNumber(const string &value)
{
    idNumber = value;
}

string Material::getTitle() const
{
    return title;
}

void Material::setTitle(const string &value)
{
    title = value;
}

string Material::getVFormat() const
{
    return vFormat;
}

void Material::setVFormat(const string &value)
{
    vFormat = value;
}

string Material::getAFormat() const
{
    return aFormat;
}

void Material::setAFormat(const string &value)
{
    aFormat = value;
}

string Material::getLanguage() const
{
    return language;
}

void Material::setLanguage(const string &value)
{
    language = value;
}

int Material::getRunTime() const
{
    return runTime;
}

void Material::setRunTime(int value)
{
    runTime = value;
}

float Material::getPrice() const
{
    return price;
}

void Material::setPrice(float value)
{
    price = value;
}

vector<string> Material::getSubTitleLanguages() const
{
    return subTitleLanguages;
}

void Material::setSubTitleLanguages(const vector<string> &value)
{
    subTitleLanguages = value;
}

Material::Material()
{

}
