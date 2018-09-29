//
// Created by jonathanalberto on 26/09/2018.
//

#ifndef PROYECTOMPOINTER_MPOINTERGC_H
#define PROYECTOMPOINTER_MPOINTERGC_H





#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <pthread.h>
#include "ListaMPointerGC.h"

using namespace std;

class MPointerGC {
private:
    //Atributos
    static bool active;
    static MPointerGC * instance;
    ListaGC<int> listaMPointer;
    string generarID();
    int ID = -1;
    thread * hilo;
    //

    MPointerGC() {
        thilo = new thread(threadFunc, this);
        cout << "Se creo una instancia nueva!\n";
    };

    MPointerGC(const MPointerGC &);

public:

    ~MPointerGC() {}

    void pararHilo();

    static void threadFunc(MPointerGC * param);

    static MPointerGC *getInstance();

    static bool isActive();

    std::string addPointer(int *nuevo);

    void addRepitedPointer(string id);

    void imprimirLista();

    void eliminarReferencia(string id);

    void revisaLista();
};
#endif //PROYECTOMPOINTER_MPOINTERGC_H
