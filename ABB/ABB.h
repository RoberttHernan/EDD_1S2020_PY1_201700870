#ifndef ABB_H_
#define ABB_H_
#include  "NodoArbol.cpp"

using namespace std;
class ABB
{
private:
    NodoArbol *root;
    NodoArbol * actual;
    int contador ;
    int altura;


    //funciones auxiliares
    
    
public:
//Constructor y Destructor
    ABB();
    ~ABB();

    //Getters y Setters
    NodoArbol* getRoot();
    void setRoot (NodoArbol * root);
    NodoArbol *getActual();
    void setActual(NodoArbol *actual);
    int getContador();
    void setContador(int contador);
    int getAltura();
    void setAltura(int altura);

//Operaciones
    void Add(Jugador*);
    bool buscar(string);
    Jugador  buscarJugador (string);
    
    bool IsEmpty(NodoArbol*);

    string InOrden (NodoArbol *);
    void GraficarInorden();
    string Preorden(NodoArbol *);//raiz, izquierda, derecha
    void GraficarPreorden();
    string PostOrden(NodoArbol *);//Izquierda, derecha, raiz
    void GraficarPostorden();

    void GraficareportePuntajeJugador(string usuario);



    void mostrarJugadoresSimple ();// mostrara solo el listado de jugadores existentes
    string graphvizArbolSimple(NodoArbol * nodo);// regresa el texto intermedio del texto graphviz necesitado para graficar en la funcion mostrarJugadoresSimple();
    
    
    //Funciones Auxiliares
    //void Podar(Nodo<T> * & node);


    

};






#endif