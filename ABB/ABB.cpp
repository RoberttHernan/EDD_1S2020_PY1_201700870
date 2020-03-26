

#include "ABB.h"
using namespace std;
string texto;
ABB::ABB()
{

    this->root = NULL;
    this->actual = NULL;
    this->contador = 0;
    this->altura = 0;
}

NodoArbol *ABB::getRoot()
{
    return this->root;
}
void ABB::setRoot(NodoArbol *root) { this->root = root; }
NodoArbol *ABB::getActual()
{
    return this->actual;
}
void ABB::setActual(NodoArbol *actual) { this->actual = actual; }

bool ABB::IsEmpty(NodoArbol *r)
{
    return r == NULL;
}
void ABB::Add(Jugador *data)
{
    NodoArbol *padre = NULL;
    actual = root;
    //buscando el dato en el arbol manteniendo el puntero al nodo padre
    while (!IsEmpty(actual) && data->getUsuario() != actual->getPlayer().getUsuario())
    {
        padre = actual;
        if (data->getUsuario() > actual->getPlayer().getUsuario())
        {
            actual = actual->getRight();
        }
        else if (data->getUsuario() < actual->getPlayer().getUsuario())
        {
            actual = actual->getLeft();
        }
    }
    //si se ha encontrado un elemento retorna sin insertar
    if (!IsEmpty(actual))
    {
        cout << "Usuario ya ingresado";
        return;
    }
    //si el padre es null el arbol estaba vacio,
    if (IsEmpty(root))
    {
        root = new NodoArbol();
        root->setData(data);
    }
    else if (data->getUsuario() < padre->getPlayer().getUsuario())
    {
        NodoArbol *temp = new NodoArbol(data);

        padre->setLeft(temp);
    }
    else if (data->getUsuario() > padre->getPlayer().getUsuario())
    {
        NodoArbol *temp = new NodoArbol(data);

        padre->setRight(temp);
    }
}

void ABB::InOrden(NodoArbol *nodo)
{
    if (nodo != NULL)
    {
        InOrden(nodo->getLeft());
        cout << nodo->getPlayer().getUsuario() << " ";
        InOrden(nodo->getRight());
    }
}

/*void ABB::InOrden(NodoArbol *nodo)
{
    int contador = 1;
    //string texto = "digraph Players { \n rankdir =TB \n node [style=Box] \n";
    string texto;
    if (nodo != NULL)
    {

        InOrden(nodo->getLeft());
        
            texto += "node" + to_string(contador) + "[shape = record, label =\"{ " + nodo->getPlayer().getUsuario() + " | MaxScore: " + to_string(nodo->getPlayer().getPuntajeUsuario()->getTail()->getData()) + "}\"]\n";
            //cout << nodo->getPlayer().getUsuario() << " ";
        
        InOrden(nodo->getRight());
    }
    //texto += "\n}";
    cout << texto;
}*/

bool ABB::buscar(string user)
{
    NodoArbol *padre = NULL;
    actual = root;
    //buscando el dato en el arbol manteniendo el puntero al nodo padre
    while (!IsEmpty(actual) && user != actual->getPlayer().getUsuario())
    {
        padre = actual;
        if (user > actual->getPlayer().getUsuario())
        {
            actual = actual->getRight();
        }
        else if (user < actual->getPlayer().getUsuario())
        {
            actual = actual->getLeft();
        }
    }
    //si se ha encontrado un elemento retorna sin insertar
    if (!IsEmpty(actual))
    {

        return true;
    }
    return false;
}
Jugador ABB::buscarJugador(string user)
{
    Jugador * nulo = new Jugador();
    NodoArbol *padre = NULL;
    actual = root;

    while (!IsEmpty(actual) && user != actual->getPlayer().getUsuario())
    {
        padre = actual;
        if (user > actual->getPlayer().getUsuario())
        {
            actual = actual->getRight();
        }
        else if (user < actual->getPlayer().getUsuario())
        {
            actual = actual->getLeft();
        }
    }
    if (!IsEmpty(actual))
    {

        return actual->getPlayer();
    }
    return *nulo;
}
//Recorridos
/*template <typename T>
void ABB<T>::Preorden(NodoArbol<T> *nodo)
{
    if (nodo != NULL)
    {
        cout << nodo->getData() << " ";
        Preorden(nodo->getLeft());
        Preorden(nodo->getRight());
    }
}
template <typename T>
void ABB<T>::InOrden(NodoArbol<T> *nodo)
{
    if (nodo != NULL)
    {
        InOrden(nodo->getLeft());
        cout << nodo->getData() << " ";
        InOrden(nodo->getRight());
    }
}
template <typename T>
void ABB<T>::PostOrden(NodoArbol<T> *nodo)
{
    if (!IsEmpty(nodo))
    {
        PostOrden(nodo->getLeft());
        PostOrden(nodo->getRight());
        cout << nodo->getData() << " ";
    }
}
template<typename T>
void ABB<T>::Podar(Nodo <T>* &node){
        if(node){
            Podar(node->getLeft());
            Podar(node->getRight());
            delete node ;
            node = NULL;
        }
}

bool ABB::IsEmpty(NodoArbol<Jugador> *r)
{
    return r == NULL;
}

template <typename T>
ABB<T>::~ABB()
{
    //Podar(root);
}
template <typename T>
bool ABB<T>::buscar(T data)
{
    NodoArbol<T> *padre = NULL;
    actual = root;
    //buscando el dato en el arbol manteniendo el puntero al nodo padre
    while (!IsEmpty(actual) && data != actual->getData())
    {
        padre = actual;
        if (data > actual->getData())
        {
            actual = actual->getRight();
        }
        else if (data < actual->getData())
        {
            actual = actual->getLeft();
        }
    }
    //si se ha encontrado un elemento retorna sin insertar
    if (!IsEmpty(actual))
    {

        return true;
    }
    return false;
}
*/
string ABB::graphvizArbolSimple(NodoArbol *nodo)
{
    //string texto = "digraph Players { \n rankdir =TB \n node [style=Box] \n";

    if (nodo != NULL)
    {

        graphvizArbolSimple(nodo->getLeft());

        texto += nodo->getPlayer().getUsuario() + "\n";

        graphvizArbolSimple(nodo->getRight());
    }
    return texto;
}
void ABB::mostrarJugadoresSimple()
{
    NodoArbol *raiz = this->root;
    string temp = graphvizArbolSimple(raiz);
    string texto = "digraph { \n" + temp + " labelloc=\"t\"; label=\"Jugadores disponibles\"; \n}";

    ofstream ficheroSalida;
    ficheroSalida.open("mostrarJugadoresSimple.dot");
    ficheroSalida << texto;
    ficheroSalida.close();

    system("dot -Tpng mostrarJugadoresSimple.dot -o mostrarJugadoresSimple.png");
    system("mostrarJugadoresSimple.png &");
}
