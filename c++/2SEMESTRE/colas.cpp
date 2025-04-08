#include <iostream>
using namespace std;

struct Nodo {
	int elemento;
	Nodo *siguiente;
};

Nodo *crearNodo(int elemento){
	Nodo *ap=new Nodo;
	ap->elemento=elemento;
	ap->siguiente=NULL;
	return ap;
}
void imprimir(Nodo *frente) {
	if (frente!=NULL) {
		cout << frente->elemento << " ";
		imprimir(frente->siguiente);
	}
	else
		cout << endl;
}

void inicializar(Nodo *&frente, Nodo *&final){
	frente = NULL;
	final = NULL;
}

bool vacia(Nodo *frente){
	if  (frente == NULL)
		return true;
	else 
		return false;
}

int consultarFrente(Nodo *frente, int elemento){
	if (!vacia(frente)){
		return frente->elemento;
}     
	else {
		return -1;                 
	}
}

int sacar(Nodo *&frente){
	Nodo *aux = frente;
	int elemento = aux->elemento;
	frente = frente ->siguiente;
		if (frente == NULL){
	delete aux;
	}
	return elemento;	
}

void agregar(Nodo *&frente, Nodo *&final, int elemento){
	Nodo *aux= new Nodo;
	aux = crearNodo(elemento);
	if(final == NULL){
		frente = aux;
	}else {
		final -> siguiente = aux;
	}
		final = aux;
}

// Realice una función que regrese el número de elementos de una cola //

int cantidadElementos(Nodo *frente){
	if(vacia(frente)){
		return 0;
	}
	return 1 + cantidadElementos(frente -> siguiente); 
}

// Realice una función que indique si la cola está llena. Deberá definir un tope y consultar el número de elementos. //

bool colaLlena(Nodo *frente, int tope){
	if(cantidadElementos(frente) == tope)
		return true;
	else 
		return false;
}

//Crear un procedimiento que vacíe la cola//

void vaciarCola(Nodo *&frente){
    if (frente != NULL){
		sacar(frente);
		vaciarCola(frente);
	}
}

int main(){
	Nodo *frente;
    Nodo *final;
    inicializar(frente, final);
	int tope = 4;
    agregar(frente, final, 5);
    agregar(frente, final, 10);
    agregar(frente, final, 12);
	agregar(frente, final, 16);
    cout << "Elementos en la cola:";
    imprimir(frente);
    int elemento;
  	cout << "Numero de cantidadElementos: "<< cantidadElementos(frente)<<endl;

	  if(colaLlena(frente, tope)){
		cout << "La cola esta llena" << endl;
	}
	else
		cout << "La cola no esta llena" << endl;
  	
  	cout << "Elemento: " << sacar(frente) << endl;
  	cout << "Elemento: " << sacar(frente) << endl;
	 imprimir(frente) ;
  	cout<<"Numero de cantidadElementos: "<< cantidadElementos(frente)<<endl;
  	
  
	if(colaLlena(frente, tope)){
		cout << "La cola esta llena" << endl;
	}
	else
		cout << "La cola no esta llena" << endl;
  	
	vaciarCola(frente);
  	cout << "El contenido de la cola es: " << cantidadElementos(frente);

	getchar();
    return 0;
}