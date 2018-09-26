#include "DLinkedList.h"
#include <cstddef>
#include <iostream>
#include <stdexcept>

using namespace std;

DLinkedList::DLinkedList() //Constructor
{
    first = new DNode();
    last = new DNode();
    first->setNext(last);
    last->setPrevious(first);
    curr = first;
    size = 0;
    pos = 0;
}

DLinkedList::~DLinkedList() //Destructor
{

    goToStart();

    for(int i=0; i<size; i++)
    {
        DNode* temp = curr->next;
        curr->next = curr->next->next;
        curr->next->previous = curr;
        delete temp;
    }

    delete last;
    delete curr;
    size = 0;
    pos = 0;
}

void DLinkedList::insert(int value, int pos) //Inserta un elemento en la lista
{   /*Si se ingresa la posicion el valor se inserta en la posicion establecida
      Si pos es NULL se coloca en la posicion actual de curr*/

    if(pos==NULL)
    {
        curr->next = curr->next->previous = new DNode(value, curr->next, curr);
    }
    else
    {
        goToPos(pos);
        curr->next = curr->next->previous = new DNode(value, curr->next, curr);
    }

    size++;
}

void DLinkedList::previous() //Curr se mueve al anterior
{
    curr = curr->getPrevious();
    pos--;
}

void DLinkedList::next() //Curr se mueve al siguiente
{
    curr = curr->getNext();
    pos++;
}

void DLinkedList::print() //Imprime los elementos de la lista
{
    goToStart();

    for(int i=0; i<size; i++)
    {
        curr = curr->getNext();
        cout << curr->getValue() << " ";
    }

    cout << endl;
}

void DLinkedList::goToStart() //Se posiciona al inicio de la lista
{
    curr = first;
}

void DLinkedList::goToEnd() //Se posiciona al final de la lista
{
    curr = last;
}

void DLinkedList::goToPos(int pos) //Se posiciona en una posicion especifica de la lista
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

void DLinkedList::append(int value) //Inserta un elemento al final de la lista
{
    last -> previous = last -> previous -> next = new DNode(value, last, last->previous);;
    size++;
}

int DLinkedList::getPos() //Retorna la posicion actual en la lista
{
    return pos;
}

int DLinkedList::getSize() //Retorna el tamaño actual de la lista
{
    return size;
}

void DLinkedList::printBackward() //Imprime los elementos de la lista al revez
{
    goToEnd();

    for(int i=0; i<size; i++)
    {
        curr = curr->getPrevious();
        cout << curr->getValue() << " ";
    }

    cout << endl;
}

void DLinkedList::remove(int pos) //Remueve un elemento en la lista
{   /*Si se ingresa la posicion el valor se remueve en la posicion establecida
      Si pos es NULL se remueve la posicion actual de curr*/

    if(pos==NULL)
    {
        DNode* temp = curr->next;
        curr->next = curr->next->next;
        curr->next->previous = curr;
        delete temp;
    }
    else
    {
        goToPos(pos);
        DNode* temp = curr->next;
        curr->next = curr->next->next;
        curr->next->previous = curr;
        delete temp;
    }

    size--;
}
