#include "doublylinkedlist.h"

void DoublyLinkedList::createnode(Project value)
{
    Node *temp = new Node; //Create new node
    temp->data = value; //New nodes data = passed value
    temp->next = NULL; //No node after, so Next set to Null
    if (head == NULL) //if there are no other nodes in list
    {
        head = temp; //points to first node created
        tail = temp; //points to first node created
        temp = NULL; //temp
    }
    else
    {
        tail->next = temp; //The tail is now pointing to the new node, as it is the end
        tail = temp; //new node is at the end, = tail
    }
}

void DoublyLinkedList::display()
{
    Node *temp = new Node; //Create new node to traverse list
    temp = head; //Set to head to start at the begining of the list
    while (temp != NULL) //Until we reach the end of the list
    {
        cout << temp->data.getTitle() << "\t"; //Output the data of the current node, then tab
        temp = temp->next; //Temp is now assigned the next node in the list
    }
    cout << "\n";
}

void DoublyLinkedList::insert_start(Project value) //To create a node to go at the start of the list
{
    Node *temp = new Node; //temp = new node
    temp->data = value; //New node = value passed
    temp->next = head; //New node Next = previous head as this replaces start of the list
    head = temp; //head = to pointer to the new node as this is new start of list
}

void DoublyLinkedList::insert_position(int pos, Project value)
{
    //Using this we do not disturb head or tail
    //New node is placed between the previous and current
    Node *pre = new Node;  //Previous node
    Node *cur = new Node; //Current node
    Node *temp = new Node; //temperary //New Node
    cur = head; //Start of the list

    for (int i = 1; i < pos; i++) //Loop until we reach the position we want to insert at
    {
        pre = cur; //set previous = to the current pointer
        cur = cur->next; //Make current = to the next node
    }
    //When we are in the right position
    temp->data = value; //Assign value to new node
    pre->next = temp; //The node before the new one, Next points to the new node
    temp->next = cur; //New node next, = to one after it.
}

void DoublyLinkedList::delete_first() //Delete first node in the list
{
    Node *temp = new Node; //Create new node to hold value, so it can be deleted.
    temp = head; //New node set to the old head
    head = head->next; //Head is changed to the next node. Therefore this will be the start of the list
    delete temp; //Remove the first node from memory.
}

void DoublyLinkedList::delete_last() //traverse list to find 2nd to last node
{
    Node *current = new Node; //make new pointer to traverse with
    Node *previous = new Node; //To set as new tail
    current = head; //Start traversing at start of the list
    while (current->next != NULL) //Untill end of list
    {
        previous = current; //pass current Node to previous
        current = current->next; //Current = next node, unless NULL
    }
    tail = previous; //Set tail to second to last node
    previous->next = NULL; //Set null as new end of list
    delete current;
}

void DoublyLinkedList::delete_position(int pos)
{
    Node *current = new Node; //To traverse
    Node *previous = new Node; //To set as new node
    current = head; //start traverse from start of list
    for (int i = 1; i < pos; i++) //until position has been found
    {
        previous = current; //Pass current node to previous
        current = current->next; //Current = next node
    }
    previous->next = current->next; //previous, now points towards the next.
    delete current;
    //there for current can not be pointed too and no longer accessed.
}

void DoublyLinkedList::delete_by_title(string Title)
{
    bool removed = false;
    Node *current = new Node; //To traverse
    Node *previous = new Node; //To set as new node
    current = head; //start traverse from start of list
    while (current != NULL) //until position has been found
    {

        if (current->data.getTitle() == Title)
        {
            if (current->data.getTitle() == head->data.getTitle())
            {
                Node *temp = new Node; //Create new node to hold value, so it can be deleted.
                temp = head; //New node set to the old head
                head = head->next; //Head is changed to the next node. Therefore this will be the start of the list
                delete temp;
                removed = true;
                break;
            }
            else if (current->next == NULL)
            {
                previous->next = NULL;
                tail = previous;
                delete current;
                removed = true;
                break;
            }
            else{
                previous->next = current->next; //previous, now points towards the next.
                delete current;
                removed = true;
                break;
            }

        }


        previous = current; //Pass current node to previous
        current = current->next; //Current = next node
    }
    if (removed == false)
    {
        throw std::invalid_argument("No film to remove: " + Title);
    }

}


unsigned int DoublyLinkedList::size()
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

//Function to get project n
Project& DoublyLinkedList::operator[](unsigned int n)
{
    Node *current = head;
    Node *previous = new Node;

    if (n > size())
    {
        throw std::invalid_argument("Index out of bounds");
    }

    int pos = 0;
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
        throw std::out_of_range("No films with genre " + Genre);
    }

    return AllProjects;
}

vector<string> DoublyLinkedList::findByRoleAndName(string Role, string Name)
{
    vector<string> AllProjects;
    Node *current = head;
    Node *previous = new Node;

    while (current != NULL)
    {

        vector<CrewMember> Crew = current->data.getCrew();

        for (int i = 0; i < Crew.size(); i++)
        {
            CrewMember test = Crew.at(i);
            if (test.getRole() == Role && test.getName() == Name)
            {
                AllProjects.push_back(current->data.getTitle());
            }
        }
        previous = current;
        current = current->next;

    }

    if (AllProjects.empty())
    {
        throw std::out_of_range("No films with this person as a " + Role + " called " + Name);
    }

    return AllProjects;
}

vector<string> DoublyLinkedList::getAllFilmTitles()
{
    vector<string> AllProjects;
    Node *current = head;
    Node *previous = new Node;

    while (current != NULL)
    {
        AllProjects.push_back(current->data.getTitle());
        previous = current;
        current = current->next;
    }

    if (AllProjects.empty())
    {
        throw std::out_of_range("No films in list");
    }

    return AllProjects;
}

vector<string> DoublyLinkedList::sortProject(vector<string> Unsorted)
{

    string Temp;
    for (int stop = Unsorted.size() - 1; stop > 0; stop-- )
    {
        for (int check = 0; check < stop; check++)
        {
            if (Unsorted.at(check) > Unsorted.at(check+1))
            {
                Temp = Unsorted.at(check);
                Unsorted[check] = Unsorted[check+1];
                Unsorted[check+1] = Temp;
            }
        }
    }

    return Unsorted;

}

vector<string> DoublyLinkedList::dailyReportsForAll()
{
    vector<string> AllProjects;
    Node *current = head;
    Node *previous = new Node;

    while (current != NULL)
    {
        AllProjects.push_back(current->data.getTitle() + " sold " + to_string(current->data.getWeeklyBoxFigures()) + " tickets this week");
        previous = current;
        current = current->next;
    }

    if (AllProjects.empty())
    {
        throw std::out_of_range("No Box Figures In Any Project");
    }

    return AllProjects;

}

string DoublyLinkedList::dailyReportsByName(string NameOfProject)
{
    string AllProjects;
    Node *current = head;
    Node *previous = new Node;

    while (current != NULL)
    {
        if(current->data.getTitle() == NameOfProject){
            AllProjects = current->data.getTitle() + " sold " + to_string(current->data.getWeeklyBoxFigures()) + " tickets this week";

        }
        previous = current;
        current = current->next;
    }

    if (AllProjects.empty())
    {
        throw std::out_of_range("No Box Figures In Any Project");
    }

    return AllProjects;

}

bool DoublyLinkedList::alreadyExists(string Title)
{
    bool Exists = false;
    Node *current = head;
    Node *previous = new Node;

    while (current != NULL)
    {

        if (current->data.getTitle() == Title)
        {
            Exists = true;
        }

        previous = current;
        current = current->next;
    }
    return Exists;
}

