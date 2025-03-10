#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

bool existeRecursivo(Nodo *n, int valor){
    if (n!= NULL){
        if (n -> dato == valor)
            return true;
        else 
            return existeRecursivo(n -> siguiente, valor);
    }
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
    if(head == NULL || head -> dato > dato){
        Nodo *nuevo = new Nodo;
        nuevo -> dato = head -> dato;
        if(head -> siguiente == NULL)
            nuevo -> siguiente = NULL;
        else
            nuevo -> siguiente = head -> siguiente;
        head -> siguiente = nuevo;
        head -> dato = dato;
    }
    else{
        if(head -> dato > dato && head -> siguiente == NULL){
            Nodo *nuevo = new Nodo;
            nuevo -> dato = head -> dato;
            nuevo -> siguiente = NULL;
            head -> siguiente = nuevo;
            head -> dato = dato;
        }
        else{
            if(head -> dato <= dato && (head -> siguiente == NULL || head -> siguiente -> dato > dato)){
                Nodo *nuevo = new Nodo;
                nuevo -> dato = dato;
                if(head -> siguiente == NULL)
                    nuevo -> siguiente = NULL;
                else
                    nuevo -> siguiente = head -> siguiente;
                head -> siguiente = nuevo;
            }
            else
                insertarOrdenado(head -> siguiente, dato);
        }
    }
}

void eliminarNodo(Nodo *&n, int dato){
    if(dato == n -> dato){
        Nodo *aux = n;
        n = n -> siguiente;
        delete aux;
        return;
    }
    if(dato == n -> siguiente -> dato){
        if(n -> siguiente -> siguiente == NULL){
            delete n -> siguiente -> siguiente;
            n -> siguiente = NULL;
        }
        else{
            Nodo *ap = n -> siguiente;
            Nodo *aux = ap -> siguiente;
            delete ap;
            n -> siguiente = aux;
        }
    }
    else
        eliminarNodo(n -> siguiente, dato);
}


int main(){
    Nodo *head = NULL;

    insertaRecursivo(head, 1);
    insertaRecursivo(head, 2);
    insertaRecursivo(head, 3);
    insertaRecursivo(head, 4);
    insertaRecursivo(head, 5);
    imprimirRecursivo(head);
    if(existeRecursivo(head, 2))
        cout << "El elemento si existe." << endl;
    else
        cout << "El elemento no existe." << endl;
    insertarOrdenado(head, 4);
    eliminarNodo(head, 4);
    imprimirRecursivo(head);
    getchar();
}