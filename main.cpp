
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "configJson/json.hpp"
#include "lista Simple/listaSimple.cpp"
#include "Otra Clases/Casillas.cpp"
#include "Lista doblemente enlazada Circular/listaEnlazadaDobleCircular.cpp"

using namespace std;
using json = nlohmann::json;

void config(string ruta);
void imprimirListaConfiguraciones();

int dimension;
listaSimple<Casillas> *listaCasillas = new listaSimple<Casillas>();//Guarda la configuracion de las casillas del juego
//lista Doblemente enlazada circular que guardara las palabras del juego
listaEnlazadaDobleCircular<string> *listaPalabras = new listaEnlazadaDobleCircular<string> ();


int main()
{

    bool bandera = true;
    int opcion;
    string ruta_configuracion;

    while (bandera == true)
    {
        cout << "***************************\n";
        cout << "*        Scrable          *\n";
        cout << "***************************\n";
        cout << "*1.Agregar configuraciones*\n";
        cout << "*2.Agregar jugadores      *\n";
        cout << "*3.Salir*\n";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            system("clear");
            cout << "ingrese el nombre del archivo de configuracion\n";
            cin >> ruta_configuracion;
            config(ruta_configuracion);
            system("clear");
            cout << "Configuracion agregadas \n";
            imprimirListaConfiguraciones();
            listaPalabras->Print();

            break;
        case 3:

            exit(-1);
            break;

        default:
            break;
        }
    }

    return 0;
}

void config(string ruta)
{
    std::ifstream i(ruta);
    json j3;
    i >> j3;

    dimension = j3.at("dimension");
    for (int x = 0; x < j3.at("casillas").at("dobles").size(); x++)
    {
        Casillas *nueva = new Casillas();
        nueva->setTipo("Doble");
        nueva->set_x(j3.at("casillas").at("dobles")[x].at("x"));
        nueva->set_y(j3.at("casillas").at("dobles")[x].at("y"));
        listaCasillas->AddHead(*nueva);
    }
    for (int x = 0; x < j3.at("casillas").at("triples").size(); x++)
    {
        Casillas *nueva = new Casillas();
        nueva->setTipo("Triple");
        nueva->set_x(j3.at("casillas").at("triples")[x].at("x"));
        nueva->set_y(j3.at("casillas").at("triples")[x].at("y"));
        listaCasillas->AddHead(*nueva);
    }
    for (int i = 0; i < j3.at("diccionario").size(); i++)
    {
        listaPalabras->AddHead(j3.at("diccionario")[i].at("Palabra"));
        
    }
}

void imprimirListaConfiguraciones()
{
    Nodo<Casillas> *nuevo = listaCasillas->getHead();
    while (nuevo != NULL)
    {
        cout << "Tipo:" << nuevo->getData().getTipo();
        cout << "(X=" << nuevo->getData().get_x() << ", Y=" << nuevo->getData().get_y() << ")\n";
        nuevo = nuevo->getNext();
    }
}
