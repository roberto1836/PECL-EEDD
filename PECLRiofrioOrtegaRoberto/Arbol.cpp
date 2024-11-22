#include "Arbol.hpp"

Arbol::Arbol() { raiz = nullptr; }
void Arbol::insertar(Proceso valor) {raiz = insertar(raiz, valor);}
pnodoAbb Arbol::insertar(pnodoAbb nodo, Proceso v){
	if(!nodo)
        return new NodoArbol(v);
    if(v.getPrioridad() <= nodo->valor.getPrioridad())
        nodo->izq = insertar(nodo->izq, v);
    else
        nodo->der = insertar(nodo->der, v);
    return nodo;
}

void Arbol::pintar(){
    pintar(raiz);
    cout << '\n';
}

void Arbol::pintar(pnodoAbb nodo){
    if(!nodo)
        return;
    pintar(nodo->izq);
    cout << nodo->valor.getPrioridad() << " ";
    pintar(nodo->der);
}

int Arbol::altura(pnodoAbb nodo){
    if(!nodo)
        return 0;
    return 1 + max(altura(nodo->izq), altura(nodo->der));
}

void Arbol::dibujarNodo(vector<string>& output, vector<string>& linkAbove, pnodoAbb nodo, int nivel, int p,
                        char linkChar)
{
    if(!nodo)
        return;

    int h = output.size();
    string SP = " ";

    if(p < 0) {
        string extra(-p, ' ');
        for(string& s : output)
            if(!s.empty())
                s = extra + s;
        for(string& s : linkAbove)
            if(!s.empty())
                s = extra + s;
    }
    if(nivel < h - 1)
        p = max(p, (int)output[nivel + 1].size());
    if(nivel > 0)
        p = max(p, (int)output[nivel - 1].size());
    p = max(p, (int)output[nivel].size());

    if(nodo->izq) {
        int procesoQueQuieroImprimirEnElArbol =
            nodo->izq->valor.getPrioridad(); 
        string izqdato = SP + to_string(procesoQueQuieroImprimirEnElArbol) + SP;
        dibujarNodo(output, linkAbove, nodo->izq, nivel + 1, p - izqdato.size(), 'L');
        p = max(p, (int)output[nivel + 1].size());
    }

    int space = p - output[nivel].size();
    if(space > 0)
        output[nivel] += string(space, ' ');
    int procesoQueQuieroImprimirEnElArbol =
        nodo->valor.getPrioridad(); 
    string nodovalor = SP + to_string(procesoQueQuieroImprimirEnElArbol) + SP;
    output[nivel] += nodovalor;

    space = p + SP.size() - linkAbove[nivel].size();
    if(space > 0)
        linkAbove[nivel] += string(space, ' ');
    linkAbove[nivel] += linkChar;

    if(nodo->der)
        dibujarNodo(output, linkAbove, nodo->der, nivel + 1, output[nivel].size(), 'R');
}

void Arbol::dibujar(){
    int h = altura(raiz);
    vector<string> output(h), linkAbove(h);
    dibujarNodo(output, linkAbove, raiz, 0, 5, ' ');

    for(int i = 1; i < h; i++) {
        for(int j = 0; j < linkAbove[i].size(); j++) {
            if(linkAbove[i][j] != ' ') {
                int size = output[i - 1].size();
                if(size < j + 1)
                    output[i - 1] += string(j + 1 - size, ' ');
                int jj = j;
                if(linkAbove[i][j] == 'L') {
                    while(output[i - 1][jj] == ' ')
                        jj++;
                    for(int k = j + 1; k < jj - 1; k++)
                        output[i - 1][k] = '_';
                } else if(linkAbove[i][j] == 'R') {
                    while(output[i - 1][jj] == ' ')
                        jj--;
                    for(int k = j - 1; k > jj + 1; k--)
                        output[i - 1][k] = '_';
                }
                linkAbove[i][j] = '|';
            }
        }
    }

    cout << '\n' << '\n';
    for(int i = 0; i < h; i++) {
        if(i)
            cout << linkAbove[i] << '\n';
        cout << output[i] << '\n';
    }
    cout << '\n' << '\n';
}


void Arbol::inorden(pnodoAbb nodo){
    if(nodo != NULL){
        inorden(nodo->izq);
        nodo->valor.mostrar();
        inorden(nodo->der);   
    }
}

Arbol::~Arbol()
{
}

