#include "LinkedList.h"
#include <cstddef>
#include <iostream>
#include <stdexcept>
using namespace std;

LinkedList::LinkedList()
{
    first = new Node();
    last = first;
    curr = first;
    size = 0;
}

LinkedList::~LinkedList()
{
    clear();
}

int LinkedList::getSize()
{
    return size;
}

int LinkedList::getPos()
{
    return pos;
}

void LinkedList::goToStart()
{
    curr = first;
}

void LinkedList::goToEnd()
{
    curr = last;
}

void LinkedList::next()
{
    curr = curr->getNext();
    pos++;
}

void LinkedList::insert(int pos, int element)
{
    Node* newNode = new Node(element, NULL);
    newNode->setNext(curr->getNext());
    curr->setNext(newNode);

    if(curr==last)
    {
        last = last->getNext();
    }

    size++;
}

void LinkedList::append(int element)
{
    goToEnd();
    insert(element);
}

void LinkedList::remove()
{
    if(curr==last)
    {
        throw runtime_error("No hay elementos en la lista");
    }

    Node* change = curr;
    next();
    change->setNext(curr->getNext());
    size--;
}

void LinkedList::print()
{
    goToStart();

    for(int i=0; i<size; i++)
    {
        curr = curr->getNext();
        cout << curr->getValue() << " ";
    }

    cout << endl;
}

void LinkedList::clear()
{
    goToStart();

    for(int i=0; i<size; i++)
    {
        Node* temp = curr;
        next();
        delete temp;
    }

    first = new Node();
    last = first;
    curr = first;
    size = 0;
    pos = 0;
}

void LinkedList::reverse()
{
    goToStart();
    int listAux[100];

    for(int i=0; i<size; i++)
    {
        curr = curr->getNext();
        listAux[i] = curr->getValue();
    }

    int tam = size;
    clear();

    for(int i=tam-1; i>=0; i--)
    {
        append(listAux[i]);
    }

    delete[] listAux;
}

void LinkedList::move(int pos)
{
    goToStart();
    this->pos = pos;

    if(pos>size)
    {
        throw runtime_error("La posicion esta fuera de la lista");
    }

    for(int i=0; i!=pos; i++)
    {
        next();
    }
}
