#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP
#include "Proceso.hpp"
class NodoLista
{
public:
	NodoLista(Proceso v, NodoLista* sig = NULL);
	~NodoLista();
private:
	Proceso valor;
	NodoLista* siguiente;
    
	friend class Lista;

};
typedef NodoLista* pnodoLista;
#endif // NODOLISTA_HPP
