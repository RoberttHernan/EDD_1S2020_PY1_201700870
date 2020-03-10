#ifndef LISTAENLAZADADOBLECIRCULAR_H_
#define LISTAENLAZADADOBLECIRCULAR_H_

#include <iostream>
#include <string>
#include <stdlib.h>

#include "Nodo.h"
#include "Nodo.cpp"


using namespace std ;
template <class T>

class listaEnlazadaDobleCircular
{
private:
   Nodo<T> *head;
   Nodo <T>*tail;
   int index;
public:
    listaEnlazadaDobleCircular(/* args */);
    ~listaEnlazadaDobleCircular();

    void AddHead(T);
    void Print();
    

    Nodo<T> *getNodo ();
    void SetNodo (Nodo <T>);
    int getIndex();
    void setIndex(int);

};












#endif