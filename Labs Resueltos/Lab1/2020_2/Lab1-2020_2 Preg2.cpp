/*
8 250
40 150 1
20 80 1
100 300 2
100 150 2
50 80 2
10 50 3
50 120 3
50 150 3
*/
#include <iostream>
#include <cmath>

using namespace std;

void cargabin(int num,int n,int cromo[]){
	int i,res;
	for(i=0;i<n;i++)cromo[i]=0; 
	i=0;
	while(num>0){
		res = num%2;
		num = num/2;
		cromo[i]=res;
		i++;
	}
}

int main(){
	int N, P,pcosto,pganancia, flagT1, flagT2, flagT3, mganancia=0;
	cin>>N>>P;
	int cromo[N], m[N], c[N], g[N], t[N], mcomb[N], mcosto[N], nmcomb;
	for(int i=0;i<N;i++){
		m[i]=i+1;
		cout<<"Maquina "<<m[i]<<": ";
		cin>>c[i]>>g[i]>>t[i];
	}
	int opcion=(int)pow(2,N);
	
	
	for(int i=0;i<opcion;i++){
		cargabin(i, N, cromo);
		pcosto=0;
		pganancia=0;
		flagT1=0;
		flagT2=0;
		flagT3=0;
		for(int j=0;j<N;j++){
			pcosto+=c[j]*cromo[j];
			pganancia+=g[j]*cromo[j];
			if(t[j]==1) flagT1=1;
			if(t[j]==2) flagT2=1;
			if(t[j]==3) flagT3=1;
		}
		if(flagT1 && flagT2 && flagT3 && pcosto<=P && pganancia>mganancia){
			mganancia=pganancia;
			mcosto[0]=pcosto;
			mcomb[0]=i;
			nmcomb=1;
		}
		else if(flagT1 && flagT2 && flagT3 && pcosto<=P && pganancia==mganancia){
			mcosto[nmcomb]=pcosto;
			mcomb[nmcomb]=i;
			nmcomb++;
		}
	}
	
	for(int i=0;i<nmcomb;i++){
		cout<<"Resultado "<<i+1<<":"<<endl;
		cargabin(mcomb[i], N, cromo);
		cout<<"Maquinas: ";
		for(int j=0;j<N;j++){
			if(cromo[j]==1) cout<<m[j]<<", ";
		}
		cout<<"Costo de maquinas "<<mcosto[i]<<" (Millones de $) y una ganancia de "<<mganancia<<" (Millones de $)"<<endl;	
	}
	return 0;
}
