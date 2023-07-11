
#include <iostream>
#include <climits>
#define MAX 10
using namespace std;

int hallaDisposicion(int alma[][MAX],int n,int m,int p,int q){
	int dp[p+1][q+1];
	for(int i=0;i<=p;i++) dp[i][0]=0;
	for(int i=0;i<=q;i++) dp[0][i]=0;
	for(int i=1;i<=p;i++){
		for(int j=1;j<=q;j++){
			if(i==1 && j==1)
				dp[i][j]=alma[i-1][j-1];
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + alma[i-1][j-1];
			}
		}
	}
	return dp[p][q];
}

int main(){
	int n=6, m=6;
	int alma[][MAX]={{1,2,9,1,2,3},{5,1,7,1,2,1},{1,7,1,3,8,1},
					 {2,2,6,1,2,2},{3,6,9,5,1,5},{1,1,4,1,9,1}};
	int p=6, q=6;
	
	cout<<hallaDisposicion(alma, n, m, p, q);
	return 0;
}
