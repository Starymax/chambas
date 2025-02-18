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
        serie2(n + 1)
    }
}

void serie3(int n, int i = 1){
    if(i > n)
        cout << i;
    else{
        cout << i << " ";
        serie3(n, i + 1);
    }
}

long factorial (int n){
        if(n == 0 || N == 1)
            return 1;
        else
            return n * factorial(n-1);
    }
    int main(){
        serie3(7)
}