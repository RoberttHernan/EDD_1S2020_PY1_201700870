#ifndef LISTAENLAZADADOBLECIRCULAR_H_
#define LISTAENLAZADADOBLECIRCULAR_H_

#include <iostream>
#include <string>
#include <stdlib.h>

#include "NodoDCLL.cpp"


using namespace std ;
template <class T>

class listaEnlazadaDobleCircular
{
private:
   NodoDCLL<T> *head;
   NodoDCLL <T>*tail;
   int index;
public:
    listaEnlazadaDobleCircular(/* args */);
    ~listaEnlazadaDobleCircular();

    void AddHead(T);
    void Print();
    

    NodoDCLL<T> *getNodo ();
    void SetNodo (NodoDCLL <T>);
    int getIndex();
    void setIndex(int);
     NodoDCLL<T> *getHead ();

};












#endif