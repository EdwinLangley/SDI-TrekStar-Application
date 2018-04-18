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

int DoublyLinkedList::size()
{
   Node *current = head;
   Node *previous = new Node;

   int Size = 1;
   while (current->next != NULL)
   {
       previous = current;
       current = previous->next;
       Size++;
   }
   return Size;
}

////Allows [] bracket notation to obtain referance to a project in nth position
//Project& DoublyLinkedList::operator[](unsigned int n)
//{
//    Node *current = head;
//    Node *previous = new Node;

//    int pos = 0;
//    while (pos != n)
//    {
//        previous = current;
//        current = previous->next;
//        pos++;
//    }
//    Project Selected = current->data;
//    return Selected;
//}

//Project& DoublyLinkedList::findByTitle (string title)
//{
//    Node *current = head;
//    Node *previous = new Node;

//    while (current->next != NULL)
//    {
//        if (current->data.getTitle() == title)
//        {
//            Project Selected = current->data;
//            return Selected;
//        }
//        else {
//            previous = current;
//            current = current->next;
//        }
//    }

//    //Return something if not found

//}



