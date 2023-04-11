#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

void cargabin(int num, int n, int cromo[], int *ptipos){
	int i, res;
	for(int i=0;i<n;i++)cromo[i]=0;
	i=0;
	while(num>0){
		res = num%2;
		num = num/2;
		cromo[i]=res;
		i++;
		if(res==1) (*ptipos)++;
	}
}

int main(){
	int ntipos, presupuesto, maxtipos, pparcial, ptipos, pherramientas, opcion;
	cout<<"Ingrese el numero de tipos de herramientas: ";
	cin>>ntipos;
	if(ntipos>10) return 0;
	int tipo[ntipos], precio[ntipos], cantidad[ntipos], cromo[ntipos];
	cout<<"Ingrese el numero maximo de tipo de herramientas a elegir: ";
	cin>>maxtipos;
	cout<<"Ingrese el maximo presupuesto P: ";
	cin>>presupuesto;
	
	cout<<"Ingrese el numero de los tipos de herramientas: ";
	for(int i=0;i<ntipos;i++)
		cin>>tipo[i];
	
	cout<<"Ingrese el precio de cada tipo de herramienta respectivamente: ";
	for(int i=0;i<ntipos;i++)
		cin>>precio[i];
	
	cout<<"Ingrese la cantidad por renovar por herramienta de cada tipo de herramienta respectivamente: ";
	for(int i=0;i<ntipos;i++)
		cin>>cantidad[i];	
	
	opcion=pow(2, ntipos);
	for(int i=0;i<opcion;i++){
		ptipos=0;
		cargabin(i, ntipos, cromo, &ptipos);
		pparcial=0;
		pherramientas=0;
		if(ptipos>maxtipos) continue;
		for(int j=0;j<ntipos;j++){
			pparcial=cromo[j]*precio[j]*cantidad[j]+pparcial;
			pherramientas=cromo[j]*cantidad[j]+pherramientas;
		}
		if(pparcial<=presupuesto){
			cout<<"Combinacion "<<i<<": "<<endl;
			for(int k=0; k<ntipos;k++)
				if(cromo[k]==1)
					cout<<tipo[k]<<" ";
			cout<<endl;
			cout<<"Monto Total: "<<pparcial<<endl;
			cout<<"Cantidad de tipos de herramientas: "<<ptipos<<endl;
		}
	}
	
	
	return 0;
}
