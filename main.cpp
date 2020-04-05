
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cstring>

#include "configJson/json.hpp"
//#include "lista Simple/listaSimple.cpp"
#include "Otra Clases/Casillas.cpp"
#include "Lista doblemente enlazada Circular/listaEnlazadaDobleCircular.cpp"
#include "Cola/Cola.cpp"
#include "Otra Clases/Letra.cpp"
#include "ABB/ABB.cpp"
#include "Matriz Dispersa/Matriz.cpp"

using namespace std;
using json = nlohmann::json;

void config(string ruta);
void graficarDiccionario();
void imprimirListaConfiguraciones();
void llenarColaAleatoria();
void registrarUsuario(string user);
void graficarColaLetras();
void llenarListaDobles(listaEnlazadaDobleCircular<Letra> *lista); // funcion que llenara las listad circulares dobles de fichas para los jugadores a partir de la cola
void graficarListasJugadores(listaEnlazadaDobleCircular<Letra> *lista_jugador);
bool buscarLetraEnListaJugador(listaEnlazadaDobleCircular<Letra> *lista, string letra); // busca una letra especifica en la lista de letras de un jugador
string ToUpperCase(string st1);
bool match(listaSimple<Casillas> *lista);
void cambiarFichas(listaEnlazadaDobleCircular<Letra> *lista_letras_jugador);
NodoDCLL<Letra> *buscarLetraEnListaJugador_nodo(listaEnlazadaDobleCircular<Letra> *lista, string letra);
int getPuntuacionLetra(string letra);
int getPuntuacionTotal(int x, int y);
int BuscarDoble_Triple(int x, int y);
void catchError();
void ReportePuntajePorJugador();
void terminarPartida();
void reportajesPuntajesTotales(NodoArbol *nodo);
void aniadirPuntajeALista(Jugador jugador);

void imprimirPuntajesTotales();

int dimension; // entero M que guarda la dimension M*M del tablero de juego
int puntajeJugadorUno = 0;
int puntajeJugadorDos = 0;
int turno = 1;

listaSimple<Casillas> *listaCasillas = new listaSimple<Casillas>(); //Guarda la configuracion de las casillas del juego
//lista Doblemente enlazada circular que guardara las palabras del juego
listaEnlazadaDobleCircular<string> *listaPalabras = new listaEnlazadaDobleCircular<string>(); //diccionario de palabras
Cola<Letra> *cola = new Cola<Letra>();                                                        // cola de fichas disponibles
ABB *arbol = new ABB();
Jugador jugador_uno;
listaEnlazadaDobleCircular<Letra> *lista_jugador_uno = new listaEnlazadaDobleCircular<Letra>(); // lista para letras del jugador uno
Jugador jugador_dos;
listaEnlazadaDobleCircular<Letra> *lista_jugador_dos = new listaEnlazadaDobleCircular<Letra>(); // lista para letras del jugador dos
Matriz<string> *tablero = new Matriz<string>();                                                 // Matriz que simulara el tablero de juego
listaSimple<Casillas> *listaCasillasTemp = new listaSimple<Casillas>();                         // lista simple que almacena las casillas temporales de insercion de datos en el tablero
listaSimple<Jugador> *listaPuntajeTotal = new listaSimple<Jugador>();                           //Lista que guarda el mayor puntaje de Cada jugador

int main()
{

    arbol->Add(new Jugador("Heidy"));
    arbol->Add(new Jugador("Carlos"));
    arbol->Add(new Jugador("Antonio"));
    arbol->Add(new Jugador("Eduardo"));
    arbol->Add(new Jugador("Rodrigo"));
    bool bandera = true;
    int opcion = 0;
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
        cout << "*4.Jugar                  *\n";
        cout << "*5.Reportes               *\n";
        cout << "*10.Salir*\n";
        cin >> opcion;
        catchError();

        system("CLS");

        switch (opcion)
        {
        case 1:
            system("CLS");
            cout << "ingrese el nombre del archivo de configuracion\n";
            cin >> ruta_configuracion;
            config(ruta_configuracion);
            llenarColaAleatoria();
            system("pause");
            system("CLS");

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

            bool bandera_caso3 = true;
            int opcion_caso3;
            while (bandera_caso3)
            {
                cout << "1: Seleccionar jugador 1\n";
                cout << "2: Seleccionar jugador 2\n";
                cout << "3: Ver jugadores actuales \n";
                cout << "4: Ver lista de Usuarios\n";
                cout << "5: Salir\n";
                cin >> opcion_caso3;
                catchError();
                system("CLS");

                switch (opcion_caso3)
                {
                case 1:
                {
                    string usuario_uno;
                    cout << "Seleccione jugador 1\n";
                    cin >> usuario_uno;
                    if (arbol->buscar(usuario_uno) && usuario_uno != jugador_dos.getUsuario())
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
                    if (arbol->buscar(usuario_dos) && usuario_dos != jugador_uno.getUsuario())
                    {
                        jugador_dos = arbol->buscarJugador(usuario_dos);
                        cout << "Jugador dos seleccionado\n";
                    }
                    else
                    {
                        cout << "Jugador Invalido, seleccione otro Usuario\n";
                    }
                }
                break;
                case 3:
                    if (jugador_uno.getUsuario() == "NULL" && jugador_dos.getUsuario() == "NULL")
                    {
                        cout << "Ningun jugador seleccionado\n";
                    }
                    else if (jugador_uno.getUsuario() != "NULL" && jugador_dos.getUsuario() == "NULL")
                    {
                        cout << "Jugador1: " + jugador_uno.getUsuario() + "\n";
                        cout << "Jugador 2 no seleccionado\n";
                    }
                    else if (jugador_uno.getUsuario() == "NULL" && jugador_dos.getUsuario() != "NULL")
                    {
                        cout << "Jugador 1 no seleccionado\n";
                        cout << "Jugador2: " + jugador_dos.getUsuario() + "\n";
                    }
                    else
                    {
                        cout << "Jugador1: " + jugador_uno.getUsuario() + "\n";
                        cout << "Jugador2: " + jugador_dos.getUsuario() + "\n";
                    }

                    break;

                case 4:
                    arbol->mostrarJugadoresSimple();

                    break;
                case 5:
                    bandera_caso3 = false;

                    break;
                default:
                    break;
                }
            }
        }
        break;
        case 4:

            if (jugador_uno.getUsuario() == "NULL" || jugador_dos.getUsuario() == "NULL")
            {
                cout << "Seleccione dos jugadores para iniciar partida!!\n";
            }
            else
            {
                bool caso_4 = true;
                int opcion_caso4;

                while (caso_4)
                {
                    system("CLS");
                    cout << "1. Repartir fichas\n";
                    cout << "2. Turno " + jugador_uno.getUsuario() + "\n";
                    cout << "3. Turno " + jugador_dos.getUsuario() + "\n";
                    cout << "4. Terminar Partida\n";
                    cin >> opcion_caso4;
                    catchError();
                    system("CLS");

                    switch (opcion_caso4)
                    {
                    case 1:
                    {
                        if (lista_jugador_uno->getHead() != NULL && lista_jugador_dos->getHead() != NULL)
                        {
                            cout << "Ya repartio las fichas anteriormente, reinicie "
                                 << "las configuraciones para iniciar un nuevo juego y repartir "
                                 << "nuevamente\n";
                            system("pause");
                        }
                        else
                        {
                            llenarListaDobles(lista_jugador_uno);
                            llenarListaDobles(lista_jugador_dos);
                            cout << "Fichas repartidas exitosamente\n";
                            system("pause");
                        }
                    }

                    break;

                    case 2: // Jugador uno
                        if (lista_jugador_uno->getHead() == NULL || lista_jugador_dos->getHead() == NULL)
                        {
                            cout << "Reparta las fichas antes de jugar!\n";
                            system("pause");
                        }
                        else
                        {
                            if (turno == 1)
                            {
                                {
                                    bool bandera_4_2 = true;
                                    int caso4_2;
                                    while (bandera_4_2)
                                    {
                                        system("CLS");
                                        cout << "1:Colocar letra\n";
                                        cout << "2:Ver fichas disponibles \n";
                                        cout << "3:Pedir fichas nuevas \n";
                                        cout << "4:Terminar turno \n";
                                        cout << "5:Ver tablero \n";
                                        cout << "6:Ver Diccionario \n";
                                        cin >> caso4_2;
                                        catchError();
                                        switch (caso4_2)
                                        {
                                        case 1:
                                        {
                                            string letra;
                                            int x;
                                            int y;

                                            cout << "Ingresa la letra\n";
                                            cin >> letra;
                                            cout << "ingresa la columna (x)\n";
                                            cin >> x;
                                            cout << "Ingresa la fila (y)\n";
                                            cin >> y;

                                            if (x > dimension || y > dimension)
                                            {
                                                cout << "Error de dimension de casilla";
                                            }
                                            else if (!buscarLetraEnListaJugador(lista_jugador_uno, letra))
                                            {
                                                cout << "Error, letra no disponible en tu lista de fichas\n";
                                            }
                                            else
                                            {

                                                tablero->AddElement(letra, x, y);
                                                listaCasillasTemp->AddHead(*new Casillas(letra, x, y));
                                                tablero->textoGraphviz();
                                                system("pause");
                                            }
                                        }

                                        break;
                                        case 2:
                                            graficarListasJugadores(lista_jugador_uno);
                                            break;
                                        case 3:
                                            cambiarFichas(lista_jugador_uno);
                                            cout << "Cambio de fichas realizado\n";
                                            graficarListasJugadores(lista_jugador_uno);
                                            system("pause");

                                            if (match(listaCasillasTemp))
                                            {
                                                cout << "Turno Valido\n";
                                                Nodo<Casillas> *temp = listaCasillasTemp->getHead();
                                                while (temp != NULL)
                                                {
                                                    NodoDCLL<Letra> *temporal = buscarLetraEnListaJugador_nodo(lista_jugador_uno, temp->getData().getTipo());
                                                    lista_jugador_uno->borrarNodo(temporal);
                                                    puntajeJugadorUno += getPuntuacionTotal(temp->getData().get_x(), temp->getData().get_y());
                                                    temp = temp->getNext();
                                                }
                                            }
                                            else
                                            {
                                                cout << "Turno Invalido\n";
                                                Nodo<Casillas> *temp = listaCasillasTemp->getHead();
                                                while (temp != NULL)
                                                {
                                                    tablero->borrarNodo(temp->getData().get_x(), temp->getData().get_y());
                                                    temp = temp->getNext();
                                                }
                                            }
                                            cout << "Tu puntaje es: " + to_string(puntajeJugadorUno) + "pts\n";
                                            system("pause");
                                            bandera_4_2 = false;
                                            if (listaCasillasTemp->getHead() != NULL)
                                            {
                                                listaCasillasTemp->DeleteAll();
                                            }
                                            turno = 2;
                                            break;
                                        case 4:
                                            if (match(listaCasillasTemp))
                                            {
                                                cout << "Turno Valido\n";
                                                Nodo<Casillas> *temp = listaCasillasTemp->getHead();
                                                while (temp != NULL)
                                                {
                                                    NodoDCLL<Letra> *temporal = buscarLetraEnListaJugador_nodo(lista_jugador_uno, temp->getData().getTipo());
                                                    lista_jugador_uno->borrarNodo(temporal);
                                                    puntajeJugadorUno += getPuntuacionTotal(temp->getData().get_x(), temp->getData().get_y());
                                                    temp = temp->getNext();
                                                }
                                            }
                                            else
                                            {
                                                cout << "Turno Invalido\n";
                                                Nodo<Casillas> *temp = listaCasillasTemp->getHead();
                                                while (temp != NULL)
                                                {
                                                    tablero->borrarNodo(temp->getData().get_x(), temp->getData().get_y());
                                                    temp = temp->getNext();
                                                }
                                            }
                                            cout << "Tu puntaje es: " + to_string(puntajeJugadorUno) + "pts\n";
                                            system("pause");
                                            bandera_4_2 = false;
                                            if (listaCasillasTemp->getHead() != NULL)
                                            {
                                                listaCasillasTemp->DeleteAll();
                                            }
                                            turno = 2;

                                            break;
                                        case 5:
                                            tablero->textoGraphviz();
                                            break;

                                        case 6:
                                            graficarDiccionario();
                                            break;
                                        default:
                                            cout << "Seleccion invalida >:| \n";
                                            system("pause");
                                            break;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                cout << "Es el turno de " + jugador_dos.getUsuario() + "\n";
                                system("pause");
                            }
                        }
                        break;
                    case 3: // Jugador dos
                        if (lista_jugador_uno->getHead() == NULL || lista_jugador_dos->getHead() == NULL)
                        {
                            cout << "Reparta las fichas antes de jugar!\n";
                            system("pause");
                        }
                        else
                        {
                            if (turno == 2)
                            {
                                {
                                    bool bandera4_3 = true;
                                    int caso4_3;
                                    while (bandera4_3)
                                    {
                                        system("CLS");
                                        cout << "1:Colocar letra\n";
                                        cout << "2:Ver fichas disponibles \n";
                                        cout << "3:Pedir fichas nuevas \n";
                                        cout << "4:Terminar turno \n";
                                        cout << "5:Ver tablero \n";
                                        cout << "6:Graficar Diccionario \n";
                                        cin >> caso4_3;
                                        catchError();

                                        switch (caso4_3)
                                        {
                                        case 1:
                                        {
                                            string letra;
                                            int x;
                                            int y;

                                            cout << "Ingresa la letra\n";
                                            cin >> letra;
                                            cout << "ingresa la columna (x)\n";
                                            cin >> x;
                                            cout << "Ingresa la fila (y)\n";
                                            cin >> y;

                                            if (x > dimension || y > dimension)
                                            {
                                                cout << "Error de dimension de casilla";
                                            }
                                            else if (!buscarLetraEnListaJugador(lista_jugador_dos, letra))
                                            {
                                                cout << "Error, letra no disponible en tu lista de fichas\n";
                                            }
                                            else
                                            {

                                                tablero->AddElement(letra, x, y);
                                                listaCasillasTemp->AddHead(*new Casillas(letra, x, y));
                                                tablero->textoGraphviz();
                                                system("pause");
                                            }
                                        }
                                        break;
                                        case 2:
                                            graficarListasJugadores(lista_jugador_dos);
                                            break;
                                        case 3:
                                            cambiarFichas(lista_jugador_dos);
                                            cout << "Cambio de Fichas realizado correctamente";
                                            graficarListasJugadores(lista_jugador_dos);
                                            system("pause");
                                            if (match(listaCasillasTemp))
                                            {
                                                cout << "Turno Valido\n";
                                                Nodo<Casillas> *temp = listaCasillasTemp->getHead();
                                                while (temp != NULL)
                                                {
                                                    NodoDCLL<Letra> *temporal = buscarLetraEnListaJugador_nodo(lista_jugador_dos, temp->getData().getTipo());
                                                    lista_jugador_dos->borrarNodo(temporal);
                                                    puntajeJugadorDos += getPuntuacionTotal(temp->getData().get_x(), temp->getData().get_y());
                                                    temp = temp->getNext();
                                                }
                                            }
                                            else
                                            {
                                                cout << "Turno Invalido\n";
                                                Nodo<Casillas> *temp = listaCasillasTemp->getHead();
                                                while (temp != NULL)
                                                {
                                                    tablero->borrarNodo(temp->getData().get_x(), temp->getData().get_y());
                                                    temp = temp->getNext();
                                                }
                                            }

                                            cout << "Tu puntaje es: " + to_string(puntajeJugadorDos) + "pts\n";
                                            system("pause");
                                            bandera4_3 = false;
                                            break;
                                        case 4:
                                            if (match(listaCasillasTemp))
                                            {
                                                cout << "Turno Valido\n";
                                                Nodo<Casillas> *temp = listaCasillasTemp->getHead();
                                                while (temp != NULL)
                                                {
                                                    NodoDCLL<Letra> *temporal = buscarLetraEnListaJugador_nodo(lista_jugador_dos, temp->getData().getTipo());
                                                    lista_jugador_dos->borrarNodo(temporal);
                                                    puntajeJugadorDos += getPuntuacionTotal(temp->getData().get_x(), temp->getData().get_y());
                                                    temp = temp->getNext();
                                                }
                                            }
                                            else
                                            {
                                                cout << "Turno Invalido\n";
                                                Nodo<Casillas> *temp = listaCasillasTemp->getHead();
                                                while (temp != NULL)
                                                {
                                                    tablero->borrarNodo(temp->getData().get_x(), temp->getData().get_y());
                                                    temp = temp->getNext();
                                                }
                                            }

                                            cout << "Tu puntaje es: " + to_string(puntajeJugadorDos) + "pts\n";
                                            system("pause");
                                            bandera4_3 = false;
                                            if (listaCasillasTemp->getHead() != NULL)
                                            {
                                                listaCasillasTemp->DeleteAll();
                                            }
                                            turno = 1;
                                            break;

                                        case 5:
                                            tablero->textoGraphviz();
                                            break;
                                        case 6:
                                            graficarDiccionario();
                                            break;
                                        default:
                                            break;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                cout << "Es el turno de " + jugador_uno.getUsuario() + "\n";
                                system("pause");
                            }
                        }
                        break;
                    case 4:
                        if (puntajeJugadorUno != 0)
                        {
                            jugador_uno.getPuntajeUsuario()->AddSort(puntajeJugadorUno);
                        }
                        if (puntajeJugadorDos != 0)
                        {
                            jugador_dos.getPuntajeUsuario()->AddSort(puntajeJugadorDos);
                        }

                        if (puntajeJugadorUno == puntajeJugadorDos)
                        {
                            system("CLS");
                            cout << "EMPATE!!!!!!!!\n";
                            system("pause");
                        }
                        else if (puntajeJugadorUno > puntajeJugadorDos)
                        {
                            system("CLS");
                            cout << "Ganaste! " + jugador_uno.getUsuario() + "\n";
                            system("pause");
                        }
                        else
                        {
                            system("CLS");
                            cout << "Ganaste! " + jugador_dos.getUsuario() + "\n";
                            system("pause");
                        }
                        terminarPartida();
                        caso_4 = false;
                        break;

                    default:
                        cout << "Seleccion invalida >:| \n";
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
            bool bandera_caso5 = true;
            int opcion_caso5;

            while (bandera_caso5)
            {
                cout << "1:Reporte de palabras(Diccionario)\n";
                cout << "2:Reporte de Fichas disponibles\n"; // done
                cout << "3:Reporte de Jugadores( Arbol binario)\n";
                cout << "4:Reporte recorrido Preorden ABB\n";
                cout << "5:Reporte recorrido Inorden ABB\n";
                cout << "6:Reporte recorrido Postorden ABB\n";
                cout << "7:Reporte Puntaje por jugador\n";
                cout << "8:Reporte Top puntuaciones\n";
                cout << "10:Salir\n";
                cin >> opcion_caso5;

                switch (opcion_caso5)
                {
                case 1:
                    graficarDiccionario();
                    break;
                case 2:
                    graficarColaLetras();
                    break;
                case 3:
                    arbol->mostrarJugadoresSimple();
                    break;
                case 4:
                    arbol->GraficarPreorden();
                    break;
                case 5:
                {
                    arbol->GraficarInorden();
                }

                break;
                case 6:
                    arbol->GraficarPostorden();
                    break;
                case 7:
                {
                    string usuario;
                    cout << "Ingrese el nombre de usuario para ver su historial de puntuaciones \n";
                    cin >> usuario;
                    arbol->GraficareportePuntajeJugador(usuario);
                    system("pause");
                }
                break;
                case 8:
                {
                    NodoArbol *root = arbol->getRoot();
                    reportajesPuntajesTotales(root);
                    imprimirPuntajesTotales();
                }

                break;
                case 9:
                {
                    bool bandera_caso9 = true;
                    int opcion_caso9;
                    while (bandera_caso9)
                    {
                        cout << "1:Jugador uno\n";
                        cout << "2:Jugador dos\n";
                        cout << "3:Salir\n";
                        cin >> opcion_caso9;

                        switch (opcion_caso9)
                        {
                        case 1:
                            graficarListasJugadores(lista_jugador_uno); //lista de fichas disponibles

                            break;
                        case 2:
                            graficarListasJugadores(lista_jugador_dos); //lista de fichas disponibles
                            break;

                        case 3:
                            bandera_caso9 = false;
                            break;
                        default:

                            break;
                        }
                    }
                }

                break;
                case 10:
                    bandera_caso5 = false;

                    break;
                default:
                    break;
                }
            }
        }
        break;

        default:
            cout << "Seleccion invalida >:| \n";
            break;
        }
    }
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
            string temp = ToUpperCase(j3.at("diccionario")[i].at("palabra"));
            listaPalabras->AddHead(temp);
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
    int a = 12, e = 12;
    int o = 9;
    int i = 6, s = 6;
    int n = 5, r = 5, u = 5, t = 5, d = 5;
    int l = 4, c = 4;
    int g = 2, b = 2, m = 2, p = 2, h = 2;
    int f = 1, v = 1, y = 1, q = 1, j = 1, enie = 1, x = 1, z = 1;
    srand(time(NULL));
    while (cola->getSize() <= 94)
    {
        num = 1 + rand() % (25 - 1);
        if (lista_numeros->buscar(num) == false)
        {
            switch (num)
            {
            case 1:
                if (a > 0)
                {
                    cola->Queue(*new Letra('A', 1));
                    a--;
                }
                else
                {
                    lista_numeros->Queue(num);
                }
                break;
            case 2:
                if (e > 0)
                {
                    cola->Queue(*new Letra('E', 1));
                    i--;
                }
                else
                {
                    lista_numeros->Queue(num);
                }

                break;
            case 3:
                if (o > 0)
                {
                    cola->Queue(*new Letra('O', 1));
                    o--;
                }
                else
                {
                    lista_numeros->Queue(num);
                }
                break;
            case 4:
                if (i > 0)
                {
                    cola->Queue(*new Letra('I', 1));
                    i--;
                }
                else
                {
                    lista_numeros->Queue(num);
                }

                break;
            case 5:
                if (s > 0)
                {
                    cola->Queue(*new Letra('S', 1));
                    s--;
                }
                else
                {
                    lista_numeros->Queue(num);
                }

                break;
            case 6:
                if (n > 0)
                {
                    cola->Queue(*new Letra('N', 1));
                    n--;
                }
                else
                {
                    lista_numeros->Queue(num);
                }

                break;
            case 7:
                if (l > 0)
                {
                    cola->Queue(*new Letra('L', 1));
                    l--;
                }
                else
                {
                    lista_numeros->Queue(num);
                }

                break;
            case 8:
                if (r > 0)
                {
                    cola->Queue(*new Letra('R', 1));
                    r--;
                }
                else
                {
                    lista_numeros->Queue(num);
                }

                break;
            case 9:
                if (u > 0)
                {
                    cola->Queue(*new Letra('U', 1));
                    u--;
                }
                else
                {
                    lista_numeros->Queue(num);
                }

                break;
            case 10:
                if (t > 0)
                {
                    cola->Queue(*new Letra('T', 1));
                    t--;
                }
                else
                {
                    lista_numeros->Queue(num);
                }

                break;
            case 11:
                if (d > 0)
                {
                    cola->Queue(*new Letra('D', 2));
                    d--;
                }
                else
                {
                    lista_numeros->Queue(num);
                }

                break;
            case 12:
                if (g > 0)
                {
                    cola->Queue(*new Letra('G', 2));
                    g--;
                }
                else
                {
                    lista_numeros->Queue(num);
                }

                break;
            case 13:
                if (c > 0)
                {
                    cola->Queue(*new Letra('C', 3));
                    c--;
                }
                else
                {
                    lista_numeros->Queue(num);
                }

                break;
            case 14:
                if (b > 0)
                {
                    cola->Queue(*new Letra('B', 3));
                    b--;
                }
                else
                {
                    lista_numeros->Queue(num);
                }

                break;
            case 15:
                if (m > 0)
                {
                    cola->Queue(*new Letra('M', 3));
                    m--;
                }
                else
                {
                    lista_numeros->Queue(num);
                }

                break;
            case 16:
                if (p > 0)
                {
                    cola->Queue(*new Letra('P', 3));
                    p--;
                }
                else
                {
                    lista_numeros->Queue(num);
                }

                break;
            case 17:
                if (h > 0)
                {
                    cola->Queue(*new Letra('H', 4));
                    h--;
                }
                else
                {
                    lista_numeros->Queue(num);
                }

                break;
            case 18:
                if (f > 0)
                {
                    cola->Queue(*new Letra('F', 4));
                    f--;
                }
                else
                {
                    lista_numeros->Queue(num);
                }

                break;
            case 19:
                if (v > 0)
                {
                    cola->Queue(*new Letra('V', 4));
                    v--;
                }
                else
                {
                    lista_numeros->Queue(num);
                }

                break;
            case 20:
                if (y > 0)
                {
                    cola->Queue(*new Letra('Y', 4));
                    y--;
                }
                else
                {
                    lista_numeros->Queue(num);
                }

                break;
            case 21:
                if (q > o)
                {
                    cola->Queue(*new Letra('Q', 5));
                    q--;
                }
                else
                {
                    lista_numeros->Queue(num);
                }

                break;
            case 22:
                if (j > 0)
                {
                    cola->Queue(*new Letra('J', 8));
                    j--;
                }
                else
                {
                    lista_numeros->Queue(num);
                }

                break;
            /*case 23:
                if (enie > 0)
                {
                    cola->Queue(*new Letra('\165', 8));
                    enie--;
                }
                else
                {
                    lista_numeros->Queue(num);
                }

                break;*/
            case 24:
                if (x > 0)
                {
                    cola->Queue(*new Letra('X', 8));
                    x--;
                }
                else
                {
                    lista_numeros->Queue(num);
                }

                break;
            case 25:
                if (z > 0)
                {
                    cola->Queue(*new Letra('Z', 10));
                    z--;
                }
                else
                {
                    lista_numeros->Queue(num);
                }

                break;

            default:
                break;
            }
        }
    }
    /*NodoCola<Letra> *temp_head = cola->getHead();
    NodoCola<Letra> *temp_tail = cola->getTail();
    int contador = 1;
    while (temp_tail != temp_head)
    {
        cout << "Letra: " << temp_tail->getData().getLetra()
             << " Puntaje= " << temp_tail->getData().getPuntaje()
             << " " << to_string(contador)
             << "\n";
        temp_tail = temp_tail->getNext();
        contador++;*/
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

void graficarColaLetras()
{
    int contador = 0;
    NodoCola<Letra> *temp = cola->getTail();
    string texto_cola = "digraph G { \n";
    texto_cola += "node1 [shape=record, label = \"{ ";

    while (temp != NULL)
    {
        //cout<<"Letra: "<<temp->getData().getLetra()<< " Puntuacion: " <<temp->getData().getPuntaje()<<"-"<<contador<<"\n";
        char letra = temp->getData().getLetra();
        texto_cola += letra + to_string(temp->getData().getPuntaje()) + "Pts|";
        temp = temp->getNext();
        contador++;
    }
    texto_cola += "}\"]\n}";
    ofstream ficheroSalida;
    ficheroSalida.open("dot_s\\FichasDisponibles.dot");
    ficheroSalida << texto_cola;
    ficheroSalida.close();

    system("dot -Tpng dot_s\\FichasDisponibles.dot -o imagenes\\FichasDisponibles.png");
    system("imagenes\\FichasDisponibles.png &");
}
void llenarListaDobles(listaEnlazadaDobleCircular<Letra> *lista)
{
    if (cola->getSize() == 0)
    {
        cout << "La cola de letras esta vacia, por favor revise la configuraciones del juego";
    }
    else
    {
        while (lista->getIndex() <= 6)
        {
            lista->AddHead(cola->getHead()->getData());
            cola->InQueue();
        }
    }
}
void graficarDiccionario()
{
    int contador = 1;
    NodoDCLL<string> *temp = listaPalabras->getHead();
    string texto = "digraph G {\n rankdir=LR \n node[shape=box] \n";
    string texto1;
    string texto2;

    while (contador <= listaPalabras->getIndex())
    {
        texto1 += "node" + to_string(contador) + "[label = \"" + temp->getData() + "\"]\n";

        if (contador == listaPalabras->getIndex())
        {
            texto2 += "node" + to_string(contador) + "->node1 [dir=both]\n";
        }
        else
        {
            texto2 += "node" + to_string(contador) + "->";
        }

        temp = temp->getNext();
        contador++;
    }
    texto += texto1 + texto2 + "\n}\n";

    ofstream ficheroSalida;
    ficheroSalida.open("dot_s\\diccionario.dot");
    ficheroSalida << texto;
    ficheroSalida.close();

    system("dot -Tpng dot_s\\diccionario.dot -o imagenes\\diccionario.png");
    system("imagenes\\diccionario.png &");
}
void graficarListasJugadores(listaEnlazadaDobleCircular<Letra> *lista_jugador)
{

    int contador = 1;
    NodoDCLL<Letra> *temp = lista_jugador->getHead();
    string texto = "digraph G {\n rankdir=LR \n node[shape=box] \n";
    string texto1;
    string texto2;

    while (contador <= lista_jugador->getIndex())
    {
        texto1 += "node" + to_string(contador) + "[label = \"" + temp->getData().getLetra() + "\"]\n";

        if (contador == lista_jugador->getIndex())
        {
            texto2 += "node" + to_string(contador) + "[dir=both];\n";
        }
        else
        {
            texto2 += "node" + to_string(contador) + "->";
        }

        temp = temp->getNext();
        contador++;
    }
    texto += texto1 + texto2 + "\n}\n";

    ofstream ficheroSalida;
    ficheroSalida.open("dot_s\\lista_letras_player_uno.dot");
    ficheroSalida << texto;
    ficheroSalida.close();

    system("dot -Tpng dot_s\\lista_letras_player_uno.dot -o imagenes\\lista_letras_player_uno.png");
    system("imagenes\\lista_letras_player_uno.png &");
}
bool buscarLetraEnListaJugador(listaEnlazadaDobleCircular<Letra> *lista, string data)
{
    NodoDCLL<Letra> *temp = lista->getHead();
    int contador = 1;

    while (contador <= lista->getIndex())
    {

        string s(1, temp->getData().getLetra());
        if (s == data)
        {
            return true;
        }
        temp = temp->getNext();
        contador++;
    }
}

string convertToString(char *a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++)
    {
        s = s + a[i];
    }
    return s;
}

bool match(listaSimple<Casillas> *lista) // funcion que hace el match para verificar la validez de las palabras en el tablero
{
    Nodo<Casillas> *temp = lista->getHead();
    int contador = 0;

    while (temp != NULL)
    {
        int x = temp->getData().get_x();
        int y = temp->getData().get_y();

        string temp1 = tablero->buscarPalabraMatriz_x(x);
        string temp2 = tablero->buscarPalabraMatriz_y(y);

        if (!listaPalabras->buscar(temp1) && !listaPalabras->buscar(temp2))
        {
            contador++;
        }
        temp = temp->getNext();
    }
    if (contador == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
string ToUpperCase(string st1)
{
    char s[50];
    int i;
    int j;

    for (int j = 0; j <= st1.size(); j++)
    {
        s[j] = st1[j];
    }

    for (int i = 0; i <= sizeof(s); i++)

    {

        if (s[i] >= 97 && s[i] <= 122)
        {
            s[i] = s[i] - 32;
        }
        j++;
    }

    return s;
}

void cambiarFichas(listaEnlazadaDobleCircular<Letra> *lista_letras_jugador)
{
    NodoDCLL<Letra> *temp_lista_letras = lista_letras_jugador->getHead();

    int contador = 1;

    while (contador <= lista_letras_jugador->getIndex())
    {
        cola->Queue(temp_lista_letras->getData());
        contador++;
    }
    lista_letras_jugador->borrarLista();
    llenarListaDobles(lista_letras_jugador);
}

NodoDCLL<Letra> *buscarLetraEnListaJugador_nodo(listaEnlazadaDobleCircular<Letra> *lista, string letra)
{
    NodoDCLL<Letra> *temp = lista->getHead();
    int contador = 1;

    while (contador <= lista->getIndex())
    {

        string s(1, temp->getData().getLetra());
        if (s == letra)
        {
            return temp;
        }
        temp = temp->getNext();
        contador++;
    }
}
int getPuntuacionLetra(string letra)
{
    if (letra == "A" || letra == "E" || letra == "O" || letra == "I" || letra == "S" || letra == "N" || letra == "L" || letra == "R" || letra == "U" || letra == "T")
    {
        return 1;
    }
    else if (letra == "D" || letra == "G")
    {
        return 2;
    }
    else if (letra == "C" || letra == "B" || letra == "M" || letra == "P")
    {
        return 3;
    }
    else if (letra == "H" || letra == "F" || letra == "V" || letra == "Y")
    {
        return 4;
    }
    else if (letra == "Q")
    {
        return 5;
    }
    else if (letra == "J" || letra == "X")
    {
        return 8;
    }
    else if (letra == "Z")
    {
        return 10;
    }
    else
    {
        return 0;
    }
}

int getPuntuacionTotal(int x, int y)
{

    string temp1 = tablero->buscarPalabraMatriz_x(x);
    string temp2 = tablero->buscarPalabraMatriz_y(y);

    int puntuacion_total_x = 0;
    int puntuacion_total_y = 0;
    if (listaPalabras->buscar(temp1)) // si encuentra una coincidencia de palabra en x
    {
        NodeMatriz<string> *temp = tablero->getRoot(); // buscando puntuacion en x
        while (temp->getX() != x)
        { // recorre a la derecha
            temp = temp->getRight();
        }
        while (temp != NULL)
        { // recorremos hacia abajo
            if (temp->getY() == -1)
            {
                temp = temp->getDown();
            }
            else
            {
                int bonus = BuscarDoble_Triple(temp->getX(), temp->getY());
                int puntoLetra = getPuntuacionLetra(temp->getData());
                int total = puntoLetra * bonus;
                puntuacion_total_x += total;
                temp = temp->getDown();
            }
        }
    }
    else if (listaPalabras->buscar(temp2))
    {
        NodeMatriz<string> *temp = tablero->getRoot();
        while (temp->getY() != y)
        {
            temp = temp->getDown();
        }
        while (temp != NULL)
        {
            if (temp->getX() == -1)
            {
                temp = temp->getRight();
            }
            else
            {
                int bonus = BuscarDoble_Triple(temp->getX(), temp->getY());
                int puntoLetra = getPuntuacionLetra(temp->getData());
                int total = puntoLetra * bonus;
                puntuacion_total_y += total;
                temp = temp->getRight();
            }
        }
    }
    return puntuacion_total_x + puntuacion_total_y;
}

int BuscarDoble_Triple(int x, int y)
{
    Nodo<Casillas> *temp = listaCasillas->getHead();
    while (temp != NULL)
    {
        if (temp->getData().get_x() == x && temp->getData().get_y() == y)
        {
            if (temp->getData().getTipo() == "Doble")
            {
                return 2;
            }
            else if (temp->getData().getTipo() == "Triple")
            {
                return 3;
            }
            else
            {
                return 1;
            }
        }
        temp = temp->getNext();
    }
    return 1;
}
void catchError()
{
    if (cin.fail())
    {
        cout << "Entrada invalida >:| \n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void ReportePuntajePorJugador()
{
}
void terminarPartida()
{
    Jugador *temp = new Jugador("NULL");
    jugador_uno = *temp;
    jugador_dos = *temp;

    tablero->borrarMatriz();
    cola->DeleteAll();
    llenarColaAleatoria();
    puntajeJugadorUno = 0;
    puntajeJugadorDos = 0;

    lista_jugador_uno->borrarLista();
    lista_jugador_dos->borrarLista();
}

void reportajesPuntajesTotales(NodoArbol *nodo)
{
    if (nodo != NULL)
    {

        aniadirPuntajeALista(nodo->getPlayer());
        reportajesPuntajesTotales(nodo->getRight());
        reportajesPuntajesTotales(nodo->getLeft());
    }
}

void aniadirPuntajeALista(Jugador jugador)
{
    Nodo<Jugador> *nuevo = new Nodo<Jugador>();
    nuevo->setData(jugador);
    Nodo<Jugador> *temp = listaPuntajeTotal->getHead();

    if (listaPuntajeTotal->getHead() == NULL)
    {
        listaPuntajeTotal->setHead(nuevo);
    }
    else
    {
        if (listaPuntajeTotal->getHead()->getData().getPuntajeUsuario()->getTail() > jugador.getPuntajeUsuario()->getTail())
        {
            nuevo->setNext(listaPuntajeTotal->getHead());
            listaPuntajeTotal->setHead(nuevo);
        }
        else
        {
            while ((temp->getNext() != NULL) && temp->getNext()->getData().getPuntajeUsuario()->getTail() < jugador.getPuntajeUsuario()->getTail())
            {
                temp = temp->getNext();
            }
            nuevo->setNext(temp->getNext());
            temp->setNext(nuevo);
        }
    }
}
void imprimirPuntajesTotales()
{
    Nodo<Jugador> *temp = listaPuntajeTotal->getHead();
    string text = "digraph G { \n ";
    string text1;
    int contador = 1;

    while (temp != NULL)
    {
        text += "node" + to_string(contador) + "[label =\"" + temp->getData().getUsuario() + "-" + to_string(temp->getData().getPuntajeUsuario()->getTail()->getData()) + "pts\"];\n";

        if (temp->getNext() == NULL)
        {
            text1 = "node" + to_string(contador) + ";\n";
        }
        else
        {
            text1 = "node" + to_string(contador) + "->";
        }
        contador++;
        temp = temp->getNext();
    }
    text += text1 + "\n}";
    cout << text;
}
