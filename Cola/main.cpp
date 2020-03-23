#include <stdlib.h>
#include <time.h>
#include <iostream>

#include "Cola.cpp"
#include "Letra.cpp"

void llenarColaAleatoria();

Cola<Letra> cola;

int main()
{
    llenarColaAleatoria();
    

    return 0;
}

void llenarColaAleatoria()
{

    Cola<int> *lista_numeros = new Cola<int>();
    int num;
    srand(time(NULL));
    while (cola.getSize() <= 25)
    {
        num = 1 + rand() % (25 - 1);
        if (lista_numeros->buscar(num) == false)
        {
            lista_numeros->Queue(num);
            switch (num)
            {
            case 1:
                cola.Queue(*new Letra('A', 1, 12));
                break;
            case 2:
            cola.Queue(*new Letra('E', 1, 12));
                break;
            case 3:
            cola.Queue(*new Letra('O', 1, 9));
                break;
            case 4:
            cola.Queue(*new Letra('I', 1, 6));
                break;
            case 5:
            cola.Queue(*new Letra('S', 1, 6));
                break;
            case 6:
            cola.Queue(*new Letra('N', 1, 5));
                break;
            case 7:
            cola.Queue(*new Letra('L', 1, 4));
                break;
            case 8:
            cola.Queue(*new Letra('R', 1, 5));
                break;
            case 9:
            cola.Queue(*new Letra('U', 1, 5));
                break;
            case 10:
            cola.Queue(*new Letra('T', 1, 4));
                break;
            case 11:
            cola.Queue(*new Letra('D', 2, 5));
                break;
            case 12:
            cola.Queue(*new Letra('G', 2, 2));
                break;
            case 13:
            cola.Queue(*new Letra('C', 3, 4));
                break;
            case 14:
            cola.Queue(*new Letra('B', 3, 2));
                break;
            case 15:
            cola.Queue(*new Letra('M', 3, 2));
                break;
            case 16:
            cola.Queue(*new Letra('P', 3, 2));
                break;
            case 17:
            cola.Queue(*new Letra('H', 4, 1));
                break;
            case 18:
            cola.Queue(*new Letra('F', 4, 1));
                break;
            case 19:
            cola.Queue(*new Letra('V', 4, 1));
                break;
            case 20:
            cola.Queue(*new Letra('Y', 4, 1));
                break;
            case 21:
            cola.Queue(*new Letra('Q', 5, 1));
                break;
            case 22:
            cola.Queue(*new Letra('J', 8, 1));
                break;
            case 23:
            cola.Queue(*new Letra('\65', 8, 1));
                break;
            case 24:
            cola.Queue(*new Letra('X', 8, 1));
                break;
            case 25:
            cola.Queue(*new Letra('Z', 10, 1));
                break;

            default:
                break;
            }
        }
    }
    NodoCola<Letra> * temp_head = cola.getHead();
    NodoCola<Letra> *temp_tail = cola.getTail();

    while (temp_tail != temp_head){
        cout<<"Letra: "<< temp_tail->getData().getLetra()
            <<" Puntaje= "<< temp_tail->getData().getPuntaje()
            <<" Cantidad= "<<temp_tail->getData().getCantidad();
        temp_tail= temp_tail->getNext();
    }
    

}