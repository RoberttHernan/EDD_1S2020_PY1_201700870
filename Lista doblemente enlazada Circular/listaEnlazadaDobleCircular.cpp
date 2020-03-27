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
void listaEnlazadaDobleCircular  <T> ::Print(){
    NodoDCLL <T> *temp = head;
    if(head==NULL){
        cout <<"Lista Vacia"<<endl;
    }
    else {
        cout <<"head";
        do
        {
            
            temp->print();
            
            if(temp->getNext()==head){
                cout <<"tail";
               
            }
             temp = temp->getNext();
             
        } while (temp!=head);
        
    }
    cout << endl << endl;
}
template <typename T>
listaEnlazadaDobleCircular <T>::~listaEnlazadaDobleCircular (){}
template <typename T>
int listaEnlazadaDobleCircular<T>::getIndex(){return this->index;}
template <typename T>
NodoDCLL<T> * listaEnlazadaDobleCircular<T>::getHead(){return this->head;}




