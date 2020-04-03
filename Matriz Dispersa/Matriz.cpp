#include "Matriz.h"

using namespace std;

template <typename T>
Matriz<T>::Matriz()
{
}

template <typename T>
NodeMatriz<T> *Matriz<T>::getRoot() { return this->root; }
template <typename T>
void Matriz<T>::setRoot(NodeMatriz<T> *root) { this->root = root; }

template <typename T>
NodeMatriz<T> *Matriz<T>::searchCol(int x)
{
    NodeMatriz<T> *temp = root;
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
NodeMatriz<T> *Matriz<T>::searchRow(int y)
{
    NodeMatriz<T> *temp = root;
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
NodeMatriz<T> *Matriz<T>::AddCol(int x)
{
    NodeMatriz<T> *head_col = root;
    NodeMatriz<T> *col = AddSortCol(new NodeMatriz<T>("Col" + to_string(x), x, -1), head_col);
    return col;
}
template <typename T>
NodeMatriz<T> *Matriz<T>::AddRow(int y)
{
    NodeMatriz<T> *head_row = root;
    NodeMatriz<T> *row = AddSortRow(new NodeMatriz<T>("Fil" + to_string(y), -1, y), head_row);
    return row;
}
template <typename T>
void Matriz<T>::AddElement(T data, int x, int y)
{
    NodeMatriz<T> *nuevo = new NodeMatriz<T>(data, x, y);
    NodeMatriz<T> *colNode = searchCol(x);
    NodeMatriz<T> *rowNode = searchRow(y);
    /*caso 1: columna y filas no existen:
        1.1 Creamos fila y creamos columna
        1.2 Insertamos de forma ordenada en columna 
        1.3 Insertamos de forma ordena en fila 
          
    **/

    if (colNode == NULL && rowNode == NULL)
    {
        std::cout << "caso1 \n";
        NodeMatriz<T> *nodoColumna = AddCol(x); //1.1
        NodeMatriz<T> *nodoFila = AddRow(y);
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
        NodeMatriz<T> *nodoColumna = AddCol(x);
        nuevo = AddSortRow(nuevo, nodoColumna); //2.1
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
        NodeMatriz<T> *nodoFila = AddRow(y); //3.1
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
NodeMatriz<T> *Matriz<T>::AddSortCol(NodeMatriz<T> *nuevo, NodeMatriz<T> *head_col)
{
    NodeMatriz<T> *temp = head_col;
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
NodeMatriz<T> *Matriz<T>::AddSortRow(NodeMatriz<T> *nuevo, NodeMatriz<T> *head_row)
{
    NodeMatriz<T> *temp = head_row;
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
void Matriz<T>::textoGraphviz() //arbol
{
    NodeMatriz<T> *temp = root;
    NodeMatriz<T> *temp_y = temp;
    NodeMatriz<T> *temp_x = temp;

    string texto = "digraph { \n node [shape = rectangle]; \n rankdir=LR; \n ";
    string texto1; //texto de nodos    node1[label = "algo"];
    string texto2; //texto de ->
    string texto3;
    string texto4; // rank same

    while (temp != NULL) // creacion de nodos
    {

        if (temp->getY() == -1) // si estamos en la fila -1
        {
            if (temp == root) // lo primero que visitamos es la raiz
            {
                texto1 += "noder[label =\"Root\"];\n";
                temp = temp->getRight();
            }
            else
            {

                texto1 += "nodeCol_" + to_string(temp->getX()) + "[label=\"Col " + to_string(temp->getX()) + "\"];\n";
                temp = temp->getRight();
            }
            if (temp == NULL) // si llegamos al final de la fila
            {
                temp = temp_y->getDown();
                temp_y = temp;
            }
        }
        else
        {
            if (temp->getX() == -1) // si estamos en la columna -1
            {
                texto1 += "nodeFil_" + to_string(temp->getY()) + "[label=\"Fil " + to_string(temp->getY()) + "\"];\n";
                temp = temp->getRight();
            }
            else
            {
                texto1 += "node" + to_string(temp->getX()) + "_" + to_string(temp->getY()) + "[label =\"" + temp->getData() + "\"];\n";
                temp = temp->getRight();
            }
            if (temp == NULL) // si llegamos al final de la fila
            {
                temp = temp_y->getDown();
                temp_y = temp;
            }
        }
    }
    temp = root;
    temp_y = temp;
    temp_x = temp;
    while (temp != NULL)
    { //union de columnas
        if (temp->getY() == -1)
        {
            if (temp == root && temp->getRight() == NULL)
            {
                texto2 += "noder\n";
                temp = temp_y->getDown();
                temp_y = temp;
            }
            else if (temp == root && temp->getRight() != NULL)
            {
                texto2 += "noder->";
                temp = temp->getRight();
            }
            else
            {
                if (temp->getRight() == NULL)
                {
                    texto2 += "nodeCol_" + to_string(temp->getX()) + "[dir =both];\n";
                    temp = temp_y->getDown();
                    temp_y = temp;
                }
                else
                {
                    texto2 += "nodeCol_" + to_string(temp->getX()) + "->";
                    temp = temp->getRight();
                }
            }
        }
        else
        {
            if (temp->getX() == -1)
            {
                if (temp->getRight() != NULL)
                {
                    texto2 += "nodeFil_" + to_string(temp->getY()) + "->";
                    temp = temp->getRight();
                }
                else
                {
                    texto2 += "nodeFil_" + to_string(temp->getY()) + "[dir =both];\n";
                    temp = temp_y->getDown();
                    temp_y = temp;
                }
            }
            else
            {
                if (temp->getRight() == NULL)
                {
                    texto2 += "node" + to_string(temp->getX()) + "_" + to_string(temp->getY()) + "[dir =both];\n";
                    temp = temp_y->getDown();
                    temp_y = temp;
                }
                else
                {
                    texto2 += "node" + to_string(temp->getX()) + "_" + to_string(temp->getY()) + "->";
                    temp = temp->getRight();
                }
            }
        }
    }
    temp = root;
    temp_y = temp;
    temp_x = temp;
    while (temp != NULL) //union de Filas
    {
        if (temp->getX() == -1)
        {
            if (temp == root && temp->getDown() == NULL)
            {
                texto3 += "noder\n";
                temp = temp_x->getRight();
                temp_x = temp;
            }
            else if (temp == root && temp->getDown() != NULL)
            {
                texto3 += "noder->";
                temp = temp->getDown();
            }
            else
            {
                if (temp->getDown() == NULL)
                {
                    texto3 += "nodeFil_" + to_string(temp->getY()) + "[dir =both];\n";
                    temp = temp_x->getRight();
                    temp_x = temp;
                }
                else
                {
                    texto3 += "nodeFil_" + to_string(temp->getY()) + "->";
                    temp = temp->getDown();
                }
            }
        }
        else
        {
            if (temp->getY() == -1)
            {
                if (temp->getDown() != NULL)
                {
                    texto3 += "nodeCol_" + to_string(temp->getX()) + "->";
                    temp = temp->getDown();
                }
                else
                {
                    texto3 += "nodeCol_" + to_string(temp->getX()) + "[dir =both];\n";
                    temp = temp_x->getRight();
                    temp_x = temp;
                }
            }
            else
            {
                if (temp->getDown() == NULL)
                {
                    texto3 += "node" + to_string(temp->getX()) + "_" + to_string(temp->getY()) + "[dir =both];\n";
                    temp = temp_x->getRight();
                    temp_x = temp;
                }
                else
                {
                    texto3 += "node" + to_string(temp->getX()) + "_" + to_string(temp->getY()) + "->";
                    temp = temp->getDown();
                }
            }
        }
    }
    temp = root;
    temp_y = temp;
    temp_x = temp;
    while (temp != NULL) //Rank same
    {
        if (temp->getX() == -1)
        {
            if (temp == root && temp->getDown() == NULL)
            {
                temp = temp_x->getRight();
                temp_x = temp;
            }
            else if (temp == root && temp->getDown() != NULL)
            {
                texto4 += "{rank=same noder,";
                temp = temp->getDown();
            }
            else
            {
                if (temp->getDown() == NULL)
                {
                    texto4 += "nodeFil_" + to_string(temp->getY()) + "}\n";
                    temp = temp_x->getRight();
                    temp_x = temp;
                }
                else
                {
                    texto4 += "nodeFil_" + to_string(temp->getY()) + ",";
                    temp = temp->getDown();
                }
            }
        }
        else
        {
            if (temp->getY() == -1)
            {
                if (temp->getDown() != NULL)
                {
                    texto4 += "{rank = same nodeCol_" + to_string(temp->getX()) + ",";
                    temp = temp->getDown();
                }
                else
                {
                    texto4 += "nodeCol_" + to_string(temp->getX()) + "}\n";
                    temp = temp_x->getRight();
                    temp_x = temp;
                }
            }
            else
            {
                if (temp->getDown() == NULL)
                {
                    texto4 += "node" + to_string(temp->getX()) + "_" + to_string(temp->getY()) + "}\n";
                    temp = temp_x->getRight();
                    temp_x = temp;
                }
                else
                {
                    texto4 += "node" + to_string(temp->getX()) + "_" + to_string(temp->getY()) + ",";
                    temp = temp->getDown();
                }
            }
        }
    }

    texto += texto1 + "\n" + texto2 + "\n" + texto3 + "\n" + texto4;
    texto += " \n }";

    ofstream ficheroSalida;
    ficheroSalida.open("dot_s\\matriz.dot");
    ficheroSalida << texto;
    ficheroSalida.close();

    system("dot -Tpng dot_s\\matriz.dot -o imagenes\\matriz.png");
    system("imagenes\\matriz.png &");
}

template <typename T>
string Matriz<T>::buscarPalabraMatriz_x(int x)
{
    NodeMatriz<T> *temp = root;
    string palabra;

    while (temp->getX() != x)
    {
        temp = temp->getRight();
    }
    while (temp != NULL)
    {

        if (temp->getY() == -1)
        {
            temp = temp->getDown();
        }
        else
        {
            palabra += temp->getData();
            temp = temp->getDown();
        }
    }
    return palabra;
}
template <typename T>
string Matriz<T>::buscarPalabraMatriz_y(int y)
{
    NodeMatriz<T> *temp = root;
    string palabra;

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
            palabra += temp->getData();
            temp = temp->getRight();
        }
    }
    return palabra;
}
template <typename T>
void Matriz<T>::borrarNodo(int x, int y)
{
    NodeMatriz<T> *temp = root;
    NodeMatriz<T> *temp_x = temp;
    NodeMatriz<T> *temp_y = temp;

    //buscando nodo en x
    while (temp->getX() != x)
    {
        temp = temp->getRight();
    }
    while (temp->getY() != y)
    {
        temp = temp->getDown();
    }
        temp->getLeft()->setRight(temp->getRight());
        temp->getUp()->setDown(temp->getDown());
        if (temp->getRight()!=NULL){
            temp->getRight()->setLeft(temp->getLeft());
        }
        if(temp->getDown()!=NULL){
            temp->getDown()->setUp(temp->getUp());
        }
        free(temp);

    
    borrarColumna(x);
    borrarFila(y);
}
template <typename T>
void Matriz<T>::borrarColumna(int x)
{
    NodeMatriz<T> *temp = root;
    while (temp->getX() != x)
    {
        temp = temp->getRight();
    }
    if (temp->getDown() == NULL)
    {
        if (temp->getRight() != NULL) //borrando un nodo medio
        {
            temp->getLeft()->setRight(temp->getRight());
            temp->getRight()->setLeft(temp->getLeft());
            temp->setRight(NULL);
            temp->setLeft(NULL);
            free(temp);
        }
        else
        {
            temp->getLeft()->setRight(NULL);
            temp->setLeft(NULL);
            free(temp);
        }
    }
}
template <typename T>
void Matriz<T>::borrarFila(int y)
{
    NodeMatriz<T> *temp = root;
    while (temp->getY() != y)
    {
        temp = temp->getDown();
    }
    if (temp->getRight() == NULL)
    {
        if (temp->getDown() != NULL) //borrando un nodo medio
        {
            temp->getUp()->setDown(temp->getDown());
            temp->getDown()->setUp(temp->getUp());
            temp->setUp(NULL);
            temp->setDown(NULL);
            free(temp);
        }
        else
        {
            temp->getUp()->setDown(NULL);
            temp->setUp(NULL);
            free(temp);
        }
    }
}
