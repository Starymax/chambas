#include <iostream>
using namespace std;
int main(){
    int suma,n,i,c;
    suma=0;
    n=0;
    cin>>n;
    i=0;
    while(i<n){
        cin>>c;
        if(c>=6){
            suma=suma+c;
            n=n+1;
        }
        i=i+1;
    }
    if (n=0){
        cout<<"no se puede";
    }
    else{
        cout<<(suma/n);
    }
}