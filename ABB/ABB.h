#ifndef ABB_H_
#define ABB_H_
#include  "NodoArbol.cpp"

using namespace std;

template <class T>
class ABB
{
private:
    NodoArbol<T> *root;
    NodoArbol <T> * actual;
    int contador ;
    int altura;


    //funciones auxiliares
    
    
public:
//Constructor y Destructor
    ABB();
    ~ABB();

    //Getters y Setters
    NodoArbol<T> * getRoot();
    void setRoot (NodoArbol<T> * root);
    NodoArbol<T> *getActual();
    void setActual(NodoArbol<T> *actual);
    int getContador();
    void setContador(int contador);
    int getAltura();
    void setAltura(int altura);

//Operaciones
    void Add(T);
    
    bool IsEmpty(NodoArbol<T>*);

    void InOrden (NodoArbol<T> *);
    void Preorden(NodoArbol <T>*);//raiz, izquierda, derecha
    void PostOrden(NodoArbol<T> *);//Izquierda, derecha, raiz
    //Funciones Auxiliares
    //void Podar(Nodo<T> * & node);


    

};






#endif