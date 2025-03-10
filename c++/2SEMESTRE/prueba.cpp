#include <iostream>
using namespace std;


void insertarOrdenado(Nodo *head, int dato){
    if(dato < head -> siguiente){
        Nodo *ant = new

                ant -> siguiente = nuevo;   ant = NULL;
                nuevo -> siguiente = sig;   sig = NULL;
    }
}



int main() {
    int n = 3; // Número de discos
    int torre1[] = {3, 2, 1}; // Inicialización de la primera torre
    int torre2[] = {0, 0, 0}; // Inicialización de la segunda torre
    int torre3[] = {0, 0, 0}; // Inicialización de la tercera torre
    int n1 = 3, n2 = 0, n3 = 0;

    mover(torre1, torre3, n1, n3, n2, n, torre1, torre2, torre3);
    mover(torre1, torre2, n1, n2, n3, n, torre1, torre2, torre3);
    imprimirtodo(torre1, torre2, torre3, n1, n2, n3, n);

    return 0;
}