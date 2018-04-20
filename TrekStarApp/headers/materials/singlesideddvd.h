#ifndef SINGLESIDEDDVD_H
#define SINGLESIDEDDVD_H

#include "main.h"
#include "dvd.h"

class SingleSidedDVD : public DVD
{
public:
    SingleSidedDVD();
    //SingleSidedDVD(Material baseMaterial,vector<string> extraLanguageTracks, vector<string> extraSubtitleTracks,vector<string> bonusFeatures,string firstSideContent);
};

#endif // SINGLESIDEDDVD_H
