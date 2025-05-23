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
    cout << endl;
}

void imprimirtodo(int torre1[], int torre2[], int torre3[], int n1, int n2, int n3, int n) {
    // Imprimir torre 1
    for (int i = 0; i < n; ++i) {
        if (i < n1)
            cout << torre1[i];
        else
            cout << " ";
    }
    cout << endl;

    // Imprimir torre 2
    for (int i = 0; i < n; ++i) {
        if (i < n2)
            cout << torre2[i];
        else
            cout << ' ';
    }
    std::cout << std::endl;

    // Imprimir torre 3
    for (int i = 0; i < n; ++i) {
        if (i < n3)
            std::cout << torre3[i];
        else
            std::cout << ' ';
    }
    std::cout << std::endl;

    // Línea divisoria
    std::cout << "--------------------------------------------" << std::endl;
}


void mover(int origen[], int destino[], int& n1, int& n2, int& n3, int n, int torre1[], int torre2[], int torre3[]) {
    if(n1 <= 0) return;
    int h = origen[n1 - 1];
    destino[n-n2-1] = h;
    n1--;
    n2++;
    imprimirtodo(torre1, torre2, torre3, n1, n2, n3, n);
}

void resolver(int torre1[], int torre2[], int torre3[], int& n1, int& n2, int& n3, int n) {
    if (n == 1) {
        mover(torre1, torre3, n1, n2, n3, n, torre1, torre2, torre3);
    } else {
        resolver(torre1, torre3, torre2, n1, n3, n2, n - 1);
        mover(torre1, torre3, n1, n2, n3, n, torre1, torre2, torre3);
        resolver(torre2, torre1, torre3, n2, n1, n3, n - 1);
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