#ifndef COLA_HPP
#define COLA_HPP
#include "NodoCola.hpp"
class Cola
{
public:
    Cola();
    ~Cola();
    
    void insertar(Proceso v);
    void eliminar();
    void mostrar();
    Proceso verPrimero();
	int getLongitud();

private:
    pnodoCola primero, ultimo;
    int longitud;
};

#endif // COLA_HPP