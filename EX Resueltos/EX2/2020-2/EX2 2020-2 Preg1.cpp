

#include <iostream>
#define MAXGRUPOS 10
#define MAXUBICACIONES 10
using namespace std;

int solu[MAXUBICACIONES][MAXGRUPOS]={};

void imprimeSolu(int ubicaciones[],int productos[],int M, int N){
	cout<<"{";
	for(int i=0;i<M;i++){
		cout<<ubicaciones[i];
		if(i!=M-1) cout<<", ";
		else cout<<"}";
	}
	
	int flagprimer=1;
	for(int i=0;i<M;i++){
		cout<<" Posicion "<<i<<": ";
		if(ubicaciones[i]){
			flagprimer=1;
			cout<<" Productos: ";
			for(int j=0;j<N;j++){
				if(solu[i][j]){
					if(!flagprimer){
						cout<<", ";
					}
					cout<<productos[j];
					flagprimer=0;
				}
			}
			cout<<". ";
		}
		else{
			cout<<"Sin productos almacenados.";
		}
	}
	cout<<endl<<endl;
}

int almacenaProductos(int productos[], int N,int ubicaciones[],int M, int indProd, int distribucion[]){
	if(indProd==N){
		imprimeSolu(distribucion, productos, M, N);
		return 0;//se pudieron almacenar todos los productos
	}
	
	for(int i=0;i<M;i++){//probamos insertarlo en todas las posiciones
		if(ubicaciones[i]-distribucion[i] >= productos[indProd]){
			distribucion[i] += productos[indProd];
			solu[i][indProd]=1;
			if(almacenaProductos(productos, N, ubicaciones, M, indProd+1, distribucion))
				return 1;
			else{
				distribucion[i] -= productos[indProd];
				solu[i][indProd] = 0;
			}
		}
	}
	return 0;
}

int main(){
	int productos[]={2,3,1,4};
	int N=4;
	int ubicaciones[]={3,2,5,1,3};
	int M=5;
	int distribucion[M]={};
	int solu[M]={};
	
	almacenaProductos(productos, N, ubicaciones, M, 0, distribucion);
	return 0;
}
