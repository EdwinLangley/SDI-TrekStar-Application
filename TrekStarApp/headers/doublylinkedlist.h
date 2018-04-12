#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "node.h"
#include "project.h"



class DoublyLinkedList
{

private:
    Node *head, *tail;
public:
    DoublyLinkedList()
    {
      head=NULL;
      tail=NULL;
    }

};

void createNewNode(Project project);

void displayAllNodes();

void insert_start(Project value);

void insert_position(int pos, Project value);

void delete_first();

void delete_last();

void delete_position(int pos);





#endif // DOUBLYLINKEDLIST_H
