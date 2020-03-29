#include "NodeMatriz.h"

template <typename T>
NodeMatriz<T>::NodeMatriz(T data, int x, int y){
    this->right=NULL;
    this->left=NULL;
    this->down=NULL;
    this->up=NULL;
    this->data= data;
    this->x = x;
    this->y = y;
}
//Getters
template <typename T>
NodeMatriz<T>* NodeMatriz<T>::getRight(){return this->right;} 
template <typename T>
NodeMatriz<T>* NodeMatriz<T>::getLeft(){return this->left;}
template <typename T>
NodeMatriz<T>* NodeMatriz<T>::getUp(){return this->up;}
template <typename T>
NodeMatriz<T>* NodeMatriz<T>::getDown(){return this->down;}
template <typename T>
T NodeMatriz<T>::getData(){return this->data;}
template <typename T>
int NodeMatriz<T>::getX(){return this->x;}  
template <typename T>
int NodeMatriz<T>::getY(){return this->y;}  

//Setters
template <typename T>
void NodeMatriz<T>::setRight(NodeMatriz<T>* right){ this->right = right;}
template <typename T>
void NodeMatriz<T>::setLeft(NodeMatriz<T>* left){ this->left = left;}
template <typename T>
void NodeMatriz<T>::setDown(NodeMatriz<T>* down){ this->down = down;}
template <typename T>
void NodeMatriz<T>::setUp(NodeMatriz<T>* up){ this->up = up;}
template <typename T>
void NodeMatriz<T>::setData(T data){ this->data = data;}
template <typename T>
void NodeMatriz<T>::setX(int x){ this->x = x;}
template <typename T>
void NodeMatriz<T>::setY(int y){ this->y = y;}



