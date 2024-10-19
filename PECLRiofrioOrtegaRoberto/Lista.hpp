#ifndef LISTA_HPP
#define LISTA_HPP
#include "Proceso.hpp"
class Lista
{
public:
	Lista();
	~Lista();
	void listarProcesos(Proceso v);
	int cambiarPrioridadProcesos();
	void buscarProcesos(Proceso v);
	void finalizarProcesos();

private:
	
};

#endif // LISTA_HPP
