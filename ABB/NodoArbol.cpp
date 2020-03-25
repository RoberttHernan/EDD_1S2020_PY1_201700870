#include "NodoArbol.h"

//constructor por defecto


NodoArbol::NodoArbol(){
    right = NULL;
    left =NULL;
    this->player.setUsuario("NULL");
    

}

//constructor por parametro
NodoArbol ::NodoArbol (Jugador *player){
    this->player = *player ;
    right = NULL;
    left = NULL;

}

//eliminar todos los nodos
void NodoArbol::deleteAll(){
    if (right){
        right->deleteAll();
        delete this ;
    }
}
//imprime un nodo
void NodoArbol:: print(){
    std:: cout << player.getUsuario() << "->";

}

void NodoArbol::setRight(NodoArbol * right){
    this->right = right;
}

 NodoArbol *NodoArbol::getRight(){
    return this->right;
}
void NodoArbol::setLeft(NodoArbol * left){
    this->left = left;
}

 NodoArbol *NodoArbol::getLeft(){
    return this->left;
}
void NodoArbol::setData(Jugador *player){
    this->player = *player;
}
Jugador NodoArbol::getPlayer(){
    return this->player;
}


//destructor

NodoArbol::~NodoArbol() {}