#ifndef LISTASIMPLE_H_
#define LISTASIMPLE_H_

#include <iostream>
#include <string>
#include <stdlib.h>

#include "Nodo.h"
#include "Nodo.cpp"


using namespace std ;
template <class T>

class listaSimple
{
private:
   Nodo<T> *head;
   Nodo<T> *tail;
   int index;
public:
    listaSimple(/* args */);
    ~listaSimple();

    void AddHead(T);
    void AddEnd(T);
    void AddSort(T);
    void Concat(listaSimple);
    void DeleteAll();
    void DeleteByData(T);
    void DeleteByPosition(int);
    void FillByUser (int);
    void FillRandom (int);
    void Intersection(listaSimple);
    void Invert();
    void LoadFile();
    void Print();
    void SaveFile (string);
    void search (T);
    void sort ();

    Nodo<T> *getNodo ();
    void SetNodo (Nodo <T>);
    Nodo<T> *getHead();
    void setHead(Nodo <T>*);
    int getIndex();
    void setIndex(int);

    Nodo <T> *getTail();
    void setTail (Nodo<T> *);

};












#endif