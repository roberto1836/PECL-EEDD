#include "Gestor.hpp"
#include <algorithm>

Gestor::Gestor(){
	p = Pila();
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

int Gestor::ProcesosEnArbol(){return a.getNumeroProcesos();}

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
    int numeroTiempoReal = 100;
    int numeroNormal = 39;
    int numTR[numeroTiempoReal];
    int numN[numeroNormal];
        
    for (int i = 0; i < numeroNormal; ++i) {
        numN[i] = i - 19;
    }
    
    random_shuffle(numN, numN + numeroNormal);
        
    for (int i = 0; i < numeroTiempoReal; ++i) {
        numTR[i] = i;
    }
	
    random_shuffle(numTR, numTR + numeroTiempoReal);
    
    while(p.getLongitud() >= 1){
        Proceso procesoAux = p.cima();
		int prioridad;
        procesoAux.setEstado(0);
        
        if(procesoAux.getTipo()){
            prioridad = numTR[100 - numeroTiempoReal];
            numeroTiempoReal--;
        }else{
            prioridad = numN[39 - numeroNormal]; 
            prioridad = prioridad + 120;
            numeroNormal--;
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
    cout << "\tGPU0: \n";
	c0.mostrar();
    cout << "\tGPU1: \n";
	c1.mostrar();
}

void Gestor::muestraProcesosGPUs2y3(){
    cout << "\tGPU2: \n";
	c2.mostrar();
    cout << "\tGPU3: \n";
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
    cout << "\tPID\tUsuario\tTipo\tEstado\t\tPrioridad" << endl;
    Lnormales.mostrar();
}

void Gestor::muestraProcesosTiempoReal(){
    cout << "\tPID\tUsuario\tTipo\tEstado\t\tPrioridad" << endl;
    LtiempoReal.mostrar();
}
void Gestor::buscarProcesos(){
    Proceso pro = Lnormales.menorPrioridad();
    
    string estado = "parado";
    if(pro.getEstado())
        estado = "ejecucion";
    string tipo = "normal";
    if(pro.getTipo())
        tipo = "tiempo real";
    if(!pro.getVacio()){
        cout << "\tNormal menor prioridad -> \t\t";
        cout << "\tEl proceso cuyo PID es "<< pro.getPID() << " es de tipo " << tipo
        << ", su estado es " << estado << " y su prioridad es: " << pro.getPrioridad() << endl;
    }
    
    
    pro = LtiempoReal.mayorPrioridad();
    
    estado = "parado";
    if(pro.getEstado())
        estado = "ejecucion";
        
    tipo = "normal";
    if(pro.getTipo())
        tipo = "tiempo real";
    if(!pro.getVacio()){
        cout << "\tTiempo real mayor prioridad -> \t\t";
        cout << "\tEl proceso cuyo PID es "<< pro.getPID() << " es de tipo " << tipo
        << ", su estado es " << estado << " y su prioridad es: " << pro.getPrioridad() << endl;
    }
}

void Gestor::buscarProcesoPorNombreUsuario(){
    string o;
    cout << "\tIntroduce un nombre de usuario: ";
    cin >> o;
    cout << "\tPID\tUsuario\tTipo\tEstado\t\tPrioridad" << endl;
    Lnormales.buscarProcesosUsuario(o);
    LtiempoReal.buscarProcesosUsuario(o);
}

void Gestor::eliminarProcesoPorPID(){
    int o;
    cout << "\tIntroduce PID: ";
    cin >> o;
    Proceso pro = Lnormales.borrarProcesosPID(o);
    if(pro.getVacio()){
        pro = LtiempoReal.borrarProcesosPID(o);
    }
    
    if(!pro.getVacio()){
        cout << "\tPID\tUsuario\tTipo\tEstado\tPrioridad" << endl;
        pro.mostrar();
        cout << endl;
        pro.setEstado(0);
        pro.mostrar();
        p.insertar(pro);
    }
        
}

void Gestor::cambiarPrioridadProcesoPorPID(){
    int o;
    cout << "\tIntroduce PID: ";
    cin >> o;
    
    Proceso *pro = Lnormales.buscarProcesoPID(o);
    if(pro == nullptr)
		pro = LtiempoReal.buscarProcesoPID(o);

    if(pro == nullptr)
        return;
		
    int prio;
    cout << "\tIntroduce prio: ";
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

void Gestor::dibujarABB(){
	Proceso v;
    v.setPrioridad(100);
    a.insertar(v);
 
	int numeroTiempoReal = 100;
    int numeroNormal = 39;
    int numTR[numeroTiempoReal];
    int numN[numeroNormal];
        
    for (int i = 0; i < numeroNormal; ++i) {
        numN[i] = i - 19;
    }
    
    random_shuffle(numN, numN + numeroNormal);
        
    for (int i = 0; i < numeroTiempoReal; ++i) {
        numTR[i] = i;
    }
	
    random_shuffle(numTR, numTR + numeroTiempoReal);
    
    while(p.getLongitud() >= 1){
        Proceso procesoAux = p.cima();
		int prioridad;
        procesoAux.setEstado(0);
        
        if(procesoAux.getTipo()){
            prioridad = numTR[100 - numeroTiempoReal];
            numeroTiempoReal--;
        }else{
            prioridad = numN[39 - numeroNormal]; 
            prioridad = prioridad + 120;
            numeroNormal--;
        }
        
        procesoAux.setPrioridad(prioridad);
		a.insertar(procesoAux);
        p.extraer();
	}
	a.dibujar();
}

void Gestor::procesosNormalesEnABB(){
    a.mostrarProcesosNormalesInOrden();
}

void Gestor::procesosTiempoRealEnABB(){
    a.mostrarProcesosTiempoRealInOrden();
}

void Gestor::procesosEnInorden(){
    a.mostrarProcesosInOrden();
}

void Gestor::buscarEnABB(){
    cout << "\t- El proceso normal cuya prioridad es la mas baja:" << endl;
	a.buscarProcesosNormalPrioridadMasBaja();
    cout << "\t- El proceso normal cuya prioridad es la mas alta:" << endl;
	a.buscarProcesosTiempoRealPrioridadMasAlta();
}

void Gestor::procesosEnNodoHoja(){
    cout << "\tProcesos almacenados en nodos hojas:" << endl;
    a.procesosNodoHoja();
}

void Gestor::cambiarPrioridadABB(){
    a.dibujar();
    int o;
    cout << "\tIndica la prioridad del proceso que quieres eliminar: ";
    cin >> o;
    
    Proceso borrado = a.borrar(o);
    a.dibujar();
    
    if(borrado.getVacio())
        return;
    
    if(borrado.getTipo()){
        LtiempoReal.insertarIZQ(borrado);
    }else{
        Lnormales.insertarIZQ(borrado);
    }
}

Gestor::~Gestor()
{
}