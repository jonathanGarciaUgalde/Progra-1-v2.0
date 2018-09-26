#include "AddressLink.h"
#include "Node.h"
#include <cstddef>
using namespace std;
#include <iostream>

template<class D>
AddressLink<D>::AddressLink()
{
    First = new Node<D>;
    Last = First;
    current = First;
    size = 0;
}

template<class D>
int AddressLink<D>::getSize(){

    return size;
}

template<class D>
int AddressLink<D>::getPos(){

    return pos;
}

template<class D>
void AddressLink<D>::goToStart(){

    current = First;
}

template<class D>
void AddressLink<D>::goToEnd(){

    current = Last;
}

template<class D>
void AddressLink<D>::next(){

    current = current->getNext();
    pos++;
}
template<class D>
void AddressLink<D>::insert(D* Address){

    Node<D>* newAddress = new Node<D>(Address);
    //newAddress->Address = Address;
    newAddress->setNext(current->getNext());
    current->setNext(newAddress);

    if (current == Last){

        Last = Last->getNext();
    }
    size++;
}
template<class D>
void AddressLink<D>::append(D* Address){

    goToEnd();
    insert(Address);
}

template<class D>
D* AddressLink<D>::remove(){

    if ( current == Last){

        throw runtime_error("La lista está vacía prro");
    }
    Node<D>* change = current;
    next();
    D* _Address = current->getAddress();
    change->setNext(current->getNext());
    size--;

    return _Address;
}
template<class D>
void AddressLink<D>::print(){

    goToStart();
    for(int i = 0; i < size; i++){

        current = current->getNext();
        cout << current->getAddress() << " ";
    }
    cout << endl;
}

template<class D>
void AddressLink<D>::move(int pos){

    goToStart();
    this->pos = pos;

    if(pos>size){

        throw runtime_error("Mamapichas la posicion esta fuera de lista ajio!");
    }
    for(int i = 0; i<size; i++){

        next();
    }
}

template<class D>
D* AddressLink<D>::getAddress(int pos){

    move(pos);
    return current->getAddress();
}
template<class D>
void AddressLink<D>::clear(){

    goToStart();
    for(int i=0; i<size; i++)
    {
        Node<D>* temp = current;
        next();
        delete temp;
    }
    First = new Node<D>();
    Last = First;
    current = First;
    size = 0;
    pos = 0;

}
template<class D>
AddressLink<D>::~AddressLink()
{
    clear();
}
template class AddressLink<int>;
//template class AddressLink<int&>;
//template class AddressLink<char>;
//template class AddressLink<float>;
