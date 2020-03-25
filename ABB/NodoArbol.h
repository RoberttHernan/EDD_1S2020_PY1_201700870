#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include ".\Otra Clases\Jugador.cpp"



class NodoArbol
{
private:
   NodoArbol* right ;
   NodoArbol * left;
   Jugador player;
public:
    NodoArbol();
    ~NodoArbol();
    NodoArbol(Jugador*);
    void deleteAll();
    void print ();
    
    //Getters y Setters
    NodoArbol* getRight();
    void setRight(NodoArbol * right);
    NodoArbol* getLeft();
    void setLeft(NodoArbol * left);
    Jugador getPlayer();
    void setData(Jugador *player);

};






#endif