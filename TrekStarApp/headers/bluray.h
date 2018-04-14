#ifndef BLURAY_H
#define BLURAY_H
#include "main.h"
#include "material.h"

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
    string getBluRay(){
        string bluRay;
        bluRay.append(VectorToString(extraLanguageTracks));
        bluRay.append(",");
        bluRay.append(VectorToString(extraSubtitleTracks));
        bluRay.append(",");
        bluRay.append(VectorToString(bonusTracks));
        bluRay.append(",");
        return bluRay;
    }
};

#endif // BLURAY_H
