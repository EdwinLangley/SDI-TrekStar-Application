#ifndef TWOSIDEDDVD_H
#define TWOSIDEDDVD_H

#include "main.h"
#include "dvd.h"

using namespace std;

class TwoSidedDVD : public DVD
{
private:
    string secondSideContent = "";

public:
    TwoSidedDVD();
    TwoSidedDVD(string idNumber, string title, string vFormat, string aFormat, string language,
                FrameAspect frame, Packaging package, int runTime, float price,
                vector<string> subTitleLanguages, vector<string> extraLanguageTracks,
                vector<string> extraSubtitleTracks, vector<string> bonusFeatures
                ,string firstSideContent, string secondSideContent)
        :DVD(idNumber,title,vFormat,aFormat,language,frame,package,runTime, price,
             subTitleLanguages,extraLanguageTracks,extraSubtitleTracks,
             bonusFeatures,firstSideContent)
    {
        this->secondSideContent=secondSideContent;
    }

    string getSecondSideContent() const;
    void setSecondSideContent(const string &value);

    bool operator ==(const TwoSidedDVD& twoSidedDVD){
        if(
                this->idNumber==twoSidedDVD.idNumber&&
                this->title==twoSidedDVD.title&&
                this->vFormat==twoSidedDVD.vFormat&&
                this->aFormat==twoSidedDVD.aFormat&&
                this->language==twoSidedDVD.language&&
                this->frame==twoSidedDVD.frame&&
                this->package==twoSidedDVD.package&&
                this->runTime==twoSidedDVD.runTime&&
                this->price==twoSidedDVD.price&&
                this->subTitleLanguages==twoSidedDVD.subTitleLanguages&&
                this->extraLanguageTracks==twoSidedDVD.extraLanguageTracks&&
                this->extraSubtitleTracks==twoSidedDVD.extraSubtitleTracks&&
                this->bonusFeatures==twoSidedDVD.bonusFeatures&&
                this->firstSideContent==twoSidedDVD.firstSideContent&&
                this->secondSideContent==twoSidedDVD.secondSideContent)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator !=(const TwoSidedDVD& twoSidedDVD){
        if(
                this->idNumber!=twoSidedDVD.idNumber||
                this->title!=twoSidedDVD.title||
                this->vFormat!=twoSidedDVD.vFormat||
                this->aFormat!=twoSidedDVD.aFormat||
                this->language!=twoSidedDVD.language||
                this->frame!=twoSidedDVD.frame||
                this->package!=twoSidedDVD.package||
                this->runTime!=twoSidedDVD.runTime||
                this->price!=twoSidedDVD.price||
                this->subTitleLanguages!=twoSidedDVD.subTitleLanguages||
                this->extraLanguageTracks!=twoSidedDVD.extraLanguageTracks||
                this->extraSubtitleTracks!=twoSidedDVD.extraSubtitleTracks||
                this->bonusFeatures!=twoSidedDVD.bonusFeatures||
                this->firstSideContent!=twoSidedDVD.firstSideContent||
                this->secondSideContent!=twoSidedDVD.secondSideContent)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

#endif // TWOSIDEDDVD_H
