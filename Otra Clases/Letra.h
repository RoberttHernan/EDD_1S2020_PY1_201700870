#ifndef LETRA_H_
#define LETRA_H_

class Letra
{
private:
    char letra;
    int puntaje;
    int cantidad;
public:
    Letra();
    Letra(char, int, int);
    ~Letra();
    char getLetra();
    int getPuntaje();
    int getCantidad();
    void setLetra(char);
    void setPuntaje( int);
    void setCantidad(int);
};







#endif