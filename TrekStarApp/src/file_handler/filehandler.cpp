#include "filehandler.h"
#include <QDir>
#include <QFile>
#include <QDateTime>
#include <QTextStream>


using namespace std;

vector<string> FileWriter::SplitLine(string inputLine){
    //Splits a line up based on the first delim character
    stringstream ss;
    string section;
    ss<<inputLine;
    vector<string> materialStorage;
    while(getline(ss,section,FIRSTLEVELDELIMCHAR)){
        materialStorage.push_back(section);
    }
    return materialStorage;
}

void FileWriter::WriteOneSidedDVD(SingleSidedDVD inputDVDS){
    //Takes all memeber variables gained from member functions
    //and puts together into one string to write
    string oneSidedDVD="1DVD";
    oneSidedDVD.append(inputDVDS.getMaterials());
    oneSidedDVD.append(FIRSTLEVELDELIMSTRNG);
    oneSidedDVD.append(inputDVDS.getDVD());
    oneSidedDVD.append("\n");
    ofstream outputFile;
    outputFile.open(MATERIALFILENAME,ios_base::app);
    outputFile<<oneSidedDVD;
    outputFile.close();
}

SingleSidedDVD FileWriter::ReadOneSidedDVD(string input)
{
    //Takes a line and converts it into a single object,
    //uses StringToVector to take vectors out of the line
    vector<string> materialStorage=SplitLine(input);

    vector<string> subtitleLanguages=StringToVector(materialStorage[15]);
    vector<string> extraLanguageTracks=StringToVector(materialStorage[16]);
    vector<string> extraSubtitleTracks=StringToVector(materialStorage[17]);
    vector<string> bonusFeatures=StringToVector(materialStorage[18]);

    FrameAspect frame(stoi(materialStorage[6]),stoi(materialStorage[7]),materialStorage[8]);
    Packaging package(materialStorage[9],stoi(materialStorage[10]),stoi(materialStorage[11]),
            stoi(materialStorage[12]));

    SingleSidedDVD returnDVD(materialStorage[1],materialStorage[2],materialStorage[3],
            materialStorage[4],materialStorage[5],frame,package,stoi(materialStorage[13]),
            stof(materialStorage[14]),subtitleLanguages,extraLanguageTracks,
            extraSubtitleTracks,bonusFeatures,materialStorage[19]);

    return returnDVD;
}

void FileWriter::WriteTwoSidedDVD(TwoSidedDVD inputDVDS){
    //Takes all memeber variables gained from member functions
    //and puts together into one string to write
    string twoSidedDVD="2DVD";
    twoSidedDVD.append(inputDVDS.getMaterials());
    twoSidedDVD.append(FIRSTLEVELDELIMSTRNG);
    twoSidedDVD.append(inputDVDS.getDVD());
    twoSidedDVD.append(FIRSTLEVELDELIMSTRNG);
    twoSidedDVD.append(inputDVDS.getSecondSideContent());
    twoSidedDVD.append("\n");
    ofstream outputFile;
    outputFile.open(MATERIALFILENAME,ios_base::app);
    outputFile<<twoSidedDVD;
    outputFile.close();
}

TwoSidedDVD FileWriter::ReadTwoSidedDVD(string input)
{
    //Takes a line and converts it into a single object,
    //uses StringToVector to take vectors out of the line
    vector<string> materialStorage=SplitLine(input);

    vector<string> subtitleLanguages=StringToVector(materialStorage[15]);
    vector<string> extraLanguageTracks=StringToVector(materialStorage[16]);
    vector<string> extraSubtitleTracks=StringToVector(materialStorage[17]);
    vector<string> bonusFeatures=StringToVector(materialStorage[18]);

    FrameAspect frame(stoi(materialStorage[6]),stoi(materialStorage[7]),materialStorage[8]);
    Packaging package(materialStorage[9],stoi(materialStorage[10]),stoi(materialStorage[11]),
            stoi(materialStorage[12]));

    TwoSidedDVD returnDVD(materialStorage[1],materialStorage[2],materialStorage[3],
            materialStorage[4],materialStorage[5],frame,package,stoi(materialStorage[13]),
            stof(materialStorage[14]),subtitleLanguages,extraLanguageTracks,
            extraSubtitleTracks,bonusFeatures,materialStorage[19],materialStorage[20]);
    return returnDVD;
}

void FileWriter::WriteBluRay(BluRay inputDVDS){
    //Takes all memeber variables gained from member functions
    //and puts together into one string to write
    string bluRay="BRAY";
    bluRay.append(inputDVDS.getMaterials());
    bluRay.append(FIRSTLEVELDELIMSTRNG);
    bluRay.append(inputDVDS.getBluRay());
    bluRay.append("\n");
    ofstream outputFile;
    outputFile.open(MATERIALFILENAME,ios_base::app);
    outputFile<<bluRay;
    outputFile.close();
}

BluRay FileWriter::ReadBluRay(string input)
{
    //Takes a line and converts it into a single object,
    //uses StringToVector to take vectors out of the line
    vector<string> materialStorage=SplitLine(input);

    vector<string> subtitleLanguages=StringToVector(materialStorage[15]);
    vector<string> extraLanguageTracks=StringToVector(materialStorage[16]);
    vector<string> extraSubtitleTracks=StringToVector(materialStorage[17]);
    vector<string> bonusFeatures=StringToVector(materialStorage[18]);

    FrameAspect frame(stoi(materialStorage[6]),stoi(materialStorage[7]),materialStorage[8]);
    Packaging package(materialStorage[9],stoi(materialStorage[10]),stoi(materialStorage[11]),
            stoi(materialStorage[12]));

    BluRay returnDVD(materialStorage[1],materialStorage[2],materialStorage[3],
            materialStorage[4],materialStorage[5],frame,package,stoi(materialStorage[13]),
            stof(materialStorage[14]),subtitleLanguages,extraLanguageTracks,
            extraSubtitleTracks,bonusFeatures);
    return returnDVD;
}

void FileWriter::WriteVHS(VHS inputDVDS){
    //Takes all memeber variables gained from member functions
    //and puts together into one string to write
    string vhs="VHSS";
    vhs.append(inputDVDS.getMaterials());
    vhs.append("\n");
    ofstream outputFile;
    outputFile.open(MATERIALFILENAME,ios_base::app);
    outputFile<<vhs;
    outputFile.close();
}

VHS FileWriter::ReadVHS(string input)
{
    //Takes a line and converts it into a single object,
    //uses StringToVector to take vectors out of the line

    vector<string> materialStorage=SplitLine(input);

    vector<string> subtitleLanguages=StringToVector(materialStorage[15]);
    FrameAspect frame(stoi(materialStorage[6]),stoi(materialStorage[7]),materialStorage[8]);
    Packaging package(materialStorage[9],stoi(materialStorage[10]),stoi(materialStorage[11]),
            stoi(materialStorage[12]));

    VHS returnVHS(materialStorage[1],materialStorage[2],materialStorage[3],
            materialStorage[4],materialStorage[5],frame,package,stoi(materialStorage[13]),
            stof(materialStorage[14]),subtitleLanguages);
    return returnVHS;
}

void FileWriter::WriteComboBox(ComboBox inputDVDS){
    //Takes all memeber variables gained from member functions
    //and puts together into one string to write
    string comboBox="CBOX";
    comboBox.append(FIRSTLEVELDELIMSTRNG);
    comboBox.append(VectorToString(inputDVDS.getIdsOfDVDs()));
    comboBox.append(FIRSTLEVELDELIMSTRNG);
    comboBox.append(inputDVDS.getDetails());
    comboBox.append("\n");
    ofstream outputFile;
    outputFile.open(MATERIALFILENAME,ios_base::app);
    outputFile<<comboBox;
    outputFile.close();
    //Incase this is used for combo-boxes
    for(int i=0;i<inputDVDS.getSingleDVDs().size();i++){
        WriteOneSidedDVD(inputDVDS.getSingleDVDs()[i]);
    }
    for(int i=0;i<inputDVDS.getDoubleDVDs().size();i++){
        WriteTwoSidedDVD(inputDVDS.getDoubleDVDs()[i]);
    }
}

ComboBox FileWriter::ReadComboBox(string input)
{
    //Takes a line and converts it into a single object,
    //uses StringToVector to take vectors out of the line
    vector<string> Materials=ReadMaterials();
    vector<string> materialStorage=SplitLine(input);
    vector<string> idsOfDVDS = StringToVector(materialStorage[1]);
    vector<SingleSidedDVD> singleDVDS;
    vector<TwoSidedDVD> doubleDVDS;
    //Match a dvd to its combo-box, Simple ID matching and line conversion using relevant functions
    for(unsigned int i=0;i<idsOfDVDS.size();i++){
        for (unsigned int j=0;j<Materials.size();j++){
            //Go through a line of the materials, get the TYPE and ID, if the ID matches
            //make the correct dvd
            string line =Materials[j];
            string type,id;
            stringstream ss;
            ss<<line;
            getline(ss,type,FIRSTLEVELDELIMCHAR);
            getline(ss,id,FIRSTLEVELDELIMCHAR);
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
    Packaging package(materialStorage[4],stoi(materialStorage[5]),
            stoi(materialStorage[6]),stoi(materialStorage[7]));
    ComboBox returnComboBox(idsOfDVDS.size(),idsOfDVDS,singleDVDS,doubleDVDS,
                            materialStorage[2],materialStorage[3],package,stof(materialStorage[8]));
    return returnComboBox;
}
void FileWriter::WriteMaterials(vector<Project> inputProject){
    //Goes through a project and checks for contained materials
    //and writes them if there is a non-zero ID value
    for (unsigned int i = 0; i < inputProject.size(); i++) {
        if(inputProject[i].getMaterialIDs()[0]=="0"){
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
    //Returns all lines in the materials file
    vector<string> materials;
    ifstream inputFile;
    inputFile.open(MATERIALFILENAME);
    if (!inputFile.is_open()){
        materials.clear();
        cout<<"No file:Materials"<<endl;
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

void FileWriter::WriteProject(){
    //Takes all projects and writes their member variables
    //Open and clear all files:
    ofstream projectFile, MaterialFile,CrewFile;
    MaterialFile.open(MATERIALFILENAME,ios_base::trunc);
    MaterialFile.close();
    CrewFile.open(CREWFILENAME,ios_base::trunc);
    CrewFile.close();
    projectFile.open(PROJECTFILENAME,ios_base::trunc);
    //If no projects are passed
    if(this->UpdatedProjectList.size()==0){
        projectFile.close();
        return;
    }
    //Write files here
    for (unsigned int i = 0; i < this->UpdatedProjectList.size(); i++) {
        string newLine = (this->UpdatedProjectList[i].getTitle());
        newLine.append(FIRSTLEVELDELIMSTRNG);
        newLine.append(this->UpdatedProjectList[i].getProjectStatus());
        newLine.append(FIRSTLEVELDELIMSTRNG);
        newLine.append(this->UpdatedProjectList[i].getSummary());
        newLine.append(FIRSTLEVELDELIMSTRNG);
        newLine.append(this->UpdatedProjectList[i].getGenre());
        newLine.append(FIRSTLEVELDELIMSTRNG);
        newLine.append(this->UpdatedProjectList[i].getReleaseDate());
        newLine.append(FIRSTLEVELDELIMSTRNG);
        newLine.append(this->UpdatedProjectList[i].getLanguage());
        newLine.append(FIRSTLEVELDELIMSTRNG);
        newLine.append(to_string(this->UpdatedProjectList[i].getCrewID()));
        newLine.append(FIRSTLEVELDELIMSTRNG);
        newLine.append(to_string(this->UpdatedProjectList[i].getWeeklyBoxFigures()));
        newLine.append(FIRSTLEVELDELIMSTRNG);
        newLine.append(to_string(this->UpdatedProjectList[i].getRunTime()));
        newLine.append(FIRSTLEVELDELIMSTRNG);
        newLine.append(VectorToString(this->UpdatedProjectList[i].getKeywords()));
        newLine.append(FIRSTLEVELDELIMSTRNG);
        newLine.append(VectorToString(this->UpdatedProjectList[i].getFilmLocations()));
        newLine.append(FIRSTLEVELDELIMSTRNG);
        newLine.append(VectorToString(this->UpdatedProjectList[i].getAllMaterials()));
        newLine.append("\n");
        projectFile << newLine;
        //Write extra materials/crews here
        WriteCrew(to_string(this->UpdatedProjectList[i].getCrewID()),
                  this->UpdatedProjectList[i].getCrew());
    }
    WriteMaterials(this->UpdatedProjectList);
    projectFile.close();
}

vector<Project> FileWriter::ReadProjects(){
    //Reads the whole file and turns each line into a project
    vector<Project> returnedProjects;
    ifstream inputFile;
    inputFile.open(PROJECTFILENAME);
    string line;
    cout<<"file reading"<<endl;
    if (!inputFile.is_open()){
        returnedProjects.clear();
        cout<<"No file:Projects"<<endl;
        inputFile.close();
        return returnedProjects;
    }
    while (getline(inputFile,line)) {
        Project tempProject;
        vector<string> resultsStorage=SplitLine(line);
        //Build a project
        tempProject.setTitle(resultsStorage[0]);
        tempProject.setProjectStatus(resultsStorage[1]);
        tempProject.setSummary(resultsStorage[2]);
        tempProject.setGenre(resultsStorage[3]);
        tempProject.setReleaseDate(resultsStorage[4]);
        tempProject.setLanguage(resultsStorage[5]);
        tempProject.setCrewID(stoi(resultsStorage[6]));
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
    //Take a crew ID as pseudo-foreign key and write a vector a CrewMember(s) to a single line
    //If not crew assigned break;
    if(crewID=="0"){
        return;
    }
    ofstream outputFile;
    string crewLine=crewID;
    for (unsigned int i=0; i<inputcrew.size();i++){
        crewLine.append(FIRSTLEVELDELIMSTRNG);
        crewLine.append(inputcrew[i].getCrewMember());
    }
    outputFile.open(CREWFILENAME,ios_base::app);
    outputFile<<crewLine;
    outputFile.close();
}

vector<string> FileWriter::ReadCrew(){
    //Reads entire file and returns a vector of containing a single line per entry
    vector<string> AllCrews;
    ifstream inputFile;
    string line;
    inputFile.open(CREWFILENAME);
    if (!inputFile.is_open()){
        AllCrews.clear();
        cout<<"No file:Crew"<<endl;
        inputFile.close();
        return AllCrews;
    }
    while(getline(inputFile,line)){
        AllCrews.push_back(line);
    }
    return AllCrews;
}

CrewMember FileWriter::CreateMember(string inputLine){
    //Breaks a single crew member line into a object
    vector<string> variables;
    stringstream ss;
    ss<<inputLine;
    string section;
    while(getline(ss,section,SECONDLEVELDELIMCHAR)){
        variables.push_back(section);
    }
    CrewMember crewMember(variables[0],variables[1],variables[2],variables[3],
            variables[4],stoi(variables[5]),StringToVector(variables[6]));
    return crewMember;
}

vector<CrewMember> FileWriter::CreateCrewMembers(string inputLine){
    //Take the entire line, start from the first crew member and create each member in the line
    vector<CrewMember> crewMembers;
    vector<string> crewMemberEntries=SplitLine(inputLine);
    for(unsigned int i=1;i<crewMemberEntries.size();i++){
        crewMembers.push_back(CreateMember(crewMemberEntries[i]));
    }
    return crewMembers;
}

vector<Project> FileWriter::BuildProjectList(){
    FileWriter aFileWriter;
    vector<Project>projects=aFileWriter.ReadProjects();
    vector<string>materialLines=aFileWriter.ReadMaterials();
    vector<string>crewLines=aFileWriter.ReadCrew();
    //Go through Project list
    for (unsigned int i=0; i<projects.size();i++){
        //Go through material list for the project
        if(projects[i].getMaterialIDs()[0]!="0"){
            for (unsigned int j=0;j<projects[i].getMaterialIDs().size();j++){
                //Go through list of materials and then compare it to the current material
                for (unsigned int k=0;k<materialLines.size();k++){
                    string line=materialLines[k];
                    string type,id;
                    stringstream ss;
                    ss<<line;
                    getline(ss,type,FIRSTLEVELDELIMCHAR);
                    getline(ss,id,FIRSTLEVELDELIMCHAR);
                    //If the current material matches a line
                    if(projects[i].getMaterialIDs()[j]==id){
                        //CALL WHICHEVER READ MATERIAL FUNCTION BASED ON WHATEVER MATERIAL TYPE
                        if(type=="1DVD"){
                            //Make a 1 sided dvd
                            //Add to project
                            projects[i].setSingleDVD(ReadOneSidedDVD(line));
                        }else if (type=="2DVD") {
                            //Make a 2 sided DVD
                            //Add to project
                            projects[i].setTwoDVD(ReadTwoSidedDVD(line));
                        }else if (type=="BRAY") {
                            //Make a BluRay
                            //Add to project
                            projects[i].setBluRay(ReadBluRay(line));
                        }else if (type=="VHSS"){
                            //Make a VHS
                            //Add to project
                            projects[i].setVhs(ReadVHS(line));
                        }else if (type=="CBOX"){
                            //Make a ComboBox
                            //Add to project
                            projects[i].setComboBox(ReadComboBox(line));
                        }
                    }
                }
            }
        }
        //Go through list of crew members and do the same as materials
        //Go through list of crews and then compare it to the current crewID
        if (projects[i].getCrewID()==0){
            continue;
        }
        for (unsigned int j=0;j<crewLines.size();j++){
            string line=crewLines[j];
            string id;
            stringstream ss;
            ss<<line;
            getline(ss,id,FIRSTLEVELDELIMCHAR);
            if(projects[i].getCrewID()==stoi(id)){
                //Write found crew to the project
                projects[i].setCrewID(stoi(id));
                vector<CrewMember> crew=CreateCrewMembers(line);
                projects[i].setCrew(crew);
            }
        }
    }
    this->OldProjectList=projects;
    return projects;
}

void FileWriter::BuildReport(){
    const string REPORTSDIRNAME = "Reports/";
    QDate currentDate=QDate::currentDate();
    QTime currentTime=QTime::currentTime();

    string currentDateString = to_string(currentDate.day())+"."+to_string(currentDate.month())+
            "."+to_string(currentDate.year());
    string currentTimeSting= to_string(currentTime.hour())+":"+to_string(currentTime.minute());

    //DO FILE REPORT STUFFS
    //Check for a difference
    //If different, write changes
    //A change report should be created with a date as the name in a folder called reports
    QDir directory;
    directory.mkdir(QString::fromStdString(REPORTSDIRNAME));
    //Write to a report that has the same date as the current date, otherwise create one.
    string fileName = REPORTSDIRNAME+"/"+currentDateString+".txt";
    ofstream reportFile;
    //Opens the file in write only mode, appending to the end of the file
    reportFile.open(fileName, ios_base::app);
    reportFile<<"New Report on: "<<currentDateString<<" at: "<<currentTimeSting<<"\n";
    //Check for a difference in projects
    if(this->OldProjectList.size()!=this->UpdatedProjectList.size()){
        //if a project has been added
        if(this->OldProjectList.size()<this->UpdatedProjectList.size()){
            for(unsigned int i=this->OldProjectList.size();i<UpdatedProjectList.size();i++){
                reportFile<<"New Project added: "<<this->UpdatedProjectList[i].getTitle()<<"\n";
            }
        }
    }
    //If the amount is the same
    else{
        for (unsigned int i=0;i<this->UpdatedProjectList.size();i++){
            if(this->OldProjectList[i]==this->UpdatedProjectList[i]){
                continue;
            }
            else{
                reportFile<<"Change made in: "<<this->UpdatedProjectList[i].getTitle()<<"\n";
            }
        }
    }
    //Sales limit exceeded
    for (unsigned int i=0;i<this->UpdatedProjectList.size();i++){
        if(this->UpdatedProjectList[i].getWeeklyBoxFigures()>ReportEarningsLimit){
            reportFile<<"Total Box Office Earning Exceeded for: "<<
                        this->UpdatedProjectList[i].getTitle()<<"\n";
        }
    }
    reportFile.close();
}

void FileWriter::ReadSettings(){
    ifstream inputFile;
    inputFile.open(SETTINGSFILE);
    string line;
    getline(inputFile,line);
    try{
        ReportEarningsLimit=stoi(line);}
    catch (invalid_argument){
        ReportEarningsLimit=1000;
    }
    inputFile.close();
}

void FileWriter::WriteSettings(){
    ofstream outputFile;
    outputFile.open(SETTINGSFILE,ios_base::trunc);
    outputFile<<ReportEarningsLimit;
    outputFile.close();

}

FileWriter::FileWriter()
{
    ReadSettings();
}

FileWriter::~FileWriter()
{
    WriteSettings();
}

