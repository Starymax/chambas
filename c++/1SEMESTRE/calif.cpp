#include <iostream>
using namespace std;
int main(){
    int nAp,c,sumaAp;
    sumaAp=0;
    nAp=0;
    cin>>c;
    while (c>-1){
        if (c>=6){
            sumaAp=sumaAp+c;
            nAp=nAp+1;
        }
        cin>>c;
        }
    if (nAp=0)
        cout<<"no se puede dividir entre 0";
    else{
        cout<<(sumaAp/nAp);
    }
    return 0;
}