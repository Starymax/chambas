#include <iostream>
using namespace std;
int main(){
    int n;
    do{
        cout<<"Ingrese un numero: ";
        cin>>n;
    }while(n<1 or n>5);
    return 0;
}