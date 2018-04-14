#include "filehandler.h"
#include "doublylinkedlist.h"

using namespace std;


void WriteProject(vector<Project> inputProject){
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
        newLine.append(inputProject[i].getLanguage());
        newLine.append(",");
        newLine.append(VectorToString(inputProject[i].getFilmLocations()));
        newLine.append(",");
        newLine.append(VectorToString(inputProject[i].getMaterials()));
        newLine.append(",");
        newLine.append("\n");
        outputFile << newLine;
    }
    outputFile.close();
}

vector<Project> ReadProjects(){
    vector<Project> returnedProjects;
    ifstream inputFile;
    inputFile.open(PROJECTFILENAME);
    string line;
    while (getline(inputFile,line)) {
        Project tempProject;
        std::stringstream lineStream;
        lineStream<<line;
        string section;
        vector<string> resultsStorage, vectorStorage;
        //Get member variables
        while (getline(lineStream,section,',')){
            resultsStorage.push_back(section);
        }
        //Build a project
        tempProject.setTitle(resultsStorage[0]);
        tempProject.setProjectStatus(resultsStorage[1]);
        tempProject.setSummary(resultsStorage[2]);
        tempProject.setGenre(resultsStorage[3]);
        tempProject.setReleaseDate(resultsStorage[4]);
        tempProject.setLanguage(resultsStorage[5]);
        tempProject.setFilmLocations(StringToVector(resultsStorage[6]));
        tempProject.setMaterials(StringToVector(resultsStorage[7]));
        //Add project to returned ones
        returnedProjects.push_back(tempProject);
    }
    return returnedProjects;
}

void WriteMaterials(DoublyLinkedList Materials){

}

void WriteOneSidedDVD(SingleSidedDVD inputDVDS){
    string oneSidedDVD="1DVD";
    twoSidedDVD.append(",");;
    oneSidedDVD=inputDVDS.getMaterials();
    oneSidedDVD.append(inputDVDS.getDVD());
    oneSidedDVD.append("\n");
    ofstream outputFile;
    outputFile.open(MATERIALFILENAME);
    outputFile<<oneSidedDVD;
    outputFile.close();
}

SingleSidedDVD ReadOneSidedDVD(){

}

void WriteTwoSidedDVD(TwoSidedDVD inputDVDS){
    string twoSidedDVD="2DVD";
    twoSidedDVD.append(",");
    twoSidedDVD=inputDVDS.getMaterials();
    twoSidedDVD.append(inputDVDS.getDVD());
    twoSidedDVD.append(inputDVDS.getSecondSideContent());
    twoSidedDVD.append("\n");
    ofstream outputFile;
    outputFile.open(MATERIALFILENAME);
    outputFile<<twoSidedDVD;
    outputFile.close();
}

void WriteBluRay(BluRay inputDVDS){
    string bluRay="BR";
    bluRay.append(",");
    bluRay=inputDVDS.getMaterials();
    bluRay.append(inputDVDS.getBluRay());
    bluRay.append("\n");
    ofstream outputFile;
    outputFile.open(MATERIALFILENAME);
    outputFile<<bluRay;
    outputFile.close();
}

void WriteVHS(VHS inputDVDS){
    string vhs="VHS";
    vhs.append(",");
    vhs=inputDVDS.getMaterials();
    vhs.append("\n");
    ofstream outputFile;
    outputFile.open(MATERIALFILENAME);
    outputFile<<vhs;
    outputFile.close();
}

void WriteComboBox(ComboBox inputDVDS){
    string comboBox;

}
