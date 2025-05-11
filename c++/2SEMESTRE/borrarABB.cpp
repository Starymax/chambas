#include <iostream>
using namespace std;

struct Nodo{
    int elemento;
    Nodo *izq;
    Nodo *dcha;
};

bool vacio(Nodo *raiz){
    if(raiz == NULL)
        return true;
    else
        return false;
}

bool esHoja(Nodo *raiz){    
    if((raiz -> izq == NULL) && (raiz -> dcha == NULL))
        return true;
    else
        return false;
}

int buscar(Nodo *raiz, int elemento){
    Nodo *actual = raiz;
    while(!vacio(actual)){
        if(elemento == actual -> elemento)
            return true;
        else if(elemento < actual -> elemento)
            actual = actual -> izq;
        else if(elemento > actual -> elemento)
            actual = actual -> dcha;
    }
    return false;
}

void insertar(Nodo *&raiz, int elemento){
    Nodo *nuevo = NULL, *actual = NULL, *anterior = NULL;
    buscar(raiz, elemento);
    if(actual != NULL)
        cout<<"duplicao"<< endl;
    else{
        Nodo *nuevo = new Nodo;
        nuevo -> elemento = elemento;
        nuevo -> izq = NULL;
        nuevo -> dcha = NULL;
        if(anterior == NULL)
            raiz = nuevo;
        else{
            if(anterior -> elemento > elemento)
                anterior -> izq = nuevo;
            else
                anterior -> dcha = nuevo;
        }
    }
}

void eliminar(Nodo *raiz, int dato){
    Nodo *padre = NULL;
    Nodo *actual = raiz;
    Nodo *nodo = NULL;
    int aux;
    bool termina = false;
    while((!vacio(actual)) && (termina != true)){
        if(dato == actual -> elemento){
            if(esHoja(actual)){
                if(padre != NULL)
                    if(padre -> dcha == actual)
                        padre -> dcha = NULL;
                    else if(padre -> izq == actual)
                        padre -> izq = NULL;
                delete actual;
                actual = NULL;
                termina = true;
            }
            else{
                padre = actual;
                if(actual -> dcha == NULL){
                    nodo = actual -> izq;
                    while(nodo -> izq != NULL){
                        padre = nodo;
                        nodo = nodo -> izq;
                    }
                }
                else{
                    while(nodo -> izq != NULL){
                        padre = nodo;
                        nodo = nodo -> izq;
                    }
                }
                else{
                    nodo = actual -> dcha;
                    while(nodo -> dcha != NULL){
                        padre = nodo;
                        nodo = nodo -> dcha;
                    }
                }
                aux = actual -> elemento;
                actual -> elemento = nodo -> elemento;
                nodo -> elemento = aux;
                actual = nodo;
        }
    }
    else{
        padre = actual;
        if(dato > actual -> elemento)
            actual = actual -> dcha;
        else
            actual = actual -> izq;
        }
    }
}   

void inorden(Nodo *raiz){
    if(raiz!= NULL){
        inorden(raiz->izq);
        cout<<" "<<raiz->dato;
        inorden(raiz->dcha);
    }
}

void preorden(Nodo *raiz){
    if(raiz!= NULL){
        cout<<" "<<raiz->dato;
        preorden(raiz->izq);
        preorden(raiz->dcha);
    }
}

void postorden(Nodo *raiz){
    if(raiz!= NULL){
        postorden(raiz->izq);
        postorden(raiz->dcha);
        cout<<" "<<raiz->dato;
    }
}

void contarNodos(Nodo *raiz, int &cont){
    if(raiz != NULL){
        cont++;
        contarNodos(raiz -> izq, cont);
        contarNodos(raiz -> dcha, cont);
    }
}

void auxAltura(Nodo *nodo, int a, int &altura){
    if(nodo -> izq)
        auxAltura(nodo, a+1, altura);
    if(nodo -> dcha)
        auxAltura(nodo, a+1, altura);
    if(esHoja(nodo) && a > altura)
        altura = a;
}

int alturaArbol(Nodo *raiz){
    int altura = 0;
    auxAltura(raiz, 0, altura);
    return altura + 1;
}

int main(){
    return 0;
}