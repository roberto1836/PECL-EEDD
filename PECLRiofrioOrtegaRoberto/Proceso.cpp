#include "Proceso.hpp"


Proceso::Proceso() { prioridad = 1; }


void Proceso::crearProceso(int pid){
    this->prioridad = pid;
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
    cout << "El proceso cuyo PID es "<< PID << "es de tipo " << tipo << endl;
}

Proceso::~Proceso()
{
}
