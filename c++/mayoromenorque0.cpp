#include <iostream>
using namespace std;
int main(){
    float n;
    cin>> n;
    if(n==0)
        cout<<"Es cero";
    else
        if(n<0)
            cout<<"Es negativo";
        else
            cout<<"Es positivo";
    return 0;
}
