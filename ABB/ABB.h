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
    
    bool IsEmpty(NodoArbol*);

    void InOrden (NodoArbol *);
    void Preorden(NodoArbol *);//raiz, izquierda, derecha
    void PostOrden(NodoArbol *);//Izquierda, derecha, raiz
    //Funciones Auxiliares
    //void Podar(Nodo<T> * & node);


    

};






#endif