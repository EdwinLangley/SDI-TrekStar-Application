#ifndef BLURAY_H
#define BLURAY_H

#include "material.h"
#include <string>
#include <vector>

using namespace std;

class BluRay : public Material
{
private:
    vector<string> extraLanguageTracks;
    vector<string> extraSubtitleTracks;
    vector<string> bonusTracks;


public:
    BluRay();
    vector<string> getExtraLanguageTracks() const;
    void setExtraLanguageTracks(const vector<string> &value);
    vector<string> getExtraSubtitleTracks() const;
    void setExtraSubtitleTracks(const vector<string> &value);
    vector<string> getBonusTracks() const;
    void setBonusTracks(const vector<string> &value);
};

#endif // BLURAY_H
