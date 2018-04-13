#include "filehandler.h"

using namespace std;

static void WriteProject(vector<Project> inputProject){
    ofstream outputFile;
    outputFile.open(PROJECTFILENAME);
    for (int i = 0; i < inputProject.size(); i++) {
        string newLine = "$";
        newLine.append(inputProject[i].getTitle());
        newLine.append(",");
        newLine.append(inputProject[i].getProjectStatus());
        newLine.append(",");
        newLine.append(inputProject[i].getSummary());
        newLine.append(",");
        newLine.append(inputProject[i].getGenre());
        newLine.append(",");
        newLine.append(inputProject[i].getReleaseDate());
        newLine.append(",");
        newLine.append("<");
        string filmLocationString;
        vector<string> filmLocations=inputProject[i].getFilmLocations();
        for (int j = 0; j < filmLocations.size(); j++) {
            filmLocationString.append(filmLocations[j]);
            filmLocationString.append(",");
        }
        newLine.append(filmLocationString);
        newLine.append(">");
        newLine.append(",");
        newLine.append(inputProject[i].getLanguage());
        newLine.append("\n");
        outputFile << newLine;
    }
    outputFile.close();
}

static vector<Project> ReadProjects(){
    vector<Project> returnedProjects;

    return returnedProjects;
}

static void WriteOneSidedDVD(SingleSidedDVD inputDVDS){
    string oneSidedDVD;
    oneSidedDVD=inputDVDS.getMaterials();
    oneSidedDVD.append(inputDVDS.getDVD());
    oneSidedDVD.append("\n");
    ofstream outputFile;
    outputFile.open(MATERIALFILENAME);
    outputFile<<oneSidedDVD;
    outputFile.close();
}

static void WriteTwoSidedDVD(TwoSidedDVD inputDVDS){
    string twoSidedDVD;
    twoSidedDVD=inputDVDS.getMaterials();
    twoSidedDVD.append(inputDVDS.getDVD());
    twoSidedDVD.append(inputDVDS.getSecondSideContent());
    twoSidedDVD.append("\n");
    ofstream outputFile;
    outputFile.open(MATERIALFILENAME);
    outputFile<<twoSidedDVD;
    outputFile.close();
}

static void WriteBluRay(BluRay inputDVDS){
    string bluRay;
    bluRay=inputDVDS.getMaterials();
    bluRay.append(inputDVDS.getBluRay());
    bluRay.append("\n");
    ofstream outputFile;
    outputFile.open(MATERIALFILENAME);
    outputFile<<bluRay;
    outputFile.close();
}

static void WriteVHS(VHS inputDVDS){
    string vhs;
    vhs=inputDVDS.getMaterials();
    vhs.append("\n");
    ofstream outputFile;
    outputFile.open(MATERIALFILENAME);
    outputFile<<vhs;
    outputFile.close();
}

static void WriteComboBox(ComboBox inputDVDS){
    string comboBox;

}
