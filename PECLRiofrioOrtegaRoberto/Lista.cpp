#include "Lista.hpp"

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

void Lista::mostrar(){
    cout << "PID\tUsuario\tTipo\tEstado\tPrioridad" << endl; 
    if(longitud < 1)
        return;
    pnodoLista aux = primero;
    aux->valor.mostrarFila();
    while(aux->siguiente != NULL){
        aux->siguiente->valor.mostrarFila();
        aux = aux->siguiente;
    }
}

int Lista::getLongitud(){
    return longitud;
}

Proceso Lista::menorPrioridad(){
    if(longitud < 1){
        Proceso p;
        p.setVacio(1);
        return p;
    }
    pnodoLista aux = primero;
    pnodoLista minimo = primero;
    
    while(aux->siguiente != NULL){
        if(aux->siguiente->valor.getPrioridad() > minimo->valor.getPrioridad())
            minimo = aux->siguiente;
        aux = aux->siguiente;
    }
    return minimo->valor;
}

Proceso Lista::mayorPrioridad(){
    if(longitud < 1){
        Proceso p;
        p.setVacio(1);
        return p;
    }
    pnodoLista aux = primero;
    pnodoLista minimo = primero;
    
    while(aux->siguiente != NULL){
        if(aux->siguiente->valor.getPrioridad() < minimo->valor.getPrioridad())
            minimo = aux->siguiente;
        aux = aux->siguiente;
    }
    return minimo->valor;
}

void Lista::buscarProcesosUsuario(string user){
    if(longitud < 1)
        return;
    pnodoLista aux = primero;
    while(aux->siguiente != NULL){
        if(aux->valor.getUsuario() == user){
            cout << "PID\tUsuario\tTipo\tEstado\tPrioridad" << endl;
            aux->valor.mostrarFila();
        }
        aux = aux->siguiente;
    }
}

void Lista::borrarProcesosPID(int pid){
    if(longitud < 1)
        return;
    pnodoLista aux = primero;
    if(primero->valor.getPID() == pid){
        eliminarPrimero();
        return;
    }else if(verUltimo().getPID() == pid){
        eliminarUltimo();
        return;
    }else{
        while(aux->siguiente != NULL){
            if(aux->siguiente->valor.getPID() == pid){
                pnodoLista p = aux->siguiente;
                aux->siguiente = p->siguiente;
                p->siguiente = NULL;
                delete p;
                longitud--;
            }
            aux = aux->siguiente;
        }
    }
}

Proceso *Lista::buscarProcesoPID(int pid){
    if(longitud < 1){
        Proceso va;
        va.setVacio(1);
        return &va;
    }
    pnodoLista aux = primero;
    while(aux->siguiente != NULL){
        if(aux->valor.getPID() == pid){
            cout << "PID\tUsuario\tTipo\tEstado\tPrioridad" << endl;
            aux->valor.mostrarFila();
            return &aux->valor;
        }
        aux = aux->siguiente;
    }
}

Lista::~Lista()
{
}

