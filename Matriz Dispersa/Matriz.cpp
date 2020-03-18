#include "Matriz.h"

using namespace std;

template <typename T>
Matriz<T>::Matriz()
{
}

template <typename T>
Node<T> *Matriz<T>::getRoot() { return this->root; }
template <typename T>
void Matriz<T>::setRoot(Node<T> *root) { this->root = root; }

template <typename T>
Node<T> *Matriz<T>::searchCol(int x)
{
    Node<T> *temp = root;
    while (temp != NULL)
    {
        if (temp->getX() == x)
        {
            return temp;
        }
        temp = temp->getRight();
    }
    return NULL;
}
template <typename T>
Node<T> *Matriz<T>::searchRow(int y)
{
    Node<T> *temp = root;
    while (temp != NULL)
    {
        if (temp->getY() == y)
        {
            return temp;
        }
        temp = temp->getDown();
    }
    return NULL;
}
template <typename T>
Node<T> *Matriz<T>::AddCol(int x)
{
    Node<T> *head_col = root;
    Node<T> *col = AddSortCol(new Node<T>("Col" + to_string(x), x, -1), head_col);
    return col;
}
template <typename T>
Node<T> *Matriz<T>::AddRow(int y)
{
    Node<T> *head_row = root;
    Node<T> *row = AddSortRow(new Node<T>("Fil" + to_string(y), -1, y), head_row);
    return row;
}
template <typename T>
void Matriz<T>::AddElement(T data, int x, int y)
{
    Node<T> *nuevo = new Node<T>(data, x, y);
    Node<T> *colNode = searchCol(x);
    Node<T> *rowNode = searchRow(y);
    /*caso 1: columna y filas no existen:
        1.1 Creamos fila y creamos columna
        1.2 Insertamos de forma ordenada en columna 
        1.3 Insertamos de forma ordena en fila 
          
    **/

    if (colNode == NULL && rowNode == NULL)
    {
        std::cout << "caso1 \n";
        Node<T> *nodoColumna = AddCol(x); //1.1
        Node<T> *nodoFila = AddRow(y);
        nuevo = AddSortCol(nuevo, nodoFila);    //1.2
        nuevo = AddSortRow(nuevo, nodoColumna); //1.3
        return;
    }

    /*caso2:: Fila existe pero columna no
        2.1 Creamos columna
        2.2 Insertamos de forma ordenada en fila
        2.3 insertamos de forma ordenada en columna
    
    */
    if (colNode == NULL && rowNode != NULL)
    {
        std::cout << "caso2 \n";
        Node<T> *nodoColumna = AddCol(x);  
        nuevo = AddSortRow(nuevo, nodoColumna);     //2.1
        nuevo = AddSortCol(nuevo, rowNode);     //2.3
         //2.2
        return;
    }
    /*caso3: columna existe pero fila no
        3.1 creamos fila
        3.2 insertamos de forma ordenada en fila
        3.3 insertamos de forma ordenada en columna
    */
    if (colNode != NULL && rowNode == NULL)
    {
        std::cout << "caso3\n";
        Node<T> *nodoFila = AddRow(y); //3.1
        nuevo = AddSortRow(nuevo, colNode);
        nuevo = AddSortCol(nuevo, nodoFila);
        return;
    }
    /*caso4: existen ambas
        4.1 Insertamos de forma ordenada en fila
        4.2 Insertamos en forma ordenada en columna
    */
    if (colNode != NULL && rowNode != NULL)
    {
        std::cout << "caso4\n";
        AddSortCol(nuevo, rowNode);
        AddSortRow(nuevo, colNode);
        return;
    }
}
template <typename T>
Node<T> *Matriz<T>::AddSortCol(Node<T> *nuevo, Node<T> *head_col)
{
    Node<T> *temp = head_col;
    bool bandera = false;
    while (bandera == false)
    {
        if (temp->getX() == nuevo->getX())
        {
            temp->setY(nuevo->getY());
            temp->setData(nuevo->getData());
            return temp;
        }
        else if (temp->getX() > nuevo->getX())
        {
            bandera = true;
            break;
        }
        if (temp->getRight() != NULL)
        {
            temp = temp->getRight();
        }
        else
        {
            break;
        }
    }
    if (bandera == true)
    {
        nuevo->setRight(temp);
        temp->getLeft()->setRight(nuevo);
        nuevo->setLeft(temp->getLeft());
        temp->setLeft(nuevo);
        return nuevo;
    }
    else
    {
        temp->setRight(nuevo);
        nuevo->setLeft(temp);
        return nuevo;
    }
}
template <typename T>
Node<T> *Matriz<T>::AddSortRow(Node<T> *nuevo, Node<T> *head_row)
{
    Node<T> *temp = head_row;
    bool bandera = false;
    while (bandera == false)
    {
        if (temp->getY() == nuevo->getY())
        {
            temp->setX(nuevo->getX());
            temp->setData(nuevo->getData());
            return temp;
        }
        else if (temp->getY() > nuevo->getY())
        {
            bandera = true;
            break;
        }
        if (temp->getDown() != NULL)
        {
            temp = temp->getDown();
        }
        else
        {
            break;
        }
    }
    if (bandera == true)
    {
        nuevo->setDown(temp);
        temp->getUp()->setDown(nuevo);
        nuevo->setUp(temp->getUp());
        temp->setUp(nuevo);
        return nuevo;
    }
    else
    {
        temp->setDown(nuevo);
        nuevo->setUp(temp);
        return nuevo;
    }
}
template <typename T>
string Matriz<T>::textoGraphviz()
{
    Node<T> *temp = root;
    Node<T> *temp_y = temp;

    string texto = "digraph { \n node [shape = rectangle]; \n rankdir=LR; \n ";

    while (temp != NULL)
    {
        if (temp->getRight() == NULL)
        {
            if (temp == root)
            {
                texto += temp->getData() + "\n";
                temp_y = temp_y->getDown();
                temp = temp_y;
            }
            else
            {
                texto += temp->getData() + " [dir = \"both\"]; \n";
                temp_y = temp_y->getDown();
                temp = temp_y;
            }
        }
        else
        {
            texto += temp->getData() + "->";
            temp = temp->getRight();
        }
    }
    texto += "\n";
    temp = root;
    Node<T> *temp_x = temp;
    while (temp != NULL)
    {
        if (temp->getDown() == NULL)
        {
            if (temp == root)
            {
                texto += temp->getData() + "\n";
                temp_x = temp_x->getRight();
                temp = temp_x;
            }
            else
            {
                texto += temp->getData() + " [dir = \"both\"]; \n";
                temp_x = temp_x->getRight();
                temp = temp_x;
            }
        }
        else
        {
            texto += temp->getData() + "->";
            temp = temp->getDown();
        }
    }
    texto += "\n";
    //rank=same
    temp = root;
    temp_x = temp;
    while (temp != NULL)
    {
        if ((temp->getY() == -1) && (temp->getDown() == NULL))
        {
            //texto += temp->getData() + " [dir = \"both\"]; \n";
            temp_x = temp_x->getRight();
            temp = temp_x;
        }
        else if ((temp->getY() == -1) && (temp->getDown() != NULL))
        {
            texto += "{rank=same " + temp->getData() + ", ";
            temp = temp->getDown();
        }
        else
        {
            if (temp->getDown() == NULL)
            {
                texto += temp->getData() + "}\n ";
                temp_x = temp_x->getRight();
                temp = temp_x;
            }
            else
            {
                texto += temp->getData() + ", ";
                temp = temp->getDown();
            }
        }
    }

    texto += " \n }";
    return texto;
}