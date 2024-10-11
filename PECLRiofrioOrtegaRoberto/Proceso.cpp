#include "Proceso.hpp"

<<<<<<< HEAD
Proceso::Proceso() { prioridad = 1; }
=======
Proceso::Proceso()
{
    
}

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
>>>>>>> 03433581995fb52b8a8d518d883eb4dd9578bd15

void Proceso::mostrar() { cout << prioridad << endl; }
Proceso::~Proceso() {
}