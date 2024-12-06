#include <iostream>
using namespace std;

void leermatriz(int matriz[][3], int f, int c){
    for(int i=0;i<f;i++){
        for(int j=0;j<c;j++)
            cin>>matriz[i][j];
    }
}

void multMatriz(int a[][3],int b[][3],int c[][3],int m,int n,int p){
    for(int i = 0; i < c; i++){
        for(int j = 0; j < f; j++){
            int suma = 0;
            for(int k = 0; k < n; k++){
                suma+= a[i][k]*b[k][j];
            }
            c[i][j]= suma;
        }
    }
}

void imp()