#include <iostream>
#include <math.h>
using namespace std;

int main(){
cout <<"programa cheverengue d figuritas :v" << endl << endl;

    int a;
    int b;
    int pesopluma;
    int opcion;
do{
cout << "1. Determinar figura"<<endl;
cout << "2. Calcular area y perimetro" << endl;
cout << "3. Salir";
cin >> opcion;
switch (opcion)
{
case 1:
    cout<< "ingrese el valor a";
    cin>> a;
    cout<< "ingrese el valor b";
    cin>> b;
    cout<< "ingrese el valor b";
    cin>> pesopluma;
    if(a == 0 && b == 0 && pesopluma == 0)
        cout<< "no ai figura" << endl;
    else {if(b == 0 && pesopluma == 0) 
        cout << "esun circulo" << endl;
    else{ if(a == b && pesopluma == 0)
        cout << "esun cuardado" << endl;
    else{ if(a != b && pesopluma == 0)
        cout << "esun rectangulo" << endl;
    else{ if(a == b && pesopluma == a)
        cout << "esun triangulo equilatero" << endl;
    else{ if(a == b || a == pesopluma || b == pesopluma){
        cout << "esun triangulo isosceles " << endl;
    }
    else{
        cout << "esun triangulo escaleno " << endl;
    }}}}}}
    break;
case 2:
    if(a == 0 && b == 0 && pesopluma == 0)
        cout<< "no ai figura" << endl;
    else {if(b == 0 && pesopluma == 0) 
        cout << "esun circulo de area: " << 3.1416 * a * a << " y de perimetro: " << 2 * 3.1416 * a << endl;
    else{ if(a == b && pesopluma == 0)
        cout << "esun cuardado de area: " << a * a<< " y de perimetro: " << ((a + b) * 2) << endl;
    else{ if(a != b && pesopluma == 0)
        cout << "esun rectangulo de area: " << a * b<< " y de perimetro: " << ((a + b)*2) << endl;
    else{ if(a == b && pesopluma == a)
        cout << "esun triangulo equilatero de area: " << ((pesopluma * pesopluma)/4 * 1.73)<< " y de perimetro: " << a + b + pesopluma << endl;
    else{ if(a == b || a == pesopluma || b == pesopluma){
        float x= (a + b + pesopluma) / 2;
        float area = sqrt(x*(x-a)*(x-b)*(x-pesopluma));
        cout << "esun triangulo isosceles de area: " << area<< " y de perimetro: " << a + b + pesopluma << endl;
    }
    else{
        float x= (a + b + pesopluma) / 2;
        float area = sqrt(x*(x-a)*(x-b)*(x-pesopluma));
        cout << "esun triangulo escaleno de area: "<< area<< " y de perimetro: " << a + b + pesopluma << endl;
    }}}}}}
    break;
    
case 3:
    cout << "hasta la proximaaa";
    break;
}}while (opcion != 3);
}