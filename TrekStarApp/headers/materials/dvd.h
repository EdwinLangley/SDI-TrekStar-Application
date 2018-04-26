#ifndef DVD_H
#define DVD_H

#include "main.h"
#include "material.h"

using namespace std;

class DVD : public Material
{
protected:
    vector<string> extraLanguageTracks;
    vector<string> extraSubtitleTracks;
    vector<string> bonusFeatures;

    string firstSideContent;

public:
    DVD();
    DVD(string idNumber, string title, string vFormat, string aFormat, string language,
        FrameAspect frame, Packaging package, int runTime, float price,
        vector<string> subTitleLanguages, vector<string> extraLanguageTracks,
        vector<string> extraSubtitleTracks, vector<string> bonusFeatures, string firstSideContent)
        :Material(idNumber,title,vFormat,aFormat,language,frame,package,
                  runTime, price,subTitleLanguages)
    {
        this->extraLanguageTracks=extraLanguageTracks;
        this->extraSubtitleTracks=extraSubtitleTracks;
        this->bonusFeatures=bonusFeatures;
        this->firstSideContent=firstSideContent;
    }
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
