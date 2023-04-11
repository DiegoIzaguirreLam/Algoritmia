#include <iostream>

using namespace std;

int potencia(int a, int b){
    int producto=1;
    if(b==0) return producto;
    producto=producto*a;
    producto=producto*potencia(a, b-1);
    return producto;
}

int main()
{
    cout<<potencia(2,4);
    return 0;
}

