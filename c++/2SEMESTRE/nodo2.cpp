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

int posicion(Nodo *head, int dato){
    if(head -> dato == dato)
        return 1;
    else
        return posicion(head -> siguiente, dato) + 1;
}

void modificar(Nodo *head, int dato, int nuevoDato){
    if(head == NULL)
        cout<< "No existe el elemento";
    else{
        if(head -> dato == dato)
            head -> dato = nuevoDato;
        else
            modificar(head -> siguiente, dato, nuevoDato);
    }
}

void eliminaDuplicados(Nodo *lista1, Nodo *&lista2){
    if(lista2 == NULL){
        lista2 = new Nodo;
        lista2 -> dato = lista1 -> dato;
        lista2 -> siguiente = NULL;
        eliminaDuplicados(lista1, lista2);
    }
    else{
        if(existeRecursivo(lista2, lista1 -> dato))
            eliminaDuplicados(lista1 -> siguiente, lista2 -> siguiente);
        else{
            Nodo *ap = new Nodo;
            ap -> dato = lista1 -> dato;
            ap -> siguiente = NULL;
            lista2 -> siguiente = ap;
            eliminaDuplicados(lista1 -> siguiente, lista2 -> siguiente);
        }
    }
}

int main(){
    Nodo *head = NULL;
    Nodo *head2 = NULL;

    insertaRecursivo(head, 1);
    insertaRecursivo(head, 7);
    insertaRecursivo(head, 5);
    insertaRecursivo(head, 2);
    insertaRecursivo(head, 5);
    imprimirRecursivo(head);
    if(existeRecursivo(head, 2))
        cout << "El elemento si existe." << endl;
    else
        cout << "El elemento no existe." << endl;
    cout << posicion(head, 7);
    eliminaDuplicados(head, head2);
    imprimirRecursivo(head2);
    getchar();
}