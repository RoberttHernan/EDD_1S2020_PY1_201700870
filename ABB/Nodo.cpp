#include "Nodo.h"

//constructor por defecto
template <typename T>

Nodo <T>::Nodo(){
    data = NULL;
    right = NULL;
    left =NULL;
}

//constructor por parametro
template <typename T>
Nodo <T>::Nodo (T data){
    this->data = data ;
    right = NULL;
    left = NULL;

}

//eliminar todos los nodos
template <typename T>
void Nodo <T>::deleteAll(){
    if (right){
        right->deleteAll();
        delete this ;
    }
}
//imprime un nodo
template <typename T>
void Nodo <T>:: print(){
    std:: cout << data << "->";
}

template <typename T>
void Nodo<T>::setRight(Nodo * right){
    this->right = right;
}
template <typename T>
 Nodo<T> *Nodo<T>::getRight(){
    return this->right;
}
template <typename T>
void Nodo<T>::setLeft(Nodo * left){
    this->left = left;
}
template <typename T>
 Nodo<T> *Nodo<T>::getLeft(){
    return this->left;
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