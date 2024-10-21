#ifndef LISTA_HPP
#define LISTA_HPP
#include "NodoLista.hpp"
class Lista
{
public:
	Lista();
	~Lista();
	void listarProcesos(Proceso v);
	int cambiarPrioridadProcesos();
	void buscarProcesos(Proceso v);
	void finalizarProcesos();
    
    void insertarIZQ(Proceso v);
    void insertarDER(Proceso v);
    void eliminarPrimero();
    void eliminarUltimo();
    
    Proceso verPrimero();
    Proceso verUltimo();
    
    void mostrar();
    
    int getLongitud();
    
    Proceso menorPrioridad();
    Proceso mayorPrioridad();
    
    void buscarProcesosUsuario(string user);
    
    void borrarProcesosPID(int pid);
    
    Proceso *buscarProcesoPID(int pid);
private:
	int longitud;
    pnodoLista primero;
};

#endif // LISTA_HPP
