#include "bluray.h"
#include "material.h"
#include "main.h"

vector<string> BluRay::getExtraLanguageTracks() const
{
    return extraLanguageTracks;
}

void BluRay::setExtraLanguageTracks(const vector<string> &value)
{
    extraLanguageTracks = value;
}

vector<string> BluRay::getExtraSubtitleTracks() const
{
    return extraSubtitleTracks;
}

void BluRay::setExtraSubtitleTracks(const vector<string> &value)
{
    extraSubtitleTracks = value;
}

vector<string> BluRay::getBonusTracks() const
{
    return bonusTracks;
}

void BluRay::setBonusTracks(const vector<string> &value)
{
    bonusTracks = value;
}

string BluRay::getBluRay()
{
    string bluRay;
    bluRay.append(VectorToString(extraLanguageTracks));//15
    bluRay.append(FIRSTLEVELDELIMSTRNG);
    bluRay.append(VectorToString(extraSubtitleTracks));//16
    bluRay.append(FIRSTLEVELDELIMSTRNG);
    bluRay.append(VectorToString(bonusTracks));//17

    return bluRay;
}

BluRay::BluRay()
{

}

BluRay::BluRay(Material inputMaterial, vector<string> extraLanguageTracks, vector<string> extraSubtitleTracks, vector<string> bonusTracks)
{

}
