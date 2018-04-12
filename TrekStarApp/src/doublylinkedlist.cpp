#include "doublylinkedlist.h"
/*
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

void DoublyLinkedList::displayAllNodes() {
    node *temp=new node;
    temp=head;
    while(temp!=NULL)
    {
      cout<<temp->data<<"\t";
      temp=temp->next;
    }
  }


void DoublyLinkedList::insert_start(Project value){
  node *temp=new node;
  temp->data=value;
  temp->next=head;
  head=temp;
}

void DoublyLinkedList::insert_position(int pos, Project value){
  node *pre=new node;
  node *cur=new node;
  node *temp=new node;
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
   node *temp=new node;
   temp=head;
   head=head->next;
   delete temp;
 }

void DoublyLinkedList::delete_last()
{
  node *current=new node;
  node *previous=new node;
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
   node *current=new node;
   node *previous=new node;
   current=head;
   for(int i=1;i<pos;i++)
   {
     previous=current;
     current=current->next;
   }
   previous->next=current->next;
 }
*/
