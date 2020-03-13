#ifndef ABB_H_
#define ABB_H_
#include  "Nodo.cpp"

using namespace std;

template <class T>
class ABB
{
private:
    Nodo<T> *root;
    Nodo <T> * actual;
    int contador ;
    int altura;


    //funciones auxiliares
    
    
public:
//Constructor y Destructor
    ABB();
    ~ABB();

    //Getters y Setters
    Nodo<T> * getRoot();
    void setRoot (Nodo<T> * root);
    Nodo<T> *getActual();
    void setActual(Nodo<T> *actual);
    int getContador();
    void setContador(int contador);
    int getAltura();
    void setAltura(int altura);

//Operaciones
    void Add(T);
    
    bool IsEmpty(Nodo<T>*);

    void InOrden (Nodo<T> *);
    void Preorden(Nodo <T>*);//raiz, izquierda, derecha
    void PostOrden(Nodo<T> *);//Izquierda, derecha, raiz
    //Funciones Auxiliares
    //void Podar(Nodo<T> * & node);


    

};






#endif