#include <iostream>
#define MAX 10

using namespace std;

void carga(int x, int y, int n, int m, int alma[][MAX]){
	if(x>=n || y>=m) return;
	if(x==n-1 && y==n-1) cout<<alma[x][y];
	for(int i=y;i<m-1;i++) cout<<alma[x][i]<< " ";
	for(int i=x;i<n-1;i++) cout<<alma[i][m-1]<< " ";
	for(int i=m-1;i>y;i--) cout<<alma[n-1][i]<< " ";
	for(int i=n-1;i>x;i--) cout<<alma[i][y]<< " ";
	carga(x+1,y+1,n-1,m-1,alma);
}

int main(){
	int alma[MAX][MAX]={             {1,  2,  3,  4, 5},
									{16, 17, 18, 19, 6},
									{15, 24, 25, 20, 7},
									{14, 23, 22, 21, 8},
									{13, 12, 11, 10, 9}};
	int n=5,m=5,cont=1;
	
	/*for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			alma[i][j]=cont++;*/
	carga(0,0,n,m,alma);
	return 0;
}
