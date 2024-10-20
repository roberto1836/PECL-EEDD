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
    

private:
	int longitud;
    pnodoLista primero;
};

#endif // LISTA_HPP
