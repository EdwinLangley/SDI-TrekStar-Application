#include "dvd.h"
#include "material.h"

vector<string> DVD::getExtraLanguageTracks() const
{
    return extraLanguageTracks;
}

void DVD::setExtraLanguageTracks(const vector<string> &value)
{
    extraLanguageTracks = value;
}

vector<string> DVD::getExtraSubtitleTracks() const
{
    return extraSubtitleTracks;
}

void DVD::setExtraSubtitleTracks(const vector<string> &value)
{
    extraSubtitleTracks = value;
}

vector<string> DVD::getBonusFeatures() const
{
    return bonusFeatures;
}

void DVD::setBonusFeatures(const vector<string> &value)
{
    bonusFeatures = value;
}

string DVD::getFirstSideContent() const
{
    return firstSideContent;
}

void DVD::setFirstSideContent(const string &value)
{
    firstSideContent = value;
}

string DVD::getDVD()
{
    string dvd;
    dvd.append(VectorToString(extraLanguageTracks));//15
    dvd.append(FIRSTLEVELDELIMSTRNG);
    dvd.append(VectorToString(extraSubtitleTracks));//16
    dvd.append(FIRSTLEVELDELIMSTRNG);
    dvd.append(VectorToString(bonusFeatures));//17
    dvd.append(FIRSTLEVELDELIMSTRNG);
    dvd.append(this->firstSideContent);//18
    return dvd;
}

DVD::DVD()
{

}
