#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE SDITests
#include <boost/test/unit_test.hpp>

#include <vector>
#include <iostream>

#include "material.h"
#include "frameaspect.h"
#include "packaging.h"
#include "project.h"
#include "crewMember.h"
#include "singlesideddvd.h"
#include "twosideddvd.h"
#include "doublylinkedlist.h"

namespace tt = boost::test_tools;

BOOST_AUTO_TEST_SUITE( MaterialTests )


BOOST_AUTO_TEST_CASE( MaterialCorrectInitId )
{
   Material material;
   BOOST_CHECK_EQUAL( material.getIdNumber(), "0");
}

BOOST_AUTO_TEST_CASE( MaterialCorrectInitRuntime )
{
   Material material;
   BOOST_CHECK_EQUAL( material.getRunTime(), 0);
}

BOOST_AUTO_TEST_CASE( MaterialCorrectInitPrice )
{
   Material material;
   BOOST_CHECK_EQUAL( material.getPrice(), 0);
}


BOOST_AUTO_TEST_CASE( MaterialSetVFormat )
{
   Material material;
   material.setVFormat("MP4");
   BOOST_CHECK_EQUAL( material.getVFormat(), "MP4");
}

BOOST_AUTO_TEST_CASE( MaterialSetTitle )
{
   Material material;
   material.setTitle("Spider Man");
   BOOST_CHECK_EQUAL( material.getTitle(), "Spider Man");
}

BOOST_AUTO_TEST_CASE( MaterialSetLanguage )
{
   Material material;
   material.setLanguage("Italian");
   BOOST_CHECK_EQUAL( material.getLanguage(), "Italian");
}

BOOST_AUTO_TEST_CASE( MaterialComplexSubObjectSubtitleLanguage)
{
   Material material;
   vector<string> langVec = {"English","French","Spanish"};
   material.setSubTitleLanguages(langVec);
   auto returnVec = material.getSubTitleLanguages();
   BOOST_TEST(returnVec == langVec , tt::per_element());
}

BOOST_AUTO_TEST_CASE( MaterialComplexSubObjectFrameAspectH )
{
   Material material;
   FrameAspect fa(16,9,"16:9");
   material.setFrame(fa);
   auto returnfa = material.getFrame();
   BOOST_CHECK_EQUAL(returnfa.getHorizontalRatio(), 16);
}

BOOST_AUTO_TEST_CASE( MaterialComplexSubObjectFrameAspectV )
{
   Material material;
   FrameAspect fa(16,9,"16:9");
   material.setFrame(fa);
   auto returnfa = material.getFrame();
   BOOST_CHECK_EQUAL(returnfa.getVerticalRatio(), 9);
}

BOOST_AUTO_TEST_CASE( MaterialComplexSubObjectFrameAspectD )
{
   Material material;
   FrameAspect fa(16,9,"16:9");
   material.setFrame(fa);
   auto returnfa = material.getFrame();
   BOOST_CHECK_EQUAL(returnfa.getRatioDescription(), "16:9");
}

BOOST_AUTO_TEST_CASE( MaterialComplexSubObjectPackageMaterial )
{
   Material material;
   Packaging packaging("Card",50,20,15);
   material.setPackage(packaging);
   auto returnPackaging = material.getPackage();
   BOOST_CHECK_EQUAL(returnPackaging.getMaterial(), "Card");
}

BOOST_AUTO_TEST_CASE( MaterialComplexSubObjectPackageWidth )
{
   Material material;
   Packaging packaging("Card",50,20,15);
   material.setPackage(packaging);
   auto returnPackaging = material.getPackage();
   BOOST_CHECK_EQUAL(returnPackaging.getWidth(), 50);
}

BOOST_AUTO_TEST_CASE( MaterialComplexSubObjectPackageHeight )
{
   Material material;
   Packaging packaging("Card",50,20,15);
   material.setPackage(packaging);
   auto returnPackaging = material.getPackage();
   BOOST_CHECK_EQUAL(returnPackaging.getHeight(), 20);
}

BOOST_AUTO_TEST_CASE( MaterialComplexSubObjectPackageDepth )
{
   Material material;
   Packaging packaging("Card",50,20,15);
   material.setPackage(packaging);
   auto returnPackaging = material.getPackage();
   BOOST_CHECK_EQUAL(returnPackaging.getDepth(), 15);
}

BOOST_AUTO_TEST_CASE( MaterialFloatPriceAccuracyReasonable )
{
   Material material;
   material.setPrice(10.06);
   BOOST_TEST(material.getPrice() == 10.06, tt::tolerance(0.01));
}

BOOST_AUTO_TEST_CASE( MaterialFloatPriceAccuracyUnReasonable )
{
   Material material;
   material.setPrice(10.6003000045);
   BOOST_CHECK_EQUAL(material.getPrice(), 10.6003000045);
}

BOOST_AUTO_TEST_CASE( MaterialMaxRunTimeUnder )
{
   Material material;
   material.setRunTime(13);
   BOOST_CHECK_EQUAL(material.getRunTime(), 13);
}

BOOST_AUTO_TEST_CASE( MaterialMaxRunTimeOver )
{
   Material material;
   material.setRunTime(2147483648);
   BOOST_CHECK_EQUAL(material.getRunTime(), 2147483648);
}

BOOST_AUTO_TEST_CASE( MaterialConstructorID )
{
   FrameAspect fa(16,9,"16:9");
   Packaging packaging("Card",50,20,15);
   vector<string> langVector = {"English","French"};
   Material material("1","Cars","MP4","WAV", "English", fa, packaging,90,10.15,langVector);
   BOOST_CHECK_EQUAL(material.getIdNumber(), "1");
}

BOOST_AUTO_TEST_CASE( MaterialConstructorTitle )
{
   FrameAspect fa(16,9,"16:9");
   Packaging packaging("Card",50,20,15);
   vector<string> langVector = {"English","French"};
   Material material("1","Cars","MP4","WAV", "English", fa, packaging,90,10.15,langVector);
   BOOST_CHECK_EQUAL(material.getTitle(), "Cars");
}

BOOST_AUTO_TEST_CASE( MaterialConstructorVFormat )
{
   FrameAspect fa(16,9,"16:9");
   Packaging packaging("Card",50,20,15);
   vector<string> langVector = {"English","French"};
   Material material("1","Cars","MP4","WAV", "English", fa, packaging,90,10.15,langVector);
   BOOST_CHECK_EQUAL(material.getVFormat(), "MP4");
}

BOOST_AUTO_TEST_CASE( MaterialConstructorAFormat )
{
   FrameAspect fa(16,9,"16:9");
   Packaging packaging("Card",50,20,15);
   vector<string> langVector = {"English","French"};
   Material material("1","Cars","MP4","WAV", "English", fa, packaging,90,10.15,langVector);
   BOOST_CHECK_EQUAL(material.getAFormat(), "WAV");
}

BOOST_AUTO_TEST_CASE( MaterialConstructorLanguage )
{
   FrameAspect fa(16,9,"16:9");
   Packaging packaging("Card",50,20,15);
   vector<string> langVector = {"English","French"};
   Material material("1","Cars","MP4","WAV", "English", fa, packaging,90,10.15,langVector);
   BOOST_CHECK_EQUAL(material.getLanguage(), "English");
}

BOOST_AUTO_TEST_CASE( MaterialConstructorFrameAspect )
{
   FrameAspect fa(16,9,"16:9");
   Packaging packaging("Card",50,20,15);
   vector<string> langVector = {"English","French"};
   Material material("1","Cars","MP4","WAV", "English", fa, packaging,90,10.15,langVector);
   auto returnFa = material.getFrame();
   BOOST_CHECK_EQUAL(returnFa.getRatioDescription(), "16:9");
}

BOOST_AUTO_TEST_CASE( MaterialConstructorPackaging )
{
   FrameAspect fa(16,9,"16:9");
   Packaging packaging("Card",50,20,15);
   vector<string> langVector = {"English","French"};
   Material material("1","Cars","MP4","WAV", "English", fa, packaging,90,10.15,langVector);
   auto returnPackaging = material.getPackage();
   BOOST_CHECK_EQUAL(returnPackaging.getMaterial(), "Card");
}

BOOST_AUTO_TEST_CASE( MaterialConstructorRuntime )
{
   FrameAspect fa(16,9,"16:9");
   Packaging packaging("Card",50,20,15);
   vector<string> langVector = {"English","French"};
   Material material("1","Cars","MP4","WAV", "English", fa, packaging,90,10.15,langVector);
   BOOST_CHECK_EQUAL(material.getRunTime(), 90);
}

BOOST_AUTO_TEST_CASE( MaterialConstructorPrice )
{
   FrameAspect fa(16,9,"16:9");
   Packaging packaging("Card",50,20,15);
   vector<string> langVector = {"English","French"};
   Material material("1","Cars","MP4","WAV", "English", fa, packaging,90,10.15,langVector);
   BOOST_TEST(material.getPrice() == 10.15, tt::tolerance(0.01));
}

BOOST_AUTO_TEST_CASE( MaterialConstructorLanguageVec )
{
   FrameAspect fa(16,9,"16:9");
   Packaging packaging("Card",50,20,15);
   vector<string> langVector = {"English","French"};
   Material material("1","Cars","MP4","WAV", "English", fa, packaging,90,10.15,langVector);
   auto returnvec = material.getSubTitleLanguages();
   BOOST_TEST(returnvec == langVector , tt::per_element());
}


BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE( ProjectTests )

BOOST_AUTO_TEST_CASE( ProjectMakeNewProjectTitle )
{
   Project project;
   BOOST_TEST(project.getTitle() == "TestTitle");
}

BOOST_AUTO_TEST_CASE( ProjectMakeNewProjectStatus )
{
   Project project;
   BOOST_TEST(project.getProjectStatus() == "TestStatus");
}

BOOST_AUTO_TEST_CASE( ProjectMakeNewProjectSummary )
{
   Project project;
   BOOST_TEST(project.getSummary() == "TestSummary");
}

BOOST_AUTO_TEST_CASE( ProjectMakeNewProjectGenre )
{
   Project project;
   BOOST_TEST(project.getGenre() == "TestGenre");
}

BOOST_AUTO_TEST_CASE( ProjectMakeNewProjectDate )
{
   Project project;
   BOOST_TEST(project.getReleaseDate() == "01/01/1000");
}

BOOST_AUTO_TEST_CASE( ProjectMakeNewProjectlanguage )
{
   Project project;
   BOOST_TEST(project.getLanguage() == "TestLanguage");
}

BOOST_AUTO_TEST_CASE( ProjectMakeNewProjectRuntime )
{
   Project project;
   BOOST_TEST(project.getRunTime() == 0);
}

BOOST_AUTO_TEST_CASE( ProjectMakeNewProjectWeeklyBox )
{
   Project project;
   BOOST_TEST(project.getWeeklyBoxFigures() == 0);
}

BOOST_AUTO_TEST_CASE( ProjectMakeNewProjectKeyWords )
{
   Project project;
   vector<string> keywordvec  = {"Keyword1","Keyword2","Keyword3"};
   project.setKeywords(keywordvec);
   auto returnvec = project.getKeywords();
   BOOST_TEST( returnvec == keywordvec, tt::per_element());
}

BOOST_AUTO_TEST_CASE( ProjectMakeNewProjectFilmLoc )
{
    Project project;
    vector<string> locvec  = {"Keyword1","Keyword2","Keyword3"};
    project.setFilmLocations(locvec);
    auto returnvec = project.getFilmLocations();
    BOOST_TEST( returnvec == locvec, tt::per_element());
}

BOOST_AUTO_TEST_CASE( ProjectMakeNewProjectCrewID )
{
   Project project;
   BOOST_TEST(project.getCrewID() == 0);
}
//TODO VEC

BOOST_AUTO_TEST_CASE( ProjectMakeNewProjectCrew )
{
   Project project;
   CrewMember crew1;
   crew1.setName("Angela");
   CrewMember crew2;
   crew2.setName("Steve");
   CrewMember crew3;
   crew3.setName("Dan");
   vector<CrewMember> crewVec = {crew1,crew2,crew3};
   project.setCrew(crewVec);
   auto returncrewVec = project.getCrew();
   CrewMember originalsecondname = crewVec.at(1);
   CrewMember newsecondname = returncrewVec.at(1);
   BOOST_TEST(originalsecondname.getName() == newsecondname.getName());
}

BOOST_AUTO_TEST_CASE( ProjectMakeNewProjectSingleDVD )
{
   Project project;
   auto instanceSDVD = project.getSingleDVD();
   BOOST_TEST(instanceSDVD.getPrice() == 0);
}

BOOST_AUTO_TEST_CASE( ProjectMakeNewProjectTwoDVD )
{
    Project project;
    auto instanceSDVD = project.getTwoDVD();
    BOOST_TEST(instanceSDVD.getPrice() == 0);
}

BOOST_AUTO_TEST_CASE( ProjectMakeNewProjectBluray )
{
    Project project;
    auto instanceSDVD = project.getBluRay();
    BOOST_TEST(instanceSDVD.getPrice() == 0);
}

BOOST_AUTO_TEST_CASE( ProjectMakeNewProjectVHS )
{
    Project project;
    auto instance = project.getVhs();
    BOOST_TEST(instance.getPrice() == 0);
}

BOOST_AUTO_TEST_CASE( ProjectMakeNewProjectComboBox )
{
    Project project;
    auto instance = project.getComboBox();
    BOOST_TEST(instance.getNumberOfDVDs() == 0);
}


BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE( LinkedListTests )

BOOST_AUTO_TEST_CASE( LinkedListMakeNew )
{
    DoublyLinkedList doublyLinkedList;
    Project project;
    doublyLinkedList.insert_start(project);
    BOOST_TEST(doublyLinkedList.size() = 1);

}

BOOST_AUTO_TEST_CASE( LinkedListMakeNewSort )
{
    DoublyLinkedList doublyLinkedList;
    Project project;
    project.setTitle("Alpha");
    Project project1;
    project1.setTitle("Beta");
    Project project2;
    project2.setTitle("Gamma");
    doublyLinkedList.insert_start(project);
    doublyLinkedList.insert_start(project1);
    doublyLinkedList.insert_start(project2);
    auto returnvec = doublyLinkedList.sortProject(doublyLinkedList.getAllFilmTitles());
    vector<string> actualorder = {"Alpha","Beta","Gamma"};

    BOOST_TEST(returnvec == actualorder , tt::per_element());

}

BOOST_AUTO_TEST_SUITE_END()