#include "Cola.cpp"


int main (){
    Cola <int> cola ;

    cola.Queue(5);
    cola.Queue(9);
    cola.Queue(15);
    cola.Print();


    return 0;
}