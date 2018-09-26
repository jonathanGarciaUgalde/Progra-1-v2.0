#include "DNode.h"
#include <cstddef>
#include <iostream>
#include <stdexcept>

using namespace std;

DNode::DNode(int value, DNode* next, DNode* previous) //Constructor con valor
{
    this->value = value;
    this->next = next;
    this->previous = previous;
}

DNode::DNode(DNode* next, DNode* previous) //Constructor vacio
{
    this->next = next;
    this->previous = previous;
}

DNode* DNode::getNext() //Retorna el siguiente Nodo
{
    return next;
}

DNode* DNode::setNext(DNode* node) //Enlaza el next del Nodo al Nodo de entrada
{
    next = node;
}

DNode* DNode::getPrevious() //Retorna el anterior Nodo
{
    return previous;
}

DNode* DNode::setPrevious(DNode* node) //Enlaza el previous del Nodo al Nodo de entrada
{
    previous = node;
}

DNode::~DNode() //Destructor
{
    //dtor
}

int DNode::getValue() //Retorna el valor del Nodo actual
{
    return value;
}
