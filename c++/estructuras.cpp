#include <iostream>
using namespace std;

struct Fecha{
    int d;
    int m;
    int a;
};

struct Estudiante{
    string matricula;
    string nombre;
    int calificacion;
    Fecha fn;
};

void leerEstudiantes(Estudiante a[], int n){
    for ( int i=0; i < n; i++){
        cout<<"Estudiante "<<i+1<<endl;
        cout<<"Matricula: ";
        cin>>a[i].matricula;
        cout<<endl<<"Nombre: ";
        cin>>a[i].nombre;
        cout<<endl<<"Calificacion: ";
        cin>>a[i].calificacion;
        cout<<endl<<"Fecha de cumpleaños"<<endl<<"Dia: ";
        cin>>a[i].fn.d;
        cout<<endl<<"Mes: ";
        cin>>a[i].fn.m;
        cout<<endl<<"Año: ";
        cin>>a[i].fn.a;
    }
}
int aniosEst(Estudiante a[], int)

int main(){
    Estudiante a[];
    int n;
    cout<<"Ingrese el numero de estudiantes: ";
    cin>>n;
    cout<<"Ingrese la fecha actual: ";
    cin>>
    leerEstudiantes(Estudiante a[],n);
    funcion
}