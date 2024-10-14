#include "Proceso.hpp"


Proceso::Proceso() { PID = 1; }


void Proceso::crearProceso(int pid){
    this->PID = pid;
    int num = rand() % 10;
    this->nombreUsuario = "user" + (0 + num);
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
    cout << "\tEl proceso cuyo PID es "<< PID << " es de tipo " << Tipo << endl;
}

bool Proceso::getTipo(){
    return tipo;
}

Proceso::~Proceso()
{
}
