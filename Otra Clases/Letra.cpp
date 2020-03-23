#include "Letra.h"


Letra::Letra()
{
    this->letra = ' ';
    this->puntaje = 0;
    this->cantidad = 0;

}
Letra::Letra(char letra, int puntaje, int cantidad)
{
    this->letra = letra;
    this->puntaje = puntaje;
    this->cantidad = cantidad;

}
Letra::~Letra()
{
}

char Letra::getLetra(){return this->letra;}
int Letra::getCantidad(){return this->cantidad;}
int Letra::getPuntaje(){return this->puntaje;}
void Letra::setLetra(char letra){this->letra= letra;}
void Letra::setCantidad(int cantidad){this->cantidad = cantidad;}
void Letra::setPuntaje(int puntaje ){ this->puntaje = puntaje; }
