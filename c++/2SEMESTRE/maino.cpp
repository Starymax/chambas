#include <iostream>
using namespace std;

void generartorre(int torre1[], int n){
    int j = 1;
    for(int i = n; i > 0; i--){
        torre1[i - 1] = j;
        j++;
    }
}

void discos(int n){
    if(n != 0)
        for(int i = 0; i < n; i++){
            cout << "0";
        }
    cout << endl;
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

void mover(int origen[], int destino[], int& n1, int& n2){
    int h = origen[n1-1];
    destino[n2] = h;
    n1--;
    n2++;
}

void resolver(int torre1[], int torre2[], int torre3[], int& n1, int& n2, int& n3, int n){
    if(n == 1){
        mover(torre1, torre3, n1, n3);
        imprimirtodo(torre1, torre2, torre3, n1, n2, n3, n);
    } 
    else{
        resolver(torre1, torre3, torre2, n1, n3, n2, n-1);
        mover(torre1, torre3, n1, n3);
        imprimirtodo(torre1, torre2, torre3, n1, n2, n3, n);
        resolver(torre2, torre1, torre3, n2, n1, n3, n-1);
    }
}

int main(){
    int n;
    cout << "Ingrese el numero de discos a mover: ";
    cin >> n;
    int n1 = n, n2 = 0, n3 = 0;
    int torre1[n], torre2[n], torre3[n];
    generartorre(torre1, n);
    imprimirtodo(torre1, torre2, torre3, n1, n2, n3, n);
    resolver(torre1, torre2, torre3, n1, n2, n3, n);

    return 0;
}