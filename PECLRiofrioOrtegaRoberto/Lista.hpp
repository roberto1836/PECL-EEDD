 #ifndef LISTA_HPP
#define LISTA_HPP
#include "NodoLista.hpp"

class Lista
{
public:
	Lista();
	~Lista();
    
    void insertarIZQ(Proceso v);
    void insertarDER(Proceso v);
    void eliminarPrimero();
    void eliminarUltimo();
    
    Proceso verPrimero();
    Proceso verUltimo();
    
    void mostrar();
    
    Proceso menorPrioridad();
    Proceso mayorPrioridad();
    
    void buscarProcesosUsuario(string user);
    
    Proceso borrarProcesosPID(int pid);
    int getLongitud();
    Proceso *buscarProcesoPID(int pid);
private:
	int longitud;
    pnodoLista primero;
};

#endif // LISTA_HPP
