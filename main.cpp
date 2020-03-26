
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "configJson/json.hpp"
//#include "lista Simple/listaSimple.cpp"
#include "Otra Clases/Casillas.cpp"
#include "Lista doblemente enlazada Circular/listaEnlazadaDobleCircular.cpp"
#include "Cola/Cola.cpp"
#include "Otra Clases/Letra.cpp"
#include "ABB/ABB.cpp"

using namespace std;
using json = nlohmann::json;

void config(string ruta);
void imprimirListaConfiguraciones();
void llenarColaAleatoria();
void registrarUsuario(string user);

int dimension;                                                      // entero M que guarda la dimension M*M del tablero de juego
listaSimple<Casillas> *listaCasillas = new listaSimple<Casillas>(); //Guarda la configuracion de las casillas del juego
//lista Doblemente enlazada circular que guardara las palabras del juego
listaEnlazadaDobleCircular<string> *listaPalabras = new listaEnlazadaDobleCircular<string>();
Cola<Letra> *cola = new Cola<Letra>();
ABB *arbol = new ABB();
Jugador jugador_uno;
Jugador jugador_dos;

int main()
{

    bool bandera = true;
    int opcion;
    string ruta_configuracion;

    while (bandera == true)
    {
        cout << "\n";
        cout << "***************************\n";
        cout << "*        Scrable          *\n";
        cout << "***************************\n";
        cout << "*1.Agregar configuraciones*\n";
        cout << "*2.Agregar jugadores      *\n";
        cout << "*3.Seleccionar Jugador    *\n";
        cout << "*5.Reportes               *\n";
        cout << "*10.Salir*\n";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            system("CLS");
            cout << "ingrese el nombre del archivo de configuracion\n";
            cin >> ruta_configuracion;
            config(ruta_configuracion);
            system("pause");

            break;

        case 2:
        {
            bool bandera_casoDos = true;
            while (bandera_casoDos)
            {
                string nombreUsuario;
                cout << "Ingrese el nombre de Usuario \n";
                cin >> nombreUsuario;

                if (arbol->buscar(nombreUsuario))
                {
                    cout << "Usuario no disponible,Escriba otro usuario\n";
                }
                else
                {
                    registrarUsuario(nombreUsuario);
                    bandera_casoDos = false;
                }
            }
        }

        break;
        case 3:
        {
            arbol->mostrarJugadoresSimple();
            bool bandera_caso3 = true;
            int opcion_caso3;
            while (bandera_caso3)
            {
                cout << "1: Seleccionar jugador 1\n";
                cout << "2: Seleccionar jugador 2\n";
                cout << "3: Seleccionar jugador 3\n";
                cin>>opcion_caso3;
                switch (opcion_caso3)
                {
                case 1:
                {
                    string usuario_uno;
                    cout << "Seleccione jugador 1\n";
                    cin >> usuario_uno;
                    if (arbol->buscar(usuario_uno) && usuario_uno!=jugador_dos.getUsuario())
                    {
                        jugador_uno = arbol->buscarJugador(usuario_uno);
                        cout << "Jugador uno seleccionado\n";
                    }
                    else
                    {
                        cout << "Jugador Invalido, seleccione otro Usuario\n";
                    }
                }

                break;
                case 2:
                {
                    string usuario_dos;
                    cout << "Seleccione jugador 2\n";
                    cin >> usuario_dos;
                    if (arbol->buscar(usuario_dos) && usuario_dos!= jugador_uno.getUsuario())
                    {
                        jugador_uno = arbol->buscarJugador(usuario_dos);
                        cout << "Jugador dos seleccionado\n";
                    }
                    else
                    {
                        cout << "Jugador Invalido, seleccione otro Usuario\n";
                    }
                }
                break;
                case 3:
                    bandera_caso3 = false;
                    break;

                default:
                    break;
                }
            }
        }
        break;
        case 10:

            exit(-1);
            break;
        case 5:
        {
            NodoArbol *raiz = arbol->getRoot();
            arbol->InOrden(raiz);
        }
        break;

        default:
            break;
        }
    }

    return 0;
}

void config(string ruta)
{
    try
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
        cout << "Dimension, casillas dobles, casillas triples y Diccionario configurado \n";
        cout << " ";
    }
    catch (exception e)
    {
        cout << "Error, Configuracion fallida, el juego podria no funcionar correctamente\n";
        system("pause");
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

void llenarColaAleatoria()
{

    Cola<int> *lista_numeros = new Cola<int>();
    int num;
    srand(time(NULL));
    while (cola->getSize() <= 25)
    {
        num = 1 + rand() % (25 - 1);
        if (lista_numeros->buscar(num) == false)
        {
            lista_numeros->Queue(num);
            switch (num)
            {
            case 1:
                cola->Queue(*new Letra('A', 1, 12));
                break;
            case 2:
                cola->Queue(*new Letra('E', 1, 12));
                break;
            case 3:
                cola->Queue(*new Letra('O', 1, 9));
                break;
            case 4:
                cola->Queue(*new Letra('I', 1, 6));
                break;
            case 5:
                cola->Queue(*new Letra('S', 1, 6));
                break;
            case 6:
                cola->Queue(*new Letra('N', 1, 5));
                break;
            case 7:
                cola->Queue(*new Letra('L', 1, 4));
                break;
            case 8:
                cola->Queue(*new Letra('R', 1, 5));
                break;
            case 9:
                cola->Queue(*new Letra('U', 1, 5));
                break;
            case 10:
                cola->Queue(*new Letra('T', 1, 4));
                break;
            case 11:
                cola->Queue(*new Letra('D', 2, 5));
                break;
            case 12:
                cola->Queue(*new Letra('G', 2, 2));
                break;
            case 13:
                cola->Queue(*new Letra('C', 3, 4));
                break;
            case 14:
                cola->Queue(*new Letra('B', 3, 2));
                break;
            case 15:
                cola->Queue(*new Letra('M', 3, 2));
                break;
            case 16:
                cola->Queue(*new Letra('P', 3, 2));
                break;
            case 17:
                cola->Queue(*new Letra('H', 4, 1));
                break;
            case 18:
                cola->Queue(*new Letra('F', 4, 1));
                break;
            case 19:
                cola->Queue(*new Letra('V', 4, 1));
                break;
            case 20:
                cola->Queue(*new Letra('Y', 4, 1));
                break;
            case 21:
                cola->Queue(*new Letra('Q', 5, 1));
                break;
            case 22:
                cola->Queue(*new Letra('J', 8, 1));
                break;
            case 23:
                cola->Queue(*new Letra('\65', 8, 1));
                break;
            case 24:
                cola->Queue(*new Letra('X', 8, 1));
                break;
            case 25:
                cola->Queue(*new Letra('Z', 10, 1));
                break;

            default:
                break;
            }
        }
    }
    /*NodoCola<Letra> *temp_head = cola->getHead();
    NodoCola<Letra> *temp_tail = cola->getTail();

    while (temp_tail != temp_head)
    {
        cout << "Letra: " << temp_tail->getData().getLetra()
             << " Puntaje= " << temp_tail->getData().getPuntaje()
             << " Cantidad= " << temp_tail->getData().getCantidad();
        temp_tail = temp_tail->getNext();
    }*/
}
void registrarUsuario(string user)
{

    /*listaSimple<int> * list = new listaSimple<int>();
    list->AddSort(0);*/
    Jugador *temp = new Jugador();
    temp->setUsuario(user);

    //temp->setPuntajeUsuario(list);

    arbol->Add(temp);
}
