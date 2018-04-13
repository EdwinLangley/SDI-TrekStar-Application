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
        for(int i=0; i<this->extraLanguageTracks.size();i++){
            bluRay.append(this->extraLanguageTracks[i]);
            bluRay.append(",");
        }
        for(int i=0; i<this->extraSubtitleTracks.size();i++){
        bluRay.append(this->extraSubtitleTracks[i]);
        bluRay.append(",");
        }
        for(int i=0; i<this->bonusTracks.size();i++){
        bluRay.append(this->bonusTracks[i]);
        bluRay.append(",");
        }
        return bluRay;
    }
};

#endif // BLURAY_H
