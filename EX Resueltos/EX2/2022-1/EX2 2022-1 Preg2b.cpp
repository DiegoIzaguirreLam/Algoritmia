
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int maxGanancia(int datos[],int N,int K){
    int dp[K+1][N+1];
    for(int i=0;i<=N;i++) dp[0][i]=0;
    for(int i=0;i<=K;i++) dp[i][0]=0;
    
    for(int i=1;i<=K;i++){
        for(int j=1;j<=N;j++){
            if(i==1 && j==1){
                dp[i][j]=0;
            }
            else{
                dp[i][j]=dp[i][j-1];
                for(int t=1; t<j;t++){
                    dp[i][j] = max(dp[i][j], dp[i-1][t]+datos[j-1]-datos[t-1]);
                }
            }
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return dp[K][N];
}

int main(){
    int N=6, K=2;
    int datos[]={315, 322, 385, 375, 365, 380};
    cout<<maxGanancia(datos, N, K);
    return 0;
}


