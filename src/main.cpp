
#include <iostream>

using namespace std;

#include <stdlib.h>

template <class T>
class MPointer {
private:

    T *value;
    int ID;
public:
    MPointer () {
    }
    ~MPointer () {
    }


    T &operator *();


    MPointer<T>& operator =(const MPointer<T>&);
    T operator =(const T&);
};


///  se sobrecarga el operador * para que cuando sea llamado retorne el valor   que se acomuló en  el  puntero value
template <class T>
T & MPointer <T>::operator *() {
    return *this->value;

};



int main() {


    return 0;
}