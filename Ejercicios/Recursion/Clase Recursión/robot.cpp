
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAXCOL 3

using namespace std;

int robot(int x, int y, int n, int m, int tablero[][MAXCOL]){
	int derecha=-999999, abajo=-999999;
	if(x==n-1 && y==m-1)
		return tablero[n-1][m-1];
	if(y+1<m)
		derecha=robot(x, y+1, n, m, tablero);
	if(x+1<n)
		abajo=robot(x+1, y, n, m, tablero);
	return max(derecha, abajo)+tablero[x][y];
}


int main(){
	int n=3, m=3;
	int tablero[][MAXCOL]={{3,-2,4},
					{1,8,3},
					{4,4,2}};
	
	cout << robot(0,0,n,m,tablero);	
	return 0;
}




