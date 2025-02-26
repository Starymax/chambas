#include <iostream>
using namespace std;

void generartorre(int torre1[], int n) {
    int j = 1;
    for (int i = n; i > 0; i--) {
        torre1[i - 1] = j;
        j++;
    }
}

void discos(int n) {
    if (n != 0)
        for (int i = 0; i < n; i++) {
            cout << "0";
        }
    cout << " " << endl;
}

void imprimirtodo(int torre1[], int torre2[], int torre3[], int n1, int n2, int n3, int n){
    cout << endl;
    for(int i = n-1; i > -1; i--){
        if(i < n1)
            discos(torre1[i]);
        else 
            discos(0);
    }
    cout << endl << "--------------------------------------------" << endl;
    for(int i = n-1; i > -1; i--){
        if(i < n2)
            discos(torre2[i]);
        else 
            discos(0);
    }
    cout << endl << "--------------------------------------------" << endl;
    for(int i = n-1; i > -1; i--){
        if(i < n3) 
            discos(torre3[i]);
        else 
            discos(0);
    }
    cout << endl << "____________________________________________" << endl;
}

void mover(int origen[], int destino[], int& n1, int& n2, int& n3, int n, int torre1[], int torre2[], int torre3[]) {
    if(n1 <= 0) return;
    destino[n2] = origen[n1 - 1];
    n1--;
    n3++;
}


int main() {
    int n = 3; // Número de discos
    int torre1[] = {3, 2, 1}; // Inicialización de la primera torre
    int torre2[] = {0, 0, 0}; // Inicialización de la segunda torre
    int torre3[] = {0, 0, 0}; // Inicialización de la tercera torre
    int n1 = 3, n2 = 0, n3 = 0;

    mover(torre1, torre3, n1, n3, n2, n, torre1, torre2, torre3);
    mover(torre1, torre2, n1, n2, n3, n, torre1, torre2, torre3);
    imprimirtodo(torre1, torre2, torre3, n1, n2, n3, n);

    return 0;
}