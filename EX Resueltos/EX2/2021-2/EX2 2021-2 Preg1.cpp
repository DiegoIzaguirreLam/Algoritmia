
#include <iostream>
#define MAX 10
#define MAXC 100
using namespace std;

double maxI=0;
double maxInversion;
double maxR=0;

int solu[9];
int maxSol[9];
int y=0;

void imprimeResultadoC(double data[][MAX], char canal[][MAXC], int n){
	cout<<"El maximo ingreso por ventas es de "<<maxI<<" dolares con una inversion total en publicidad de "<<maxInversion<<" dolares."<<endl;
	cout<<endl<<"Los canales de publicidad que se deben de elegir para obtener el maximo ingreso total son: "<<endl;
	
	for(int i=0;i<n;i++){
		if(maxSol[i]){
			cout<<"- Canal "<<i+1<<" - "<<canal[i]<<", ingreso = "<<data[i][0]*data[i][1]<<" dolares con una inversion publicitaria de "<<data[i][0]<<" dolares."<<endl;
		}
	}
}

void imprimeResultadoD(double data[][MAX], char canal[][MAXC], int n){
	cout<<"El nivel maximo de recordacion de marca es de "<<maxR<<" dolares con una inversion total de "<<maxInversion<<" dolares y un ingreso de "<<maxI<<" dolares"<<endl;
	cout<<endl<<"Los canales de publicidad que se deben de elegir para obtener el maximo ingreso total son: "<<endl;
	
	for(int i=0;i<n;i++){
		if(maxSol[i]){
			cout<<"- Canal "<<i+1<<" - "<<canal[i]<<", recordacion de marca = "<<data[i][2]<<", ingreso = "<<data[i][0]*data[i][1]<<" dolares con una inversion publicitaria de "<<data[i][0]<<" dolares."<<endl;
		}
	}
}

int calculaMax(double data[][MAX],int n, int P, int i, double parcialI, int invParcial){
	if(P<0) return 0;
	if(i>=n || P==0){
		if(parcialI>maxI){
			maxI=parcialI;
			maxInversion=invParcial;
			for(int j=0;j<9;j++) maxSol[j]=solu[j];
		}
		return 0;
	}
	solu[i]=1;
	if(calculaMax(data, n, P-data[i][0], i+1, parcialI+data[i][0]*data[i][1], invParcial+data[i][0])){
		return 1;
	}
	else{
		solu[i]=0;
		return calculaMax(data, n, P, i+1, parcialI, invParcial);
	}
}

int hallaMaxRecordacion(double data[][MAX],int n, int P, int i, double parcialI, int invParcial, int parcialR){
	if(P<0) return 0;
	if(i>=n || P==0){
		if(parcialR>maxR){
			maxI=parcialI;
			maxInversion=invParcial;
			maxR=parcialR;
			for(int j=0;j<9;j++) maxSol[j]=solu[j];
		}
		return 0;
	}
	solu[i]=1;
	if(hallaMaxRecordacion(data, n, P-data[i][0], i+1, parcialI+data[i][0]*data[i][1], invParcial+data[i][0], parcialR+data[i][2])){
		return 1;
	}
	else{
		solu[i]=0;
		return hallaMaxRecordacion(data, n, P, i+1, parcialI, invParcial, parcialR);
	}
}



int main(){
	
	double data[9][MAX]={{30000, 1.2, 2000},
					   {14000, 2.8, 3000},
					   {18000, 1.4, 1200},
					   {9000,  2.5, 400},
					   {15000, 1.3, 700},
					   {10000, 2, 800},
					   {21000, 1.2, 1300},
					   {15000, 2.5, 1000},
					   {20000, 1.1, 200}};
	
	char canal[][MAXC]={{"TV"},{"YOUTUBE"},{"RADIO"},{"EMAIL"},{"DIARIO"},{"FB"},{"ANUNCIOS"},{"GOOGLE_ADS"},{"EVENTOS"}};
	int P=50000;
	
	int n=9;
	calculaMax(data, n, P, 0, 0, 0);
	imprimeResultadoC(data, canal, n);
	for(int i=0;i<n;i++){
		solu[i]=0;
		maxSol[i]=0;
	}
	y=0;
	for(int i=0;i<MAXC;i++) cout<<"-";
	cout<<endl;
	hallaMaxRecordacion(data, n, P, 0, 0, 0, 0);
	imprimeResultadoD(data, canal, n);
	return 0;
}






