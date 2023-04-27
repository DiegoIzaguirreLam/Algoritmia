
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void imprime(int inicio, int fin){
	if(inicio>=fin) return;
	cout<<" * ";
	imprime(inicio+1, fin);
}

void triangulo(int a, int b){
	if(a>b) return;
	int i;
	for(i=0;i<b;i++) cout<<" * ";
	cout<<endl;
	triangulo(a, b-1);
	for(i=0;i<b;i++) cout<<" * ";
	cout<<endl;
}

int main(){
	triangulo(3,5);
	return 0;
}


