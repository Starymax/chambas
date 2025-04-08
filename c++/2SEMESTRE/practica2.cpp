#include <iostream>
using namespace std;

struct Poli{
    int coeficiente;
    int exponente;
    Poli *sig;
};

void insertar(Poli *&base, int exponente, int coeficiente, int n){
    if(base != NULL){
        if(base -> exponente < exponente && n == 1){
            Poli *nuevo = new Poli;
            nuevo->coeficiente = coeficiente;
            nuevo->exponente = exponente;
            nuevo->sig = base;
            base = nuevo;
        } else if(base -> exponente == exponente){
            base->coeficiente += coeficiente;
        } else if(base -> sig -> exponente < exponente){
            Poli *nuevo = new Poli;
            nuevo->coeficiente = coeficiente;
            nuevo->exponente = exponente;
            nuevo->sig = base->sig;
            base->sig = nuevo;
        } else
            insertar(base->sig, exponente, coeficiente, n+1);
    }
}

void imprimir(Poli *base, int n){
    if(base != NULL){
        if(base->coeficiente != 0){
            if(base->coeficiente > 0 && n > 1)
                cout << "+ " << base->coeficiente;
            else
                cout << base->coeficiente;
            if(base->exponente > 1)
                cout << 'x' << '^' << base->exponente << " ";
            else if(base->exponente == 1)
                cout << 'x';
        }
        imprimir(base->sig, n+1);
    } else
        cout << endl;
}

int evaluar(Poli *base, int x){
    if(base != NULL){
        int potencia = 1;
        for(int i = 0; i < base->exponente; i++){
            potencia *= x;
        }
        int resultado = potencia * base->coeficiente;
        return resultado + evaluar(base->sig, x);
    }
    return 0;
}

int main(){
    int n = 1;
    int exp, coef, x;
    Poli* base = new Poli{3, 4, new Poli{-4, 2, new Poli{11, 0, NULL}}};
    imprimir(base, n);
    cout << "Coeficiente: ";
    cin >> coef;
    cout << "Exponiente: ";
    cin >> exp;
    insertar(base, exp, coef, n);
    imprimir(base, n);
    cout << "Inserte valor de X: ";
    cin >> x;
    cout << evaluar(base, x) << endl;
    getchar();
    return 0;
}