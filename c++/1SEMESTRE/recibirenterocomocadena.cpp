#include <iostream>
using namespace std;


int longitud(string a){
    int i = 0;
    while (a[i] != '\0')
        i++;
    return i;
}

int recibirentero() {
    string entero;
    char h;
    int ent = 0;
    bool band2 = false;
    while (band2 == false){
        bool band = false;
        cin>>entero;
        for (int i = 0; i < longitud(entero); i++){
            h = entero[i];
            if((h < '0' || h > '9') || h == '-'){
                band = true;
            }
        }
        if(band == true)
            cout<<"Ingrese una cantidad valida."<<endl;
        else{
            for(int i = 0; i < longitud(entero); i++){
                h = entero[i];
                ent = ent * 10 + (h - '0');
            }
            band2 = true;
        }
    }
    return ent;
}

int main(){
    string entero;
    int ent;
    ent = recibirentero();
    cout<<ent;

    return 0;
}