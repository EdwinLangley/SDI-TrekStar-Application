#include "gui.h"
#include "mainwindow.h"
#include "node.h"
#include "project.h"
#include "doublylinkedlist.h"
#include "main.h"
#include "filehandler.h"
#include "controllermain.h"
#include "controllerproject.h"

using namespace std;

int main(int argc, char *argv[])
{
    // Calls function which stores qss variables in a global list variable
    readVariables();

    try {
        //Testing LinkedList
        DoublyLinkedList list;
        Project test1;
        test1.setTitle("The Revenant");

        CrewMember testCrew1;
        testCrew1.setName("Jeff");
        testCrew1.setRole("Actor");

        CrewMember testCrew2;
        testCrew2.setName("Jane");
        testCrew2.setRole("Director");

        CrewMember testCrew3;
        testCrew3.setName("Jeremy");
        testCrew3.setRole("Actor");

        vector<CrewMember> CrewTest;
        CrewTest.push_back(testCrew1);
        CrewTest.push_back(testCrew2);
        CrewTest.push_back(testCrew3);

        test1.setCrew(CrewTest);
        test1.setCrewID("1");

        list.createnode(test1);


        Project test2;
        test2.setTitle("Four Lions");


        testCrew1.setName("Annie");
        testCrew1.setRole("Actor");


        testCrew2.setName("Jane");
        testCrew2.setRole("Director");


        testCrew3.setName("Edwin");
        testCrew3.setRole("Terrorist");

        vector<CrewMember> CrewTest2;
        CrewTest2.push_back(testCrew1);
        CrewTest2.push_back(testCrew2);
        CrewTest2.push_back(testCrew3);

        test2.setCrew(CrewTest2);
        test2.setCrewID("2");

        list.createnode(test2);


        Project test3;
        test3.setTitle("Spiderman 3");
        test3.setWeeklyBoxFigures(3000);
        list.createnode(test3);

        Project test4;
        test4.setTitle("Batman");
        test4.setWeeklyBoxFigures(5000);
        list.createnode(test4);

        Project test5;
        test5.setTitle("Kingsmen");
        test5.setGenre("Action/Comdedy");
        test5.setWeeklyBoxFigures(9000);
        list.createnode(test5);




        vector<string> AllFilms = list.getAllFilmTitles();


        try {
            string Name;
            vector<string> vecTest = list.findByRoleAndName("Terrorist","Edwin");
            Name = vecTest.at(0);
            std::cout << Name << std::endl;

            list.findByTitle(Name).setTitle("Four Lions is shit jk");


            vector<string> vecTest2 = list.findByRoleAndName("Terrorist","Edwin");
            Name = vecTest2.at(0);
            std::cout << Name << std::endl;
            vector<string> SortedFilms = list.sortProject(list.getAllFilmTitles());

            vector<string> allDailyReports = list.dailyReportsForAll();

            cout << "----------Unsorted----------" << endl;

            for (int i = 0; i < AllFilms.size(); i++)
            {
                cout << AllFilms[i] << endl;
            }

            cout << "----------Sorted----------" << endl;

            for (int i = 0; i < SortedFilms.size(); i++)
            {
                cout << SortedFilms[i] << endl;
            }
            cout << "Num of films: " << list.size() << endl;

            cout << "----------Daily Reports----------" << endl;

            for (int i = 0; i < allDailyReports.size(); i++)
            {
                cout << allDailyReports[i] << endl;
            }

            cout << "----------Daily Report for one----------" << endl;

            cout << list.dailyReportsByName("Batman") << endl;




            cout << list.findByTitle(SortedFilms[2]).getGenre() << endl;


            //After moving the revenant. Lists again:
            list.delete_by_title(SortedFilms[4]);


            AllFilms = list.getAllFilmTitles();
            SortedFilms = list.sortProject(list.getAllFilmTitles());

            cout << "----------Unsorted----------" << endl;

            for (int i = 0; i < AllFilms.size(); i++)
            {
                cout << AllFilms[i] << endl;
            }

            cout << "----------Sorted----------" << endl;

            for (int i = 0; i < SortedFilms.size(); i++)
            {
                cout << SortedFilms[i] << endl;
            }
            cout << "Num of films: " << list.size() << endl;

        } catch (...)
        {
            //Update gui with no names
            cout << "No film with this person in specified role" << endl;
        }






    } catch (std::bad_alloc e)
    {
        cout << e.what() << endl;
    }


    QApplication a(argc, argv);

    controllermain cm;
    controllerproject cp;

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
