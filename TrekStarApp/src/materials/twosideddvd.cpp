#include "twosideddvd.h"

string TwoSidedDVD::getSecondSideContent() const
{
    return secondSideContent;
}

void TwoSidedDVD::setSecondSideContent(const string &value)
{
    secondSideContent = value;
}

TwoSidedDVD::TwoSidedDVD()
{

}

//TwoSidedDVD::TwoSidedDVD(Material baseMaterial, vector<string> extraLanguageTracks, vector<string> extraSubtitleTracks, vector<string> bonusFeatures, string firstSideContent, string secondSideContent)
//{

//    this->idNumber=baseMaterial.getIdNumber();
//    this->title=baseMaterial.getTitle();
//    this->vFormat=baseMaterial.getVFormat();
//    this->aFormat=baseMaterial.getAFormat();
//    this->language=baseMaterial.getLanguage();
//    this->frame=baseMaterial.getFrame();
//    this->package=baseMaterial.getPackage();
//    this->runTime=baseMaterial.getRunTime();
//    this->price=baseMaterial.getPrice();
//    this->subTitleLanguages=baseMaterial.getSubTitleLanguages();
//    this->extraLanguageTracks=extraLanguageTracks;
//    this->extraSubtitleTracks=extraSubtitleTracks;
//    this->bonusFeatures=bonusFeatures;
//    this->firstSideContent=firstSideContent;
//    this->secondSideContent=secondSideContent;
//}
