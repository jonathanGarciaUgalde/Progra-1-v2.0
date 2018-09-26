#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H
#include "DNode.h"
#include "LinkedList.h"
#include <cstddef>
#include <iostream>
#include <stdexcept>

using namespace std;

class DLinkedList:public LinkedList
{
    public:
        DLinkedList();
        virtual ~DLinkedList();
        void insert(int value, int pos=NULL);
        void append(int value);
        void remove(int pos=NULL);
        void goToStart();
        void goToEnd();
        void goToPos(int pos);
        void next();
        void previous();
        int getPos();
        int getSize();
        void print();
        void printBackward();

    private:
        DNode* first;
        DNode* last;
        DNode* curr;
        int size;
        int pos;
};

#endif // DLINKEDLIST_H
