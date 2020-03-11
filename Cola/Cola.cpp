
#include "Cola.h"

using namespace std;

template <typename T>

Cola <T>::Cola (){
    head = NULL;
    tail = NULL;
    size = 0 ;

}
template <typename T>
void Cola<T>::Queue(T data){
    Nodo <T> *newNode = new Nodo<T> (data);
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
    Nodo <T> *temp = tail;
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
Cola <T>::~Cola (){

}