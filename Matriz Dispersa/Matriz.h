#ifndef MATRIZ_H_
#define MATRIZ_H_

#include <string>
#include "NodeMatriz.cpp"

using namespace std;
template <class T>
class Matriz
{
private:
    NodeMatriz<T> *root = new NodeMatriz<T> ("root",-1,-1) ;
public:
    Matriz();
    ~Matriz();
    NodeMatriz<T>* getRoot();
    void setRoot(NodeMatriz<T>*);
    NodeMatriz <T>* searchCol(int x);// search a column on x
    NodeMatriz<T>* searchRow(int y);// search a Row on y
    NodeMatriz<T>* AddCol(int x);//Añade una columna en x dato una coordenada x
    NodeMatriz<T>* AddRow (int y);//añade una fila en y dado una coordenanda y
    void AddElement(T data, int x, int y);//añade un elemento a la matriz
    NodeMatriz<T>* AddSortCol (NodeMatriz<T>*, NodeMatriz<T>*);//inserta ordeno en columna
    NodeMatriz<T>* AddSortRow (NodeMatriz<T>*, NodeMatriz<T>*);//inserta ordanado en fila
    void textoGraphviz();
    string buscarPalabraMatriz_x(int x);//buscar palabras en una columna
    string buscarPalabraMatriz_y(int y);//buscar palabras en una columna
    
    void borrarNodo(int , int);
    void borrarFila(int); // borrar una fila residual vacia
    void borrarColumna(int);// borra una columna residual vacia
    void Matriz<T>::borrarMatriz();//borrar todos los nodos dejando unicamente la raiz
    

};






#endif

