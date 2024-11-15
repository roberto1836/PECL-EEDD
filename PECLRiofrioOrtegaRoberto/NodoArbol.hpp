#ifndef NODOARBOL_HPP
#define NODOARBOL_HPP
#include <iostream>
#include "Proceso.hpp"

class NodoArbol
{
public:
	NodoArbol(Proceso valor);
	~NodoArbol();
	
private:
    Proceso valor; 
    NodoArbol* izq;
    NodoArbol* der;

    friend class Arbol;

};
typedef NodoArbol* pnodoAbb;
#endif // NODOARBOL_HPP
