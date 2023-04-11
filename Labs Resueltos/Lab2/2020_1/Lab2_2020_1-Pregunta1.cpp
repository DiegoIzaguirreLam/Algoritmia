
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#define MAXCOL 10

using namespace std;

int recorrido(int x, int y, int matriz[][MAXCOL], int L, int R, int T, int B){
	int cuenta=0;
	if(L==R or T==B){
		cout<<matriz[T][L]<<endl;
		return cuenta+1;
	}
	int i;
	for(i=L; i<R; i++){
		cout<<matriz[T][i]<<" ";
		cuenta++;
	}
	//cout<<endl;
	for(i=T; i<B; i++){
		cout<<matriz[i][R]<<" ";
		cuenta++;
	}
	//cout<<endl;
	for(i=R; i>L; i--){
		cout<<matriz[B][i]<<" ";
		cuenta++;
	} 
	//cout<<endl;
	for(i=B; i>T; i--){
		cout<<matriz[i][L]<<" ";
		cuenta++;
	}
	//cout<<endl;
	cuenta=cuenta+recorrido(x+1, y+1, matriz, L+1, R-1, T+1, B-1);
	return cuenta;
}

int main(){
	int n=5, m=5, matriz[][MAXCOL]={{1, 2, 3, 4, 5},
									{16, 17, 18, 19, 6},
									{15, 24, 25, 20, 7},
									{14, 23, 22, 21, 8},
									{13, 12, 11, 10, 9}};
	int L=0, R=n-1, T=0, B=m-1;
	cout<<"Total de monticulos encontrados: "<<recorrido(0, 0, matriz, L, R, T, B);
	return 0;
}


