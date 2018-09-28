#include "Block.h"
#include "LinkedList.h"
#include <cstddef>
#include <iostream>
#include <stdexcept>
using namespace std;

Block::Block(int ID, int Length, Block* next)
{
    //LinkedList* ListaPower = new LinkedList();
    this->ListaPower = new LinkedList();
    this->ID = ID;
    this->Length = Length;
    this->next = next;
}
//Constructor 2 fantasma
Block::Block(Block* next)
{
    this->next = next;
}

int Block::getID(){

    return ID;
}

int Block::getLength(){

    return Length;
}

LinkedList* Block::getListica(){

    return ListaPower;
}

Block* Block::getNext(){

    return next;
}

void Block::setNext(Block* block){

    next = block;
}

Block::~Block()
{
    //dtor
}
