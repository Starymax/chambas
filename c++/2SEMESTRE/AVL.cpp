#include <iostream>
using namespace std;

struct Nodo{
    int elemento;
    Nodo *izq;
    Nodo *dcha;
    Nodo *padre;
    int altura;
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
}

void actualizarAltura(Nodo *nodo){
    if (nodo != NULL){
        int alturaizq = 0;
        int alturadcha = 0;
        if(nodo -> izq != NULL)
            alturaizq = nodo -> izq -> altura;
        if(nodo -> dcha != NULL)
            alturadcha = nodo -> dcha -> altura;
        if(alturaizq >= alturadcha)
            nodo -> altura = 1 + alturaizq;
        else
            nodo -> altura = 1 + alturadcha;
    }
}

Nodo* rsd(Nodo *&p) {
    Nodo *q = p -> izq;
    p -> izq = q -> dcha;
    if(q -> dcha != NULL)
        q -> dcha -> padre = p;
    q -> dcha = p;
    q -> padre = p->padre;
    p -> padre = q;

    if (q->padre != NULL){
        if (q -> padre -> izq == p) 
            q -> padre -> izq = q;
        else 
            q -> padre -> dcha = q;
    }
    actualizarAltura(p);
    actualizarAltura(q);
    return q;
}

Nodo* rsi(Nodo *&p){
    Nodo *q = p -> dcha;
    p -> dcha = q -> izq;
    if (q -> izq != NULL) 
        q -> izq -> padre = p;

    q -> izq = p;
    q -> padre = p -> padre;
    p -> padre = q;

    if (q -> padre) {
        if (q -> padre -> izq == p) q -> padre -> izq = q;
        else q -> padre -> dcha = q;
    }

    actualizarAltura(p);
    actualizarAltura(q);
    return q;
}

Nodo* rdd(Nodo *&nodo){
    nodo -> izq = rsi(nodo -> izq);
    if (nodo -> izq != NULL)
        nodo -> izq -> padre = nodo;
    return rsd(nodo);
}

Nodo* rdi(Nodo *&nodo){
    nodo -> dcha = rsd(nodo -> dcha);
    if (nodo -> izq != NULL)
        nodo -> izq -> padre = nodo;
    return rsd(nodo);
}

Nodo* factorEquilibrio(Nodo *&nodo){
    while(nodo != NULL){
        actualizarAltura(nodo);
        int altdcha = 0;
        int altizq = 0;
        if(nodo -> izq != NULL)
            altizq = nodo -> izq -> altura;
        if(nodo -> dcha != NULL)
            altdcha = nodo -> dcha -> altura;
        int fe = altdcha - altizq;
        if(fe < -1){
            int izqAltura = 0;
            if(nodo -> izq -> izq != NULL)
                izqAltura = nodo -> izq -> izq -> altura;
            int derAltura = 0;
            if(nodo -> izq -> dcha != NULL) 
                derAltura = nodo -> izq -> dcha -> altura;
            if (izqAltura >= derAltura)
                nodo = rsd(nodo);
            else
                nodo = rdd(nodo);
        }
        else if (fe > 1){
            int izqAltura = 0;
            if(nodo -> dcha -> izq != NULL)
                izqAltura = nodo -> dcha -> izq -> altura;
            int derAltura = 0;
            if(nodo -> dcha -> dcha != NULL) 
                derAltura = nodo -> dcha -> dcha -> altura;

            if (derAltura >= izqAltura)
                nodo = rsi(nodo);
            else
                nodo = rdi(nodo);
        }
        if (nodo->padre == NULL)
            break;
        nodo = nodo -> padre;
    }
    return nodo;
}

void insertar(Nodo *&raiz, int elemento){
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
        nuevo -> padre = anterior;
        nuevo -> altura = 1;
        if(anterior == NULL){
            raiz = nuevo;
        } else if(anterior->elemento > elemento)
            anterior->izq = nuevo;
        else
            anterior->dcha = nuevo;
        Nodo *temp = nuevo;
        while(temp != NULL){
            actualizarAltura(temp);
            temp = temp -> padre;
        }
        raiz = factorEquilibrio(nuevo);
    }
}

void eliminar(Nodo *&raiz, int dato){
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
    if(padre != NULL)
        raiz = factorEquilibrio(padre);
}

void imprimir(Nodo *raiz, int nivel = 0){
    if (raiz != NULL){
        imprimir(raiz->dcha, nivel + 1);
        for (int i = 0; i < nivel; i++)
            cout << "   ";
        cout << raiz->elemento << endl;
        imprimir(raiz->izq, nivel + 1);
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

int main(){
    Nodo *raiz = NULL;
    Nodo *actual = NULL;
    Nodo *anterior = NULL;
    int opcion, elemento;
    do{
        cout << endl << "ARBOL AVL By Valentin, Oswaldo y Denis";
        cout << endl << "1. insertar elemento";
        cout << endl << "2. eliminar elemento";
        cout << endl << "3. buscar elemento";
        cout << endl << "4. inorden";
        cout << endl << "5. preorden";
        cout << endl << "6. postorden";
        cout << endl << "7. imprimir arbol";
        cout << endl << "8. salir";
        cout << endl << "seleccione una opcion: ";
        cin >> opcion;
        switch (opcion){
            case 1:
                cout << "ingrese el elemento a insertar: ";
                cin >> elemento;
                insertar(raiz, elemento);
                break;
            case 2:
                cout << "ingrese el elemento a eliminar: ";
                cin >> elemento;
                eliminar(raiz, elemento);
                break;
            case 3:
                cout << "ingrese el elemento a buscar: ";
                cin >> elemento;
                buscar(raiz, elemento, actual, anterior);
                if(actual != NULL)
                    cout << elemento << " existe\n";
                else
                    cout << elemento << " no encontrado\n";
                break;
            case 4:
                cout << "recorrido inorden:";
                inorden(raiz);
                cout << endl;
                break;
            case 5:
                cout << "recorrido preorden:";
                preorden(raiz);
                cout << endl;
                break;
            case 6:
                cout << "recorrido postorden:";
                postorden(raiz);
                cout << endl;
                break;
            case 7:
                imprimir(raiz);
                break;
            case 8:
                cout << "adios";
                break;
            default:
                cout << "opcion no valida intente de nuevo\n";
                break;
        }
    }while(opcion != 8);

    return 0;
}