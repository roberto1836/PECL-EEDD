#ifndef GESTOR_HPP
#define GESTOR_HPP
#include "Pila.hpp"
#include "Cola.hpp"
#include "Proceso.hpp"
#include "Lista.hpp"

class Gestor
{

public:
    Gestor();
    ~Gestor();

	int ProcesosEnPila();
	int ProcesosEnGPU0();
	int ProcesosEnGPU1();
	int ProcesosEnGPU2();
	int ProcesosEnGPU3();
	int ProcesosEnListasTiempoReal();
	int ProcesosEnListaNormal();
//	int ProcesosEnArbol(Arbol a);
	void genera12Procesos();
	void muestraProcesos();
	void borraProcesosPila();
	void encolarProcesos();
	void muestraProcesosGPUs0y1();
	void muestraProcesosGPUs2y3();
	void borraProcesosColas();
	void enlistarProcesos();
	void muestraProcesosNormal();
	void muestraProcesosTiempoReal();
	void buscarProcesos();
	void buscarProcesoPorNombreUsuario();
	void eliminarProcesoPorPID();
	void cambiarPrioridadProcesoPorPID();
	void reiniciar();
    
    
private:
	Pila p;
	Cola c0;
	Cola c1;
	Cola c2;
	Cola c3;
	Cola prioridad;
    int pid = 300;
	Lista ln;
	Lista lt;
//	Arbol a;

};

#endif // GESTOR_HPP
