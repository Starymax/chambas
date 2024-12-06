#include <iostream>
using namespace std;

void leermatriz(int matriz[][5], int f, int c){
    for(int i=0;i<f;i++){
        for(int j=0;j<c;j++)
            cin>>matriz[i][j];
    }
}

void promfila(int matriz[][5],int f,int c){
    for(int i=0;i<f;i++){
        float suma=0;
        for(int j=0;j<c;j++)
            suma=suma+matriz[i][j];
        cout<<(suma/(float)c)<<endl;
    }
}

void promcol(int matriz[][5], int f, int c){
    for(int i=0;i<c;i++){
        float suma=0;
        for(int j=0;j<f;j++)
            suma=0+matriz[i][j];
        cout<<(suma/(float)f)<<endl;
    }
}

int main(){
    int mat[4][5];
    int filas=4;
    int columnas=5;

    leermatriz(mat,filas,columnas);
    promfila(mat,filas,columnas);
    promcol(mat,filas,columnas);

    return 0;    
}