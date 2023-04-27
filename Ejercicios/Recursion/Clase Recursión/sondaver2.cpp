#include <iostream>
#define MAX 10
//lab 2 2020_2
using namespace std;

int mapa[][6]={{0,0,0,1,0,1},
				{0,0,1,0,0,0},
				{0,1,0,0,0,1},
				{1,0,0,0,0,0},
				{0,1,0,0,0,0},
				{0,0,0,0,1,0}};


int busca(int x, int y, int xm, int ym, int n, int m, int indicaprimer){
	int cont=0;
	if(x>=n || y>=m || x<0 || y<0){
		return cont;
	}
	if(indicaprimer==1) cont+=mapa[x][y];
	if(indicaprimer==1){
		for(int i=x-1;i>=0;i--)	cont+=mapa[i][y];
		for(int i=x+1;i<n;i++)	cont+=mapa[i][y];
		for(int i=y+1;i<m;i++)	cont+=mapa[x][i];
		for(int i=y-1;i>=0;i--)	cont+=mapa[x][i];
	}
	else{
		if(xm!=1){
			for(int i=x-1;i>=0;i--)	cont+=mapa[i][y];
			for(int i=x+1;i<n;i++)	cont+=mapa[i][y];
		}
		if(ym!=1){
			for(int i=y+1;i<m;i++)	cont+=mapa[x][i];
			for(int i=y-1;i>=0;i--)	cont+=mapa[x][i];
		}
	}
	
	cont+=busca(x+xm,y+ym,xm,ym,n,m,0);
	
	return cont;
}



int main(){
	int n=6,m=6;
	
	cout<<busca(0, 0, 0, 1, n, m, 1)<<endl;
	return 0;
}
