#ifndef JUGADOR_H_
#define JUGADOR_H_


#include <iostream>
#include <string>
#include "..\lista Simple\listaSimple.cpp"
using namespace std;

class Jugador
{
private:
    string usuario;
    listaSimple<int> *puntaje_usuario = new listaSimple<int>();

public:
    Jugador();
    Jugador (string usuario);
    ~Jugador();
    string getUsuario ();
    void setUsuario(string);
    listaSimple<int> * getPuntajeUsuario ();
    void setPuntajeUsuario (listaSimple<int>*);
    
    
};

Jugador::Jugador()
{
    
}
Jugador::Jugador(string usuario)
{
    this->usuario= usuario;
}

Jugador::~Jugador()
{
}





#endif