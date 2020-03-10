
#ifndef NODE_H
#define NODE_H

#include <iostream>

template <class T>

class Nodo
{
private:
   Nodo* next ;
   Nodo* prev;
   T data;
public:
    Nodo();
    ~Nodo();
    Nodo(T);
    void deleteAll();
    void print ();
    
    //Getters y Setters
    Nodo* getNext();
    Nodo* getPrev();
    void setNext(Nodo * next);
    void setPrev (Nodo * prev);
    T getData();
    void setData(T data);

};






#endif