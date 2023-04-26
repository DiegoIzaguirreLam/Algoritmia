#include <iostream>
#define MAXFIL 6
#define MAXCOL 6
using namespace std;

int alma[][MAXCOL]={{1,2,9,1,2,3},
					{5,1,7,0,2,1},
					{0,7,0,3,8,1},
					{1,2,6,1,2,2},
					{0,6,9,5,0,5},
					{0,0,4,0,9,0}};


int recorre_row(int row, int i, int m){
	if(i==m-1) return 0;
	return recorre_row(row, i+1, m) + alma[row][i];
}

int recorre_col(int col, int i, int n){
	if(i==n) return 0;
	return recorre_col(col, i+1, n) + alma[i][col];
}

int busca(int n, int m, int row, int col){
	if(row == n-1){
		return 0;
	}
	int cont=0;
	cont = recorre_row(row, 0, m) + recorre_col(m-1, row, n);
	/*for(int i=0;i<m-1;i++){
		cont+=alma[row][i];
	}
	for(int j=row;j<n;j++){
		cont+=alma[j][m-1];
	}*/
	return max(cont, busca(n,m-1,row+1,col));
}

int revisa(int valor, int pedido[], int p, int i){
	if(i==p) return 0;
	if(valor==pedido[i]){
		pedido[i]=0;
		return 1;
	}
	revisa(valor, pedido, p, i+1);
}

int atiende(int n, int m, int row, int col, int pedido[], int p){
	if(row == n-1){
		return 0;
	}
	int aux[p], conth=0, contv=0, flag=0;
	for(int i=0;i<p;i++) aux[i]=pedido[i];
	
	for(int i=0;i<m-1;i++)
		if(alma[row][i]!=0)
			conth+=revisa(alma[row][i], aux, p, 0);
	for(int i=row;i<n;i++)
		if(alma[i][m-1]!=0)
			contv+=revisa(alma[i][m-1], aux, p, 0);
	if(conth + contv == p)
		flag = 1;
	if(flag || atiende(n, m-1, row+1, col, pedido, p))
		return 1;
	return 0;
}


int main(){
	int n=6, p=3, pedido[]={2,7,2};
	cout << busca(n, n, 0, 0)<<endl;
	cout << atiende(n, n, 0, 0, pedido, p);
	return 0;
}
