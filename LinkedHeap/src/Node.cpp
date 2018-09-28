#include "Node.h"
#include <cstddef>
using namespace std;

Node::Node(int value, int* offset, Node* next) //const Iniciar con valor
{
    this->value = value;
    this->offset = offset;
    this->next = next;
}

Node::Node(Node* next) //const Iniciar sin valor
{
    this->next = next;
}

Node::~Node() //dest
{
    //dtor
}

int Node::getValue() //Returna el valor del nodo actual
{
    return value;
}

int* Node::getOffset()
{
    return offset;
}

Node* Node::getNext() //Apunta al siguiente nodo
{
    return next;
}

void Node::setNext(Node* node) //Apunta a un nuevo nodo
{
    next = node;
}
