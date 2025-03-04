#include <iostream>
using namespace std;

void generartorre(int torre1[], int n){
    int j = 1;
    for (int i = n; i > 0; i--) {
        torre1[i - 1] = j;
        j++;
    }
}

void discos(int n){
    if (n != 0)
        for (int i = 0; i < n; i++){
            cout << "0";
        }
    cout << " " << endl;
}

void imprimirtodo(int torre1[], int torre2[], int torre3[], int n1, int n2, int n3, int n, int j){
    cout << endl;
    for(int i = j-1; i > -1; i--){
        if(i < n1)
            discos(torre1[i]);
        else 
            discos(0);
    }
    cout << endl << "--------------------------------------------" << endl;
    for(int i = j-1; i > -1; i--){
        if(i < n2)
            discos(torre2[i]);
        else 
            discos(0);
    }
    cout << endl << "--------------------------------------------" << endl;
    for(int i = j-1; i > -1; i--){
        if(i < n3) 
            discos(torre3[i]);
        else 
            discos(0);
    }
    cout << endl << "*******************************************" << endl;
}


void mover(int origen[], int destino[], int& n1, int& n2, int& n3, int n, int torre1[], int torre2[], int torre3[], int j){
    if(n1 <= 0)
        return;
    destino[n2] = origen[n1 - 1];
    n1--;
    n2++;
}

void resolver(int torre1[], int torre2[], int torre3[], int& n1, int& n2, int& n3, int n, int j){
    if(n == 1){
        mover(torre1, torre3, n1, n3, n2, n, torre1, torre2, torre3, j);
        imprimirtodo(torre1, torre2, torre3, n1, n2, n3, n, j);
    }
    else{
        resolver(torre1, torre3, torre2, n1, n3, n2, n - 1, j);
        mover(torre1, torre3, n1, n3, n2, n, torre1, torre2, torre3, j);
        resolver(torre2, torre1, torre3, n2, n1, n3, n - 1, j);
    }
}

int main(){
    int n;
    cout << "Ingrese el numero de discos a mover: ";
    cin >> n;
    int j = n;
    int n1 = n, n2 = 0, n3 = 0;
    int torre1[n], torre2[n], torre3[n];
    generartorre(torre1, n);
    imprimirtodo(torre1, torre2, torre3, n1, n2, n3, n, j);
    resolver(torre1, torre2, torre3, n1, n2, n3, n, j);
    int respuesta;
    cin >> respuesta;

    return 0;
}