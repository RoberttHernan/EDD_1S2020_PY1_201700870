#include "ABB.h"

using namespace std ;

template <typename T>

ABB<T>::ABB(){

    this->root = NULL;
    this->actual = NULL;
    this->contador =0;
    this->altura=0;
    
}

template<typename T>
NodoArbol <T> *ABB<T>::getRoot(){
    return this->root;
}


template <typename T >
    void ABB<T>::Add(T data){
        NodoArbol<T> *padre = NULL;
        actual= root;
        //buscando el dato en el arbol manteniendo el puntero al nodo padre
        while (!IsEmpty(actual) && data !=actual->getData()){
            padre = actual;
            if(data > actual->getData()){
                actual= actual->getRight();
            }
            else if(data< actual->getData()){
                actual=actual->getLeft();
            }

        }
        //si se ha encontrado un elemento retorna sin insertar 
       if(!IsEmpty(actual)){return ;}
       //si el padre es null el arbol estaba vacio,
       if(IsEmpty(root)){
           root = new NodoArbol<T> (data); 
           }
       else if(data<padre->getData()){
           padre->setLeft(new NodoArbol<T>(data));
           
       }
       else if(data>padre->getData()){
           padre->setRight(new NodoArbol <T>(data));
          
       }

    }
//Recorridos
template<typename T>
void ABB<T>::Preorden(NodoArbol<T> *nodo){
    if(nodo!=NULL){
        cout <<nodo->getData()<<" ";
        Preorden(nodo->getLeft());
        Preorden(nodo->getRight());
    }
    
}
template <typename T>
void ABB<T>::InOrden(NodoArbol<T> * nodo){
        if(nodo!=NULL){
            InOrden(nodo->getLeft());
            cout<<nodo->getData()<<" ";
            InOrden(nodo->getRight());
        }       
        
}
template <typename T>
void ABB<T>::PostOrden(NodoArbol <T> * nodo){
    if(!IsEmpty(nodo)){
        PostOrden(nodo->getLeft());
        PostOrden(nodo->getRight());
        cout<<nodo->getData()<<" ";

    }
}
/*template<typename T>
void ABB<T>::Podar(Nodo <T>* &node){
        if(node){
            Podar(node->getLeft());
            Podar(node->getRight());
            delete node ;
            node = NULL;
        }
}*/
template <typename T>
bool ABB<T>::IsEmpty(NodoArbol <T>* r){
return r == NULL;
}
template <typename T>
ABB<T>::~ABB(){
    //Podar(root);
}

