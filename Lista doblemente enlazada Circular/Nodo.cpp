#include "Nodo.h"

//constructor por defecto
template <typename T>

Nodo <T>::Nodo(){
    this->data = NULL;
    this->next = NULL;
    this->prev =NULL;

}

//constructor por parametro
template <typename T>
Nodo <T>::Nodo (T data){
    this->data = data ;
    this->next = NULL;
    this->prev = NULL;

}

//eliminar todos los nodos
template <typename T>
void Nodo <T>::deleteAll(){
    if (next){
        next->deleteAll();
        delete this ;
    }
}
//imprime un nodo
template <typename T>
void Nodo <T>:: print(){
    std:: cout << data << "->";
}

template <typename T>
void Nodo<T>::setNext(Nodo * next){
    this->next = next ;
}
template <typename T>
void Nodo<T>::setPrev(Nodo * prev){
    this->prev = prev;
}
template <typename T>
 Nodo<T> *Nodo<T>::getNext(){
    return this->next;
}
template <typename T>
 Nodo<T> *Nodo<T>::getPrev(){
    return this->prev;
}
template <typename T>
void Nodo <T>::setData(T data){
    this->data = data;
}
template <typename T>
T Nodo<T>::getData(){
    return this->data;
}


//destructor

template<typename T>
Nodo<T>::~Nodo() {}