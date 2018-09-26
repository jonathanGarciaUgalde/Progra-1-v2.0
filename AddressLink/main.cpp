#include "AddressLink.h"
#include "Node.h"
#include <cstddef>
using namespace std;
#include <iostream>

int main()
{
    AddressLink<int>* Mierda = new AddressLink<int>();
    int a = 6;
    Mierda->append(&a);
    //Mierda->append(5);
    //Mierda->append(4);
    //Mierda->append(3);
    Mierda->print();
    //cout << endl;
    //cout<< Mierda->getSize();


    return 0;
}
