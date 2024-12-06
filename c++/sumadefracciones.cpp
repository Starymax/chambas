#include <iostream>
using namespace std;
int main(){
    float n,i,j,k;
    cin>>n;
    i=2;
    j=3;
    do{
        k=k+(i/j);
        i++;
        j++;
    }while(i<=n);
    cout<<k;
    
    return 0;
}