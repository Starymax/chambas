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

void buscar(Nodo *raiz, int elemento, Nodo *&actual, Nodo *&anterior){
    bool encontrado = false;
    anterior = NULL;
    actual = raiz;

    while (!encontrado && actual != NULL){
        if (actual->elemento == elemento){
            encontrado = true;
        } else {
            anterior = actual;
            if (actual->elemento > elemento){
                actual = actual->izq;
            } else{
                actual = actual->dcha;
            }
        }
    }

    if (!encontrado) {
        cout << "No existe " << elemento << endl;
    } else {
        cout << elemento << " existe" << endl;
    }
}

void insertar(Nodo *&raiz, int elemento){
    Nodo *nuevo = NULL;
    Nodo *actual = NULL;
    Nodo *anterior = NULL;
    buscar(raiz, elemento, actual, anterior);
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
                if(padre != NULL){
                    if(padre -> dcha == actual)
                        padre -> dcha = NULL;
                    else if(padre -> izq == actual)
                        padre -> izq = NULL;
                }
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
        cout<<" "<<raiz->elemento;
        inorden(raiz->dcha);
    }
}

void preorden(Nodo *raiz){
    if(raiz!= NULL){
        cout<<" "<<raiz->elemento;
        preorden(raiz->izq);
        preorden(raiz->dcha);
    }
}

void postorden(Nodo *raiz){
    if(raiz!= NULL){
        postorden(raiz->izq);
        postorden(raiz->dcha);
        cout<<" "<<raiz->elemento;
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
        auxAltura(nodo -> izq, a+1, altura);
    if(nodo -> dcha)
        auxAltura(nodo -> dcha, a+1, altura);
    if(esHoja(nodo) && a > altura)
        altura = a;
}

int alturaArbol(Nodo *raiz){
    int altura = 0;
    auxAltura(raiz, 0, altura);
    return altura + 1;
}

int main(){
    Nodo *raiz = NULL;
    int cont = 0;

    insertar(raiz, 50);
    insertar(raiz, 30);
    insertar(raiz, 70);
    insertar(raiz, 20);
    insertar(raiz, 40);
    insertar(raiz, 60);
    insertar(raiz, 80);

    cout << "inorden:";
    inorden(raiz);
    cout << endl;

    cout << "preorden:";
    preorden(raiz);
    cout << endl;

    cout << "postorden:";
    postorden(raiz);
    cout << endl;

    eliminar(raiz, 30);
    cout << "inorden eliminado:";
    inorden(raiz);
    cout << endl;

    contarNodos(raiz, cont);
    cout << "cantidad de nodos: " << cont << endl;

    cout << "altura del arbol: " << alturaArbol(raiz) << endl;

    return 0;
}