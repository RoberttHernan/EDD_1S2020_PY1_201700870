#include "listaEnlazadaDobleCircular.h"

using namespace std ;

//contructor por defecto
template <typename T>

listaEnlazadaDobleCircular <T>::listaEnlazadaDobleCircular(){
    index = 0;
    head = NULL;
    tail = NULL;

}
//Insertar al inicio 
template <typename T>
void listaEnlazadaDobleCircular <T>::AddHead(T data)
{
    NodoDCLL <T> *newNode = new NodoDCLL<T> (data);
    NodoDCLL <T> *temp = head;

    if (head==NULL){
        head = newNode;
        tail = newNode;
        head->setPrev(tail);
        tail->setNext(head);
        
    
       

    }else {
        newNode->setNext(head);
        tail ->setNext(newNode);
        head->setPrev(newNode);
        head = newNode;
        
        
        
        
       

    }
    index++;

}
template <typename T>
void listaEnlazadaDobleCircular<T>::Print()
{
    NodoDCLL<T> *temp = head;
    if (head == NULL)
    {
        cout << "Lista Vacia" << endl;
    }
    else
    {
        do
        {

            temp->print();

            if (temp->getNext() == head)
            {
                temp->getNext()->print();
            }
            temp = temp->getNext();

        } while (temp != head);
    }
    cout << endl
         << endl;
}
template <typename T>
bool listaEnlazadaDobleCircular<T>::buscar(T data)
{
    NodoDCLL<T> *temp = head;
    int contador = 1;
    while (contador <= index)
    {
        if (temp->getData() == data)
        {
            return true;
        }
        temp = temp->getNext();
        contador++;
    }
    return false;
}
template <typename T>
void listaEnlazadaDobleCircular<T>::borrar(T data)
{
    NodoDCLL<T> *temp = head;
    int contador = 1;

    while (temp->getData() != data && contador <= index)
    {
        temp = temp->getNext();
        contador++;
    }
    if (contador > index)
    {
        return;
    }
    else
    {
        if (temp == head)
        {
            if (index != 1)
            {
                head = temp->getNext();
                temp->getNext()->setPrev(tail);
                tail->setNext(temp->getNext());
                temp->setNext(NULL);
                temp->setPrev(NULL);
                free(temp);
                index--;
                return;
            }
            else
            {
               head = NULL;
               tail =NULL;
               index =0;
                return;
            }
        
        }
        else if (temp == tail){
            tail = temp->getPrev();
            tail->setNext(head);
            head->setPrev(tail);
            temp->setNext(NULL);
            temp->setPrev(NULL);
            free(temp);
            index--;
            return;
        }
        else{
            temp->getPrev()->setNext(temp->getNext());
            temp->getNext()->setPrev(temp->getPrev());
            temp->setNext(NULL);
            temp->setPrev(NULL);
            free(temp);
            index--;
            return;
        }
    }
}
template <typename T>
void listaEnlazadaDobleCircular<T>::borrarNodo(NodoDCLL<T> *temp)
{

    if (temp == NULL)
    {
        return;
    }
    else{
         if (temp == head)
        {
            if (index != 1)
            {
                head = temp->getNext();
                temp->getNext()->setPrev(tail);
                tail->setNext(temp->getNext());
                temp->setNext(NULL);
                temp->setPrev(NULL);
                free(temp);
                index--;
                return;
            }
            else
            {
                head = NULL;
                tail = NULL;
                index = 0;
                return;
            }
        }
        else if (temp == tail)
        {
            tail = temp->getPrev();
            tail->setNext(head);
            head->setPrev(tail);
            temp->setNext(NULL);
            temp->setPrev(NULL);
            free(temp);
            index--;
            return;
        }
        else
        {
            temp->getPrev()->setNext(temp->getNext());
            temp->getNext()->setPrev(temp->getPrev());
            temp->setNext(NULL);
            temp->setPrev(NULL);
            free(temp);
            index--;
            return;
        }
    }
        
}
template <typename T>
void listaEnlazadaDobleCircular<T>::borrarLista(){
    NodoDCLL<T> *temp = head;

    while (index>0){
        borrarNodo(temp);
        temp = head;
    }


}
template <typename T>
listaEnlazadaDobleCircular <T>::~listaEnlazadaDobleCircular (){}
template <typename T>
int listaEnlazadaDobleCircular<T>::getIndex(){return this->index;}
template <typename T>
NodoDCLL<T> * listaEnlazadaDobleCircular<T>::getHead(){return this->head;}
template <typename T>
NodoDCLL<T> * listaEnlazadaDobleCircular<T>::getTail(){return this->tail;}
template <typename T>
void listaEnlazadaDobleCircular<T>::setIndex(int index){
    this->index = index;
}
template <typename T>
void listaEnlazadaDobleCircular<T>::setHead(NodoDCLL<T> *head){
    this->head = head;
}



