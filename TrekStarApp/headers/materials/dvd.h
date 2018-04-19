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
    //DVD(Material baseMaterial,vector<string> extraLanguageTracks, vector<string> extraSubtitleTracks,vector<string> bonusFeatures,string firstSideContent);
    DVD(string idNumber,string title,string vFormat,string aFormat,string language,int runTime,float price, vector<string> subTitleLanguages,
        vector<string> extraLanguageTracks, vector<string> extraSubtitleTracks,vector<string> bonusFeatures,string firstSideContent)
    //    :Material(idNumber, title, vFormat, aFormat, language, runTime, price, subTitleLanguages),
     //     extraLanguageTracks(extraLanguageTracks),extraSubtitleTracks(extraSubtitleTracks),bonusFeatures(bonusFeatures),firstSideContent(firstSideContent)
    {
    }
    vector<string> getExtraLanguageTracks() const;
    void setExtraLanguageTracks(const vector<string> &value);
    vector<string> getExtraSubtitleTracks() const;
    void setExtraSubtitleTracks(const vector<string> &value);
    vector<string> getBonusFeatures() const;
    void setBonusFeatures(const vector<string> &value);
    string getFirstSideContent() const;
    void setFirstSideContent(const string &value);
    string getDVD(){
        string dvd;
//        dvd.append(VectorToString(extraLanguageTracks));
//        dvd.append(",");
//        dvd.append(VectorToString(extraSubtitleTracks));
//        dvd.append(",");
//        dvd.append(VectorToString(bonusFeatures));
//        dvd.append(",");
//        dvd.append(this->firstSideContent);
//        dvd.append(",");
        return dvd;
    }

};

#endif // DVD_H
