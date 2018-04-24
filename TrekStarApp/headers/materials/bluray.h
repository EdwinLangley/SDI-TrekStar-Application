#ifndef BLURAY_H
#define BLURAY_H
#include "main.h"
#include "material.h"


using namespace std;


std::string VectorToString(std::vector<std::string> inputVector);
std::vector<std::string> StringToVector(std::string inputString);

class BluRay : public Material
{
private:
    vector<string> extraLanguageTracks;
    vector<string> extraSubtitleTracks;
    vector<string> bonusTracks;


public:
    BluRay();
    BluRay(Material inputMaterial, vector<string> extraLanguageTracks, vector<string> extraSubtitleTracks, vector<string> bonusTracks);
    vector<string> getExtraLanguageTracks() const;
    void setExtraLanguageTracks(const vector<string> &value);
    vector<string> getExtraSubtitleTracks() const;
    void setExtraSubtitleTracks(const vector<string> &value);
    vector<string> getBonusTracks() const;
    void setBonusTracks(const vector<string> &value);
    string getBluRay();
};

#endif // BLURAY_H
