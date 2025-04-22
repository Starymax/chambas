#include <iostream>
#include <string>
using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
};

void inicializar(Nodo *&tope) {
    tope = nullptr;
}

bool vacia(Nodo *tope) {
    return (tope == nullptr);
}

void consultarTope(Nodo *tope, int &dato) {
    if (!vacia(tope))
        dato = tope->dato;
}

void meter(Nodo *&tope, int dato) {
    Nodo *aux = new Nodo;
    aux->dato = dato;
    aux->siguiente = tope;
    tope = aux;
}

void sacar(Nodo *&tope, int &dato) {
    if (!vacia(tope)) {
        Nodo *aux = tope;
        dato = tope->dato;
        tope = tope->siguiente;
        delete aux;
    }
}

void vaciarPila(Nodo *&tope) {
    int dato;
    while (!vacia(tope)) {
        sacar(tope, dato);
    }
}

void mostrarPila(Nodo *tope) {
    while (tope != nullptr) {
        cout << tope->dato << " ";
        tope = tope->siguiente;
    }
    cout << endl;
}

int main() {
    Nodo *pila;
    int dato;

    inicializar(pila);
    meter(pila, 10);
    meter(pila, 20);
    meter(pila, 30);

    cout << "Pila completa: ";
    mostrarPila(pila);

    consultarTope(pila, dato);
    cout << "Tope de la pila: " << dato << endl;

    sacar(pila, dato);
    cout << "Elemento sacado: " << dato << endl;

    cout << "Pila despues de sacar: ";
    mostrarPila(pila);

    vaciarPila(pila);
    getchar();

    return 0;
}