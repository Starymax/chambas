#include <iostream>
using namespace std;
int main(){
    int n1,n2,n3,m1,m2;
    cout<<"ingrese el primer numero";
    cin>>n1;
    cout<<"ingrese el primer numero";
    cin>>n2;
    cout<<"ingrese el primer numero";
    cin>>n2;
    m1=n1;
    if(n2>m1){
        m1=n2;
        if(n3>n2)
            m2=n3;
        else
            m2=n1;
    }
    else{
        if(n3>n2)
            m2=n3;
        else
            m2=n2;
    }
    cout<<"los numeros mayores son: "<<m1<<" y "<<m2;
    return 0
}