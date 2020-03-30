#include "Letra.h"


Letra::Letra()
{
    this->letra = ' ';
    this->puntaje = 0;

}
Letra::Letra(char letra, int puntaje)
{
    this->letra = letra;
    this->puntaje = puntaje;

}
Letra::Letra(char letra){
    this->letra = letra;
}
Letra::~Letra()
{
}

char Letra::getLetra(){return this->letra;}
int Letra::getPuntaje(){return this->puntaje;}
void Letra::setLetra(char letra){this->letra= letra;}
void Letra::setPuntaje(int puntaje ){ this->puntaje = puntaje; }
