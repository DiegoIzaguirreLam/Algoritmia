
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;




int main(){
	int n=5;
	
	cout<<factorial(5);
	return 0;
}



int factorial(int n){
	if(n==0) return 1;
	return n*factorial(n-1);
}
