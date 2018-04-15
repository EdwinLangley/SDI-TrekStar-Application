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

class FileWriter
{
public:
    FileWriter();
    //Stored as
    //$Title,ProjectStatus,Summary,Genre,ReleaseData,<VECTOR of FilmLocations>,Language,
    //<VECTOR of OneSidedDVD>,<VECTOR of TwoSidedDVD>,<VECTOR of BluRay>,<VECTOR of VHS> \n
    static void WriteProject(vector<Project> inputProject);
    static vector<Project> ReadProjects(string input);

    static void WriteMaterials(vector<Project> inputProject);
    static vector<string> ReadMaterials();

    static void WriteCrew(vector<string> inputcrew);
    static vector<string>ReadCrew();

    static void WriteOneSidedDVD(SingleSidedDVD inputDVDS);
    static SingleSidedDVD ReadOneSidedDVD(string input);

    static void WriteTwoSidedDVD(TwoSidedDVD inputDVDS);
    static TwoSidedDVD ReadTwoSidedDVD(string input);

    static void WriteBluRay(BluRay inputDVDS);
    static BluRay ReadBluRay(string input);

    static void WriteVHS(VHS inputDVDS);
    static VHS ReadVHS(string input);

    static void WriteComboBox(ComboBox inputDVDS);
    static ComboBox ReadComboBox(string input);

    static vector<Project> BuildProjectList();
};

#endif // FILEWRITER_H
