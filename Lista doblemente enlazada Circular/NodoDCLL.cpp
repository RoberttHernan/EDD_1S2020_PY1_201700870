#include "NodoDCLL.h"

//constructor por defecto
template <typename T>

NodoDCLL<T>::NodoDCLL(){
    this->data = NULL;
    this->next = NULL;
    this->prev =NULL;

}

//constructor por parametro
template <typename T>
NodoDCLL <T>::NodoDCLL (T data){
    this->data = data ;
    this->next = NULL;
    this->prev = NULL;

}

//eliminar todos los nodos
template <typename T>
void NodoDCLL <T>::deleteAll(){
    if (next){
        next->deleteAll();
        delete this ;
    }
}
//imprime un nodo
template <typename T>
void NodoDCLL <T>:: print(){
    std:: cout << data << "->";
}

template <typename T>
void NodoDCLL<T>::setNext(NodoDCLL * next){
    this->next = next ;
}
template <typename T>
void NodoDCLL<T>::setPrev(NodoDCLL * prev){
    this->prev = prev;
}
template <typename T>
 NodoDCLL<T> *NodoDCLL<T>::getNext(){
    return this->next;
}
template <typename T>
 NodoDCLL<T> *NodoDCLL<T>::getPrev(){
    return this->prev;
}
template <typename T>
void NodoDCLL <T>::setData(T data){
    this->data = data;
}
template <typename T>
T NodoDCLL<T>::getData(){
    return this->data;
}


//destructor

template<typename T>
NodoDCLL<T>::~NodoDCLL() {}