
#include <stdio.h>
#include <cmath>
#include <iostream>
#define MAXVEHICULOS 32

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
	int T[4], ccT[4], rkgT[4], csT[4], nT[4], pparcial, cparcial, opcion, cargaTotal, distancia, precioGalon;
	int tipo, minCosto=99999999, minNumTipo[4];
	int nTipo[4];
	cout<<"Ingrese la informacion para cada tipo de vehiculo: "<<endl;
	for(int i=0;i<4;i++){
		cout<<"Tipo: ";
		cin>>T[i];
		cout<<"Capacidad de carga en toneladas: ";
		cin>>ccT[i];
                cout<<"Rendimiento en kms/galon: ";
                cin>>rkgT[i];
		cout<<"Costo en soles por servicio de mantenimiento cada 5000kms: ";
		cin>>csT[i];
		cout<<"Cantidad de vehiculos: ";
		cin>>nT[i];
	}
	int Nvehiculos=nT[0]+nT[1]+nT[2]+nT[3];
        int cromo[Nvehiculos];
	cout<<"Ingrese los valores de M, D y P: ";
	cin>>cargaTotal>>distancia>>precioGalon;
	opcion=(int)pow(2, Nvehiculos);
	double factorDistCosto=distancia/5000;
	for(int i=0; i<opcion;i++){
		cargabin(i, Nvehiculos, cromo);
		pparcial=0;
		cparcial=0;
		for(int j=0;j<4;j++) nTipo[j]=0;
		for(int j=0;j<Nvehiculos;j++){
			if(!cromo[j]) continue;
			if(j<nT[0]) tipo=0;
			if(j>=nT[0] and j<nT[1]) tipo=1;
			if(j>=nT[1] and j<nT[2]) tipo=2;
			if(j>=nT[2] and j<nT[3]) tipo=3;
			pparcial=pparcial+ccT[tipo];
			cparcial=cparcial+(int)csT[tipo]*factorDistCosto+(distancia/rkgT[tipo])*precioGalon;
			nTipo[tipo]++;
		}
		if(cparcial<minCosto && pparcial>=cargaTotal){
			minCosto=cparcial;
			for(int k=0;k<4;k++) minNumTipo[k]=nTipo[k];
		}
	}
	
	cout<<"La mejor combinacion tiene un costo de "<<minCosto<<" y es: "<<endl;
	cout<<"Tipo 1: "<<minNumTipo[0]<<endl;
	cout<<"Tipo 2: "<<minNumTipo[1]<<endl;
	cout<<"Tipo 3: "<<minNumTipo[2]<<endl;
	cout<<"Tipo 4: "<<minNumTipo[3]<<endl;
	return 0;
}




