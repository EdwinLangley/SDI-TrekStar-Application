#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "main.h"
//#include "node.h"
#include "project.h"
#include "filehandler.h"



class DoublyLinkedList
{
public:
    struct Node
    {
        Project data;
        Node *next;
        Node *prev;
    };


private:
    Node *head, *tail;
public:
    FileWriter File;
    DoublyLinkedList()
    {
        head=NULL;
        tail=NULL;
        //To load projects into the double linked list
        vector<Project> AllProjects = File.BuildProjectList();
        if(AllProjects.size()==0){
            for (int i =0;i<AllProjects.size();i++)
            {
                createnode(AllProjects[i]);
            }
        }
    }

    //Deconstructor to delete all nodes
    ~DoublyLinkedList()
    {
        //For getting all project and information, and then writting using the Filewriter
        vector<string> Titles = getAllFilmTitles();
        vector<Project> Projects;


        for (int i = 0; i < Titles.size(); i++)
        {
            Projects.push_back(findByTitle(Titles[i]));
        }
        File.WriteProject(Projects);



        Node *current = head;
        Node *nextNode = NULL;
        while (current != NULL)
        {
            nextNode = current->next;
            // destroy the current node
            delete current;
            current = nextNode;
        }


    }





void createnode(Project value);

void display();

//void displayAllNodes();

void insert_start(Project value);

void insert_position(int pos, Project value);

void delete_first();

void delete_last();

void delete_by_title(string Title);

void delete_position(int pos);

//Function to get the amount of nodes of the linked list
unsigned int size();

//Passed back a reference to the project in the nth position, index starting at 0
Project& operator[](unsigned int n);

//Finds a project based on the Title Name. If no project with specified title.
//Then throws an invalid_argument error that will need to be caught
Project& findByTitle(string title);

//Function to return a vector of strings with Film names that are for the same genre.
//If no films are found for this genre, throws an out_of_range error that needs to be caught
vector<string> findByGenre(string Genre);

//Returns a vector<string> of project titles with the selected Role and Name
vector<string> findByRoleAndName(string Role, string Name);

//Returns a vector of project titles containing the keyword searched for
vector<string> findByKeyword(string keyword);

//A function to get all the titles of projects stored
vector<string> getAllFilmTitles();

//A function to sort alphabetically a vector it is passed
vector<string> sortProject(vector<string> Unsorted);

//Get Box office stats for all
vector<string> dailyReportsForAll();

//Get Box office stats for one
string dailyReportsByName(string NameOfProject);

//Function to check if a project with the Title already exists
bool alreadyExists(string Title);

//function to sort by date newest
vector<string> sortByNewest();

//function to sort by date oldest
vector<string> sortByOldest();

};



#endif // DOUBLYLINKEDLIST_H
