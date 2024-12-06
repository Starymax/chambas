#include <iostream>
using namespace std;
int main(){
    int n,b,e,i;
    i=0;
    cin>>b;
    cin>>e;
    n=1;
    do{
        n=n*b;
        i=i+1;
    }while(i<e);
    cout<<n;
}