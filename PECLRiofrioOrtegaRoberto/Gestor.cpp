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
int Gestor::ProcesosEnListaNormal(){
    return Lnormales.getLongitud();
}
int Gestor::ProcesosEnListaTiempoReal(){
    return LtiempoReal.getLongitud();
}

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
    while(c0.getLongitud() >= 1){
        Proceso p = c0.verPrimero();
        p.setEstado(1);
        Lnormales.insertarIZQ(p);
        c0.eliminar();
    }
    
    while(c1.getLongitud() >= 1){        
        Proceso p = c1.verPrimero();
        p.setEstado(1);
        Lnormales.insertarIZQ(p);
        c1.eliminar();
    }
    
    while(c2.getLongitud() >= 1){
        Proceso p = c2.verPrimero();
        p.setEstado(1);
        LtiempoReal.insertarIZQ(p);
        c2.eliminar();
    }
    
    while(c3.getLongitud() >= 1){
        Proceso p = c3.verPrimero();
        p.setEstado(1);
        LtiempoReal.insertarIZQ(p);
        c3.eliminar();
    }
}

void Gestor::muestraProcesosNormal(){
    Lnormales.mostrar();
}

void Gestor::muestraProcesosTiempoReal(){
    LtiempoReal.mostrar();
}
void Gestor::buscarProcesos(){
    cout << "Normal menor prioridad -> \t\t";
    Lnormales.menorPrioridad().mostrar();
    cout << "Tiempo real mayor prioridad -> \t\t";
    LtiempoReal.mayorPrioridad().mostrar();
}

void Gestor::buscarProcesoPorNombreUsuario(){
    string o;
    cout << "Introduce un nombre de usuario: ";
    cin >> o;
    
    Lnormales.buscarProcesosUsuario(o);
}

void Gestor::eliminarProcesoPorPID(){
    int o;
    cout << "Introduce PID: ";
    cin >> o;
    
    Lnormales.borrarProcesosPID(o);
    LtiempoReal.borrarProcesosPID(o);
}

void Gestor::cambiarPrioridadProcesoPorPID(){
    int o;
    cout << "Introduce PID: ";
    cin >> o;
    
    Proceso *pro = Lnormales.buscarProcesoPID(o);
    int prio;
    cout << "Introduce prio: ";
    cin >> prio;
    pro->setPrioridad(prio);
}

void Gestor::reiniciar(){
    borraProcesosPila();
    borraProcesosColas();
    
    while(Lnormales.getLongitud() > 0){
        Lnormales.eliminarPrimero();
    }
    while(LtiempoReal.getLongitud() > 0){
        LtiempoReal.eliminarPrimero();
    }
}

Gestor::~Gestor()
{
}