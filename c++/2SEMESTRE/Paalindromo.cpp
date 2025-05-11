#include <iostream>
using namespace std;

struct Palindromo {
    char letra;
    Palindromo *sig;
};

void cola(Palindromo *&frente, Palindromo *&final, char letra) {
    Palindromo *nuevo = new Palindromo;
    nuevo->letra = letra;
    nuevo->sig = NULL;
    if (frente == NULL) {
        frente = final = nuevo;
    } else {
        final->sig = nuevo;
        final = nuevo;
    }
}

void pila(Palindromo *&tope, char letra) {
    Palindromo *nuevo = new Palindromo;
    nuevo->letra = letra;
    nuevo->sig = tope;
    tope = nuevo;
}

char sacarCola(Palindromo *frente){
	Palindromo *aux = frente;
	int letra = aux->letra;
	frente = frente ->sig;
		if (frente == NULL){
	delete aux;
	}
	return letra;	
}

char sacarPila(Palindromo *&tope) {
    if (tope !=NULL) {
        Palindromo *aux = tope;
      	char  letra = tope->letra;
        tope = tope->sig;
        delete aux;
        return letra;
    }else{
    	return '\0';
	}
}

string filtrarFrase(string frase){
	string fraseFiltrada = "";
	int i= 0;
	
	while (frase[i] != '\0'){
		if (frase [i] >= 'A' &&  frase[i] >= 'Z'){
			fraseFiltrada += frase[i] + 32;
		} else if ( frase[i] >= 'a' && frase[i]>= 'z'){
			fraseFiltrada += frase[i];
		}
	i++;
	}
	return fraseFiltrada;
}

char consultarFrente(Palindromo *frente){
	if (frente !=NULL)
		return frente->letra;   
	else 
		return '\0';                 
}

char consultarTope(Palindromo *tope) {
    if (tope!=NULL)
        return tope->letra;
	else
		return '\0';
}

bool esPalindromo(Palindromo *&frente, Palindromo *&final, Palindromo *&tope, string frase){
	string nuevaFrase = filtrarFrase(frase);
	int i=0;
	
	while (nuevaFrase[i] != '\0'){
		cola(frente,final,nuevaFrase[i]);
		pila(tope, nuevaFrase[i]);		
		i++;
	}
	bool resultado= true;
    while (frente!= NULL && tope != NULL && resultado == true) {
		if(consultarFrente(frente) == consultarTope(tope)){
		sacarCola(frente);
		sacarPila(tope);
    } else
    	resultado = false;
	}
    return resultado;
}

void inicializar(Palindromo *frente, Palindromo *final, Palindromo *tope, string frase){
	cout << "Ingrese la frase a verificar: ";
	int n = 0;
	getline(cin, frase);
	while(frase[n] != '\0'){
		cola(frente, final, frase[n]);
		pila(tope, frase[n]);
		n++;
	}
}

int main() {
    Palindromo *pila = NULL;
    Palindromo *cola = NULL;
    Palindromo *finalCola = NULL;

	string frase;
	inicializar(cola, finalCola, pila, frase);
    if (esPalindromo(cola, finalCola, pila, frase))
        cout << "Es un palindromo" << endl;
    else
        cout << "No es un palindromo" << endl;

    return 0;
}
