
#include <iostream>
#define MAX 5
using namespace std;

void merge(int A[], int inicial, int medio, int final){
	int longitud1, longitud2, i, p, q;
	
	longitud1=(medio+1)-inicial;//primera mitad del arreglo
	longitud2=final-medio;//segunda mitad del arreglo
	
	int P[longitud1+1];
	int Q[longitud2+1];
	
	//agrego los valores mayores de ambos arreglos
	P[longitud1]=999999;
	Q[longitud2]=999999;
	
	//copiamos los valores desde A hacia los arreglos auxiliares P y Q
	for (i=inicial;i<=medio;i++)
		P[i-inicial]=A[i];
	for (i=medio+1;i<=final;i++)
		Q[i-(medio+1)]=A[i];
	
	p=q=0;
	for (i=inicial;i<=final;i++)
		if (P[p]<Q[q])
			A[i]=P[p++];
		else
			A[i]=Q[q++];
}

void mergesort(int A[], int inicial, int final){
	if (inicial==final)
		return;
		
	int medio=(inicial+final)/2;
	mergesort(A,inicial, medio);//logn
	mergesort(A,medio+1, final);//logn
	
	merge(A, inicial, medio, final);
	
}

int realizadp(int mat[][MAX],int n){
	int arr[n*n];
	int indProd=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			if(mat[i][j]!=0)
				arr[indProd++]=mat[i][j];
	}
	
	mergesort(arr, 0, indProd-1);
	
	for(int i=0;i<indProd;i++) cout<<arr[i]<<" ";
	
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
	int dif=99999;
	for(int j=sum/3;j>=0;j--){
		if(dp[n][j]==1){
			dif=sum-3*j;
			if(dif==0){
				return 1;
			}
			return 0;
		}
	}
}
int main(){
	int n=MAX;
	int mat[][MAX]={{3,0,6,0,0},{0,0,0,0,0},{0,0,4,0,0}, {0,0,0,0,0},{3,2,0,0,3}};
	
	cout<<endl<<realizadp(mat, n)<<endl;
	
	return 0;
}

