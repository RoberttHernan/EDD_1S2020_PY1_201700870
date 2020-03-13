#ifndef NODE_H
#define NODE_H

#include <iostream>

template <class T>

class Nodo
{
private:
   Nodo* right ;
   Nodo * left;
   T data;
public:
    Nodo();
    ~Nodo();
    Nodo(T);
    void deleteAll();
    void print ();
    
    //Getters y Setters
    Nodo* getRight();
    void setRight(Nodo * right);
    Nodo* getLeft();
    void setLeft(Nodo * left);
    T getData();
    void setData(T data);

};






#endif