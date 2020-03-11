
#ifndef NODE_H
#define NODE_H

#include <iostream>

template <class T>

class Nodo
{
private:
   Nodo* next ;
   T data;
public:
    Nodo();
    ~Nodo();
    Nodo(T);
    void deleteAll();
    void print ();
    
    //Getters y Setters
    Nodo* getNext();
    void setNext(Nodo * next);
    T getData();
    void setData(T data);

};






#endif