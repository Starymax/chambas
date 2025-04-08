#include <iostream>
using namespace std;

struct Alumno{
    float calif;
    string nombre;
    Alumno *sig;
};

void mover(Alumno *todos, Alumno *&lista1, Alumno *&lista2){
    if(todos !=NULL){
        if(todos -> calif >= 6 || todos -> calif < 7){
            Alumno *lista1 = new Alumno;
            lista1 -> calif = todos -> calif;
            lista1 -> nombre = todos -> nombre;
            lista1 -> sig = NULL;
            mover(todos -> sig, lista1 -> sig, lista2);
        } else {
            if(todos -> calif < 6 || todos -> calif >= 4){
                Alumno *lista2 = new Alumno;
                lista2 -> calif = todos -> calif;
                lista2 -> sig = NULL;
                mover(todos -> sig, lista1, lista2 -> sig);
            }
        }
    }
}   

void imprimir(Nodo *lista) {
	if (lista != NULL) {
		cout << lista->nombre << ": " << lista->calif << " ";
		imprimir(lista->siguiente);
	}
	else
		cout << endl;
}

int main(){
    Alumno *lista1 = NULL;
    Alumno *lista2 = NULL;
    Alumno *todos;
}