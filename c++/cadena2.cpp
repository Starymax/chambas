#include <iostream>
using namespace std;

string iniciales(string cad){
    string ini="iniciales: ";
    ini= ini + cad[0];
    int i = 1;
    while(cad[i]!='\0'){
        if (cad[i]==' '){
            ini=ini+cad[i+1];
        }
        i++;
    }
    return ini;
}

void vocales(string cad){
    string a="a: ";
    string e="e: ";
    string i="i: ";
    string o="o: ";
    string u="u: ";
    int k = 0;
    while (cad[k]!='\0'){
        if (cad[k]=='a')
            a=a+'*';
        if (cad[k]=='e')
            e=e+'*';
        if (cad[k]=='i')
            i=i+'*';
        if (cad[k]=='o')
            o=o+'*';
        if (cad[k]=='u')
            u=u+'*';
        k++;
    }
    cout<<a<<endl;
    cout<<e<<endl;
    cout<<i<<endl;
    cout<<o<<endl;
    cout<<u<<endl;
}

int main(){
    string cadena = "";
    getline(cin,cadena);
    cout<<iniciales(cadena)<<endl;
    vocales(cadena);
    return 0;
}