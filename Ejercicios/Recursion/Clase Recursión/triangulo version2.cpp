
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


void imprime(int ini, int fin){
	if(ini>=fin) return;
	cout<<" * ";
	imprime(ini+1, fin);
}

void triangulo(int a, int b){
	int i;
	if(a>b) return;
	imprime(0, a);
	cout<<endl;
	triangulo(a+1, b);
	imprime(0, a);
	cout<<endl;
}

int main(){
	triangulo(3, 5);
	return 0;
}




