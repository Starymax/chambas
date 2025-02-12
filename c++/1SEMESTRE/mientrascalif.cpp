#include <iostream>
using namespace std;
int main(){
    int n,c;
    n=0;
    cin>>c;
    while(c>-1){
        n=n+1;
        cin>>c;
    }
    cout<<n;
    return 0;
}
