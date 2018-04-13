#ifndef NODE_H
#define NODE_H

#include "main.h"
#include "project.h"

class Node
{
public:
    Project data;
    Node* next;
    Node* prev;

    Node();
};

#endif // NODE_H

