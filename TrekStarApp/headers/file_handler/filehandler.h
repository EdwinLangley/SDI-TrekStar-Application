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
    static void WriteOneSidedDVD(SingleSidedDVD inputDVDS);
    static void WriteTwoSidedDVD(TwoSidedDVD inputDVDS);
    static void WriteBluRay(BluRay inputDVDS);
    static void WriteVHS(VHS inputDVDS);
    static void WriteComboBox(ComboBox inputDVDS);
};

#endif // FILEWRITER_H
