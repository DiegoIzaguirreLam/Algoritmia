
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int buscaiguales(int arr[],int n){
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
	for(int j=8;j>=0;j--){
		if(dp[n][j]==1){
			dif=8-j;
			if(dif) cout<<endl<<"Si solo se utiliza el turno mañana, se desperdicia "<<dif<<" horas del turno, ya que las tareas como maximo suman "<<j<<", sin sobrepasar las 8 horas del turno"<<endl;
			else cout<<endl<<"Si solo se utiliza el turno mañana, no se desperdicia ninguna hora del turno, ya que las tareas como maximo suman "<<j<<", sin sobrepasar las 8 horas del turno"<<endl;
			break;
		}
	}
	for(int j=16;j>=0;j--){
		if(dp[n][j]==1){
			dif=16-j;
			if(dif) cout<<"Si se usan dos turnos, se desperdicia "<<dif<<" horas del turno, ya que las tareas como maximo suman "<<j<<", sin sobrepasar las 16 horas de los turnos"<<endl;
			else cout<<"Si se usan dos turnos, no se desperdicia ninguna hora del turno, ya que las tareas como maximo suman "<<j<<", sin sobrepasar las 16 horas de los turnos"<<endl;
			break;
		}
	}
	for(int j=24;j>=0;j--){
		if(dp[n][j]==1){
			dif=24-j;
			if(dif) cout<<"Si se usan los tres turnos, se desperdicia "<<dif<<" horas del turno, ya que las tareas como maximo suman "<<j<<", sin sobrepasar las 24 horas de los turnos"<<endl;
			else cout<<"Si se usan los tres turnos, no se desperdicia ninguna hora del turno, ya que las tareas como maximo suman "<<j<<", sin sobrepasar las 24 horas de los turnos"<<endl;
			break;
		}
	}
	return 0;
}

int main(){
	int arr[]={1, 3, 6, 10, 16}, n=5;
	buscaiguales(arr, n);
	return 0;
}



