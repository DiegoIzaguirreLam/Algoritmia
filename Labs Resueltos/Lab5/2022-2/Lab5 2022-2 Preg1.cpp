
#include <iostream>

using namespace std;


void ordena(int pesos[], int n){
	int temp;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(pesos[i]>pesos[j]){
				temp=pesos[i];
				pesos[i]=pesos[j];
				pesos[j]=temp;
			}
		}
	}
}

int maxPeso(int pesos[], int n, int k){
    int f[n+1];
    f[0]=0;
    f[1]=0;
    ordena(pesos, n);
    for(int i=2;i<=n;i++){
        if(pesos[i-1]-pesos[i-2]<k){
            f[i]=f[i-2]+pesos[i-1]+pesos[i-2];
        }
        else
            f[i]=f[i-1];
    }
    return f[n];
}

int main(){
	int pesos[]={3,25,18,15,4,12,6};
	int n=7, k=5;
	cout<<"El peso maximo es: "<<maxPeso(pesos, n, k);
	
	return 0;
}
