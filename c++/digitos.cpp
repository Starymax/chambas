#include <iostream>
using namespace std;
int main(){
    int n,digito;
    cout<<"
    ingrese el numero";
    cin>>n;
    if(n<=9)
        digito=1;
    if(n>=10)
        digito=2;
    if(n>=100)
        digito=3;
    if(n>=1000)
        digito=4;
    cout<<n<<" tiene "<<digito<<" digitos.";
    return 0;
}