#include "NodoCola.h"

//constructor por parametro
template <typename T>
NodoCola <T>::NodoCola (T data){
    this->data = data ;
    next = NULL;

}

//eliminar todos los nodos
template <typename T>
void NodoCola <T>::deleteAll(){
    if (next){
        next->deleteAll();
        delete this ;
    }
}
//imprime un nodo
template <typename T>
void NodoCola <T>:: print(){
    std:: cout << data << "->";
}

template <typename T>
void NodoCola<T>::setNext(NodoCola * next){
    this->next = next ;
}
template <typename T>
 NodoCola<T> *NodoCola<T>::getNext(){
    return this->next;
}
template <typename T>
void NodoCola <T>::setData(T data){
    this->data = data;
}
template <typename T>
T NodoCola<T>::getData(){
    return this->data;
}


//destructor

template<typename T>
NodoCola<T>::~NodoCola() {}