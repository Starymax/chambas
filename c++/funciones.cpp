#include <iostream>
using namespace std;

float getPromedio(int a[], int n){
    float suma=0;
    for(int i=0;i<n;i++)
        suma = suma+(a[i]);
    suma = suma/n;
    return suma;
}

int Orden(int a[],int n){
    int orden=1;
    for (int i=0;i<(n-2);i++){
        if(a[i]>a[i+1])
            orden= 0;
    }
    return orden;
}

int getPos(int a[],int n,int x){
    int posicion=-1;
    for(int i=0;i<n;i++){
        if (a[i]==x){
            posicion=i+1;
            return posicion;
        }
    }
    return posicion;
}

int main(){
    int n, i,x;
    cin>>n>>x;
    int a[n];
    i=0;
    while (i<n){
        cin>>(a[i]);
        i++;
    }
    cout<<"promedio"<<getPromedio(a,n)<<"\n";
    cout<<"orden"<<Orden(a,n)<<endl;
    cout<<"pos:"<<getPos(a,n,x);
    return 0;
}