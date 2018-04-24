#include "filehandler.h"

using namespace std;

//TAKE MATERIAL(ABSTRACT CLASS COMPONENT) OUT OF A DERRIVED CLASS
Material FileWriter::SplitMaterial(string inputLine){

    stringstream ss;
    string section;
    ss<<inputLine;
    vector<string> materialStorage;
    while(getline(ss,section,',')){
        materialStorage.push_back(section);
    }
    FrameAspect frame(stoi(materialStorage[5]),stoi(materialStorage[6]),materialStorage[7]);
    Packaging package(materialStorage[8],stoi(materialStorage[9]),stoi(materialStorage[10]),stoi(materialStorage[11]));
    Material outputMaterial(materialStorage[0],materialStorage[1],materialStorage[2],materialStorage[3],materialStorage[4],
            frame, package, stoi(materialStorage[12]),stof(materialStorage[13]),StringToVector(materialStorage[14]));
    return outputMaterial;
}

void FileWriter::WriteOneSidedDVD(SingleSidedDVD inputDVDS){
    string oneSidedDVD="1DVD,";
    oneSidedDVD=inputDVDS.getMaterials();
    oneSidedDVD.append(inputDVDS.getDVD());
    oneSidedDVD.append("\n");
    ofstream outputFile;
    outputFile.open(MATERIALFILENAME);
    outputFile<<oneSidedDVD;
    outputFile.close();
}

SingleSidedDVD FileWriter::ReadOneSidedDVD(string input)
{
    stringstream ss;
    string section;
    ss<<input;
    vector<string> materialStorage;
    while(getline(ss,section,',')){
        materialStorage.push_back(section);
    }
    vector<string> extraLanguageTracks=StringToVector(materialStorage[8]);
    vector<string> extraSubtitleTracks=StringToVector(materialStorage[9]);
    vector<string> bonusFeatures=StringToVector(materialStorage[10]);
    string firstSideContent=materialStorage[11];
    SingleSidedDVD returnDVD(SplitMaterial(input),extraLanguageTracks,extraSubtitleTracks,bonusFeatures,firstSideContent);
    return returnDVD;
}

void FileWriter::WriteTwoSidedDVD(TwoSidedDVD inputDVDS){
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

TwoSidedDVD FileWriter::ReadTwoSidedDVD(string input)
{
    stringstream ss;
    string section;
    ss<<input;
    vector<string> materialStorage;
    while(getline(ss,section,',')){
        materialStorage.push_back(section);
    }
    vector<string> extraLanguageTracks=StringToVector(materialStorage[8]);
    vector<string> extraSubtitleTracks=StringToVector(materialStorage[9]);
    vector<string> bonusFeatures=StringToVector(materialStorage[10]);
    string firstSideContent=materialStorage[11];
    string secondSideContent=materialStorage[12];
    TwoSidedDVD returnDVD(SplitMaterial(input),extraLanguageTracks,extraSubtitleTracks,bonusFeatures,firstSideContent,secondSideContent);
    return returnDVD;
}

void FileWriter::WriteBluRay(BluRay inputDVDS){
    string bluRay="BRAY,";
    bluRay=inputDVDS.getMaterials();
    bluRay.append(inputDVDS.getBluRay());
    bluRay.append("\n");
    ofstream outputFile;
    outputFile.open(MATERIALFILENAME);
    outputFile<<bluRay;
    outputFile.close();
}

BluRay FileWriter::ReadBluRay(string input)
{
    stringstream ss;
    string section;
    ss<<input;
    vector<string> materialStorage;
    while(getline(ss,section,',')){
        materialStorage.push_back(section);
    }
    vector<string> extraLanguageTracks=StringToVector(materialStorage[8]);
    vector<string> extraSubtitleTracks=StringToVector(materialStorage[9]);
    vector<string> bonusFeatures=StringToVector(materialStorage[10]);
    BluRay returnDVD(SplitMaterial(input),extraLanguageTracks,extraSubtitleTracks,bonusFeatures);
    return returnDVD;
}

void FileWriter::WriteVHS(VHS inputDVDS){
    string vhs="VHSS,";
    vhs=inputDVDS.getMaterials();
    vhs.append("\n");
    ofstream outputFile;
    outputFile.open(MATERIALFILENAME);
    outputFile<<vhs;
    outputFile.close();
}

VHS FileWriter::ReadVHS(string input)
{
    VHS returnVHS(SplitMaterial(input));
    return returnVHS;
}

void FileWriter::WriteComboBox(ComboBox inputDVDS){
    string comboBox="CBOX";
    comboBox.append(",");
    comboBox.append(VectorToString(inputDVDS.getIdsOfDVDs()));
    comboBox.append("\n");
    ofstream outputFile;
    outputFile.open(MATERIALFILENAME);
    outputFile<<comboBox;
    outputFile.close();
}

ComboBox FileWriter::ReadComboBox(string input)
{
    vector<string> Materials=ReadMaterials();
    stringstream ss;
    string section;
    ss<<input;
    getline(ss,section,',');
    vector<string> idsOfDVDS = StringToVector(section);
    vector<SingleSidedDVD> singleDVDS;
    vector<TwoSidedDVD> doubleDVDS;
    for(int i=0;i<idsOfDVDS.size();i++){
        string comboID=idsOfDVDS[i];
        for (int j=0;j<Materials.size();j++){
            string line =Materials[j];
            string type,id;
            stringstream ss;
            ss<<line;
            getline(ss,type,',');
            getline(ss,id,',');
            //If the current material matches a line
            if(idsOfDVDS[i]==id){
                //CALL WHICHEVER READ MATERIAL FUNCTION BASED ON WHATEVER MATERIAL TYPE
                if(type=="1DVD"){
                    //Make a 1 sided dvd
                    //Add to project
                    singleDVDS.push_back(ReadOneSidedDVD(line));
                }
                else if (type=="2DVD") {
                    //Make a 2 sided DVD
                    //Add to project
                    doubleDVDS.push_back(ReadTwoSidedDVD(line));
                }
            }
        }
    }
    ComboBox returnComboBox(idsOfDVDS.size(),idsOfDVDS,singleDVDS,doubleDVDS);
    return returnComboBox;
}
void FileWriter::WriteMaterials(vector<Project> inputProject){
    ofstream outputFile;
    outputFile.open(MATERIALFILENAME,ios_base::trunc);
    outputFile.close();
    for (int i = 0; i < inputProject.size(); i++) {
        if(inputProject[i].getMaterialIDs()[0]=="0"){//ISSUE HERE
            continue;
        }
        if(inputProject[i].getSingleDVD().getIdNumber()!="0"){
            WriteOneSidedDVD(inputProject[i].getSingleDVD());
        }
        if(inputProject[i].getTwoDVD().getIdNumber()!="0"){
            WriteTwoSidedDVD(inputProject[i].getTwoDVD());
        }
        if(inputProject[i].getBluRay().getIdNumber()!="0"){
            WriteBluRay(inputProject[i].getBluRay());
        }
        if(inputProject[i].getVhs().getIdNumber()!="0"){
            WriteVHS(inputProject[i].getVhs());
        }
        if(inputProject[i].getComboBox().getIdsOfDVDs()[0]!="0"){
            WriteComboBox(inputProject[i].getComboBox());
        }
    }
}

vector<string> FileWriter::ReadMaterials(){
    vector<string> materials;
    ifstream inputFile;
    inputFile.open(MATERIALFILENAME);
    if (!inputFile.is_open()){
        materials.clear();
        cout<<"empty file:Materials"<<endl;
        inputFile.close();
        return materials;
    }
    string line;
    while (getline(inputFile,line)) {
        materials.push_back(line);
    }
    inputFile.close();
    return materials;
}

void FileWriter::WriteProject(vector<Project> inputProject){
    ofstream outputFile;
    outputFile.open(PROJECTFILENAME,ios_base::trunc);
	if(inputProject.size()==0){
		outputFile.close();
		return;
	}
    for (int i = 0; i < inputProject.size(); i++) {
//      string newLine = "$";
        string newLine;
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
        newLine.append(to_string(inputProject[i].getWeeklyBoxFigures()));
        newLine.append(",");
        newLine.append(to_string(inputProject[i].getRunTime()));
        newLine.append(",");
        newLine.append(VectorToString(inputProject[i].getKeywords()));
        newLine.append(",");
        newLine.append(VectorToString(inputProject[i].getFilmLocations()));
        newLine.append(",");
        newLine.append(VectorToString(inputProject[i].getMaterials()));
        newLine.append("\n");
        outputFile << newLine;
        WriteMaterials(inputProject);
        WriteCrew(inputProject[i].getCrewID(),inputProject[i].getCrew());
    }
    outputFile.close();
}

vector<Project> FileWriter::ReadProjects(){
    vector<Project> returnedProjects;
    ifstream inputFile;
    inputFile.open(PROJECTFILENAME);
    string line;
    cout<<"file reading"<<endl;
    if (!inputFile.is_open()){
        returnedProjects.clear();
        cout<<"empty file:Projects"<<endl;
        inputFile.close();
        return returnedProjects;
    }
    while (getline(inputFile,line)) {
        Project tempProject;
        stringstream lineStream;
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
        tempProject.setWeeklyBoxFigures(stoi(resultsStorage[7]));
        tempProject.setRunTime(stoi(resultsStorage[8]));
        tempProject.setKeywords(StringToVector(resultsStorage[9]));
        tempProject.setFilmLocations(StringToVector(resultsStorage[10]));
        //USE THIS TO DETERMINE WHICH MATERIALS TO ASSIGN TO THE PROJECT
        tempProject.setMaterials(StringToVector(resultsStorage[11]));
        //Add project to returned ones
        returnedProjects.push_back(tempProject);
    }
    inputFile.close();
    cout<<returnedProjects.size()<<endl;
    return returnedProjects;
}

void FileWriter::WriteCrew(string crewID, vector<CrewMember> inputcrew){
    vector<string> crewMemebers;
    if(crewID=="0"){
        return;
    }
    for (int i=0; i<inputcrew.size();i++){
        crewMemebers.push_back(inputcrew[i].getCrewMember());
    }
    ofstream outputFile;
    string crewLine=crewID;
    crewLine.append(",");
    crewLine.append(VectorToString(crewMemebers));
    outputFile.open(CREWFILENAME);
    outputFile<<crewLine;
    outputFile.close();
}

vector<string> FileWriter::ReadCrew(){
    vector<string> AllCrews;
    ifstream inputFile;
    string line;
    inputFile.open(CREWFILENAME);
    if (!inputFile.is_open()){
        AllCrews.clear();
        cout<<"empty file:Crew"<<endl;
        inputFile.close();
        return AllCrews;
    }
    while(getline(inputFile,line)){
        AllCrews.push_back(line);
    }
    return AllCrews;
}

CrewMember FileWriter::CreateMember(string inputLine){
    vector<string> variables;
    stringstream ss;
    ss<<inputLine;
    string section;
    while(getline(ss,section,',')){
        variables.push_back(section);
    }
    CrewMember crewMember(variables[0],variables[1],variables[2],variables[3],
            variables[4],stoi(variables[5]),StringToVector(variables[6]));
    return crewMember;
}

vector<CrewMember> FileWriter::CreateCrewMembers(string inputLine){
    vector<CrewMember> crewMembers;
    vector<string> crewMemberLines=StringToVector(inputLine);
    for(int i=0;i<crewMemberLines.size();i++){
        CrewMember crew = CreateMember(crewMemberLines[i]);
        crewMembers.push_back(crew);
    }
    return crewMembers;
}

vector<Project> FileWriter::BuildProjectList(){
    FileWriter aFileWriter;
    vector<Project>projects=aFileWriter.ReadProjects();
    vector<string>materialLines=aFileWriter.ReadMaterials();
    vector<string>crewLines=aFileWriter.ReadCrew();
    //Go through Project list
    for (int i=0; i<projects.size();i++){
        //Go through material list for the project
        if(projects[i].getMaterialIDs()[0]=="0"){
            continue;
        }
        for (int j=0;j<projects[i].getMaterialIDs().size();j++){
            //Go through list of materials and then compare it to the current material
            for (int k=0;k<materialLines.size();k++){
                string line=materialLines[k];
                string type,id;
                stringstream ss;
                ss<<line;
                getline(ss,type,',');
                getline(ss,id,',');
                //If the current material matches a line
                if(projects[i].getMaterialIDs()[j]==id){
                    //CALL WHICHEVER READ MATERIAL FUNCTION BASED ON WHATEVER MATERIAL TYPE
                    if(type=="1DVD"){
                        //Make a 1 sided dvd
                        //Add to project
                        projects[i].getSingleDVD()=ReadOneSidedDVD(line);
                    }else if (type=="2DVD") {
                        //Make a 2 sided DVD
                        //Add to project
                        projects[i].getTwoDVD()=ReadTwoSidedDVD(line);
                    }else if (type=="BRAY") {
                        //Make a BluRay
                        //Add to project
                        projects[i].getBluRay()=ReadBluRay(line);
                    }else if (type=="VHSS"){
                        //Make a VHS
                        //Add to project
                        projects[i].getVhs()=ReadVHS(line);
                    }else if (type=="CBOX"){
                        //Make a ComboBox
                        //Add to project
                        projects[i].getComboBox()=ReadComboBox(line);
                    }
                }
            }
        }
        //Go through list of crew members and do the same as materials
        //Go through list of crews and then compare it to the current crewID
        if (projects[i].getCrewID()=="0"){
            continue;
        }
        for (int j=0;j<crewLines.size();j++){
            string line=crewLines[j];
            string id;
            stringstream ss;
            ss<<line;
            getline(ss,id,',');
            if(projects[i].getCrewID()==id){
                //Write found crew to the project
                vector<CrewMember> crew=CreateCrewMembers(line);
                projects[i].setCrew(crew);
            }
        }
    }
    return projects;
}

FileWriter::FileWriter()
{

}
