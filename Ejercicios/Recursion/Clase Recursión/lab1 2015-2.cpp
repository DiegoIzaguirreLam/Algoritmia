#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>

using namespace std;

void patron(int n, int i){
	int nAsterisk=pow(2, i);
	int j;
	if(nAsterisk==n){
		for(j=0;j<nAsterisk;j++) cout<<" * ";
		cout<<endl;
		return;
	}
	
	for(j=0;j<i;j++) cout<<"   ";
	for(j=0;j<nAsterisk;j++) cout<<" * ";
	cout<<endl;
	for(j=0;j<i;j++) cout<<"   ";
	for(j=0;j<nAsterisk+1;j++) cout<<" * ";
	cout<<endl;
	patron(n, i+1);
	for(j=0;j<i;j++) cout<<"   ";
	for(j=0;j<nAsterisk;j++) cout<<" * ";
	cout<<endl;
}


int main(){
	patron(8, 0);
	return 0;
}

