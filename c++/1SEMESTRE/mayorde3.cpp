#include <iostream>

using namespace std;
int main(){
    int n1,n2,n3,mayor;
    cin>>n1;
    cin>>n2;
    cin>>n3;
    mayor = n1;
    if(n2>mayor){
                  mayor = n2;
                  }
    if(n3>mayor){
                  mayor = n3;
                  }
    cout<<"el numero mayor es "<<mayor;
    return 0;
}