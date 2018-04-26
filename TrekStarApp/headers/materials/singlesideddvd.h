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
};

#endif // SINGLESIDEDDVD_H
