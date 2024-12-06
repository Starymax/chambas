#include <iostream>
using namespace std;
int main(){
    int año;
    cout<<"Ingrese el año: ";
    cin>>año;
    if(año%4==0)
        cout<<"El año "<<año<<" es bisiesto";
    else
        cout<<"El año "<<año<<" no es bisiesto";
    return 0;
}