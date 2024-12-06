#include <iostream>
using namespace std;

void leermatriz(int matriz[][5], int f, int c){
    for(int i=0;i<f;i++){
        for(int j=0;j<c;j++)
            cin>>matriz[i][j];
    }
}

void getmatiden(int matriz[][5],int n){
    for(int i=0;i<n;i++){
        for(int j;j<n;j++){
            if(i=j)
                matriz[i][j]=1;
            else
                matriz[i][j]=0;
        }
    }
}