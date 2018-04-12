#include "doublylinkedlist.h"

DoublyLinkedList::DoublyLinkedList()
{

}

void DoublyLinkedList::createNewNode(Project project)
{
    Node* temp=new node;
    temp->data=project;
    temp->next=NULL;
    if(head==NULL)
    {
      head=temp;
      tail=temp;
      temp=NULL;
    }
    else
    {
      tail->next=temp;
      tail=temp;
    }
  }
