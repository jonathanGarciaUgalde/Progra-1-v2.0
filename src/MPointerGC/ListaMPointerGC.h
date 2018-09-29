//
// Created by jonathan alberto on 16/09/2018.
//

#ifndef PROYECTOMPOINTER_LISTAMPOINTERGC_H
#define PROYECTOMPOINTER_LISTAMPOINTERGC_H
#include <iostream>
#include <string>


/**
 * Es una estructura de  datos tipo template que  va funcionar  de estructura de almacenamiento para
 * el Garbage Collector, el tipo de dato será template, significa que  se puede  almacenar  en sus nodos
 * cualquier  tipo de dato.
 * @tparam T tipo de dato
 */
template <class T>
struct nodo{
    int *data;
    int cantRef;// cantidadRef
    string ID;
    nodo<T> *siguiente;
};

/**
 * Lista Genérica adaptada para el Garbage Collector
 * @tparam T
 */
template <class T>
class ListaMPointerGC {

private:
    //Atributos
    nodo<T> *primero;
    int lenght = 0;
    //Fin de Atributos

public:

    /**
     * Constructor
     */
    ListaMPointerGC(){
        primero = nullptr;
    }
    ListaMPointerGC ListaMPointer= new ListaMPointerGC();

    /**
 * Obtiene el nodo en la posición dada
 */
    nodo<T> getNodo(int pos){//obtenerNodo
        int i = 0;
        nodo<T> *aux = primero;
        while (i<pos){
            aux = aux->siguiente;
            i++;
        }
        return *aux;
    };

    /**
     * Inserta un nuevo nodo a la lista
     * @param dato dirección de memoria a guardar como dato
     * @param ID ID asignado a este dato
     */
    void insertarNodo(int *dato, string ID){
        auto *nuevo = new nodo<T>();
        if(this->primero == nullptr){
            nuevo->dato = dato;
            nuevo->ID = ID;
            primero = nuevo;
        }
        else{
            nodo<T> *aux;
            aux = this->primero;
            int x = 0;
            while(aux->siguiente){
                x++;
                aux = aux->siguiente;
            }
            nuevo->dato = dato;
            nuevo->ID = ID;
            aux->siguiente = nuevo;
        }
        nuevo->cantRef ++;
        this->lenght ++;
    };

    /**
     * Obtiene el dato en la posición dada
     * @param pos posición donde se encuentra el dato
     * @return dato
     */
    int* getDato(int pos){//obtenerDato
        int i = 0;
        nodo<T> *aux = primero;
        while (i<pos){
            aux = aux->siguiente;
            i++;
        }
        return aux->dato;
    };

    /**
     * Obtiene la cantidad de referencias que tiene un dato
     * @param id ID del dato
     * @return cantidad de referencias
     */
    int getCantRefPorID(string id){//CantidadDeReferencias
        nodo<T> *aux = primero;
        for(int i = 0; i < this->lenght; i++){
            if(id == this->getNodo(i).ID){
                return this->getNodo(i).cantRef;
            }
            return 0;
        }
    }

    /**
     * Obtiene el largo de la lista
     * @return
     */
    int getLenght() const {
        return lenght;
    }

    /**
     * Retorna el ID de la posición dada
     * @param pos posición del que se necesita el ID
     * @return ID
     */
    string idNecesitado(int pos){
        nodo<T> *aux = this->primero;
        for(int i = 0; i<pos; i++){
            aux = aux->siguiente;
        }
        return aux->ID;
    }

    /**
     * Elimina el nodo de la posición dada
     * @param pos posicion del nodo a eliminar
     */
    void eliminarNodo(int pos){
        nodo<T> *aux = primero;
        if(pos == 0){
            primero = aux->siguiente;
            free(aux);
        } else {
            for (int i = 0; i < pos-1; i++) {
                aux = aux->siguiente;
            }
            free(aux->siguiente);
            aux->siguiente = aux->siguiente->siguiente;
        }
        this->lenght--;
    }

    /**
     * Elimina el nodo por el ID
     * @param id ID del nodo a eliminar
     */
    void eliminarNodo(string id){
        for(int i = 0; i < this->lenght; i++){
            if(this->getNodo(i).ID == id){
                eliminarNodo(i);
                break;
            }
        }
    }

    /**
     * Disminuye la cantidad de referencias del nodo con el ID solicitado
     * @param id ID del nodo a disminuir referencias
     */
    void disminuirRef(string id){// disminuyoRef
        nodo<T> *aux = primero;
        for(int i = 0; i < this->lenght; i++){
            if(aux->ID == id){
                aux->cantRef --;
                break;
            }
            aux = aux->siguiente;
        }
    }

    /**
     * Aumenta la cantidad de referencias del nodo con el ID solicitado
     * @param id ID del nodo a aumentar referencias
     */
    void aumentarRef(string id){//AumentoRef
        nodo<T> *aux = primero;
        for(int i = 0; i < this->lenght; i++){
            if(aux->ID == id){
                aux->cantRef ++;
                break;
            }
            aux = aux->siguiente;
        }
    }
};

#endif //PROYECTOMPOINTER_LISTAMPOINTERGC_H
