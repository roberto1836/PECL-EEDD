#ifndef ARBOL_HPP
#define ARBOL_HPP
#include "NodoArbol.hpp"
#include <vector>
using namespace std;

class Arbol
{
public:
	Arbol();
	void insertar(Proceso v);
	void pintar();
	void dibujar();
    void inorden(pnodoAbb nodo);
    void mostrarProcesosNormalesInOrden();
    void mostrarProcesosTiempoRealInOrden();
    void mostrarProcesosInOrden();

    void procesoNodoHoja(pnodoAbb nodo);
    void procesosNodoHoja();

	void buscarProcesosPorPrioridadMasBaja(pnodoAbb nodo);
	void buscarProcesosPorPrioridadMasAlta(pnodoAbb nodo);
    
    void buscarProcesosTiempoRealPrioridadMasAlta();
    void buscarProcesosNormalPrioridadMasBaja();

    NodoArbol* borrarProceso(int e, pnodoAbb nodo);
    NodoArbol* borrarNodo(pnodoAbb nodo);
    Proceso maximo(pnodoAbb nodo);
    Proceso borrar(int prio);
	~Arbol();
	int getNumeroProcesos();
    
private:
    Proceso borrado;
	pnodoAbb raiz;
    pnodoAbb insertar(pnodoAbb, Proceso);
    void pintar(pnodoAbb);
    int altura(pnodoAbb);
    void dibujarNodo(vector<string>& output, vector<string>& linkAbove, pnodoAbb nodo, int nivel, int minPos,
                     char linkChar);
    int numeroProcesos;
};

#endif // ARBOL_HPP
