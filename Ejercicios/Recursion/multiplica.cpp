#include <iostream>

using namespace std;

int multiplica(int a, int b){
    int suma=0;
    if(b==0) return suma;
    if(b>0){
        suma+=a;
        suma+=multiplica(a, b-1);
    }
    else{
        suma-=a;
        suma+=multiplica(a, b+1);
    }
    return suma;
}

int main()
{
    cout<<multiplica(5,-2);
    return 0;
}
