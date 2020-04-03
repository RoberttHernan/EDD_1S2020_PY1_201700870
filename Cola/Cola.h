#ifndef COLA_H_
#define COLA_H_


#include <string>
#include <iostream>
#include "NodoCola.cpp"

template <class T>

class Cola
{
private:
    NodoCola<T> *head ;
    NodoCola <T>*tail;
    int size ;
public:
    Cola();
    ~Cola();
    void Queue(T);
    void InQueue();
    void Print();

    NodoCola<T> *getHead ();
    void SetHead (NodoCola <T>*);
    NodoCola<T> *getTail ();
    void SetTail (NodoCola <T>*);
    int getSize();
    void setSize(int);
    bool buscar(T);
    void DeleteAll();

};





#endif