#include "gui.h"
#include "mainwindow.h"
#include "node.h"
#include "project.h"
#include "doublylinkedlist.h"
#include "main.h"
#include "filehandler.h"

using namespace std;

int main(int argc, char *argv[])
{
    // Calls function which stores qss variables in a global list variable
    readVariables();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

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
