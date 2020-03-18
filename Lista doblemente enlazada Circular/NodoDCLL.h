#ifndef NODEDCLL_H_
#define NODEDCLL_H_

#include <iostream>

template <class T>

class NodoDCLL
{
private:
   NodoDCLL* next ;
   NodoDCLL* prev;
   T data;
public:
    NodoDCLL();
    ~NodoDCLL();
    NodoDCLL(T);
    void deleteAll();
    void print ();
    
    //Getters y Setters
    NodoDCLL* getNext();
    NodoDCLL* getPrev();
    void setNext(NodoDCLL * next);
    void setPrev (NodoDCLL * prev);
    T getData();
    void setData(T data);

};






#endif