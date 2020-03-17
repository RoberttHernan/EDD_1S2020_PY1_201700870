#include "Casillas.h"

using namespace std;

Casillas::Casillas(){
    this->tipo="NULL";
    this->x =-1;
    this->y=-1;
}
int Casillas::get_x(){return this->x;}
void Casillas::set_x(int x){ this->x = x;}
int Casillas::get_y(){return this->y;}
void Casillas::set_y(int y){this->y = y;}
string Casillas::getTipo(){return this->tipo;}
void Casillas::setTipo(string tipo){this->tipo = tipo;}
