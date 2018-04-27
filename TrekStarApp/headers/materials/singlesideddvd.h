#ifndef SINGLESIDEDDVD_H
#define SINGLESIDEDDVD_H

#include "main.h"
#include "dvd.h"

class SingleSidedDVD : public DVD
{
public:
    SingleSidedDVD();
    SingleSidedDVD(string idNumber, string title, string vFormat, string aFormat, string language,
                   FrameAspect frame, Packaging package, int runTime, float price,
                   vector<string> subTitleLanguages, vector<string> extraLanguageTracks,
                   vector<string> extraSubtitleTracks, vector<string> bonusFeatures,
                   string firstSideContent)
        :DVD(idNumber,title,vFormat,aFormat,language,frame,package,runTime, price,
             subTitleLanguages,extraLanguageTracks,extraSubtitleTracks,
             bonusFeatures,firstSideContent)
    {
    }
    bool operator ==(const SingleSidedDVD& singleSidedDVD){
        if(
                this->idNumber==singleSidedDVD.idNumber&&
                this->title==singleSidedDVD.title&&
                this->vFormat==singleSidedDVD.vFormat&&
                this->aFormat==singleSidedDVD.aFormat&&
                this->language==singleSidedDVD.language&&
                this->frame==singleSidedDVD.frame&&
                this->package==singleSidedDVD.package&&
                this->runTime==singleSidedDVD.runTime&&
                this->price==singleSidedDVD.price&&
                this->subTitleLanguages==singleSidedDVD.subTitleLanguages&&
                this->extraLanguageTracks==singleSidedDVD.extraLanguageTracks&&
                this->extraSubtitleTracks==singleSidedDVD.extraSubtitleTracks&&
                this->bonusFeatures==singleSidedDVD.bonusFeatures&&
                this->firstSideContent==singleSidedDVD.firstSideContent)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator !=(const SingleSidedDVD& singleSidedDVD){
        if(
                this->idNumber!=singleSidedDVD.idNumber||
                this->title!=singleSidedDVD.title||
                this->vFormat!=singleSidedDVD.vFormat||
                this->aFormat!=singleSidedDVD.aFormat||
                this->language!=singleSidedDVD.language||
                this->frame!=singleSidedDVD.frame||
                this->package!=singleSidedDVD.package||
                this->runTime!=singleSidedDVD.runTime||
                this->price!=singleSidedDVD.price||
                this->subTitleLanguages!=singleSidedDVD.subTitleLanguages||
                this->extraLanguageTracks!=singleSidedDVD.extraLanguageTracks||
                this->extraSubtitleTracks!=singleSidedDVD.extraSubtitleTracks||
                this->bonusFeatures!=singleSidedDVD.bonusFeatures||
                this->firstSideContent!=singleSidedDVD.firstSideContent)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

#endif // SINGLESIDEDDVD_H
