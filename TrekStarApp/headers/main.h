#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <atomic>
#include <thread>
#include <chrono>
#include <ctime>

//JOE'S CONSTANTS DON'T TOUCH
#define PROJECTFILENAME     "ProjectFile.txt"
#define MATERIALFILENAME    "MaterialFile.txt"
#define CREWFILENAME        "CrewFile.txt"
#define SETTINGSFILE "settings.txt"


#define FIRSTLEVELDELIMCHAR     '#'
#define FIRSTLEVELDELIMSTRNG    "#"

#define SECONDLEVELDELIMCHAR    '|'
#define SECONDLEVELDELIMSTRNG   "|"

#define VECTORDELIMCHAR         '%'
#define VECTORDELIMSTRNG        "%"


std::string VectorToString(std::vector<std::string> inputVector);
std::vector<std::string> StringToVector(std::string inputString);
//void updateReports( unsigned int update_interval_millisecs);


#endif //MAIN_H
