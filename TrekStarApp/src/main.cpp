#include "gui.h"
#include "mainwindow.h"
#include "node.h"
#include "project.h"
#include "doublylinkedlist.h"
#include "main.h"
#include "filehandler.h"
#include "controller.h"

using namespace std;
//using namespace std::chrono;



int main(int argc, char *argv[])
{
    // Calls function which stores qss variables in a global list variable
    readVariables();

    QApplication a(argc, argv);

    controller cm;

    return a.exec();

}

vector<string> StringToVector(string inputString){
    vector<string> outputVector;
    stringstream ss;
    ss<<inputString;
    string section;
    while(getline(ss,section,'.')){
        outputVector.push_back(section);
    }
    return outputVector;
}

string VectorToString(vector<string> inputVector){
    string outputString;
    for(int i=0; i<inputVector.size();i++){
        outputString.append(inputVector[i]);
        outputString.append(".");
    }
    return outputString;
}

//void updateReports( unsigned int update_interval_millisecs)
//{

//    const auto wait_duration = std::chrono::milliseconds(2000);
//    while (true)
//    {
//        system_clock::time_point today = system_clock::now();
//        time_t timeNow;
//        timeNow = system_clock::to_time_t( today );
//        ofstream myfile;
//        myfile.open("example.txt",(ofstream::app));
//        myfile << ">>>> Report at time  " << ctime(&timeNow);
//        myfile << "=============================================" << endl;
//        myfile.close();

//        std::this_thread::sleep_for(wait_duration);
//    }

//}
