
#ifndef NODOCOLA_H
#define NODECOLA_H

#include <iostream>

template <class T>

class NodoCola
{
private:
   NodoCola* next ;
   T data;
public:
    NodoCola();
    ~NodoCola();
    NodoCola(T);
    void deleteAll();
    void print ();
    
    //Getters y Setters
    NodoCola* getNext();
    void setNext(NodoCola * next);
    T getData();
    void setData(T data);

};






#endif