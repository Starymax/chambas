#include <iostream>
using namespace std;

void busquedaBinaria(int a[], int& medio, int n, int b, int& aux){
    medio = n/2 + aux - 1;
    if(a[medio] != b){
        if(a[aux] <= b)
            busquedaBinaria(a, medio, medio, b, aux);
        else
            busquedaBinaria(a, medio, n, b, medio);
    }
    else 
        cout << medio;
}

int main(){
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int n = 10;
    int b = 9;
    int aux = 0;
    int medio;
    busquedaBinaria(a, medio, n, b, aux);
}