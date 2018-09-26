#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList* lista = new LinkedList();

    for(int i=0; i<26; i++)
    {
        if(i<21){lista->insert(i, i);} //Inserta el elemento "i" en la posicion "i"
        else{lista->append(i);}
    }
    lista->print();
    lista->remove(10); //Quita el elemento en la posicion 10
    lista->print();
    lista->insert(10, 10);
    lista->print();
    lista->printBackward();
    cout << "Tamaño de la lista: " << lista->getSize() << endl;

    lista->~DLinkedList();

    return 0;
}
