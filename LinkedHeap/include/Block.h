#ifndef BLOCK_H
#define BLOCK_H
#include "LinkedList.h"
#include <cstddef>
#include <iostream>
#include <stdexcept>
using namespace std;


class Block
{
    public:
        Block(int ID, int Lenght, Block* next = NULL);
        Block(Block* next = NULL);
        virtual ~Block();
        int getID();
        int getLength();
        LinkedList* getListica();
        Block* getNext();
        void setNext(Block* node);

    protected:

    private:
    int ID, Length;
    Block* next;
    LinkedList* ListaPower;
};

#endif // BLOCK_H
