#ifndef NODO_H_
#define NODO_H_
#include <iostream>

template <class T>
class Node
{
private:
    Node<T> *right;
    Node<T> *left;
    Node<T> *up;
    Node<T> *down;
    T data;
    int x;
    int y;

public:
    Node(T data, int x, int y);
   
    ~Node();
    //Getters
    Node<T>*getRight();
    Node<T>*getLeft();
    Node<T>*getDown();
    Node<T>*getUp();
    T getData();
    int getX();
    int getY();

    //Setters
    void setRight (Node<T>* right);
    void setLeft (Node<T>* left);
    void setDown (Node<T>* down);
    void setUp (Node<T>* up);
    void setData(T);
    void setX(int x);
    void setY(int y);


};

#endif
