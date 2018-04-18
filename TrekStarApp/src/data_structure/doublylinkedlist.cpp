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

unsigned int DoublyLinkedList::size()
{
    Node *current = head;
    Node *previous = new Node;

    unsigned int Size = 1;
    while (current->next != NULL)
    {
        previous = current;
        current = previous->next;
        Size++;
    }

    return Size;
}

//Function to get project n
Project& DoublyLinkedList::operator[](unsigned int n)
{
    Node *current = head;
    Node *previous = new Node;

    if (n > size())
    {
        throw std::invalid_argument("Index out of bounds");
    }

    unsigned int pos = 0;
    while (pos != n)
    {
        previous = current;
        current = previous->next;
        pos++;
    }

    return current->data;
}

Project& DoublyLinkedList::findByTitle(string title)
{
    Node *current = head;
    Node *previous = new Node;

    while (current != NULL)
    {
        if (current->data.getTitle() == title)
        {

            return current->data;
        }
        else {
            previous = current;
            current = current->next;
        }
    }

    throw std::invalid_argument("Project not found");

}

vector<string> DoublyLinkedList::findByGenre(string Genre)
{
    vector<string> AllProjects;
    Node *current = head;
    Node *previous = new Node;

    while (current != NULL)
    {

        if (current->data.getGenre() == Genre)
        {
            AllProjects.push_back(current->data.getTitle());
        }
        previous = current;
        current = current->next;
    }

    if (AllProjects.empty())
    {
        throw std::out_of_range("No films with this genre");
    }

    return AllProjects;
}



