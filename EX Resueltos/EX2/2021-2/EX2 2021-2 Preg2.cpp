
#include <iostream>
#include <cmath>
#define col 4
#define fil 4
using namespace std;

int calcula(int x, int y, int valor, int alma[][col]){
	if(x<=0 || y<=0) return 999999;
	return abs(valor-alma[x-1][y-1]);
}

int vuelodron(int alma[][col],int x,int y){
	int dp[fil+1][col+1];
	int dia, izq, arr;
	for(int i=0;i<=fil;i++) dp[i][0]=0;
	for(int i=0;i<=col;i++) dp[0][i]=0;
	
	for(int i=1;i<=fil;i++){
		for(int j=1;j<=col;j++){
			if(i==1 && j==1) dp[i][j]=0;
			else{
				dia = dp[i-1][j-1] + calcula(i-1, j-1, alma[i-1][j-1], alma);
				arr = dp[i-1][j] + calcula(i-1, j, alma[i-1][j], alma);
				izq = dp[i][j-1] + calcula(i, j-1, alma[i-1][j], alma);
				dp[i][j] = min(dia,min(arr, izq));
			}
		}
	}
	return dp[fil][col];
}

int main(){
	int alma[][col]={{4,2,2,4},{1,4,6,8},{2,5,9,1},{1,3,11,12}};
	
	
	cout<<vuelodron(alma,0,0);
	
	return 0;
}


