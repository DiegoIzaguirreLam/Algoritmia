#include <iostream>

using namespace std;

int MCD(int m, int n){
    int divisor;
    if(n<=m && m%n==0){
        return n;
    }
    if(n>m){
        divisor=MCD(n, m);
    }
    divisor=MCD(n,m%n);
    return divisor;
}

int main()
{
    cout<<MCD(12,4);
    return 0;
}
