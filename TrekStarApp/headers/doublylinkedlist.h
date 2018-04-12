#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "node.h"



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


#endif // DOUBLYLINKEDLIST_H
