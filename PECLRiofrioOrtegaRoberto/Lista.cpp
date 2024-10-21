#include "Lista.hpp"
#include "Gestor.hpp"
Lista::Lista()
{
    primero = NULL;
    longitud = 0;
}

void Lista::insertarIZQ(Proceso v){
    pnodoLista nuevo;
    nuevo = new NodoLista(v);
    
    if(!primero){
        primero = nuevo;
    }else{
        nuevo->siguiente = primero;
        primero = nuevo;
    }
    longitud++;
}

void Lista::insertarDER(Proceso v){
    pnodoLista nuevo,aux;
    nuevo = new NodoLista(v);
    
    if(longitud < 1)
        primero = nuevo;
    else{
        aux = primero;
        while(aux->siguiente != NULL){
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
    longitud++;
}

Proceso Lista::verPrimero(){
    return primero->valor;
}

Proceso Lista::verUltimo(){
    pnodoLista aux;
    aux = primero;
    while(aux->siguiente != NULL){
        aux = aux->siguiente;
    }
    return aux->valor;
}

void Lista::eliminarPrimero(){
    if(longitud < 1)
        return;
    pnodoLista aux = primero;
    primero = primero->siguiente;
    longitud--;
    aux->siguiente = NULL;
    delete aux;
}

void Lista::eliminarUltimo(){
    if(longitud < 1)
        return;
    pnodoLista aux,p;
    aux = primero;
    
    if(aux->siguiente == NULL){
        primero = NULL;
        delete aux;
    }else{
        while(aux->siguiente->siguiente != NULL){
            aux = aux->siguiente;
        }
        p = aux->siguiente;
        aux->siguiente = NULL;
        delete p;
    }
    longitud--;
}

int Lista::getLongitud(){
    return this->longitud;
}

Lista::~Lista()
{
}

