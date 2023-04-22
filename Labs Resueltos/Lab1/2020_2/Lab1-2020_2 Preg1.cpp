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
	int nSelecc=0,pcosto, N, M, P;
	double ppromedior, mpromedior=999999999;
	cout<<"Ingrese los parametros N, M y P"<<endl;
	cin>>N>>M>>P;
	int cromo[N];
	int opcion=(int)pow(2,N);
	int mcomb[N], nmcomb=0,mcosto[N];
	int c[N], r[N], s[N];
	cout<<"Ingrese la rotura (r) y el suelo (s) para cada obrero:"<<endl;
	for(int i=0;i<N;i++){
		c[i]=i+1;
		cout<<"Obrero "<<c[i]<<": ";
		cin>>r[i]>>s[i];
	}
	
	for(int i=0;i<opcion;i++){
		cargabin(i,N,cromo);
		ppromedior=0;
		nSelecc=0;
		pcosto=0;
		for(int j=0;j<N;j++){
			ppromedior+=cromo[j]*r[j];
			nSelecc+=cromo[j];
			pcosto+=s[j]*cromo[j];
		}
		ppromedior=ppromedior/nSelecc;
		if(ppromedior==mpromedior && pcosto<=P && nSelecc>=M && nSelecc<=N){
			mpromedior=ppromedior;
			mcosto[nmcomb]=pcosto;
			mcomb[nmcomb]=i;
			nmcomb++;
		}
		else if(ppromedior<mpromedior && pcosto<=P && nSelecc>=M && nSelecc<=N){
			mpromedior=ppromedior;
			nmcomb=0;
			mcosto[nmcomb]=pcosto;
			mcomb[nmcomb]=i;
			nmcomb++;
		}
	}
	cout<<"Soluciones: "<<endl;
	for(int i=0;i<nmcomb;i++){
		cout<<"Obreros: ";
		cargabin(mcomb[i], N, cromo);
		for(int j=0;j<N;j++){
			if(cromo[j]==1) cout<<c[j]<<", ";
		}
		cout<<"Costo de Salarios de "<<mcosto[i]<<" (Miles de $) y una rotura promedio de "<<mpromedior<<endl<<endl;
	}

	return 0;
}
