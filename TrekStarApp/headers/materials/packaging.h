#ifndef PACKAGING_H
#define PACKAGING_H

#include "main.h"

using namespace std;

class Packaging
{

private:
    string material = "";
    unsigned int height = 0;
    unsigned int width = 0;
    unsigned int depth = 0;


public:
    Packaging();
    Packaging(string material, unsigned int height,unsigned int width,unsigned int depth);
    string getMaterial() const;
    void setMaterial(const string &value);
    unsigned int getHeight() const;
    void setHeight(unsigned int value);
    unsigned int getWidth() const;
    void setWidth(unsigned int value);
    unsigned int getDepth() const;
    void setDepth(unsigned int value);
    string getPackaging();
};

#endif // PACKAGING_H
