#include "Node.h"
#include <cstddef>
using namespace std;
#include <iostream>

template<class D>
Node<D>::Node(D* Address, Node<D>* next)
{
    this->Address = Address;
    this->next = next;
}
template<class D>
Node<D>::Node(Node<D>* next){

    this -> next = next;
}
template<class D>
D* Node<D>::getAddress(){

    return Address;
}

template<class D>
Node<D>* Node<D>::getNext(){

    return next;
}
template<class D>
void Node<D>::setNext(Node<D>* node){

    next = node;
}

template<class D>
Node<D>::~Node()
{
    //dtor
}
template class Node<int>;
//template class Node<int&>;
//template class Node<char>;
//template class Node<float>;
