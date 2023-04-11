#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

void cargabin(int num, int n, int cromo[]){
	int i, res;
	for(int i=0;i<n;i++)cromo[i]=0;
	i=0;
	while(num>0){
		res = num%2;
		num = num/2;
		cromo[i]=res;
		i++;
	}
}



int main(){
	int salario[]={2560, 3040, 3520}, salariohora[]={16,19,22};
	
	
	return 0;
}
