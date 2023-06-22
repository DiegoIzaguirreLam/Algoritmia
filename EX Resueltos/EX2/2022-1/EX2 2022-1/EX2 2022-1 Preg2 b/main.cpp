/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 22 de junio de 2023, 11:34 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int hallaMax(int a, int b){
    if(a>=b) return a;
    return b;
}
int gananciaMaxima(int arr[], int n,int k){
    
    int dp[k+1][n];
    
    for(int j=0;j<n;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=k;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=0;
            for(int l=0;l<j;l++){//es un LIS
                if(dp[i-1][l]+(arr[j]-arr[l])>dp[i][j]){
                    dp[i][j]=dp[i-1][l]+arr[j]-arr[l];//revisa la solucion optima para i-1 acciones para un día l, y evalúa la ganancia con ese día l y el dia actual j. se cambia si este valor es mayor al actual en dp[i][j]
                }
                if(dp[i][l]>dp[i][j])//para que siempre dp[i][j] tome el mayor valor posible, sea obtenido con lo anterior o el valor de dp[i][l]
                    dp[i][j]=dp[i][l];
            }
        }
    }
    for(int i=0;i<=k;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return dp[k][n-1];
}


int main(int argc, char** argv) {
    int arr[]={315,322,385,375,365,380};
    int n=6;
    int k=2;
    cout<<"La ganancia máxima será "<<gananciaMaxima(arr, n, k)<<" soles para $100";
    return 0;
}

