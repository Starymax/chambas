#include <iostream>
using namespace std;
int main(){
    int i,n,x;
    cout<<"Ingrese el numero final: ";
    cin>>x;
    i=0;
    do{
        cout<<"Ingrese sus numeros: ";
        cin>>n;
        i++;
    }while(n!=x);
    cout<<"La posicion de su numero es: "<<i;
    return 0;
}