#include <iostream>
using namespace std;
int main(){
    int n;
    cin>> n;
    if(n==0){
        cout<<n<<" no es par ni impar";
    }
    if(n%2==1){
        cout<<n<<" es impar";
    }
    else{
        cout<<n<<" es par";
    }
    return 0;
}