#include "Nodo.h"

//constructor por defecto
template <typename T>

Nodo <T>::Nodo(){
    next = NULL;
}

//constructor por parametro
template <typename T>
Nodo <T>::Nodo (T data){
    this->data = data ;
    next = NULL;

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
 Nodo<T> *Nodo<T>::getNext(){
    return this->next;
}
template <typename T>
void Nodo <T>::setData(T data){
    this->data = data;
}
template <typename T>
T Nodo<T>::getData(){
    return this->data;
}
template<typename T>
void Nodo<T>::delete_all()
{
    if (next)
        next->delete_all();
    delete this;
}


//destructor

template<typename T>
Nodo<T>::~Nodo() {}