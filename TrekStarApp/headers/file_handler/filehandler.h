#ifndef FILEWRITER_H
#define FILEWRITER_H

#include "main.h"
#include "project.h"
#include "twosideddvd.h"
#include "singlesideddvd.h"
#include "bluray.h"
#include "vhs.h"
#include "combobox.h"

#define PROJECTFILENAME     "ProjectFile.csv"
#define MATERIALFILENAME    "MaterialFile.csv"
#define CREWFILENAME        "CrewFile.csv"

class FileWriter
{
public:
    FileWriter();
    //Stored as
    //$Title,ProjectStatus,Summary,Genre,ReleaseData,<VECTOR of FilmLocations>,Language,
    //<VECTOR of OneSidedDVD>,<VECTOR of TwoSidedDVD>,<VECTOR of BluRay>,<VECTOR of VHS> \n
    void WriteProject(vector<Project> inputProject);
    vector<Project> ReadProjects();

    void WriteMaterials(vector<Project> inputProject);
    vector<string> ReadMaterials();
    Material SplitMaterial(string inputLine);

    void WriteCrew(string crewID, vector<CrewMember> inputcrew);
    vector<string>ReadCrew();
    vector<CrewMember> CreateCrewMembers(string inputLine);
    CrewMember CreateMember(string inputLine);

    void WriteOneSidedDVD(SingleSidedDVD inputDVDS);
    SingleSidedDVD ReadOneSidedDVD(string input);

    void WriteTwoSidedDVD(TwoSidedDVD inputDVDS);
    TwoSidedDVD ReadTwoSidedDVD(string input);

    void WriteBluRay(BluRay inputDVDS);
    BluRay ReadBluRay(string input);

    void WriteVHS(VHS inputDVDS);
    VHS ReadVHS(string input);

    void WriteComboBox(ComboBox inputDVDS);
    ComboBox ReadComboBox(string input);

    vector<Project> BuildProjectList();
};

#endif // FILEWRITER_H
