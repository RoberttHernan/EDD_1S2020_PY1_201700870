#ifndef COLA_H_
#define COLA_H_


#include <string>
#include <iostream>
#include "Nodo.cpp"

template <class T>

class Cola
{
private:
    Nodo<T> *head ;
    Nodo <T>*tail;
    int size ;
public:
    Cola();
    ~Cola();
    void Queue(T);
    void InQueue();
    void Print();

    Nodo<T> *getHead ();
    void SetHead (Nodo <T>);
    Nodo<T> *getTail ();
    void SetTail (Nodo <T>);
    int getSize();
    void setSize(int);

};





#endif