#include "NodoLista.hpp"

NodoLista::NodoLista(Proceso v, NodoLista* sig){
    valor = v;
    siguiente = sig;
}

NodoLista::~NodoLista(){
    
}

