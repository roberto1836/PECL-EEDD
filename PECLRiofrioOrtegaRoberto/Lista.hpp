 #ifndef LISTA_HPP
#define LISTA_HPP
#include "NodoLista.hpp"

class Lista
{
public:
	Lista();
	~Lista();
	void listarProceso(Proceso v);
	int cambiarPrioridadProcesos();
	void buscarProcesos();
	Proceso finalizarProcesos();
	void muestraProcesos();
	
    
    void insertarIZQ(Proceso v);
    void insertarDER(Proceso v);
    void eliminarPrimero();
    void eliminarUltimo();
	int getLongitud();
    
    Proceso verPrimero();
    Proceso verUltimo();
    

private:
	int longitud;
    pnodoLista primero;
};

#endif // LISTA_HPP
