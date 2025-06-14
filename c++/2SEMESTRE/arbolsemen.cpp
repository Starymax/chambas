#include <iostream>
using namespace std;

struct Nodo{
    int indice;
    int inicio;
    int fin;
    Nodo *izq;
    Nodo *dcha;
};

Nodo* construir(int arr[], int inicio, int fin){
    Nodo *nodo = new Nodo;
    nodo -> inicio = inicio;
    nodo -> fin = fin;
    nodo -> izq = NULL;
    nodo -> dcha = NULL;
    if(inicio == fin){
        nodo -> indice = inicio;
        return nodo;
    }
    int medio = (inicio + fin) / 2;
    nodo -> izq = construir(arr, inicio, medio);
    nodo -> dcha = construir(arr, medio + 1, fin);
    if(arr[nodo -> izq -> indice] < arr[nodo -> dcha -> indice])
        nodo -> indice = nodo -> izq -> indice;
    else
        nodo -> indice = nodo -> dcha -> indice;
    return nodo;
}

int buscar(Nodo *nodo, int arr[], int inicio, int fin){
    if(nodo == NULL || inicio > nodo -> fin || fin < nodo -> inicio)
        return -1;
    if(nodo -> inicio >= inicio && nodo -> fin <= fin)
        return nodo -> indice;
    int izq = buscar(nodo -> izq, arr, inicio, fin);
    int dcha = buscar(nodo -> dcha, arr, inicio, fin);
    if(izq == -1) 
        return dcha;
    if(dcha == -1) 
        return izq;
    if(arr[izq] < arr[dcha])
        return izq;
    else
        return dcha;
}

Nodo* eliminar(Nodo *nodo, int arr[], int pos){
    if(nodo == NULL)
        return NULL;
    if(nodo -> inicio == nodo -> fin && nodo -> inicio == pos){
        delete nodo;
        return NULL;
    }
    int medio = (nodo -> inicio + nodo -> fin) / 2;
    if(pos <= medio)
        nodo -> izq = eliminar(nodo -> izq, arr, pos);
    else
        nodo -> dcha = eliminar(nodo -> dcha, arr, pos);
    if(nodo -> izq == NULL)
        nodo -> indice = nodo -> dcha -> indice;
    else if(nodo -> dcha == NULL)
        nodo -> indice = nodo -> izq -> indice;
    else if(arr[nodo -> izq -> indice] < arr[nodo -> dcha -> indice])
            nodo -> indice = nodo -> izq -> indice;
        else
            nodo -> indice = nodo -> dcha -> indice;

    return nodo;
}

void imprimir(Nodo *raiz, int nivel = 0){
    if (raiz != NULL){
        imprimir(raiz->dcha, nivel + 1);
        for (int i = 0; i < nivel; i++)
            cout << "   ";
        cout << raiz->indice << endl;
        imprimir(raiz->izq, nivel + 1);
    }
}

void inorden(Nodo *raiz){
    if(raiz!= NULL){
        inorden(raiz->izq);
        cout<<" "<<raiz->indice;
        inorden(raiz->dcha);
    }
}

void preorden(Nodo *raiz){
    if(raiz!= NULL){
        cout<<" "<<raiz->indice;
        preorden(raiz->izq);
        preorden(raiz->dcha);
    }
}

void postorden(Nodo *raiz){
    if(raiz!= NULL){
        postorden(raiz->izq);
        postorden(raiz->dcha);
        cout<<" "<<raiz->indice;
    }
}

void borrar(Nodo *&raiz){
    if(raiz != NULL){
        borrar(raiz -> izq);
        borrar(raiz -> dcha);
        delete raiz;
        raiz = NULL;
    }
}

int main(){
    int arr[10000];
    int opcion;
    int n = 0;
    Nodo *raiz = NULL;
    do{
        cout << endl <<"arbol segmentado by Valentin, Oswaldo y Denisse" << endl;
        cout << "1. insertar valor" << endl;
        cout << "2. eliminar segun indice" << endl;
        cout << "3. buscar el menor valor segun rango" << endl;
        cout << "4. preorden" << endl;
        cout << "5. inorden" << endl;
        cout << "6. postorden" << endl;
        cout << "7. imprimir arbol" << endl;
        cout << "0. salir" << endl;
        cout << "seleccione una opcion:";
        cin >> opcion;
        switch (opcion){
            case 1:
                cout << "ingrese el valor a insertar: ";
                int valor;
                cin >> valor;
                arr[n] = valor;
                n++;
                borrar(raiz);
                raiz = construir(arr, 0, n - 1);
                break;
            case 2:
                cout << "ingrese el indice a eliminar: ";
                int pos;
                cin >> pos;
                if(pos < 0 || pos >= n)
                    cout << "indice fuera de rango" << endl;
                else{
                    raiz = eliminar(raiz, arr, pos);
                    n--;
                }
                break;
            case 3:
                cout << "ingrese el rango" << endl << "(inicio): ";
                int inicio;
                int fin;
                cin >> inicio;
                cout << "(fin): "; 
                cin >> fin;
                if(inicio < 0 || fin >= n || inicio > fin)
                    cout << "rango invalido" << endl;
                else{
                    int menor = buscar(raiz, arr, inicio, fin);
                    if(menor != -1)
                        cout << "el valor mas pequeno en el rango [" << inicio << ", " << fin << "] es: " << arr[menor] << endl;
                    else
                        cout << "no se encontraron valores en el rango" << endl;
                }
                break;
            case 4:
                cout << "recorrido preorden: ";
                preorden(raiz);
                cout << endl;
                break;
            case 5:
                cout << "recorrido inorden: ";
                inorden(raiz);
                cout << endl;
                break;
            case 6:
                cout << "recorrido postorden: ";
                postorden(raiz);
                cout << endl;
                break;
            case 7:
                cout << "arreglo actual: ";
                for(int i = 0; i < n; i++)
                    cout << arr[i] << " ";
                cout << endl << "arbol: " << endl;
                imprimir(raiz);
                break;
            case 8:
                cout << "saliendo..." << endl;
                break;
        }
    }while (opcion != 8);

    return 0;
}