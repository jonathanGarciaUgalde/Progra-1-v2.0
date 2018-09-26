#ifndef NODE_H
#define NODE_H

#include <cstddef>
using namespace std;
#include <iostream>

template<class D>
class Node
{
    public:
        Node<D>(D* Address, Node<D>* next = NULL);
        Node<D>(Node<D>* next = NULL);
        D* getAddress();
        Node<D>* getNext();
        void setNext(Node<D>* node);
        virtual ~Node();

    protected:


    private:
        Node<D>* next;
        D* Address;

};

#endif // NODE_H
