
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int hallaMaxTiempo(int arr[],int N,int R){
    int dp[R][N+1];
    int suma=0;
    dp[0][0]=0;
    for(int i=0;i<=N;i++){
        suma += arr[i];
        dp[0][i+1]=suma;
    }
    for(int i=0;i<R;i++)
        dp[i][0]=0;
    int sumaSig;
    for(int i=1;i<R;i++){
        for(int j=1;j<=N;j++){
            sumaSig=0;
            dp[i][j]=99999;
            for(int k=j-1;k>=0;k--){
                sumaSig+=arr[k];
                dp[i][j]=min(dp[i][j], max(dp[i-1][k], sumaSig));
            }
        }
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<=N;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[R-1][N];
}

int main(){
    int arr[]={10, 15, 30, 45, 60}; //ordenarlas primero (sin recursion)
    int N=5;
    int R=3;
    
    cout<<"El tiempo maximo para "<<R<<" robots es de "<<hallaMaxTiempo(arr, N, R)<<" horas"<<endl;
    return 0;
}
