

#include <iostream>
#include <cmath>
using namespace std;

int maxG=0;

void filtraProductos(int producto[][2],int N,int pFiltrados[],int cFiltrados[], int &nFiltrados, int &panetonInd){
	int menorInd;
	int menorPrecio;
	int tipo, tipoEva;
        int i=0;
	while(i<N){
		tipo = producto[i][0]/pow(10, 5);
		menorPrecio = producto[i][1];
		menorInd=i;
		do{
			if(producto[i][1]<menorPrecio){
				menorPrecio=producto[i][1];
				menorInd = i;
			}
			i++;
			tipoEva = producto[i][0]/pow(10, 5);
		}while(tipo==tipoEva);
		pFiltrados[nFiltrados]=producto[menorInd][1];
		cFiltrados[nFiltrados++]=producto[menorInd][0];
		if(tipo==7){
			panetonInd = menorInd;
		}
	}
}

int maxGanancia(int pFiltrados[], int cFiltrados[],int nFiltrados, int P, int escogidos[], int nEsc, int panetonInd, int i, int parcial, int escogidosMax[], int &nEscMax){
	if(parcial > P) return 0;
	if(i==nFiltrados){
		if(parcial>maxG){
			maxG = parcial;
			for(int j=0;j<nEsc;j++){
				escogidosMax[j]=escogidos[j];
			}
			nEscMax=nEsc;
		}
		return 0;
	}
	escogidos[nEsc++]=cFiltrados[i];
	if(i==panetonInd){//se debe poner de todas formas
		if(maxGanancia(pFiltrados, cFiltrados, nFiltrados, P, escogidos, nEsc, panetonInd, i+1, parcial+pFiltrados[i], escogidosMax, nEscMax))
			return 1;
		else//si no puede tomar el paneton, entonces la solucion no es valida
			return 0;
	}
	else{
		if(maxGanancia(pFiltrados, cFiltrados, nFiltrados, P, escogidos, nEsc, panetonInd, i+1, parcial+pFiltrados[i], escogidosMax, nEscMax)){
			return 1;
		}
		else{//retrocede y se prueba sin tomar el producto
			nEsc--;
			return maxGanancia(pFiltrados, cFiltrados, nFiltrados, P, escogidos, nEsc, panetonInd, i+1, parcial, escogidosMax, nEscMax);
		}
		return 0;
	}
}

int main(){
	int N=10, P=20;
	int producto[][2]={{500021, 2}, {500024, 3}, {500120, 4}, {300492, 4}, {300120, 3}, {700399, 10}, {700120, 8}, {800211, 3}, {800184, 5},{900212, 5}};
	int escogidos[N]={};
	int nEsc=0;
	int pFiltrados[N], cFiltrados[N];
	int nFiltrados=0;
	int panetonInd;
	int escogidosMax[N], nEscMax=0;
	
	filtraProductos(producto, N, pFiltrados, cFiltrados, nFiltrados, panetonInd);
	for(int i=0;i<nFiltrados;i++) cout<<pFiltrados[i]<<" ";
	cout<<endl;
	maxGanancia(pFiltrados, cFiltrados, nFiltrados, P, escogidos, nEsc, panetonInd, 0, 0, escogidosMax, nEscMax);
	cout<<maxG<<endl;
	for(int j=0;j<nEscMax;j++){
		cout<<escogidosMax[j]<<" ";
	}
	return 0;
}


