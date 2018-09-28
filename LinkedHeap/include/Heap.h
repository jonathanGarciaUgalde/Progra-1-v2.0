#ifndef HEAP_H
#define HEAP_H
#include "Block.h"
#include "LinkedList.h"
#include <cstddef>
#include <iostream>
#include <stdexcept>
using namespace std;



class Heap
{
    public:
        Heap();
        virtual ~Heap();
        int getSize();
        int getPos();
        void goToStart();
        void goToEnd();
        void next();
        void insertBlock(int ID, int Length); //inserta un elemento en la posición curr
        void appendBlock(int Length);
        void insertValues(int ID, int value);
        int remove();
        void print();
        void clear();
        void move(int pos);
        int getValue(int ID, int pos);
        int getID(int pos);
        //int getLength(int pos);

    protected:
        Block* first; //head
        Block* last; //tail
        Block* current; //current
        int _size;
        int pos;


    private:
};

#endif // HEAP_H
