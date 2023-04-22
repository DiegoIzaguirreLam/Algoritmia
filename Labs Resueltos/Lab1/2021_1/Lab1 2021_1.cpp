/*
Datos de entrada:
13 7000 13
2 30 10000 7
4 25 17000 3
6 22 27000 2
8 15 35000 1
*/
#include <iostream>
#include <math.h>
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
	int max=32,n=4, nparcial, cparcial, mcosto=999999999,pvalor,nTvehiculos, tipo, pcapacidad;
	int T[n], ccT[n], rkgT[n], csT[n], nT[n], M, D, P;
	int nTipo[n], mnTipo[n];
	
	cin>>M>>D>>P;
	cout<<"Ingrese la informacion de cada tipo de vehiculo de forma ordenada: "<<endl;
	for(int i=0;i<n;i++){
		cin>>ccT[i]>>rkgT[i]>>csT[i]>>nT[i];
		T[i]=i+1;
	}
	nTvehiculos=nT[0]+nT[1]+nT[2]+nT[3];
	int cromo[nTvehiculos];
	int opcion=(int)pow(2,nTvehiculos);
	
	
	for(int i=0;i<opcion;i++){
		cargabin(i,nTvehiculos,cromo);
		nparcial=0;
		cparcial=0;
		pcapacidad=0;
		for(int k=0;k<n;k++)
			nTipo[k]=0;
		for(int j=0;j<nTvehiculos;j++){
			if(!cromo[j]) continue;
			
			if(j<nT[0]) tipo=0;
			if(j>=nT[0] && j<nT[1]+nT[0]) tipo=1;
			if(j>=nT[1]+nT[0] && j<nT[2]+nT[1]+nT[0]) tipo=2;
			if(j>=nT[2]+nT[1]+nT[0] && j<nT[3]+nT[2]+nT[1]+nT[0]) tipo=3;
			
			cparcial+=(D/rkgT[tipo])*P+(D/5000)*csT[tipo];
			pcapacidad+=ccT[tipo];
			nparcial++;
			nTipo[tipo]++;
		}
		if(cparcial<mcosto && nparcial<=32 && pcapacidad>=M){
			mcosto=cparcial;
			for(int k=0;k<n;k++)
				mnTipo[k]=nTipo[k];
		}
	}
	
	cout<<"Costo: "<<mcosto<<endl;
	cout<<"Tipo 1: "<<mnTipo[0]<<endl;
	cout<<"Tipo 2: "<<mnTipo[1]<<endl;
	cout<<"Tipo 3: "<<mnTipo[2]<<endl;
	cout<<"Tipo 4: "<<mnTipo[3]<<endl;
	
	return 0;
}




