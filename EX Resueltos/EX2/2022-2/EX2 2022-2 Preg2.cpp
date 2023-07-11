#include <iostream>
#define MAX 10

using namespace std;

int hallaNFormas(int num1[],int num2[],int m,int n){
	int dp[n+1][m+1];//n primeros digitos de numero grande en fila y n primeros digitos de numero a formar en columna.
	for(int i=0;i<=m;i++) dp[0][i]=0;
	for(int i=0;i<=n;i++) dp[i][0]=1;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(num1[j-1]==num2[i-1]){
				dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
			}
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	return dp[n][m];
}

int main(){
	int m=2, n=5;
	int num1[]={9,5};//num buscado
	int num2[]={9,9,5,5,9};//num donde se busca
	
	cout<<"Se puede armar el numero de "<<hallaNFormas(num1, num2, m, n)<<" formas."<<endl;
	return 0;
}


