#include <iostream>

using namespace std;

void imprime_descendente(int n){
    if(n==0) return;
    cout<<n<<" ";
    imprime_descendente(n-1);
}

void imprime_ascendente(int n){
    if(n==0) return;
    imprime_ascendente(n-1);
    cout<<n<<" ";
}

int main()
{
    imprime_ascendente(12);
    return 0;
}
