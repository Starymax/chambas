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
        frente = aux;
        aux -> sig = tope;
        tope = aux;
        inicializar(tope, frente -> sig);
    }
}

int contador(Palindromo *frente){
    return 1 + contador(frente->sig);
}

void esPalindromo(Palindromo *&frente, Palindromo *&tope, int n){
    if(n>0){
        if(frente -> letra != tope -> letra){
            cout << "no es palindrom";
        }
        else{
            cout << frente -> letra;
            cout << tope -> letra;
            Palindromo *aux = frente;
            frente = frente->sig;
            delete aux;
            aux = tope;
            tope = tope -> sig;
            delete aux;
            esPalindromo(frente, tope, n-1);
        }
    } else{
        cout << "sies palindromo";
    }
}

int main(){
    Palindromo *frente = NULL;
    Palindromo *tope = NULL;
    inicializar(tope, frente);
    esPalindromo(frente, tope, contador(frente)/2);
    return 0;
}