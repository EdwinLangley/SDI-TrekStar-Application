#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "main.h"
//#include "node.h"
#include "project.h"



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
    DoublyLinkedList()
    {
      head=NULL;
      tail=NULL;
    }

    //Deconstructor to delete all nodes
    ~DoublyLinkedList()
    {
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

//A function to get all the titles of projects stored
vector<string> getAllFilmTitles();

//A function to sort alphabetically a vector it is passed
vector<string> sortProject(vector<string> Unsorted);

};



#endif // DOUBLYLINKEDLIST_H
