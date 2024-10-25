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

int Lista::getLongitud(){
    return this->longitud;
}

void Lista::muestraProcesos(){
	pnodoLista aux;
	aux = primero;
	cout << "PID " << "Nombre de usuario " << "Tipo de proceso " << "Estado de proceso " << "Prioridad" << endl;
	for (int i = 0; i < getLongitud(); i++){
		cout << aux->valor.getPID() << aux->valor.getNombreUsuario() << aux->valor.getTipo() << aux->valor.getEstado() << aux-> valor.getPrioridad();
		aux = aux->siguiente;
	}
}

void Lista::buscarProcesos(){
	int minimo = 0;
	int maximo = 0;
	pnodoLista aux;
	aux = primero;
	for(int i = 0; i < getLongitud(); i++){
		if(primero->valor.getPrioridad() >= aux->valor.getPrioridad()){
			aux = aux -> siguiente;
			maximo = primero-> valor.getPrioridad();
		}else{
			minimo = aux -> valor.getPrioridad();
		}
	}
	cout << "El proceso normal con menor prioridad es " << minimo;
	cout << "El proceso en tiempo real con mayor prioridad es " << maximo;
}

Proceso Lista::finalizarProcesos(){
	int num_prioridad;
	cout << "Que numero de prioridad quiere eliminar";
	cin >> num_prioridad;
	for (int i = 0; i < getLongitud(); i++){
		if(primero -> valor.getPID() == num_prioridad){
			cout << "El proceso existe";
			eliminarPrimero();
			primero->valor.setEstado(1);
		}else{
			primero = primero->siguiente;
		}
	return primero->valor;
	}
}

int Lista::cambiarPrioridadProcesos(){
	int num_PID;
	int nueva_prioridad;
	cout << "Que numero de prioridad quiere eliminar"; 
	cin >> num_PID;
	for (int i = 0; i < getLongitud(); i++){
		if(primero -> valor.getPID() != num_PID){
			primero = primero -> siguiente;
		}else{
			cout << "El proceso existe, inserte la nueva prioridad ";
			cin >> nueva_prioridad;
			primero -> valor.setPrioridad(nueva_prioridad);
		}
	}
	return primero -> valor.getPrioridad();
}



Lista::~Lista()
{
}

