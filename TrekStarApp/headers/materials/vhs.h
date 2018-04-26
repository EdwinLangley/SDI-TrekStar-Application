#ifndef VHS_H
#define VHS_H

#include "main.h"
#include "material.h"

class VHS : public Material
{
public:
    VHS();
    VHS(string idNumber, string title, string vFormat, string aFormat, string language,
        FrameAspect frame, Packaging package, int runTime, float price,
        vector<string> subTitleLanguages)
        :Material(idNumber,title,vFormat,aFormat,language,frame,package,
                  runTime, price,subTitleLanguages)
    {
    }
};

#endif // VHS_H
