
#include <cstdio>
#include <cstdlib>
#include <iostream>
#define MAX 10
using namespace std;
void imprimeResultado(int subs[], int n, int arr[]){
    int ind;
    cout<<endl<<"Resultado: ";
    for(int i=0;i<n;i++){
        cout<<arr[subs[i]]<<"k ";
    }
    cout<<" Ubicaciones: ";
    for(int i=0;i<n;i++){
        ind=subs[i];
        if(ind%4==0) cout<<"IA"<<ind/4+1<<" ";
        if(ind%4==1) cout<<"IB"<<ind/4+1<<" ";
        if(ind%4==2) cout<<"DA"<<ind/4+1<<" ";
        if(ind%4==3) cout<<"DB"<<ind/4+1<<" ";
    }
}

int hallaPeso(int arr[],int n, int peso){
	int sum=0;
	
	for(int i=0;i<n;i++) 
		sum = sum + arr[i];
	
	int dp[n+1][sum+1];
	
	for(int i=0;i<=n;i++) dp[i][0]=1;
	for(int i=1;i<=sum;i++) dp[0][i]=0; 
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=sum;j++){
			dp[i][j] = dp[i-1][j];
			if(arr[i-1]<=j && dp[i][j]==0)	
				dp[i][j]=dp[i-1][j-arr[i-1]];
		}
	for(int i=0;i<=n;i++){
		cout << endl;
		for(int j=0;j<=sum;j++)	
			cout << dp[i][j] <<" ";	
	} // solo para ver lo que se esta haciendo
    int j=peso;
	if(dp[n][j]==1){
		int  subset1[n], indSubs1=0;
		int i = n;
		int k = j;
		while(i > 0 && k >= 0){//para todas las filas de elementos validos y columnas hasta 0.
		    if(!dp[i-1][k]){//si el de la misma columna una fila arriba es 1, entonces no necesitamos el valor en arr[i] para el subconjunto (por tanto debe estar en el otro subconjunto)
		        subset1[indSubs1++]=i-1;
		        k -= arr[i-1];
		    }
		i--;
		}
		imprimeResultado(subset1, indSubs1, arr);
		return 1;	
	}
    return 0; 
}

int main(){
    int n=16;
    int arr[]={7, 9, 8, 18, 17, 12, 6, 7, 14, 11, 10, 15, 19, 8, 12, 11};
    int peso=23;
    hallaPeso(arr, n, peso);
}


