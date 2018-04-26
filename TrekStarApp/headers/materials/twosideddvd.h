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
};

#endif // TWOSIDEDDVD_H
