#include "Cola.hpp"

Cola::Cola()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}

void Cola::insertar(Proceso v){
    pnodoCola nuevo;
    nuevo = new NodoCola(v);
    if(ultimo)
        ultimo->siguiente = nuevo;
    ultimo = nuevo;
    
    if(!primero)
        primero = nuevo;
    longitud++;
}

void Cola::mostrar(){
    pnodoCola aux = primero;
    cout << "\El contenido de la cola es: ";
    while(aux){
        aux->valor.mostrar();
        aux = aux->siguiente;
    }
    cout << endl;
}

void Cola::eliminar()
{
    pnodoCola nodo;
    nodo = primero;
    if(!nodo)
        return ;
    primero = nodo->siguiente;
    delete nodo;
    if(!primero)
        ultimo = NULL;
    longitud--;
}

Proceso Cola::verPrimero(){
    return primero->valor;
}

int Cola::getLongitud(){
    return this->longitud;
}

Cola::~Cola()
{
    while(primero)
        eliminar();
}
