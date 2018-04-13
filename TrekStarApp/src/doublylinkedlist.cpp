#include "doublylinkedlist.h"

/*
DoublyLinkedList::DoublyLinkedList()
{

}
*/
void DoublyLinkedList::createNewNode(Project project)
{
    Node* temp=new Node;
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

void DoublyLinkedList::displayAllNodes() {
    Node *temp=new Node;
    temp=head;
    while(temp!=NULL)
    {
      std::cout << "test data" << std::endl;
      //temp->data
      //temp=temp->next;
    }
  }


void DoublyLinkedList::insert_start(Project value){
  Node *temp=new Node;
  temp->data=value;
  temp->next=head;
  head=temp;
}

void DoublyLinkedList::insert_position(int pos, Project value){
  Node *pre=new Node;
  Node *cur=new Node;
  Node *temp=new Node;
  cur=head;
  for(int i=1;i<pos;i++)
  {
    pre=cur;
    cur=cur->next;
  }
  temp->data=value;
  pre->next=temp;
  temp->next=cur;
}

void DoublyLinkedList::delete_first()
 {
   Node *temp=new Node;
   temp=head;
   head=head->next;
   delete temp;
 }

void DoublyLinkedList::delete_last()
{
  Node *current=new Node;
  Node *previous=new Node;
  current=head;
  while(current->next!=NULL)
  {
    previous=current;
    current=current->next;
  }
  tail=previous;
  previous->next=NULL;
  delete current;
}

void DoublyLinkedList::delete_position(int pos)
 {
   Node *current=new Node;
   Node *previous=new Node;
   current=head;
   for(int i=1;i<pos;i++)
   {
     previous=current;
     current=current->next;
   }
   previous->next=current->next;
 }

