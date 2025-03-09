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
            existeRecursivo(n -> siguiente, valor);
    else
        return false;
}

bool estaVacia(Nodo *cabeza){
    if (cabeza == NULL)
        return true;
    else
        return false;
}

void insertaRecursivo(Nodo *&n, int dato){ // el *& es para que reciba el apuntador y la estructura?????
    if (estaVacia(n)){
        Nodo *ap = new Nodo;
        ap -> dato = dato;
        ap -> siguiente = NULL;
        n = ap;
    }
    else if (n -> siguiente == NULL){ // HASTA LLEGAR AL FINAL
        Nodo*ap = new Nodo;
        ap -> dato = dato;
        ap -> siguiente = NULL;
        n -> siguiente = ap;
    }
    else
        insertaRecursivo(n -> siguiente, dato); // AVANZAR
}

// LO MISMO QUE ARRIBA SOLO QUE REUSANDO CODIGO

Nodo* crearNodo(int dato){
    Nodo *ap = new Nodo;
    ap -> dato = dato;
    ap -> siguiente = NULL;
    return ap;
}

void insertaRecursivo2(Nodo *&n, int dato){
    if(estaVacia(n)){
        n = crearNodo(dato);
    }
    else
        if(n -> siguiente == NULL){
            n -> siguiente = crearNodo(dato);
        }
        else
            insertaRecursivo2(n -> siguiente, dato);
}

void imprimirRecursivo(Nodo *n){
    if(n != NULL){
        cout << "Dato: " << n -> dato << endl;
        imprimirRecursivo(n -> siguiente);
    }
}

void insertarOrdenado(Nodo *head, int dato){
    if(dato < head -> siguiente){
        Nodo *ant = new

                ant -> siguiente = nuevo;   ant = NULL;
                nuevo -> siguiente = sig;   sig = NULL;
    }
}

void eliminarNodo(Nodo *n){ //cuando el dato es igual al buscado se elimina, usar auxiliar para apuntar al siguiente nodo antes de eliminarlo
    aux = ap ->siguiente;
    delete ap;
}

int main(){
    Nodo *head = NULL;

    insertaRecursivo(head, 5);
    insertaRecursivo(head, 4);
    insertaRecursivo(head, 3);
    insertaRecursivo(head, 2);
    insertaRecursivo(head, 1);
    imprimirRecursivo(head);
    eliminarNodo(head);
    imprimirRecursivo(head);
    if(existeRecursivo(head, 6))
        cout << "El elemento si existe." << endl;
    else
        cout << "El elemento no existe." << endl;
    getchar();
}