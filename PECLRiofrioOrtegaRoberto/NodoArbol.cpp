#include "NodoArbol.hpp"


NodoArbol::NodoArbol(Proceso valor)
{
	this->valor = valor;
	this->izq = nullptr;
    this->der = nullptr;
}

NodoArbol::~NodoArbol()
{
}

