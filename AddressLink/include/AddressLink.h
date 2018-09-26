#ifndef ADDRESSLINK_H
#define ADDRESSLINK_H

#include "Node.h"
#include <cstddef>
using namespace std;
#include <iostream>

template<class D>
class AddressLink
{
    public:
        AddressLink();
        virtual ~AddressLink();
        int getSize();
        int getPos();
        void goToStart();
        void goToEnd();
        void next();
        void insert(D* Address);
        void append(D* Address);
        D* remove();
        void print();
        void clear();
        void move(int pos);
        D* getAddress(int pos);

    protected:
        Node<D>* First;
        Node<D>* Last;
        Node<D>* current;
        int size;
        int pos;

    private:
};

#endif // ADDRESSLINK_H
