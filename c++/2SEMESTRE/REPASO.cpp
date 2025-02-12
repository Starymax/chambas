#include <iostream>
using namespace std;

int buscarX(int a[], int n, int x){
    int band, i = 0;
    while(!band && i < n){
        if (a[i] == x)
            band = 1;
        i++;
    }
    return band;
}

int mayor(int a[], int n){
    int b = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > b)
            b = a[i];
    }
    return b;
}

int estaOrdenado(int a[], int n){
    int i = 0, band = 1;
    int j = a[0];
    while(band == 1 && i < n){
        if(a[i] < j){
            band = 0;
        }
        j = a[i];
        i++;
    }
    return band;
}

int obtienePosX(int a[], int n, int x){
    int i = 0;
    int band = -1;
    while(band == -1 && i < n){
        if(a[i] == x)
            band = i;
        i++;
    }
    return band;
}

void ordenar(int a[], int n){
    for(int i = 0; i < n-1; i++){
        if(a[i] > a[i+1]){
            int h = a[i];
            a[i] = a[i+1];
            a[i+1] = h;
        }
    }
}

int main(){
    int a[] = {1,2,3,6,5};
    int n = 5;
    int x = 6;
    cout<<"buscarx: "<<buscarX(a,n,x)<<endl;
    cout<<"mayor: "<<mayor(a,n)<<endl;
    cout<<"estaordenado: "<<estaOrdenado(a,n)<<endl;
    cout<<"obtieneposx: " << obtienePosX(a,n,x) << endl;
    return 0;
}