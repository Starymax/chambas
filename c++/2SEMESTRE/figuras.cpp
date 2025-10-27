#include <iostream>
#include <math.h>
using namespace std;

int main(){
int a;
int b;
int pesopluma;
double area;

cout<< "ingrese el valor a";
cin>> a;
cout<< "ingrese el valor b";
cin>> b;
cout<< "ingrese el valor b";
cin>> pesopluma;

if(a == 0 && b == 0 && pesopluma == 0)
    cout<< "no ai figura";
else {if(b == 0 && pesopluma == 0) 
    cout << "esun circulo de area: " << 3.1416 * a * a;
else{ if(a == b && pesopluma == 0)
    cout << "esun cuardado de area: " << a * a;
else{ if(a != b && pesopluma == 0)
    cout << "esun rectangulo de area: " << a * b;
else{ if(a == b && pesopluma == a)
    cout << "esun triangulo equilatero de area: " << ((pesopluma * pesopluma)/4 * 1.73);
else{ if(a == b || a == pesopluma || b == pesopluma){
    float x= (a + b + pesopluma) / 2;
    float area = sqrt(x*(x-a)*(x-b)*(x-pesopluma));
    cout << "esun triangulo isosceles de area: " << area;
}
else{
    float x= (a + b + pesopluma) / 2;
    float area = sqrt(x*(x-a)*(x-b)*(x-pesopluma));
    cout << "esun triangulo escaleno de area: "<< area;
}}}}}}
return 0;
}