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
    bool operator ==(const VHS& vhs){
        if(
                this->idNumber==vhs.idNumber&&
                this->title==vhs.title&&
                this->vFormat==vhs.vFormat&&
                this->aFormat==vhs.aFormat&&
                this->language==vhs.language&&
                this->frame==vhs.frame&&
                this->package==vhs.package&&
                this->runTime==vhs.runTime&&
                this->price==vhs.price&&
                this->subTitleLanguages==vhs.subTitleLanguages)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator !=(const VHS& vhs){
        if(
                this->idNumber!=vhs.idNumber||
                this->title!=vhs.title||
                this->vFormat!=vhs.vFormat||
                this->aFormat!=vhs.aFormat||
                this->language!=vhs.language||
                this->frame!=vhs.frame||
                this->package!=vhs.package||
                this->runTime!=vhs.runTime||
                this->price!=vhs.price||
                this->subTitleLanguages!=vhs.subTitleLanguages)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

#endif // VHS_H
