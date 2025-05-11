#include <iostream>
using namespace std;

struct Palindromo{
    char letra;
    Palindromo *sig;
};

void inicializar(Palindromo *&tope, Palindromo *&frente){
    char letra;
    char fin = '.';
    cin>>letra;
    if(letra != fin){
        Palindromo *aux = new Palindromo;
        aux -> letra = letra;
        aux -> sig = NULL;
        if(frente == NULL)
            frente = aux;
        else
            aux -> sig = tope;
        tope = aux;
        inicializar(tope, frente -> sig);
    }
}

void imprimir(Palindromo *frente){
    cout<< frente -> letra;
    imprimir(frente-> sig);
}

int contador(Palindromo *frente){
    if(frente == NULL)
        return 0;
    return 1 + contador(frente->sig);
}

void esPalindromo(Palindromo *frente, Palindromo *tope, int n, int valor){
    if (frente->letra == tope->letra)
        valor = 0;
    esPalindromo(frente->sig, tope->sig, n - 1, valor);
}


int main(){
    Palindromo *frente = NULL;
    Palindromo *tope = NULL;
    int valor = 1;
    cout << "ingrese la palabra y termine con un punto '.':" << endl;
    inicializar(tope, frente);
    imprimir(frente);
    imprimir(tope);
    esPalindromo(frente, tope, contador(frente)/2, valor);
    if(valor == 1)
        cout << "sies palindromo" << endl;
    else
        cout << "noes palindromo" << endl;
    getchar();
    return 0;
}