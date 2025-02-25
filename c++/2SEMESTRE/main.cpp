#include <iostream>
using namespace std;

void imprimirTorres(int torre1[], int altura1, int torre2[], int altura2, int torre3[], int altura3, int n) {
    for (int i = n - 1; i >= 0; --i) {
        // Imprimir torre 1
        if (i < altura1) {
            for (int j = 0; j < n - torre1[i]; ++j) cout << " ";
            for (int j = 0; j < torre1[i]; ++j) cout << "0";
            cout << "|";
            for (int j = 0; j < torre1[i]; ++j) cout << "0";
            for (int j = 0; j < n - torre1[i]; ++j) cout << " ";
        } else {
            for (int j = 0; j < 2 * n + 1; ++j) cout << " ";
        }
        cout << " ";

        // Imprimir torre 2
        if (i < altura2) {
            for (int j = 0; j < n - torre2[i]; ++j) cout << " ";
            for (int j = 0; j < torre2[i]; ++j) cout << "0";
            cout << "|";
            for (int j = 0; j < torre2[i]; ++j) cout << "0";
            for (int j = 0; j < n - torre2[i]; ++j) cout << " ";
        } else {
            for (int j = 0; j < 2 * n + 1; ++j) cout << " ";
        }
        cout << " ";

        // Imprimir torre 3
        if (i < altura3) {
            for (int j = 0; j < n - torre3[i]; ++j) cout << " ";
            for (int j = 0; j < torre3[i]; ++j) cout << "0";
            cout << "|";
            for (int j = 0; j < torre3[i]; ++j) cout << "0";
            for (int j = 0; j < n - torre3[i]; ++j) cout << " ";
        } else {
            for (int j = 0; j < 2 * n + 1; ++j) cout << " ";
        }
        cout << endl;
    }
    cout << string(3 * (2 * n + 2), '-') << endl;
}

void moverDisco(int torreDesde[], int& alturaDesde, int torreHacia[], int& alturaHacia, int n) {
    int disco = torreDesde[alturaDesde - 1];
    alturaDesde--;
    torreHacia[alturaHacia] = disco;
    alturaHacia++;
    imprimirTorres(torreDesde, alturaDesde, torreHacia, alturaHacia, torreHacia, alturaHacia, n);
}

void hanoi(int n, int torre1[], int& altura1, int torre2[], int& altura2, int torre3[], int& altura3) {
    if (n == 1) {
        moverDisco(torre1, altura1, torre3, altura3, n);
    } else {
        hanoi(n - 1, torre1, altura1, torre3, altura3, torre2, altura2);
        moverDisco(torre1, altura1, torre3, altura3, n);
        hanoi(n - 1, torre2, altura2, torre1, altura1, torre3, altura3);
    }
}

int main() {
    int n;
    cout << "Ingrese el numero de discos a mover: ";
    cin >> n;

    int torre1[n], altura1 = n;
    int torre2[n], altura2 = 0;
    int torre3[n], altura3 = 0;

    for (int i = 0; i < n; ++i) {
        torre1[i] = n - i;
    }

    imprimirTorres(torre1, altura1, torre2, altura2, torre3, altura3, n);
    hanoi(n, torre1, altura1, torre2, altura2, torre3, altura3);

    return 0;
}


void resolver1(int torre1[], int torre2[], int torre3[], int n, int n2, int n3){
    if(torre1[n-1] < torre3[n3-1] || n2 == 0){
        torre3[n3] = torre1[n-1];
        torre2[n2] = torre1[n-2];
        torre2[n2+1] = torre3[n3];
        if(torre3[n3] < torre1[n-3]){
            torre1[n-2] = torre3[n3];
            imprimirtodo(torre1, torre2, torre3, n, n2, n3);
            resolver(torre3, torre1, torre2, n3-1, n-1, n2+2);
        }
        else{
            torre3[n3] = torre1[n-2];
            imprimirtodo(torre1, torre2, torre3, n, n2, n3);
            resolver(torre3, torre1, torre2, n3+1, n-3, n2+2);
        }
    }
}
void imprimirtodo(int torre1[], int torre2[], int torre3[], int n1, int n2, int n3, int n){
    cout << endl;
    for (int i = n - 1; i >= 0; --i) {
        if (i < n1)
            discos(torre1[i]);
        else
            discos(0);

        if (i < n2)
            discos(torre2[i]);
        else
            discos(0);

        if (i < n3)
            discos(torre3[i]);
        else
            discos(0);

        cout << endl;
    }
    
    cout << endl << "____________________________________________" << endl;
}