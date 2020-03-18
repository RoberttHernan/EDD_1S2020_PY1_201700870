#ifndef CASILLAS_H_
#define CASILLAS_H_
#include <string>

using namespace std;
class Casillas
{
private:
    string tipo;
    int x;
    int y;
public:
    Casillas();
    Casillas(string tipo, int x, int y);
    ~Casillas();
    string getTipo();
    void   setTipo(string tipo);
    int get_x();
    void set_x(int x);
    int get_y();
    void set_y(int y);
    
};






#endif