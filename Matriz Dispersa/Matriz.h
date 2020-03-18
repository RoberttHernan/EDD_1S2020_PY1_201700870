#ifndef MATRIZ_H_
#define MATRIZ_H_

#include <string>
#include "Node.cpp"

using namespace std;
template <class T>
class Matriz
{
private:
    Node<T> *root = new Node<T> ("root",-1,-1) ;
public:
    Matriz();
    ~Matriz();
    Node<T>* getRoot();
    void setRoot(Node<T>*);
    Node <T>* searchCol(int x);// search a column on x
    Node<T>* searchRow(int y);// search a Row on y
    Node<T>* AddCol(int x);//Añade una columna en x dato una coordenada x
    Node<T>* AddRow (int y);//añade una fila en y dado una coordenanda y
    void AddElement(T data, int x, int y);//añade un elemento a la matriz
    Node<T>* AddSortCol (Node<T>*, Node<T>*);//inserta ordeno en columna
    Node<T>* AddSortRow (Node<T>*, Node<T>*);//inserta ordanado en fila
    std::string textoGraphviz();

};






#endif

