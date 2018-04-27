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
    BluRay(string idNumber, string title, string vFormat, string aFormat, string language,
           FrameAspect frame, Packaging package, int runTime, float price,
           vector<string> subTitleLanguages, vector<string> extraLanguageTracks,
           vector<string> extraSubtitleTracks, vector<string> bonusTracks)
        :Material(idNumber,title,vFormat,aFormat,language,frame,package,
                  runTime, price,subTitleLanguages){
        this->extraLanguageTracks=extraLanguageTracks;
        this->extraSubtitleTracks=extraSubtitleTracks;
        this->bonusTracks=bonusTracks;
    }
    vector<string> getExtraLanguageTracks() const;
    void setExtraLanguageTracks(const vector<string> &value);
    vector<string> getExtraSubtitleTracks() const;
    void setExtraSubtitleTracks(const vector<string> &value);
    vector<string> getBonusTracks() const;
    void setBonusTracks(const vector<string> &value);
    string getBluRay();

    bool operator ==(const BluRay& bluRay){
        if(
                this->idNumber==bluRay.idNumber&&
                this->title==bluRay.title&&
                this->vFormat==bluRay.vFormat&&
                this->aFormat==bluRay.aFormat&&
                this->language==bluRay.language&&
                this->frame==bluRay.frame&&
                this->package==bluRay.package&&
                this->runTime==bluRay.runTime&&
                this->price==bluRay.price&&
                this->subTitleLanguages==bluRay.subTitleLanguages&&
                this->extraLanguageTracks==bluRay.extraLanguageTracks&&
                this->extraSubtitleTracks==bluRay.extraSubtitleTracks&&
                this->bonusTracks==bluRay.bonusTracks)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator !=(const BluRay& bluRay){
        if(
                this->idNumber!=bluRay.idNumber||
                this->title!=bluRay.title||
                this->vFormat!=bluRay.vFormat||
                this->aFormat!=bluRay.aFormat||
                this->language!=bluRay.language||
                this->frame!=bluRay.frame||
                this->package!=bluRay.package||
                this->runTime!=bluRay.runTime||
                this->price!=bluRay.price||
                this->subTitleLanguages==bluRay.subTitleLanguages||
                this->extraLanguageTracks!=bluRay.extraLanguageTracks||
                this->extraSubtitleTracks!=bluRay.extraSubtitleTracks||
                this->bonusTracks!=bluRay.bonusTracks)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};

#endif // BLURAY_H
