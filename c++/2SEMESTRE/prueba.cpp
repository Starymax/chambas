#include <iostream>
using namespace std;

struct Nodo{
    int indice;
    Nodo *izq;
    Nodo *dcha;
};

Nodo* insertar(int &arr[], int indice, int inicio, int fin){
}
Nodo* construir(int arr[], int inicio, int fin){
    Nodo *nodo = new Nodo;
    nodo -> inicio = inicio;
    nodo -> fin = fin;
    nodo -> izq = NULL;
    nodo -> dcha = NULL;
    if(inicio == fin){
        nodo -> suma = arr[inicio];
        return nodo;
    }
    int medio = (inicio + fin) / 2;
    nodo -> izq = construir(arr, inicio, medio);
    nodo -> dcha = construir(arr, medio + 1, fin);
    nodo -> suma = nodo -> izq -> suma + nodo -> dcha -> suma;
    return nodo;
}

int sumar(Nodo *nodo, int ini, int fin){
    if(nodo == NULL || ini > nodo -> inicio || fin < nodo -> fin)
        return 0;
    if(ini == nodo -> incio && nodo -> fin == fin)
        return nodo -> suma;
    return sumar(nodo -> izq, ini, fin) + sumar(nodo -> dcha, ini, fin);
}

