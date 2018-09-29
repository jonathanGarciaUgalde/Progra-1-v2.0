//
// Created by jonathanalberto on 19/09/2018.
//

#ifndef PROYECTOMPOINTER_MPOINTER_H
#define PROYECTOMPOINTER_MPOINTER_H



#include <stdlib.h>
#include <iostream>
#include "MPointerGC.h"

using namespace std;

template <class T>
class MPointer {
private:
    T *data;// puntero a data
public:
    string ID;
    string IDserver;
    bool serverActivo;
    MPointer();
    ~MPointer();
    //T operator &();// adressof() de Roy
    T& operator *();
    MPointer<T>& operator =(const MPointer<T> &);
    T operator =(const T&);
    void MPointer_init_(string IP, int puerto);

};

/**
 * Constructor  que inicializa la clase MPointer
 * @tparam T   tipo de dato que se va a trabajar
 */
template <class T>
MPointer<T>::MPointer(){
    if(MPointerGC::isActive()) {
        data = (T *) malloc(sizeof(T));// asigna la cantidad de memoria  del tipo de dato que  vamos a trabajar
        ID = "";
    }


    else{
        cout<<"error, no se inicializado la clase MPointerGC o el servidor"<<endl;
    }
}

/**
 * llamamos a la clase MPointerGC para que destruya  la referencia  de la clase MPointer  quese creó
 *  en el destructor  del MPointer
 * @tparam T
 */
template <class T>
MPointer<T>::~MPointer() {
    MPointerGC *GC = MPointerGC::getInstance();
    GC->eliminarReferencia(this->ID);
}

/**
 * Operador &,se sobrecarga el operador & para que realice la funcipin del * en este  caso  se  retorna el valor guardado en data.
 */
template <class T>
T MPointer<T>::operator &() {
    return *this->data;
}

/**
 *Operador *, permite almacenar un valor en data
 *
 */
template <class T>
T &MPointer<T>::operator *() {
    if(MPointerGC::isActive()) {
        MPointerGC *GC =MPointerGC::getInstance();
        if (this->ID == ""){
            this-> ID = GC->addPointer(data);
        }
    }

        //Aqui se puede  incluir el metodo desarrollado  por Roy
//    else if(){}

    else {
        cout << "error, no se inicializado la clase MPointerGC o el servidor"<< endl;
    }
    return *this->data;
}
// En este caso se van a desarrollar las dos sobrecargas  del operador de asignación
/**
 * Operador  de asignación para el caso de copia de dos MPointer.
 *
 * @tparam T
 * @param a Dirección de memoria de MPointer
 * @return La dirrecion de memoria con las modificaciones hechas
 */
template <class T>
MPointer<T>& MPointer<T>::operator =(const MPointer<T> &a) {//n
    if(this != &a) {
        if (MPointerGC::isActive()) {
            MPointerGC *GC = MPointerGC::getInstance();
            this->data = a.data;
            this->ID = a.ID;
            GC->addRepitedPointer(this->ID);
        }
//
        else {
            cout <<  "error, no se inicializado la clase MPointerGC o el servidor"<<endl;
        }
    }
    return  *this;

}

/**
 *  para este caso  la sobrecaga del Operador de asignación   verifica si es diferente del tipo MPointer
 * @tparam T
 * @param a  Dirección de memoria del dato que se quiere asignar
 * @return El valor del guardado en data
 */
template <class T>
T MPointer<T>::operator =(const T &a) {
    if(MPointerGC::isActive()) {
        MPointerGC *GC =MPointerGC::getInstance();
        *this->data = a;
        if (this->ID == "") {
            this->ID = GC->addPointer(data);
        }
    }
//    else if(){}

    else{
        cout << "Primero debe activar MPointerGC o el Servidor"<<endl;
    }
    return *this->data;

}

template<class T>
void MPointer<T>::MPointer_init_(string IP, int puerto) {
    serverActivo = true;
}

#endif //PROYECTOMPOINTER_MPOINTER_H
