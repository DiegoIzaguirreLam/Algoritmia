#include <iostream>
#define MAXFIL 10
#define MAXCOL 9

using namespace std;

int encuentraMax(int D, int dia,int P,int paq[][MAXCOL], int col, int *colMax, int flagprimer){
	if(col==P) return 0;
	int maxAnt=encuentraMax(D,dia,P,paq,col+1, colMax,0);
	int valor;
	if(paq[dia][col]>maxAnt){
		(*colMax)=col;
	}
	if(flagprimer){
		valor=paq[dia][*colMax];
		paq[dia][*colMax]=0;
		return valor;
	}
	else{
		return paq[dia][*colMax];
	}
}

void pintaDia(int D, int dia, int P, int paq[][MAXCOL], int res[][MAXCOL], int i, int npinta){
	if(i == npinta) return;
	int colMax=0, valor;
	valor=encuentraMax(D,dia,P,paq,0,&colMax,1);
	res[dia][i]=valor;
	pintaDia(D, dia, P, paq, res, i+1, npinta);
}

void pinta(int M,int N,int D,int P, int paq[][MAXCOL], int res[][MAXCOL], int dia, int npinta, int flag){
	if(dia==M) return;
	int colMax;
	pintaDia(D, dia, P, paq, res, 0, npinta);
	if(npinta<M && flag==0) pinta(M, N, D, P, paq, res, dia+1, npinta+1, 0);
	else if(npinta == M && flag==0)	pinta(M, N, D, P, paq, res, dia+1, npinta, 1);
	else if( npinta > N && flag==1)	pinta(M, N, D, P, paq, res, dia+1, npinta-1, 1);
	else if( npinta == N ) pinta(M, N, D, P, paq, res, dia+1, npinta, 2);
}


int main(){	
	int M=8, I=6, N=4, D=10, P=9, colMax;
	int paq[][MAXCOL]={{1,2,3,4,5,6,7,8,0},
						{1,2,3,4,5,6,7,8,1},
						{1,2,3,4,5,6,7,8,2},
						{1,2,3,4,5,6,7,8,3},
						{1,2,3,4,5,6,7,8,4},
						{1,2,3,4,5,6,7,8,5},
						{1,2,3,4,5,6,7,8,6},
						{1,2,3,4,5,6,7,8,7},
						{1,2,3,4,5,6,7,8,8},
						{1,2,3,4,5,6,7,8,9}};
	int res[D][MAXCOL]={};
	pinta(M, N, D, P, paq, res, 0, I, 0);
	for(int i=0;i<D;i++){
		for(int j=0;j<P;j++){
			if(res[i][j]!=0)
				cout << res[i][j] << " ";
		}
		cout<<endl;
	}
	return 0;
}
