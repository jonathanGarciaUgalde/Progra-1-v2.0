#ifndef DNODE_H
#define DNODE_H
#include "Node.h"
#include <cstddef>
#include <iostream>
#include <stdexcept>

using namespace std;

class DNode : public Node
{
    public:
        DNode(int value, DNode* next, DNode* previous);
        DNode(DNode* next=NULL, DNode* previous=NULL);
        virtual ~DNode();
        DNode* getNext();
        DNode* setNext(DNode* node);
        DNode* getPrevious();
        DNode* setPrevious(DNode* node);
        int getValue();

        int value;
        DNode* next;
        DNode* previous;
};

#endif // DNODE_H
