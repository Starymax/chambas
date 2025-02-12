#include <iostream>
using namespace std;
int main(){
    int n,i,j;
    cin>>n;
    i=n;
    j=2;
    cout<<n<<" = ";
    do{
        if((i%j)==0){
            i=(i/j);
            cout<<j;
                if(i!=1)
                    cout<<"x";
        }
        else
            j++;
    }while(i!=1);

    return 0;
}
