#ifndef PROCESO_HPP
#define PROCESO_HPP
#include <iostream>
using namespace std;
class Proceso
{
public:
    Proceso();
    ~Proceso();
    void mostrar();
private:
    bool tipo;
    int PID;
    int nombreUsuario;
    bool estado;
    int prioridad;
};

#endif // PROCESO_HPP
