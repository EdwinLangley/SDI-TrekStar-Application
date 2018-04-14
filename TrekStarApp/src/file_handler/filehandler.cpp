#include "filehandler.h"
#include "doublylinkedlist.h"

using namespace std;

void WriteOneSidedDVD(SingleSidedDVD inputDVDS){
    string oneSidedDVD="1DVD,";
    oneSidedDVD=inputDVDS.getMaterials();
    oneSidedDVD.append(inputDVDS.getDVD());
    oneSidedDVD.append("\n");
    ofstream outputFile;
    outputFile.open(MATERIALFILENAME);
    outputFile<<oneSidedDVD;
    outputFile.close();
}

SingleSidedDVD ReadOneSidedDVD(string input)
{

}

static void WriteTwoSidedDVD(TwoSidedDVD inputDVDS){
    string twoSidedDVD="2DVD,";
    twoSidedDVD=inputDVDS.getMaterials();
    twoSidedDVD.append(inputDVDS.getDVD());
    twoSidedDVD.append(inputDVDS.getSecondSideContent());
    twoSidedDVD.append("\n");
    ofstream outputFile;
    outputFile.open(MATERIALFILENAME);
    outputFile<<twoSidedDVD;
    outputFile.close();
}

TwoSidedDVD ReadTwoSidedDVD(string input)
{

}

static void WriteBluRay(BluRay inputDVDS){
    string bluRay="BRAY,";
    bluRay=inputDVDS.getMaterials();
    bluRay.append(inputDVDS.getBluRay());
    bluRay.append("\n");
    ofstream outputFile;
    outputFile.open(MATERIALFILENAME);
    outputFile<<bluRay;
    outputFile.close();
}

BluRay ReadBluRay(string input)
{

}

static void WriteVHS(VHS inputDVDS){
    string vhs="VHSS,";
    vhs=inputDVDS.getMaterials();
    vhs.append("\n");
    ofstream outputFile;
    outputFile.open(MATERIALFILENAME);
    outputFile<<vhs;
    outputFile.close();
}

VHS ReadVHS(string input)
{

}

static void WriteComboBox(ComboBox inputDVDS){
    string comboBox="CBOX";

}

ComboBox ReadComboBox(string input)
{

}

static void WriteMaterials(vector<Project> inputProject){
    for (int i = 0; i < inputProject.size(); i++) {
        if(inputProject[i].singleDVD.getIdNumber()!="0"){
            WriteOneSidedDVD(inputProject[i].singleDVD);
        }
        if(inputProject[i].twoDVD.getIdNumber()!="0"){
            WriteTwoSidedDVD(inputProject[i].twoDVD);
        }
        if(inputProject[i].bluRay.getIdNumber()!="0"){
            WriteBluRay(inputProject[i].bluRay);
        }
        if(inputProject[i].vhs.getIdNumber()!="0"){
            WriteVHS(inputProject[i].vhs);
        }
        if(inputProject[i].comboBox.getIdsOfDVDs()[0]!="0"){
            WriteComboBox(inputProject[i].comboBox);
        }
    }
}

static vector<string> ReadMaterials(){
    vector<string> materials;
    ifstream inputFile;
    inputFile.open(MATERIALFILENAME);
    string line;
    while (getline(inputFile,line)) {
        materials.push_back(line);
    }
    inputFile.close();
    return materials;
}

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
        newLine.append(inputProject[i].getLanguage());
        newLine.append(",");
        newLine.append(inputProject[i].getCrewID());
        newLine.append(",");
        newLine.append(VectorToString(inputProject[i].getFilmLocations()));
        newLine.append(",");
        newLine.append(VectorToString(inputProject[i].getMaterials()));
        newLine.append(",");
        newLine.append("\n");
        outputFile << newLine;
        WriteMaterials(inputProject);
    }
    outputFile.close();
}

static vector<Project> ReadProjects(){
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
        tempProject.setCrewID(resultsStorage[6]);
        tempProject.setFilmLocations(StringToVector(resultsStorage[7]));
        //USE THIS TO DETERMINE WHICH MATERIALS TO ASSIGN TO THE PROJECT
        tempProject.setMaterials(StringToVector(resultsStorage[8]));
        //Add project to returned ones
        returnedProjects.push_back(tempProject);
    }
    inputFile.close();
    return returnedProjects;
}

static void WriteCrew(vector<string> inputcrew){

}

static vector<string>ReadCrew(){

}

static vector<Project> BuildProjectList(){
    vector<Project>projects=ReadProjects();
    vector<string>materialLines=ReadMaterials();
    vector<string>crewLines=ReadCrew();
    //Go through Project list
    for (int i=0; i<projects.size();i++){
        //Go through material list for the project
        for (int j=0;j<projects[i].materialIDs.size();j++){
            //Go through list of materials and then compare it to the current material
            for (int k=0;k<materialLines.size();k++){
                string line=materialLines[k];
                string type,id;
                stringstream ss;
                ss<<line;
                getline(ss,type,',');
                getline(ss,id,',');
                //If the current material matches a line
                if(projects[i].materialIDs[j]==id){
                    //CALL WHICHEVER READ MATERIAL FUNCTION BASED ON WHATEVER MATERIAL TYPE
                    if(type=="1DVD"){
                        //Make a 1 sided dvd
                        //Add to project
                        projects[i].singleDVD=ReadOneSidedDVD(line);
                    }else if (type=="2DVD") {
                        //Make a 2 sided DVD
                        //Add to project
                        projects[i].twoDVD=ReadTwoSidedDVD(line);
                    }else if (type=="BRAY") {
                        //Make a BluRay
                        //Add to project
                        projects[i].bluRay=ReadBluRay(line);
                    }else if (type=="VHSS"){
                        //Make a VHS
                        //Add to project
                        projects[i].vhs=ReadVHS(line);
                    }else if (type=="CBOX"){
                        //Make a ComboBox
                        //Add to project
                        projects[i].comboBox=ReadComboBox(line);
                    }
                }
            }
        }
        //Go through list of crew members and do the same as materials
        //Go through list of crews and then compare it to the current crewID
        for (int j=0;j<crewLines.size();j++){
            string line=crewLines[j];
            string type,id;
            stringstream ss;
            ss<<line;
            getline(ss,type,',');
            getline(ss,id,',');
            if(projects[i].getCrewID()==id){
                //Write found crew to the project
            }
        }
    }
}
