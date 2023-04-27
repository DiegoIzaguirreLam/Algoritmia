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


int busca(int x, int y, int xm, int ym, int n, int m, int x1, int y1){
	int cont=0;
	if(x>=n || y>=m || x<0 || y<0){
		return cont;
	}
	if(x1==0 && y1==0) cont+=mapa[x][y];
	if(x1==0){
		for(int i=x-1;i>=0;i--)	cont+=mapa[i][y];
		for(int i=x+1;i<n;i++)	cont+=mapa[i][y];
	}
	if(y1==0){
		for(int i=y+1;i<m;i++)	cont+=mapa[x][i];
		for(int i=y-1;i>=0;i--)	cont+=mapa[x][i];
	}
	cont+=busca(x+xm,y+ym,xm,ym,n,m,xm,ym);
	
	return cont;
}



int main(){
	int n=6,m=6;
	
	cout<<busca(0, 0, 0, 1, n, m, 0, 0)<<endl;
	return 0;
}
