#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

bool existeRecursivo(Nodo *n, int valor){
    if (n!= NULL)
        if (n -> dato == valor)
            return true;
        else 
            existeRecursivo(n -> siguiente, valor)
    else
        return false;
}

bool estaVacia(Nodo *cabeza){
    if (cabeza == NULL)
        return true;
    else
        return false;
}

void insertaRecursivo(Nodo *&n, int dato){
    if (estaVacia(n)){
        Nodo *ap = new Nodo;
        ap -> dato = dato;
        ap -> siguiente = NULL;
        n = ap;
    }
    else if (n -> siguiente == NULL){
        Nodo*ap = new Nodo;
        ap -> dato = dato;
        ap -> siguiente = NULL;
        n -> siguiente = ap;
    }
    else
        insertaRecursivo(n -> siguiente, dato);
}