#ifndef FILEWRITER_H
#define FILEWRITER_H

#include "main.h"
#include "project.h"
#include "twosideddvd.h"
#include "singlesideddvd.h"
#include "bluray.h"
#include "vhs.h"
#include "combobox.h"

class FileWriter
{
public:
    vector<Project> OldProjectList;
    vector<Project> UpdatedProjectList;
    //CHANGE THIS TO A RELEVANT VALUE
    int ReportEarningsLimit=100;

    FileWriter();
    ~FileWriter();
    //Updated
    //Stored as
    //Title#ProjectStatus#Summary#Genre#ReleaseDate#Language#CrewID#WeeklyBoxFigures#RunTime#VECTOR of keywords#VECTOR of filmLocations#vector of MaterialIDs\n
    void WriteProject();
    vector<Project> ReadProjects();
    //Updated
    void WriteMaterials(vector<Project> inputProject);
    vector<string> ReadMaterials();

    //Utility
    vector<string> SplitLine(string inputLine);
    void BuildReport();

    //Updated
    void WriteCrew(string crewID, vector<CrewMember> inputcrew);
    vector<string>ReadCrew();
    vector<CrewMember> CreateCrewMembers(string inputLine);
    CrewMember CreateMember(string inputLine);

    //Updated
    void WriteOneSidedDVD(SingleSidedDVD inputDVDS);
    SingleSidedDVD ReadOneSidedDVD(string input);

    //Updated
    void WriteTwoSidedDVD(TwoSidedDVD inputDVDS);
    TwoSidedDVD ReadTwoSidedDVD(string input);

    //Updated
    void WriteBluRay(BluRay inputDVDS);
    BluRay ReadBluRay(string input);

    //Updated
    void WriteVHS(VHS inputDVDS);
    VHS ReadVHS(string input);

    //Updated
    void WriteComboBox(ComboBox inputDVDS);
    ComboBox ReadComboBox(string input);

    vector<Project> BuildProjectList();
};

#endif // FILEWRITER_H
