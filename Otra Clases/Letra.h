#ifndef LETRA_H_
#define LETRA_H_

class Letra
{
private:
    char letra;
    int puntaje;
public:
    Letra();
    Letra(char, int);
    ~Letra();
    char getLetra();
    int getPuntaje();
    void setLetra(char);
    void setPuntaje( int);
    
};







#endif