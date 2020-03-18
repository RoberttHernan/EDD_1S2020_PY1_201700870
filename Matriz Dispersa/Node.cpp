#include "Node.h"

template <typename T>
Node<T>::Node(T data, int x, int y){
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
Node<T>* Node<T>::getRight(){return this->right;} 
template <typename T>
Node<T>* Node<T>::getLeft(){return this->left;}
template <typename T>
Node<T>* Node<T>::getUp(){return this->up;}
template <typename T>
Node<T>* Node<T>::getDown(){return this->down;}
template <typename T>
T Node<T>::getData(){return this->data;}
template <typename T>
int Node<T>::getX(){return this->x;}  
template <typename T>
int Node<T>::getY(){return this->y;}  

//Setters
template <typename T>
void Node<T>::setRight(Node<T>* right){ this->right = right;}
template <typename T>
void Node<T>::setLeft(Node<T>* left){ this->left = left;}
template <typename T>
void Node<T>::setDown(Node<T>* down){ this->down = down;}
template <typename T>
void Node<T>::setUp(Node<T>* up){ this->up = up;}
template <typename T>
void Node<T>::setData(T data){ this->data = data;}
template <typename T>
void Node<T>::setX(int x){ this->x = x;}
template <typename T>
void Node<T>::setY(int y){ this->y = y;}


