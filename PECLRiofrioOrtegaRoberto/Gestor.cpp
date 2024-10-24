#include "Gestor.hpp"


Gestor::Gestor(){
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
int Gestor::ProcesosEnListasTiempoReal(){
	return ln.getLongitud();
}
int Gestor::ProcesosEnListaNormal(){
	return lt.getLongitud();
}

//Gestor::ProcesosEnArbol(Arbol a){}

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

void Gestor::encolarProcesos(){

	while(p.getLongitud() >= 1){
        
        
        Proceso procesoAux = p.cima();
		int prioridad;
        procesoAux.setEstado(1);
        
        if(procesoAux.getTipo()){
            prioridad = rand() % 100;
        }else{
            prioridad = rand() % 39 - 19; 
            prioridad = prioridad + 120;
        }
        
        procesoAux.setPrioridad(prioridad);

        if(!procesoAux.getTipo()){
            if(c0.getLongitud() < c1.getLongitud()){
                c0.insertar(procesoAux);
                p.extraer();
            }else{
                c1.insertar(procesoAux);
                p.extraer();
            }
        }else{
            if(c2.getLongitud() < c3.getLongitud()){
                c2.insertar(procesoAux);
                p.extraer();
            }else{
                c3.insertar(procesoAux);
                p.extraer();
            }
        }
    }
}

void Gestor::muestraProcesosGPUs0y1(){
	c0.mostrar();
	c1.mostrar();
}

void Gestor::muestraProcesosGPUs2y3(){
	c2.mostrar();
	c3.mostrar();
}

void Gestor::borraProcesosColas(){
	while(c0.getLongitud() >= 1){
        c0.eliminar();
    }
    while(c1.getLongitud() >= 1){
        c1.eliminar();
    }
    while(c2.getLongitud() >= 1){
        c2.eliminar();
    }
    while(c3.getLongitud() >= 1){
        c3.eliminar();
    }
}

void Gestor::enlistarProcesos(){
	
	while(c0.getLongitud() >=1){
		Proceso aux = c0.verPrimero();
		aux.setEstado(0);
		if(!primero){
			ln.insertarIZQ(aux);
			c0.eliminar();
		}else{
			ln.insertarDER(aux);
			c0.eliminar();
		}
	}
	
	while(c1.getLongitud() >=1){
		Proceso aux = c0.verPrimero();
		aux.setEstado(0);
		if(!primero){
			ln.insertarIZQ(aux);
			c1.eliminar();
		}else{
			ln.insertarDER(aux);
			c1.eliminar();
		}
	}
	
	while(c2.getLongitud() >=1){
		Proceso aux = c0.verPrimero();
		aux.setEstado(0);
		if(!primero){
			lt.insertarIZQ(aux);
			c2.eliminar();
		}else{
			lt.insertarDER(aux);
			c2.eliminar();
		}
	}
	
	while(c3.getLongitud() >=1){
		Proceso aux = c0.verPrimero();
		aux.setEstado(0);
		if(!primero){
			lt.insertarIZQ(aux);
			c3.eliminar();
		}else{
			lt.insertarDER(aux);
			c3.eliminar();
		}
	}
}

void Gestor::muestraProcesosNormal(){
	ln.muestraProcesos();
}

void Gestor::muestraProcesosTiempoReal(){
	lt.muestraProcesos();
}
void Gestor::buscarProcesos(){
	ln.buscarProcesos();
	lt.buscarProcesos();
}

//void Gestor::buscarProcesoPorNombreUsuario(){}


void Gestor::eliminarProcesoPorPID(){
	Proceso v = ln.finalizarProcesos();
	p.insertar(v);
	Proceso v2 = lt.finalizarProcesos();
	p.insertar(v2);
}

void Gestor::cambiarPrioridadProcesoPorPID(){
	ln.cambiarPrioridadProcesos();
	lt.cambiarPrioridadProcesos();
}

void Gestor::reiniciar(){
	borraProcesosPila();
	borraProcesosColas();
	
	while(ln.getLongitud() >= 1){
		ln.eliminarUltimo();
		if(ln.getLongitud() == 1)
			ln.eliminarPrimero();
	}
	
	while(lt.getLongitud() >= 1){
		lt.eliminarUltimo();
		if(lt.getLongitud() == 1)
			lt.eliminarPrimero();
	}
}

Gestor::~Gestor()
{
}