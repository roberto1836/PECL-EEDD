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
	void buscarProcesosPorPrioridad(pnodoAbb nodo);
	void buscarProcesosPorPrioridadMasBaja();
	void buscarProcesosPorPrioridadMasAlta();
	~Arbol();
	
private:
	pnodoAbb raiz;
    pnodoAbb insertar(pnodoAbb, Proceso);
    void pintar(pnodoAbb);
    int altura(pnodoAbb);
    void dibujarNodo(vector<string>& output, vector<string>& linkAbove, pnodoAbb nodo, int nivel, int minPos,
                     char linkChar);

};

#endif // ARBOL_HPP
