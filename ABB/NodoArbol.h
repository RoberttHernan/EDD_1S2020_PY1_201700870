#ifndef NODE_H
#define NODE_H

#include <iostream>

template <class T>

class NodoArbol
{
private:
   NodoArbol* right ;
   NodoArbol * left;
   T data;
public:
    NodoArbol();
    ~NodoArbol();
    NodoArbol(T);
    void deleteAll();
    void print ();
    
    //Getters y Setters
    NodoArbol* getRight();
    void setRight(NodoArbol * right);
    NodoArbol* getLeft();
    void setLeft(NodoArbol * left);
    T getData();
    void setData(T data);

};






#endif