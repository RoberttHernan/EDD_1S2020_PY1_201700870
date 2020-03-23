#include "NodoArbol.h"

//constructor por defecto
template <typename T>

NodoArbol <T>::NodoArbol(){
    data = NULL;
    right = NULL;
    left =NULL;
}

//constructor por parametro
template <typename T>
NodoArbol <T>::NodoArbol (T data){
    this->data = data ;
    right = NULL;
    left = NULL;

}

//eliminar todos los nodos
template <typename T>
void NodoArbol <T>::deleteAll(){
    if (right){
        right->deleteAll();
        delete this ;
    }
}
//imprime un nodo
template <typename T>
void NodoArbol <T>:: print(){
    std:: cout << data << "->";
}

template <typename T>
void NodoArbol<T>::setRight(NodoArbol * right){
    this->right = right;
}
template <typename T>
 NodoArbol<T> *NodoArbol<T>::getRight(){
    return this->right;
}
template <typename T>
void NodoArbol<T>::setLeft(NodoArbol * left){
    this->left = left;
}
template <typename T>
 NodoArbol<T> *NodoArbol<T>::getLeft(){
    return this->left;
}
template <typename T>
void NodoArbol <T>::setData(T data){
    this->data = data;
}
template <typename T>
T NodoArbol<T>::getData(){
    return this->data;
}


//destructor

template<typename T>
NodoArbol<T>::~NodoArbol() {}