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
    if(primero){
        if(primero->valor.getPrioridad() > nuevo->valor.getPrioridad()){
            nuevo->siguiente = primero;
            primero = nuevo;
        }else{
            pnodoCola aux = primero;
            while(aux->siguiente && (aux->siguiente->valor.getPrioridad() < nuevo->valor.getPrioridad())){
                    aux = aux->siguiente;
            }
            
            if(aux->siguiente){
                nuevo->siguiente = aux->siguiente;
                aux->siguiente = nuevo;
            }else{
                ultimo->siguiente = nuevo;
                ultimo = nuevo;
            }
        }
    }else{
        ultimo = nuevo;
        primero = nuevo;
    }
    
    longitud++;
}

void Cola::mostrar(){
    pnodoCola aux = primero;
    cout << "\El contenido de la cola es: \n";
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
