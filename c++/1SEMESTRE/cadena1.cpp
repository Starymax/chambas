#include <iostream>
using namespace std;

string kesima(string cad,int k){
    string pal="";
    int i=0;
    j=1;
    while (j<k)&&(cad[i]!='\0'){
        if (cad[i]==' '){
            j++;
        }
        i++;
    }
    while(cad[i]!=' ')&&(cad[i]!='\0'){
        pal=pal+cad[i];
        i++;
    }
    return pal;
}

string ultima(string cad){
    string pal="";
    int lcad=longitud(cad)
    int i=lcad-1;
    while(cad[i-1]!=' ')&&(i>-1){
        i--;
    }
    for(int j=i;j<lcad;j++){
        pal=pal+cad[j];
    }
    return pal;
}