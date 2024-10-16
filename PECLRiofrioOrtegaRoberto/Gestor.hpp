#ifndef GESTOR_HPP
#define GESTOR_HPP
#include "Pila.hpp"
#include "Cola.hpp"
#include "Proceso.hpp"
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
//	int ProcesosEnListaTiempoReal(Lista l);
//	int ProcesosEnListaNormal(Lista l);
//	int ProcesosEnArbol(Arbol a);
	void genera12Procesos();
	void muestraProcesos();
	void borraProcesosPila();
	void encolarProcesos();
	void muestraProcesosGPUs0y1();
	void muestraProcesosGPUs2y3();
	void borraProcesosColas();
	void CasoH();
	void CasoI();
	void CasoJ();
	void CasoK();
	void CasoL();
	void CasoM();
	void CasoN();
	void CasoO();
    
    
private:
	Pila p;
	Cola c0;
	Cola c1;
	Cola c2;
	Cola c3;
	Cola prioridad;
    int pid = 300;
//	Lista l;
//	Arbol a;

};

#endif // GESTOR_HPP
