#ifndef GESTOR_HPP
#define GESTOR_HPP
#include "Pila.hpp"
#include "Cola.hpp"
class Gestor
{
public:
    Gestor();
    ~Gestor();
	int ProcesosEnPila(Pila p);
	int ProcesosEnGPU0(Cola c);
	int ProcesosEnGPU1(Cola c);
	int ProcesosEnGPU2(Cola c);
	int ProcesosEnGPU3(Cola c);
//	int ProcesosEnListaTiempoReal(Lista l);
//	int ProcesosEnListaNormal(Lista l);
//	int ProcesosEnArbol(Arbol a);
	void CasoA();
	void CasoB();
	void CasoC();
	void CasoD();
	void CasoE();
	void CasoF();
	void CasoG();
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
//	Lista l;
//	Arbol a;
};

#endif // GESTOR_HPP
