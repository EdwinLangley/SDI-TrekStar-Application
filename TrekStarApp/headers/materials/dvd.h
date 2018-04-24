#ifndef DVD_H
#define DVD_H

#include "main.h"
#include "material.h"

using namespace std;

class DVD : public Material
{
private:
    vector<string> extraLanguageTracks;
    vector<string> extraSubtitleTracks;
    vector<string> bonusFeatures;

    string firstSideContent;

public:
    DVD();
    vector<string> getExtraLanguageTracks() const;
    void setExtraLanguageTracks(const vector<string> &value);
    vector<string> getExtraSubtitleTracks() const;
    void setExtraSubtitleTracks(const vector<string> &value);
    vector<string> getBonusFeatures() const;
    void setBonusFeatures(const vector<string> &value);
    string getFirstSideContent() const;
    void setFirstSideContent(const string &value);
    string getDVD();

};

#endif // DVD_H
