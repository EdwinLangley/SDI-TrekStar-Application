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
    TwoSidedDVD(Material baseMaterial,vector<string> extraLanguageTracks, vector<string> extraSubtitleTracks,vector<string> bonusFeatures,string firstSideContent, string secondSideContent);
    string getSecondSideContent() const;
    void setSecondSideContent(const string &value);
};

#endif // TWOSIDEDDVD_H
