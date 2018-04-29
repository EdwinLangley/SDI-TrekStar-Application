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

        for (unsigned int i = 0; i < Crew.size(); i++)
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

    return AllProjects;
}

vector<string> DoublyLinkedList::findByKeyword(string keyword)
{
    vector<string> AllProjects;
    Node *current = head;
    Node *previous = new Node;

    while (current != NULL)
    {

        vector<string> Keywords = current->data.getKeywords();

        for (unsigned int i = 0; i < Keywords.size(); i++)
        {
            if (Keywords[i] == keyword)
            {
                AllProjects.push_back(current->data.getTitle());
            }
        }
        previous = current;
        current = current->next;

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
        AllProjects.clear();
        return AllProjects;

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
    vector<string> AllProjects = {};
    Node *current = head;
    Node *previous = new Node;

    while (current != NULL)
    {
        AllProjects.push_back(current->data.getTitle() + " sold " + to_string(current->data.getWeeklyBoxFigures()) + " tickets this week");
        previous = current;
        current = current->next;
    }

    return AllProjects;

}

string DoublyLinkedList::dailyReportsByName(string NameOfProject)
{
    string AllProjects = {};
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


vector<string> DoublyLinkedList::sortByNewest()
{
    vector<Project> AllProjects;
    Node *current = head;
    Node *previous = new Node;

    while (current != NULL)
    {

        AllProjects.push_back(current->data);

        previous = current;
        current = current->next;
    }

    Project Temp;
    Project Compare1;
    Project Compare2;
    string date1;
    string date2;
    string toMakeToInt1;
    string toMakeToInt2;
    int CompareInt1;
    int CompareInt2;

    for (int stop = AllProjects.size() - 1; stop > 0; stop-- )
    {
        for (int check = 0; check < stop; check++)
        {
            Compare1 = AllProjects.at(check);
            Compare2 = AllProjects.at(check+1);

            date1 = Compare1.getReleaseDate();
            date2 = Compare2.getReleaseDate();

            toMakeToInt1 = date1.substr(6,4) + date1.substr(3,2) + date1.substr(0,2);
            toMakeToInt2 = date2.substr(6,4) + date2.substr(3,2) + date2.substr(0,2);

            CompareInt1 = stoi(toMakeToInt1);
            CompareInt2 = stoi(toMakeToInt2);


            if (CompareInt1 > CompareInt2)
            {
                Temp = AllProjects.at(check);
                AllProjects[check] = AllProjects[check+1];
                AllProjects[check+1] = Temp;
            }
        }
    }

    vector<string> AllProjectsStrings;

    for (int stop = AllProjects.size() - 1; stop >= 0; stop-- )
    {
        AllProjectsStrings.push_back(AllProjects.at(stop).getTitle() + ": was released on " +AllProjects.at(stop).getReleaseDate());
    }

    return AllProjectsStrings;

}

vector<string> DoublyLinkedList::sortByOldest()
{
    vector<Project> AllProjects;
    Node *current = head;
    Node *previous = new Node;

    while (current != NULL)
    {

        AllProjects.push_back(current->data);

        previous = current;
        current = current->next;
    }

    Project Temp;
    Project Compare1;
    Project Compare2;
    string date1;
    string date2;
    string toMakeToInt1;
    string toMakeToInt2;
    int CompareInt1;
    int CompareInt2;

    for (int stop = AllProjects.size() - 1; stop > 0; stop-- )
    {
        for (int check = 0; check < stop; check++)
        {
            Compare1 = AllProjects.at(check);
            Compare2 = AllProjects.at(check+1);

            date1 = Compare1.getReleaseDate();
            date2 = Compare2.getReleaseDate();

            toMakeToInt1 = date1.substr(6,4) + date1.substr(3,2) + date1.substr(0,2);
            toMakeToInt2 = date2.substr(6,4) + date2.substr(3,2) + date2.substr(0,2);

            CompareInt1 = stoi(toMakeToInt1);
            CompareInt2 = stoi(toMakeToInt2);


            if (CompareInt1 > CompareInt2)
            {
                Temp = AllProjects.at(check);
                AllProjects[check] = AllProjects[check+1];
                AllProjects[check+1] = Temp;
            }
        }
    }

    vector<string> AllProjectsStrings;

    for (unsigned int stop =0; stop < AllProjects.size(); stop++ )
    {
        AllProjectsStrings.push_back(AllProjects.at(stop).getTitle() + ": was released on " +AllProjects.at(stop).getReleaseDate());
    }

    return AllProjectsStrings;

}


int DoublyLinkedList::getNewCrewId()
{
    int HighestId = 0;
    Node *current = head;
    Node *previous = new Node;

    while (current != NULL)
    {

        if (current->data.getCrewID() > HighestId)
        {
            HighestId = current->data.getCrewID();
        }
        previous = current;
        current = current->next;
    }

    return HighestId+1;
}

int DoublyLinkedList::getNewMaterialId()
{
    int HighestId = 0;
    Node *current = head;
    Node *previous = new Node;

    while (current != NULL)
    {
        vector<string> ProjectIds = current->data.getMaterialIDs();

        for (int i = 0; i < ProjectIds.size(); i++)
        {
            if (stoi(ProjectIds[i]) > HighestId)
            {
                HighestId = stoi(ProjectIds[i]);
            }
        }

        previous = current;
        current = current->next;
    }

    return HighestId+1;
}

