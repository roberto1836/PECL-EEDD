#ifndef NODOCOLA_HPP
#define NODOCOLA_HPP
#include "Proceso.hpp"
class NodoCola
{
public:
    NodoCola(Proceso v, NodoCola* sig = NULL);
    ~NodoCola();
private:
    Proceso valor;
    NodoCola* siguiente;
    
    friend class Cola;
};
typedef NodoCola* pnodoCola;
#endif // NODOCOLA_HPP