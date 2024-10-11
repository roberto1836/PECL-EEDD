#include <stdio.h>
#include "Pila.hpp"
#include "Cola.hpp"
int main(int argc, char **argv)
{   
    Pila p;
    Cola c;
	for (int i = 0; i < 10; ++i) {
        Proceso pro = Proceso();
        p.insertar(pro);
        c.insertar(pro);
    }
    
    p.mostrar();
    c.mostrar();
    
	return 0;
}
