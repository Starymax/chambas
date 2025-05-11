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
        inicializar(tope -> sig, frente -> sig);
    }
}

int contador(Palindromo *frente){
    if(frente == NULL)
        return 0;
    return 1 + contador(frente->sig);
}

bool esPalindromo(Palindromo *frente, Palindromo *tope, int n) {
    if (n <= 0)
        return true;
    if (frente->letra != tope->letra)
        return false;
    return esPalindromo(frente->sig, tope->sig, n - 1);
}


int main(){
    Palindromo *frente = NULL;
    Palindromo *tope = NULL;
    cout << "ingrese la palabra y termine con un punto '.':" << endl;
    inicializar(tope, frente);
    if (esPalindromo(frente, tope, contador(frente)/2))
        cout << "sies palindromo" << endl;
    else
        cout << "noes palindromo" << endl;
    return 0;
}