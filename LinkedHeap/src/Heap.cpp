#include "Heap.h"
#include "Block.h"
#include "LinkedList.h"
#include <cstddef>
#include <iostream>
#include <stdexcept>
using namespace std;


Heap::Heap()
{
    //Constructor
    first = new Block();
    last = first;
    current = first;
    _size = 0;
}

Heap::~Heap()
{
    //Destructor
    clear();
}

int Heap::getSize() //Retorna el tamaño de la lista
{
    return _size;
}

int Heap::getPos() //Retorna la posicion actual de la lista
{
    return pos;
}


void Heap::goToStart() //Se mueve al inicio de la lista
{
    current = first;
}

void Heap::goToEnd() //Se mueve al final de la lista
{
    current = last;
}

void Heap::next() //Se mueve a la siguiente posicion
{
    current = current->getNext();
    pos++;
}

void Heap::insertBlock(int ID, int Length) //Inserta un Block
{
    Block* newBlock = new Block(ID, Length, NULL);
    newBlock->setNext(current->getNext());
    current->setNext(newBlock);

    if(current==last)
    {
        last = last->getNext();
    }

    _size++;
}

void Heap::appendBlock(int Length) //Inserta un elemento al final de la lista
{
    int ID = (_size + 1);
    goToEnd();
    insertBlock(ID, Length);
}


void Heap::insertValues(int ID, int val) //, int* offset = &val) //Inserta un dato en el nodo directamente
{

    move(ID - 1);
    int* offset = &val;
    if(sizeof(val) > current->getLength()) {

        throw runtime_error("No hay espacio Prro!");
    }
    current->getListica()->append(val, offset);





}

int Heap::remove() //Elimina un elemento
{
    if(current==last)
    {
        throw runtime_error("No hay elementos en la lista");
    }

    Block* change = current;
    next();
    int _ID = current->getID();
    change->setNext(current->getNext());
    _size--;

    return _ID;
}

void Heap::print() //Imprime la lista
{
    goToStart();

    for(int i=0; i<_size; i++)
    {
        current = current->getNext();
        cout << current->getID() << " ";
    }

    cout << endl;
}

void Heap::clear() //Limpia la lista
{
    goToStart();

    for(int i=0; i< _size; i++)
    {
        Block* temp = current;
        next();
        delete temp;
    }

    first = new Block();
    last = first;
    current = first;
    _size = 0;
    pos = 0;
}


void Heap::move(int pos) //Mueve curr a cualquier posicion
{
    goToStart();
    this->pos = pos;

    if(pos > _size)
    {
        throw runtime_error("La posicion esta fuera de la lista");
    }

    for(int i=0; i!=pos; i++)
    {
        next();
    }
}

int Heap::getValue(int ID, int pos) //Retorna el valor del elemento
{
    move(ID - 1);

    return current->getListica()->getValue(pos);

}
