#include <iostream>
using namespace std;

int main(){
    cout << "ingrese el lado a";
    int a;
    cin>> a;
    cout<< "ingrese el lado b";
    int b;
    cin>> b;
    if(a == 0|| b == 0)
        cout << " ningun valor puede ser 0";
    else{
        cout << "el area es: " << a*b;
        if(a == b)
            cout << " y es un cuadrado";
    }
}