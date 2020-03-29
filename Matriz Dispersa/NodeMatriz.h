#ifndef NODOMATRIZ_H_
#define NODOMATRIZ_H_
#include <iostream>

template <class T>
class NodeMatriz
{
private:
    NodeMatriz<T> *right;
    NodeMatriz<T> *left;
    NodeMatriz<T> *up;
    NodeMatriz<T> *down;
    T data;
    int x;
    int y;

public:
    NodeMatriz(T data, int x, int y);
   
    ~NodeMatriz();
    //Getters
    NodeMatriz<T>*getRight();
    NodeMatriz<T>*getLeft();
    NodeMatriz<T>*getDown();
    NodeMatriz<T>*getUp();
    T getData();
    int getX();
    int getY();

    //Setters
    void setRight (NodeMatriz<T>* right);
    void setLeft (NodeMatriz<T>* left);
    void setDown (NodeMatriz<T>* down);
    void setUp (NodeMatriz<T>* up);
    void setData(T);
    void setX(int x);
    void setY(int y);


};

#endif
