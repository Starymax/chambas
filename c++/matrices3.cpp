#include <iostream>
using namespace std;

void leermatriz(int matriz[][5], int f, int c){
    for(int i=0;i<f;i++){
        for(int j=0;j<c;j++)
            cin>>matriz[i][j];
    }
}

int esSimetrica(int matriz[][5], int n){
    int simetria=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i-1;j++){
            if(matriz[i][j]!=matriz[j][i])
                simetria=0;
        }
    }
    return simetria;
}

void interExtremos(int matriz[][5], int f,int c){
    for(int i=0;i<c;i++){
        int aux=matriz[0][i];
        matriz[0][i]=matriz[f-1][i];
        matriz[f-1][i]=aux;
    }
}

int esIdentidad(int matriz[][5],int n){
    int bandera=1;
    int i,j=0;
    while(i<n&&bandera==1){
        while(j<n&&bandera==1){
            if(i!=j&&matriz[i][j]!=0){
                bandera=0;
            }
            else{
                if(i==j&&matriz[i][j]!=1){
                    bandera=0;
                }
            }
            j++;
        }
        i++;
        j=0;
    }
    return bandera;
}

int main(){
    int mat[5][5];
    int filas=5;
    int columnas=5;
    int n=5;

    leermatriz(mat,filas,columnas);
    cout<<esSimetrica(mat,n);
    return 0;    
}