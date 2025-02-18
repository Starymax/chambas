#include <iostream>
using namespace std;

int serie1(int n){
    if(n > 0)
        cout << n << " ";
    return serie1(n-1);
}

void serie2(int n){
    if(n > 99)
        cout << n << " ";
    else{
        cout << n << " ";
        serie2(n + 1);
    }
}

void serie3(int n, int i = 1){
    if(i <= n){
        cout << i << " ";
        serie3(n, i + 1);
    }
}

long factorial (int n){
        if(n == 0 || n == 1)
            return 1;
        else
            return n * factorial(n-1);
}

long potencia(int b, int e){
    if(e == 0)
        return 1;
    if(e == 1)
        return b;
    else
        return b * potencia(b, e - 1);
}

int digitos(long n){
    if(n < 10)
        return 1;
    else
        return digitos(n/10) + 1;
}

int main(){
    cout << potencia(5,3);
    cout << digitos(564611);
}