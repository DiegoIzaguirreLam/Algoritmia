
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


void triangulo(int a, int b){
	int i;
	
	if(a>b) return;
	
	for(i=0;i<a;i++) cout<<" * ";
	cout<<endl;
	triangulo(a+1, b);
	for(i=0;i<a;i++) cout<<" * ";
	cout<<endl;
}

int main(){
	triangulo(3, 5);
	return 0;
}




