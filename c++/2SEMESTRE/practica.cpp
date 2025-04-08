#include <iostream>
using namespace std;

struct Alumno{
    string nombre;
    float calif;
    Alumno *sig;
};

void mover(Alumno *todos, Alumno *&lista1, Alumno *&lista2){
    if(todos !=NULL){
        if(todos -> calif >= 6 && todos -> calif < 7){
            Alumno  *nuevo = new Alumno;
            nuevo->calif = todos->calif;
            nuevo->nombre = todos->nombre;
            nuevo->sig = NULL;
            lista1 = nuevo;
            mover(todos -> sig, lista1 -> sig, lista2);
        } else {
            if(todos -> calif < 6 && todos -> calif >= 4){
                Alumno *nuevo = new Alumno;
                nuevo->calif = todos->calif;
                nuevo->nombre = todos->nombre;
                nuevo->sig = NULL;
                lista2 = nuevo;
                mover(todos -> sig, lista1, lista2 -> sig);
        }
        mover(todos -> sig, lista1, lista2);
        }
    }
}

void imprimir(Alumno *lista) {
	if (lista != NULL) {
		cout << lista->nombre << ": " << lista->calif << " ";
		imprimir(lista->sig);
	}
	else
		cout << endl;
}

int main(){
    Alumno *lista1 = NULL;
    Alumno *lista2 = NULL;
    Alumno *todos = new Alumno{
        "Carlos", 4.9, new Alumno{
        "DavidSeñor", 2.3, new Alumno{
        "Denis", 8.5, new Alumno{
        "EmiMorales", 6.3, new Alumno{
        "Fernando", 6.9, new Alumno{
        "Guicho", 4.2, new Alumno{
        "Isabel", 5.1, new Alumno{
        "Javier", 7.8, new Alumno{
        "Lucía", 3.5, new Alumno{
        "Marlen", 5.7, new Alumno{
        "Oswaldo", 3.8, new Alumno{
        "Pepo", 6.6, new Alumno{
        "Roberto", 5.6, new Alumno{
        "Ulises", 7.5, new Alumno{
        "Valentin", 6.0, NULL
    }}}}}}}}}}}}}}};

    mover(todos, lista1, lista2);
    cout << "Calificaciones entre 6 y 7:" << endl;
    imprimir(lista1);
    cout << "Calificaciones entre 4 y 6:" << endl;
    imprimir(lista2);
    getchar();
    return 0;
}