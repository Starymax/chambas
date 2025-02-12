#include <iostream>
using namespace std;
int main(){
    long long n1=1;
    long long n2=1;
    long long n3=1;
    long long i=2;
    cout<<n1<<", "<<n2<<", ";
    do{
        n3=n1+n2;
        cout<<n3<<", ";
        n1=n2;
        n2=n3;
        i++;
    }while(i<101);
}