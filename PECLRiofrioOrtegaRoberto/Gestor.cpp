#include "Gestor.hpp"

Gestor::Gestor(){
	Pila p;
	Proceso v;
	Cola c0;
	Cola c1;
	Cola c2;
	Cola c3;
//	Lista l;
//	Arbol a;
}

Gestor::ProcesosEnPila(Pila p){
	return p.getLongitud();
}
Gestor::ProcesosEnGPU0(Cola c0){

}
Gestor::ProcesosEnGPU1(Cola c1){

}
Gestor::ProcesosEnGPU2(Cola c2){

}
Gestor::ProcesosEnGPU3(Cola c3){

}
//Gestor::ProcesosEnListasTiempoReal(Lista l){}
//Gestor::ProcesosEnListaNormal(Lista l){}
//Gestor::ProcesosEnArbol(){}
void Gestor::CasoA(){
	int pid = 300;
	if (p.getLongitud() <= 48){
		for(int i=0; i = 12; i++){
			v.crearProceso(pid);
			p.insertar(v);
			pid++;
		}
	}
	p.mostrar();
}
void Gestor::CasoB(){
	p.mostrar();
}
void Gestor::CasoC(){
	while(p.getLongitud() == 0)
		p.extraer();
}
void Gestor::CasoD(){
	
}
void Gestor::CasoE(){
	c0.mostrar();
	c1.mostrar();
}
void Gestor::CasoF(){
	c2.mostrar();
	c3.mostrar();
}
void Gestor::CasoG(){
	while(c0.getLongitud() == 0 & c1.getLongitud() == 0 & c2.getLongitud() == 0 & c3.getLongitud() == 0){
		c0.eliminar();
		c1.eliminar();
		c2.eliminar();
		c3.eliminar();
		
	}
}
Gestor::~Gestor()
{
}

