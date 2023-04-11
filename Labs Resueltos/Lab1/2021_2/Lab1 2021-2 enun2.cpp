#include <cstdio>
#include <math.h>
#include <cstdlib>
#include <iostream>
#define MAXCLIENTES 16

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
	int T=10000, N=6;
	int cromo[N], clientes[N], cantidad[N]={3000,3800,2800,3500,3200,3400}, macciones=0, pacciones, ncomb[N], k=0;
	double P=4, porcentaje[N]={0.1,0.02,0.15,0.05,0.08,0.03}, mprecio=0, pprecio; 
	int opcion=(int)pow(2,N);
	for(int i=0;i<N;i++) clientes[i]=i+1;
	
	
	for(int i=0;i<opcion;i++){
		cargabin(i,N,cromo);
		pprecio=pacciones=0;
		for(int j=0;j<N;j++){
			pprecio=pprecio+cromo[j]*cantidad[j]*P*porcentaje[j];
			pacciones=pacciones+cromo[j]*cantidad[j];
		}
		if(pacciones>T) continue;
		if(pprecio>mprecio+1){
                    k=0;
                    mprecio=pprecio;
                    macciones=pacciones;
                    ncomb[k]=i;
                    k++;
		}
                else if(abs(mprecio-pprecio)<=1){
                    ncomb[k]=i;
                    k++;
                }
	}
	for(int s=0;s<k;s++){
            cargabin(ncomb[s], N, cromo);
            cout<<"Maxima ganancia: "<<mprecio<<" por un total de "<<macciones<<" acciones"<<endl;
            for(int j=0;j<N;j++){
                if(cromo[j]==1)
                    cout<<"El cliente "<<clientes[j]<<" otorga una ganancia de "<<cantidad[j]*P*porcentaje[j]<<" por comprar "<<cantidad[j]<<" acciones."<<endl;
            }
        }

	return 0;
}


