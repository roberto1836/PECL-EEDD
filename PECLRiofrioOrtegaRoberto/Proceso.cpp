#include "Proceso.hpp"

Proceso::Proceso()
{
    prioridad = 1;
}

void Proceso::mostrar(){
    cout << prioridad << endl;
}

Proceso::~Proceso()
{
}

