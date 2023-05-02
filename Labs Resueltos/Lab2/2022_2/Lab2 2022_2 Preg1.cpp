#include <iostream>
#define MAXF 8
#define MAXC 8
using namespace std;

int almacena(int M[][MAXC], int F, int C, int P, int fila, int a, int b){
	if(fila>=F){
		return 0;
	}
	if(a<0) a=0;
	if(b>=C) b=C-1;
	for(int i=a;i<=b;i++)
		if(M[fila][i]==0){
			M[fila][i]=5;
			P--;
			if(P==0) return 1;
		}
	almacena(M, F, C, P, fila+1, a-1, b+1);
}

int main(){
	int F, C, P;
	cout<<"Ingrese F, C y P: "<<endl;
	cin>>F>>C>>P;
	cout<<"Ingrese la matriz del anaquel (M): "<<endl;
	int M[MAXF][MAXC];
	for(int i=0;i<F;i++)
		for(int j=0;j<C;j++) cin>>M[i][j];
	int cumple;
	if(C%2!=0) cumple=almacena(M, F, C, P, 0, C/2, C/2);
	else cumple=almacena(M, F, C, P, 0, C/2 - 1, C/2);
	cout<<endl<<endl;
	for(int i=0;i<F;i++){
		for(int j=0;j<C;j++) cout<<M[i][j]<<" ";
		cout<<endl;
	}
	if(cumple)
		cout<<"Si es posible ordenar los productos"<<endl;
	else
		cout<<"No es posible utilizar este anaquel para la cantidad de productos solicitados"<<endl;
	return 0;
}

/*
5 5 16
0 0 0 0 0
0 0 0 0 0
0 0 0 1 0
0 1 0 0 0
0 0 0 0 0



6 6 27
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 1 0 0
0 1 0 0 0 0
0 0 0 0 1 0
0 0 0 0 0 0

datos en bruto:
C=6, F=6, P=27
		int M[][MAX]={{0,0,0,0,0,0},
				  {0,0,0,0,0,0},
				  {0,0,0,1,0,0},
				  {0,1,0,0,0,0},
				  {0,0,0,0,1,0},
				  {0,0,0,0,0,0}};*/



