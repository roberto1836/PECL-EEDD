#include "Proceso.hpp"


Proceso::Proceso() {
        
}


void Proceso::crearProceso(int pid){
    this->PID = pid;
    int num = rand() % 10;
    strcpy(nombreUsuario, "user");
    this->nombreUsuario[4] = ('0' + num);
    this->tipo = (rand() % 2);
}

void Proceso::setVacio(bool v){
    this->vacio = v;
}

bool Proceso::getVacio(){
    return this->vacio;
}

void Proceso::mostrar(){
    string Tipo;
    if(!tipo){
        Tipo = "normal";
    }else{
        Tipo = "tiempo real";
    }
    
    cout << "\tEl proceso cuyo PID es "<< PID << " es de tipo " << Tipo;
    
    
    if(true){
        string e = "parado";
        if(estado){
            e = "ejecucion";
        }
        cout << ", su estado es " << e << " y su prioridad es: " << prioridad;
    }
    cout << endl;
}

bool Proceso::getTipo(){
    return this->tipo;
}

bool Proceso::getEstado(){
    return this->estado;
}

void Proceso::setEstado(bool e){
    this->estado = e;
}

int Proceso::getPrioridad(){
    return this->prioridad;
}

void Proceso::setPrioridad(int p){
    this->prioridad = p;
}

void Proceso::mostrarFila(){
    cout << PID << "\t" << nombreUsuario <<"\t" << tipo << "\t" << estado << "\t" << prioridad << endl;
}

char* Proceso::getUsuario(){
    return this->nombreUsuario;
}

int Proceso::getPID(){
    return this->PID;
}

Proceso::~Proceso()
{
}