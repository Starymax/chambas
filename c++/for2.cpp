#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=n;i>=1;i=i-1){
        for(int j=1;j<=(n-i+1);j++)
            cout<<i;
    cout<<endl;
    }
}