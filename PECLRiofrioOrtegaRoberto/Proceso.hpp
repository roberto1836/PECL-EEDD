#ifndef PROCESO_HPP
#define PROCESO_HPP
#include <iostream>
#include <string.h>
using namespace std;
class Proceso
{
public:
    Proceso();
    ~Proceso();
    void mostrar();
    bool getVacio();
    void setVacio(bool v);
    void crearProceso(int pid);
    bool getTipo();
    bool getEstado();
    void setEstado(bool e);
    int getPrioridad();
    void setPrioridad(int p);
<<<<<<< HEAD
	char* getUsuario();

    
=======
    int getPID();
    char* getUsuario();
>>>>>>> 5e2eb4627aac9374f00a0044aa3d4da10606fbd1
private:
    bool tipo;
    int PID;
    char nombreUsuario[7];
    bool estado;
    int prioridad;
    bool vacio;

};

#endif // PROCESO_HPP