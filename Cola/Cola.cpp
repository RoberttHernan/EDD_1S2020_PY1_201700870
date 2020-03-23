
#include "Cola.h"

using namespace std;

template <typename T>

Cola <T>::Cola (){
    head = NULL;
    tail = NULL;
    size = 0 ;

}
template<typename T>
NodoCola<T>* Cola<T>::getHead(){return this->head;}
template<typename T>
void Cola<T>::SetHead(NodoCola<T>* head){ this->head = head;}
template<typename T>
void Cola<T>::SetTail(NodoCola<T>* tail){ this->tail = tail;}
template<typename T>
NodoCola<T>* Cola<T>::getTail(){return this->tail;}
template<typename T>
int Cola<T>::getSize(){return this-> size;}
template <typename T>
void Cola<T>::setSize(int size){this->size = size;}
template <typename T>
void Cola<T>::Queue(T data){
    NodoCola <T> *newNode = new NodoCola<T> (data);
    if (head == NULL){
        head = newNode;
        tail = newNode;
    }else {
        newNode->setNext(tail);
        tail = newNode;
    }
    size++;
}
template <typename T>
void Cola<T>::Print(){
    NodoCola <T> *temp = tail;
    if(head==NULL){
        cout <<"Lista Vacia"<<endl;
    }else {
        cout<<"Tail->";

        while (temp != NULL){
            temp->print();
            
            if(temp->getNext()==NULL){
                cout <<"<-head";
               
            }
             temp = temp->getNext();
    }
    }
    
}
template <typename T>
bool Cola<T>::buscar(T data){
    NodoCola<T> *temp = head;
    while(temp!=NULL){
        if(temp->getData() == data){
            return true;
        }
        temp = temp->getNext();
    }
    return false;
}
template <typename T>
Cola <T>::~Cola (){

}