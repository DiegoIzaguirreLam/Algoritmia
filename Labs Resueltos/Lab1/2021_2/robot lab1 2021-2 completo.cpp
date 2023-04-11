
#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

void cargabin(int num, int n, int cromo[]){
	int i, res;
	for(int i=0;i<n;i++)cromo[i]=0;
	i=0;
	while(num>0){
		res = num%2;
		num = num/2;
		cromo[i]=res;
		i++;
	}
}


int main(){
	int peso, n, pparcial, pvalor, mvalor=0, nresultados=1, indmvalor;
	cout<<"Ingrese el numero de productos: "<<endl;
	cin>>n;
	cout<<"Ingrese el peso maximo: "<<endl;
	cin>>peso;
	int paq[n];
	cout<<"Ingrese el peso de los productos: "<<endl;
	for(int i=0;i<n;i++)
		cin>>paq[i];
	int valor[n];
	cout<<"Ingrese el valor de los productos respectivamente: "<<endl;
	for(int i=0;i<n;i++)
		cin>>valor[i];
	int cromo[n];
	int opcion = (int)pow(2, n);
	
	for(int i=0;i<opcion;i++){
		cargabin(i,n,cromo);
		pparcial=0;
		pvalor=0;
		for(int j=0;j<n;j++){
			pparcial=cromo[j]*paq[j]+pparcial;
			pvalor=cromo[j]*valor[j]+pvalor;
		}
		if(pparcial<=peso && pvalor>mvalor){
			indmvalor=i;
			mvalor=pvalor;
		}
	}
	
	cargabin(indmvalor,n,cromo);
	cout<<"Ganancia: "<<mvalor<<"   Resultado: ";
	for(int j=0;j<n;j++)
		if(cromo[j]==1)
			cout<<paq[j]<<"k ";
	cout<<"   Ubicaciones: ";
	for(int j=0;j<n;j++){
		if(cromo[j]==1){
			if(j%4==0) cout<<"IA"<<j/4+1<<" ";
			if(j%4==1) cout<<"IB"<<j/4+1<<" ";
			if(j%4==2) cout<<"DA"<<j/4+1<<" ";
			if(j%4==3) cout<<"DB"<<j/4+1<<" ";
		}
	}
	nresultados++;
	cout<<endl;
	return 0;
}


