#include "Jugador.h"
using namespace std;


string Jugador::getUsuario(){return this->usuario;}
void Jugador::setUsuario(string usuario){ this->usuario = usuario;}
listaSimple<int> * Jugador::getPuntajeUsuario(){return this->puntaje_usuario;}
void Jugador::setPuntajeUsuario(listaSimple<int> *puntaje_usuario){this->puntaje_usuario = puntaje_usuario;}

