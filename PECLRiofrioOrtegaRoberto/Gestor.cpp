#include "Gestor.hpp"

Gestor::Gestor(){
//	Lista l;
//	Arbol a;
}

int Gestor::ProcesosEnPila(){
	return p.getLongitud();
}
int Gestor::ProcesosEnGPU0(){
	return c0.getLongitud();
}
int Gestor::ProcesosEnGPU1(){
	return c1.getLongitud();
}
int Gestor::ProcesosEnGPU2(){
	return c2.getLongitud();
}
int Gestor::ProcesosEnGPU3(){
	return c3.getLongitud();
}
//Gestor::ProcesosEnListasTiempoReal(Lista l){}
//Gestor::ProcesosEnListaNormal(Lista l){}
//Gestor::ProcesosEnArbol(){}

void Gestor::genera12Procesos(){
	if (p.getLongitud() < 48){
		for(int i=0; i < 12; i++){
            Proceso v;
			v.crearProceso(pid);
			p.insertar(v);
			pid++;
		}
	}
}
void Gestor::muestraProcesos(){
	p.mostrar();
}
void Gestor::borraProcesosPila(){
	while(p.getLongitud() >= 1){
        p.extraer();
    }
}
void Gestor::CasoD(){
	while(p.getLongitud() >= 1){
        if(!p.cima().getTipo()){
            if(c0.getLongitud() < c1.getLongitud()){
                c0.insertar(p.cima());
                p.extraer();
            }else{
                c1.insertar(p.cima());
                p.extraer();
            }
        }else{
            if(c2.getLongitud() < c3.getLongitud()){
                c2.insertar(p.cima());
                p.extraer();
            }else{
                c3.insertar(p.cima());
                p.extraer();
            }
        }
    }
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

